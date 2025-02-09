/*
 * Copyright 2013 Canonical Ltd.
 * Copyright 2021 Robert Tari
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *      Lars Uebernickel <lars.uebernickel@canonical.com>
 *      Robert Tari <robert@tari.in>
 */

public class SoundMenu: Object
{
    public enum DisplayFlags {
        NONE = 0,
        SHOW_MUTE = 1,
        HIDE_INACTIVE_PLAYERS = 2,
        HIDE_PLAYERS = 4,
        GREETER_PLAYERS = 8,
        SHOW_SILENT_MODE = 16,
        HIDE_INACTIVE_PLAYERS_PLAY_CONTROLS = 32,
        ADD_PLAY_CONTROL_INACTIVE_PLAYER = 64
    }

    public enum PlayerSectionPosition {
        LABEL = 0,
        PLAYER_CONTROLS = 1,
        PLAYLIST = 2
    }

    const string PLAYBACK_ITEM_TYPE = "org.ayatana.indicator.playback-item";

    public SoundMenu (string? settings_action, DisplayFlags flags) {
        /* A sound menu always has at least two sections: the volume section (this.volume_section)
         * at the start of the menu, and the settings section at the end. Between those two,
         * it has a dynamic amount of player sections, one for each registered player.
         */

        this.volume_section = new Menu ();

        if ((flags & DisplayFlags.SHOW_MUTE) != 0)
            volume_section.append (_("Mute"), "indicator.mute");
        if ((flags & DisplayFlags.SHOW_SILENT_MODE) != 0) {
            var item = new MenuItem(_("Silent Mode"), "indicator.silent-mode(true)");
            item.set_attribute("x-ayatana-type", "s", "org.ayatana.indicator.switch");
            volume_section.append_item(item);
        }

        volume_section.append_item (this.create_slider_menu_item (_("Volume"), "indicator.volume(0)", 0.0, 1.0, 0.01,
                                                                  "audio-volume-low-zero-panel",
                                                                  "audio-volume-high-panel", true));

        this.menu = new Menu ();
        this.menu.append_section (null, volume_section);

        if (settings_action != null) {
            settings_shown = true;
            this.menu.append (_("Sound Settings…"), settings_action);
        }

        var root_item = new MenuItem (null, "indicator.root");
        root_item.set_attribute ("x-ayatana-type", "s", "org.ayatana.indicator.root");
        root_item.set_attribute ("x-ayatana-scroll-action", "s", "indicator.scroll");
        root_item.set_attribute ("x-ayatana-secondary-action", "s", "indicator.mute");
        root_item.set_attribute ("submenu-action", "s", "indicator.indicator-shown");
        root_item.set_submenu (this.menu);

        this.root = new Menu ();
        root.append_item (root_item);

        this.hide_players = (flags & DisplayFlags.HIDE_PLAYERS) != 0;
        this.hide_inactive = (flags & DisplayFlags.HIDE_INACTIVE_PLAYERS) != 0;
        this.hide_inactive_player_controls = (flags & DisplayFlags.HIDE_INACTIVE_PLAYERS_PLAY_CONTROLS) != 0;
        this.add_play_button_inactive_player = (flags & DisplayFlags.ADD_PLAY_CONTROL_INACTIVE_PLAYER) != 0;
        this.notify_handlers = new HashTable<MediaPlayer, ulong> (direct_hash, direct_equal);

        this.greeter_players = (flags & DisplayFlags.GREETER_PLAYERS) != 0;
    }

    ~SoundMenu () {
        if (export_id != 0) {
            bus.unexport_menu_model(export_id);
            export_id = 0;
        }
    }

    public void set_default_player (string default_player_id) {
        this.default_player = default_player_id;
        foreach (var player_stored in notify_handlers.get_keys ()) {
            int index = this.find_player_section(player_stored);
            if (index != -1 && player_stored.id == this.default_player) {
                add_player_playback_controls (player_stored, index, true);
            }
        }
    }

    DBusConnection? bus = null;
    uint export_id = 0;

    public void export (DBusConnection connection, string object_path) {
        bus = connection;
        try {
            export_id = bus.export_menu_model (object_path, this.root);
        } catch (Error e) {
            critical ("%s", e.message);
        }
    }

    public bool show_mic_volume {
        get {
            return this.mic_volume_shown;
        }
        set {
            if (value && !this.mic_volume_shown) {
                var slider = this.create_slider_menu_item (_("Microphone Volume"), "indicator.mic-volume", 0.0, 1.0, 0.01,
                                                           "audio-input-microphone-low-zero-panel",
                                                           "audio-input-microphone-high-panel", false);
                volume_section.append_item (slider);
                this.mic_volume_shown = true;
            }
            else if (!value && this.mic_volume_shown) {
                int location = -1;
                while ((location = find_action(this.volume_section, "indicator.mic-volume")) != -1) {
                    this.volume_section.remove (location);
                }
                this.mic_volume_shown = false;
            }
        }
    }

    public bool show_high_volume_warning {
        get {
            return this.high_volume_warning_shown;
        }
        set {
            if (value && !this.high_volume_warning_shown) {
                /* NOTE: Action doesn't really exist, just used to find below when removing */
                var item = new MenuItem(_("High volume can damage your hearing."), "indicator.high-volume-warning-item");
                volume_section.append_item (item);
                this.high_volume_warning_shown = true;
            }
            else if (!value && this.high_volume_warning_shown) {
                int location = -1;
                while ((location = find_action(this.volume_section, "indicator.high-volume-warning-item")) != -1) {
                    this.volume_section.remove (location);
                }
                this.high_volume_warning_shown = false;
            }
        }
    }

    int find_action (Menu menu, string in_action) {
        int n = menu.get_n_items ();
        for (int i = 0; i < n; i++) {
            string action;
            menu.get_item_attribute (i, "action", "s", out action);
            if (in_action == action)
                return i;
        }

        return -1;
    }

    public void update_all_players_play_section() {
        foreach (var player_stored in notify_handlers.get_keys ()) {
            int index = this.find_player_section(player_stored);
            if (index != -1) {
                // just update to verify if we must hide the player controls
                update_player_section (player_stored, index);
            }
        }
    }

    private void check_last_running_player () {
        foreach (var player in notify_handlers.get_keys ()) {
            if (player.is_running && number_of_running_players == 1) {
                // this is the first or the last player running...
                // store its id
                this.last_player_updated (player.id);
            }
        }
    }

    public void add_player (MediaPlayer player) {
        if (this.notify_handlers.contains (player))
            return;

        if (player.is_running || !this.hide_inactive)
            this.insert_player_section (player);
        this.update_playlists (player);

        var handler_id = player.notify["is-running"].connect ( () => {
            int index = this.find_player_section(player);
            if (player.is_running) {
                if (index == -1) {
                    this.insert_player_section (player);
                }
                number_of_running_players++;
            }
            else {
                number_of_running_players--;
                if (this.hide_inactive)
                    this.remove_player_section (player);
            }
            this.update_playlists (player);

            // we need to update the rest of players, because we might have
            // a non running player still showing the playback controls
            update_all_players_play_section();

            check_last_running_player ();
        });
        this.notify_handlers.insert (player, handler_id);

        player.playlists_changed.connect (this.update_playlists);
        player.playbackstatus_changed.connect (this.update_playbackstatus);

        check_last_running_player ();
    }

    public void remove_player (MediaPlayer player) {
        this.remove_player_section (player);

        var id = this.notify_handlers.lookup(player);
        if (id != 0) {
            player.disconnect(id);
        }

        player.playlists_changed.disconnect (this.update_playlists);

        /* this'll drop our ref to it */
        this.notify_handlers.remove (player);

        check_last_running_player ();
    }

    public void update_volume_slider (VolumeControl.ActiveOutput active_output) {
        int index = find_action (this.volume_section, "indicator.volume");
        if (index != -1) {
            string label = "Volume";
            switch (active_output) {
                case VolumeControl.ActiveOutput.SPEAKERS:
                    label = _("Volume");
                    break;
                case VolumeControl.ActiveOutput.HEADPHONES:
                    label = _("Volume (Headphones)");
                    break;
                case VolumeControl.ActiveOutput.BLUETOOTH_SPEAKER:
                    label = _("Volume (Bluetooth)");
                    break;
                case VolumeControl.ActiveOutput.USB_SPEAKER:
                    label = _("Volume (Usb)");
                    break;
                case VolumeControl.ActiveOutput.HDMI_SPEAKER:
                    label = _("Volume (HDMI)");
                    break;
                case VolumeControl.ActiveOutput.BLUETOOTH_HEADPHONES:
                    label = _("Volume (Bluetooth headphones)");
                    break;
                case VolumeControl.ActiveOutput.USB_HEADPHONES:
                    label = _("Volume (Usb headphones)");
                    break;
                case VolumeControl.ActiveOutput.HDMI_HEADPHONES:
                    label = _("Volume (HDMI headphones)");
                    break;
                case VolumeControl.ActiveOutput.CALL_MODE:
                    break;
            }
            this.volume_section.remove (index);
            this.volume_section.insert_item (index, this.create_slider_menu_item (_(label), "indicator.volume(0)", 0.0, 1.0, 0.01,
                                                                  "audio-volume-low-zero-panel",
                                                                  "audio-volume-high-panel", true));
        }
    }

    public Menu root;
    public Menu menu;
    Menu volume_section;
    bool mic_volume_shown;
    bool settings_shown = false;
    bool high_volume_warning_shown = false;
    bool hide_inactive;
    bool hide_players = false;
    bool hide_inactive_player_controls = false;
    bool add_play_button_inactive_player = false;
    HashTable<MediaPlayer, ulong> notify_handlers;
    bool greeter_players = false;
    int number_of_running_players = 0;
    string default_player = "";

    /* returns the position in this.menu of the section that's associated with @player */
    int find_player_section (MediaPlayer player) {
        debug("Looking for player: %s", player.id);
        string action_name = @"indicator.$(player.id)";
        int n = this.menu.get_n_items ();
        for (int i = 0; i < n; i++) {
            var section = this.menu.get_item_link (i, Menu.LINK_SECTION);
            if (section == null) continue;

            string action;
            section.get_item_attribute (0, "action", "s", out action);
            if (action == action_name)
                return i;
        }

        debug("Unable to find section for player: %s", player.id);
        return -1;
    }

    int find_player_playback_controls_section (Menu player_menu) {
        int n = player_menu.get_n_items ();
        for (int i = 0; i < n; i++) {
            string type;
            player_menu.get_item_attribute (i, "x-ayatana-type", "s", out type);
            if (type == PLAYBACK_ITEM_TYPE)
                return i;
        }

        return -1;
    }

    MenuItem create_playback_menu_item (MediaPlayer player) {
        var playback_item = new MenuItem (null, null);
        playback_item.set_attribute ("x-ayatana-type", "s", PLAYBACK_ITEM_TYPE);
        if (player.is_running) {
            if (player.can_do_play) {
                playback_item.set_attribute ("x-ayatana-play-action", "s", "indicator.play." + player.id);
            }
            if (player.can_do_next) {
                playback_item.set_attribute ("x-ayatana-next-action", "s", "indicator.next." + player.id);
            }
            if (player.can_do_prev) {
                playback_item.set_attribute ("x-ayatana-previous-action", "s", "indicator.previous." + player.id);
            }
        } else {
            if (this.add_play_button_inactive_player) {
                playback_item.set_attribute ("x-ayatana-play-action", "s", "indicator.play." + player.id);
            }
        }
        return playback_item;
    }

    void insert_player_section (MediaPlayer player) {
        if (this.hide_players)
            return;

        var section = new Menu ();
        Icon icon;

        debug("Adding section for player: %s (%s)", player.id, player.is_running ? "running" : "not running");

        icon = player.icon;
        if (icon == null)
            icon = new ThemedIcon.with_default_fallbacks ("application-default-icon");

        var base_action = "indicator." + player.id;
        if (this.greeter_players)
            base_action += ".greeter";

        var player_item = new MenuItem (player.name, base_action);
        player_item.set_attribute ("x-ayatana-type", "s", "org.ayatana.indicator.media-player");
        if (icon != null)
            player_item.set_attribute_value ("icon", icon.serialize ());
        section.append_item (player_item);

        if (player.is_running|| !this.hide_inactive_player_controls || player.id == this.default_player) {
            var playback_item = create_playback_menu_item (player);
            section.insert_item (PlayerSectionPosition.PLAYER_CONTROLS, playback_item);
        }

        /* Add new players to the end of the player sections, just before the settings */
        if (settings_shown) {
            this.menu.insert_section (this.menu.get_n_items () -1, null, section);
        } else {
            this.menu.append_section (null, section);
        }
    }

    void remove_player_section (MediaPlayer player) {
        if (this.hide_players)
            return;

        int index = this.find_player_section (player);
        if (index >= 0)
            this.menu.remove (index);
    }

    void add_player_playback_controls (MediaPlayer player, int index, bool adding_default_player) {
        var player_section = this.menu.get_item_link(index, Menu.LINK_SECTION) as Menu;

        int play_control_index = find_player_playback_controls_section (player_section);
        if (player.is_running || !this.hide_inactive_player_controls || (number_of_running_players == 0 && adding_default_player) ) {
            MenuItem playback_item = create_playback_menu_item (player);
            if (play_control_index != -1) {
                player_section.remove (PlayerSectionPosition.PLAYER_CONTROLS);
            }
            player_section.insert_item (PlayerSectionPosition.PLAYER_CONTROLS, playback_item);
        } else {
            if (play_control_index != -1 && number_of_running_players >= 1) {
                // remove both, playlist and play controls
                player_section.remove (PlayerSectionPosition.PLAYLIST);
                player_section.remove (PlayerSectionPosition.PLAYER_CONTROLS);
            }
        }
    }

    void update_player_section (MediaPlayer player, int index) {
        add_player_playback_controls (player, index, false);
    }

    void update_playlists (MediaPlayer player) {
        int index = find_player_section (player);
        if (index < 0)
            return;

        var player_section = this.menu.get_item_link (index, Menu.LINK_SECTION) as Menu;

        /* if a section has three items, the playlists menu is in it */
        if (player_section.get_n_items () == 3)
            player_section.remove (2);

        if (!player.is_running)
            return;

        var count = player.get_n_playlists ();
        if (count == 0)
            return;

        var playlists_section = new Menu ();
        for (int i = 0; i < count; i++) {
            var playlist_id = player.get_playlist_id (i);
            playlists_section.append (player.get_playlist_name (i),
                                      @"indicator.play-playlist.$(player.id)::$playlist_id");

        }

        var submenu = new Menu ();
        submenu.append_section (null, playlists_section);
        player_section.append_submenu (_("Choose Playlist"), submenu);
    }

    void update_playbackstatus (MediaPlayer player) {
        int index = find_player_section (player);
        if (index != -1) {
            update_player_section (player, index);
        }
    }

    MenuItem create_slider_menu_item (string label, string action, double min, double max, double step, string min_icon_name, string max_icon_name, bool sync_action) {
        var min_icon = new ThemedIcon.with_default_fallbacks (min_icon_name);
        var max_icon = new ThemedIcon.with_default_fallbacks (max_icon_name);

        var slider = new MenuItem (label, action);
        slider.set_attribute ("x-ayatana-type", "s", "org.ayatana.indicator.slider");
        slider.set_attribute_value ("min-icon", min_icon.serialize ());
        slider.set_attribute_value ("max-icon", max_icon.serialize ());
        slider.set_attribute ("min-value", "d", min);
        slider.set_attribute ("max-value", "d", max);
        slider.set_attribute ("step", "d", step);
        if (sync_action) {
            slider.set_attribute ("x-ayatana-sync-action", "s", "indicator.volume-sync");
        }

        return slider;
    }

    public signal void last_player_updated (string player_id);
}

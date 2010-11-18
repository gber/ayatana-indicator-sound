/* music-player-bridge.h generated by valac 0.10.0, the Vala compiler, do not modify */


#ifndef __MUSIC_PLAYER_BRIDGE_H__
#define __MUSIC_PLAYER_BRIDGE_H__

#include <glib.h>
#include <glib-object.h>
#include <libindicate/./indicator-messages.h>
#include <libindicate/./indicator.h>
#include <libindicate/./interests.h>
#include <libindicate/./listener.h>
#include <libindicate/./server.h>
#include <stdlib.h>
#include <string.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <gio/gio.h>
#include <gee.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS


#define TYPE_MUSIC_PLAYER_BRIDGE (music_player_bridge_get_type ())
#define MUSIC_PLAYER_BRIDGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridge))
#define MUSIC_PLAYER_BRIDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridgeClass))
#define IS_MUSIC_PLAYER_BRIDGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MUSIC_PLAYER_BRIDGE))
#define IS_MUSIC_PLAYER_BRIDGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MUSIC_PLAYER_BRIDGE))
#define MUSIC_PLAYER_BRIDGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MUSIC_PLAYER_BRIDGE, MusicPlayerBridgeClass))

typedef struct _MusicPlayerBridge MusicPlayerBridge;
typedef struct _MusicPlayerBridgeClass MusicPlayerBridgeClass;
typedef struct _MusicPlayerBridgePrivate MusicPlayerBridgePrivate;

#define TYPE_PLAYER_ITEM (player_item_get_type ())
#define PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_ITEM, PlayerItem))
#define PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_ITEM, PlayerItemClass))
#define IS_PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_ITEM))
#define IS_PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_ITEM))
#define PLAYER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_ITEM, PlayerItemClass))

typedef struct _PlayerItem PlayerItem;
typedef struct _PlayerItemClass PlayerItemClass;
typedef struct _PlayerItemPrivate PlayerItemPrivate;

#define TYPE_TRANSPORT_MENUITEM (transport_menuitem_get_type ())
#define TRANSPORT_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRANSPORT_MENUITEM, TransportMenuitem))
#define TRANSPORT_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRANSPORT_MENUITEM, TransportMenuitemClass))
#define IS_TRANSPORT_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRANSPORT_MENUITEM))
#define IS_TRANSPORT_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRANSPORT_MENUITEM))
#define TRANSPORT_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRANSPORT_MENUITEM, TransportMenuitemClass))

typedef struct _TransportMenuitem TransportMenuitem;
typedef struct _TransportMenuitemClass TransportMenuitemClass;
typedef struct _TransportMenuitemPrivate TransportMenuitemPrivate;

#define TRANSPORT_MENUITEM_TYPE_ACTION (transport_menuitem_action_get_type ())

#define TRANSPORT_MENUITEM_TYPE_STATE (transport_menuitem_state_get_type ())

#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;

#define TYPE_METADATA_MENUITEM (metadata_menuitem_get_type ())
#define METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitem))
#define METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))
#define IS_METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_METADATA_MENUITEM))
#define IS_METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_METADATA_MENUITEM))
#define METADATA_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))

typedef struct _MetadataMenuitem MetadataMenuitem;
typedef struct _MetadataMenuitemClass MetadataMenuitemClass;
typedef struct _MetadataMenuitemPrivate MetadataMenuitemPrivate;

#define TYPE_TITLE_MENUITEM (title_menuitem_get_type ())
#define TITLE_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TITLE_MENUITEM, TitleMenuitem))
#define TITLE_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TITLE_MENUITEM, TitleMenuitemClass))
#define IS_TITLE_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TITLE_MENUITEM))
#define IS_TITLE_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TITLE_MENUITEM))
#define TITLE_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TITLE_MENUITEM, TitleMenuitemClass))

typedef struct _TitleMenuitem TitleMenuitem;
typedef struct _TitleMenuitemClass TitleMenuitemClass;
typedef struct _TitleMenuitemPrivate TitleMenuitemPrivate;
typedef struct _PlayerControllerPrivate PlayerControllerPrivate;

#define TYPE_MPRIS2_CONTROLLER (mpris2_controller_get_type ())
#define MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2Controller))
#define MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))
#define IS_MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MPRIS2_CONTROLLER))
#define IS_MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MPRIS2_CONTROLLER))
#define MPRIS2_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))

typedef struct _Mpris2Controller Mpris2Controller;
typedef struct _Mpris2ControllerClass Mpris2ControllerClass;

#define PLAYER_CONTROLLER_TYPE_WIDGET_ORDER (player_controller_widget_order_get_type ())

#define PLAYER_CONTROLLER_TYPE_STATE (player_controller_state_get_type ())

#define TYPE_MPRIS_ROOT (mpris_root_get_type ())
#define MPRIS_ROOT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MPRIS_ROOT, MprisRoot))
#define IS_MPRIS_ROOT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MPRIS_ROOT))
#define MPRIS_ROOT_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_MPRIS_ROOT, MprisRootIface))

typedef struct _MprisRoot MprisRoot;
typedef struct _MprisRootIface MprisRootIface;

#define TYPE_MPRIS_PLAYER (mpris_player_get_type ())
#define MPRIS_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MPRIS_PLAYER, MprisPlayer))
#define IS_MPRIS_PLAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MPRIS_PLAYER))
#define MPRIS_PLAYER_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_MPRIS_PLAYER, MprisPlayerIface))

typedef struct _MprisPlayer MprisPlayer;
typedef struct _MprisPlayerIface MprisPlayerIface;

#define TYPE_FREE_DESKTOP_PROPERTIES (free_desktop_properties_get_type ())
#define FREE_DESKTOP_PROPERTIES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FREE_DESKTOP_PROPERTIES, FreeDesktopProperties))
#define IS_FREE_DESKTOP_PROPERTIES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FREE_DESKTOP_PROPERTIES))
#define FREE_DESKTOP_PROPERTIES_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TYPE_FREE_DESKTOP_PROPERTIES, FreeDesktopPropertiesIface))

typedef struct _FreeDesktopProperties FreeDesktopProperties;
typedef struct _FreeDesktopPropertiesIface FreeDesktopPropertiesIface;
typedef struct _Mpris2ControllerPrivate Mpris2ControllerPrivate;

#define TYPE_FAMILIAR_PLAYERS_DB (familiar_players_db_get_type ())
#define FAMILIAR_PLAYERS_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDB))
#define FAMILIAR_PLAYERS_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBClass))
#define IS_FAMILIAR_PLAYERS_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FAMILIAR_PLAYERS_DB))
#define IS_FAMILIAR_PLAYERS_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FAMILIAR_PLAYERS_DB))
#define FAMILIAR_PLAYERS_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBClass))

typedef struct _FamiliarPlayersDB FamiliarPlayersDB;
typedef struct _FamiliarPlayersDBClass FamiliarPlayersDBClass;
typedef struct _FamiliarPlayersDBPrivate FamiliarPlayersDBPrivate;

#define TYPE_FETCH_FILE (fetch_file_get_type ())
#define FETCH_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FETCH_FILE, FetchFile))
#define FETCH_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FETCH_FILE, FetchFileClass))
#define IS_FETCH_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FETCH_FILE))
#define IS_FETCH_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FETCH_FILE))
#define FETCH_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FETCH_FILE, FetchFileClass))

typedef struct _FetchFile FetchFile;
typedef struct _FetchFileClass FetchFileClass;
typedef struct _FetchFilePrivate FetchFilePrivate;

struct _MusicPlayerBridge {
	GObject parent_instance;
	MusicPlayerBridgePrivate * priv;
};

struct _MusicPlayerBridgeClass {
	GObjectClass parent_class;
};

struct _PlayerItem {
	DbusmenuMenuitem parent_instance;
	PlayerItemPrivate * priv;
};

struct _PlayerItemClass {
	DbusmenuMenuitemClass parent_class;
};

struct _TransportMenuitem {
	PlayerItem parent_instance;
	TransportMenuitemPrivate * priv;
};

struct _TransportMenuitemClass {
	PlayerItemClass parent_class;
};

typedef enum  {
	TRANSPORT_MENUITEM_ACTION_PREVIOUS,
	TRANSPORT_MENUITEM_ACTION_PLAY_PAUSE,
	TRANSPORT_MENUITEM_ACTION_NEXT
} TransportMenuitemaction;

typedef enum  {
	TRANSPORT_MENUITEM_STATE_PLAYING,
	TRANSPORT_MENUITEM_STATE_PAUSED
} TransportMenuitemstate;

struct _MetadataMenuitem {
	PlayerItem parent_instance;
	MetadataMenuitemPrivate * priv;
};

struct _MetadataMenuitemClass {
	PlayerItemClass parent_class;
};

struct _TitleMenuitem {
	PlayerItem parent_instance;
	TitleMenuitemPrivate * priv;
};

struct _TitleMenuitemClass {
	PlayerItemClass parent_class;
};

struct _PlayerController {
	GObject parent_instance;
	PlayerControllerPrivate * priv;
	gint current_state;
	GeeArrayList* custom_items;
	Mpris2Controller* mpris_bridge;
};

struct _PlayerControllerClass {
	GObjectClass parent_class;
};

typedef enum  {
	PLAYER_CONTROLLER_WIDGET_ORDER_SEPARATOR,
	PLAYER_CONTROLLER_WIDGET_ORDER_TITLE,
	PLAYER_CONTROLLER_WIDGET_ORDER_METADATA,
	PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT
} PlayerControllerwidget_order;

typedef enum  {
	PLAYER_CONTROLLER_STATE_OFFLINE,
	PLAYER_CONTROLLER_STATE_INSTANTIATING,
	PLAYER_CONTROLLER_STATE_READY,
	PLAYER_CONTROLLER_STATE_CONNECTED,
	PLAYER_CONTROLLER_STATE_DISCONNECTED
} PlayerControllerstate;

struct _MprisRootIface {
	GTypeInterface parent_iface;
	void (*Quit) (MprisRoot* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*Quit_finish) (MprisRoot* self, GAsyncResult* _res_, GError** error);
	void (*Raise) (MprisRoot* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*Raise_finish) (MprisRoot* self, GAsyncResult* _res_, GError** error);
	gboolean (*get_HasTracklist) (MprisRoot* self);
	void (*set_HasTracklist) (MprisRoot* self, gboolean value);
	gboolean (*get_CanQuit) (MprisRoot* self);
	void (*set_CanQuit) (MprisRoot* self, gboolean value);
	gboolean (*get_CanRaise) (MprisRoot* self);
	void (*set_CanRaise) (MprisRoot* self, gboolean value);
	char* (*get_Identity) (MprisRoot* self);
	void (*set_Identity) (MprisRoot* self, const char* value);
	char* (*get_DesktopEntry) (MprisRoot* self);
	void (*set_DesktopEntry) (MprisRoot* self, const char* value);
};

struct _MprisPlayerIface {
	GTypeInterface parent_iface;
	void (*PlayPause) (MprisPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*PlayPause_finish) (MprisPlayer* self, GAsyncResult* _res_, GError** error);
	void (*Next) (MprisPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*Next_finish) (MprisPlayer* self, GAsyncResult* _res_, GError** error);
	void (*Previous) (MprisPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*Previous_finish) (MprisPlayer* self, GAsyncResult* _res_, GError** error);
	GHashTable* (*get_Metadata) (MprisPlayer* self);
	void (*set_Metadata) (MprisPlayer* self, GHashTable* value);
	gint32 (*get_Position) (MprisPlayer* self);
	void (*set_Position) (MprisPlayer* self, gint32 value);
	char* (*get_PlaybackStatus) (MprisPlayer* self);
	void (*set_PlaybackStatus) (MprisPlayer* self, const char* value);
};

struct _FreeDesktopPropertiesIface {
	GTypeInterface parent_iface;
};

struct _Mpris2Controller {
	GObject parent_instance;
	Mpris2ControllerPrivate * priv;
};

struct _Mpris2ControllerClass {
	GObjectClass parent_class;
};

struct _FamiliarPlayersDB {
	GObject parent_instance;
	FamiliarPlayersDBPrivate * priv;
};

struct _FamiliarPlayersDBClass {
	GObjectClass parent_class;
};

struct _FetchFile {
	GObject parent_instance;
	FetchFilePrivate * priv;
};

struct _FetchFileClass {
	GObjectClass parent_class;
};


GType music_player_bridge_get_type (void) G_GNUC_CONST;
MusicPlayerBridge* music_player_bridge_new (void);
MusicPlayerBridge* music_player_bridge_construct (GType object_type);
void music_player_bridge_on_server_added (MusicPlayerBridge* self, IndicateListenerServer* object, const char* type);
void music_player_bridge_on_server_removed (MusicPlayerBridge* self, IndicateListenerServer* object, const char* type);
void music_player_bridge_set_root_menu_item (MusicPlayerBridge* self, DbusmenuMenuitem* menu);
GAppInfo* music_player_bridge_create_app_info (const char* path);
GType player_item_get_type (void) G_GNUC_CONST;
GType transport_menuitem_get_type (void) G_GNUC_CONST;
GType transport_menuitem_action_get_type (void) G_GNUC_CONST;
GType transport_menuitem_state_get_type (void) G_GNUC_CONST;
GType player_controller_get_type (void) G_GNUC_CONST;
TransportMenuitem* transport_menuitem_new (PlayerController* parent);
TransportMenuitem* transport_menuitem_construct (GType object_type, PlayerController* parent);
void transport_menuitem_change_play_state (TransportMenuitem* self, TransportMenuitemstate update);
GeeHashSet* transport_menuitem_attributes_format (void);
GType metadata_menuitem_get_type (void) G_GNUC_CONST;
extern char* metadata_menuitem_album_art_cache_dir;
#define METADATA_MENUITEM_ALBUM_ART_DIR_SUFFIX "indicators/sound/album-art-cache"
MetadataMenuitem* metadata_menuitem_new (void);
MetadataMenuitem* metadata_menuitem_construct (GType object_type);
void metadata_menuitem_fetch_art (MetadataMenuitem* self, const char* uri, const char* prop);
GeeHashSet* metadata_menuitem_attributes_format (void);
GType title_menuitem_get_type (void) G_GNUC_CONST;
TitleMenuitem* title_menuitem_new (PlayerController* parent);
TitleMenuitem* title_menuitem_construct (GType object_type, PlayerController* parent);
void title_menuitem_toggle_active_triangle (TitleMenuitem* self, gboolean update);
GeeHashSet* title_menuitem_attributes_format (void);
GType mpris2_controller_get_type (void) G_GNUC_CONST;
GType player_controller_widget_order_get_type (void) G_GNUC_CONST;
GType player_controller_state_get_type (void) G_GNUC_CONST;
#define PLAYER_CONTROLLER_WIDGET_QUANTITY 4
PlayerController* player_controller_new (DbusmenuMenuitem* root, GAppInfo* app, const char* mpris_name, const char* icon_name, gint offset, PlayerControllerstate initial_state);
PlayerController* player_controller_construct (GType object_type, DbusmenuMenuitem* root, GAppInfo* app, const char* mpris_name, const char* icon_name, gint offset, PlayerControllerstate initial_state);
void player_controller_update_state (PlayerController* self, PlayerControllerstate new_state);
void player_controller_activate (PlayerController* self);
void player_controller_instantiate (PlayerController* self);
void player_controller_vanish (PlayerController* self);
void player_controller_hibernate (PlayerController* self);
void player_controller_update_layout (PlayerController* self);
void player_controller_determine_state (PlayerController* self);
const char* player_controller_get_name (PlayerController* self);
void player_controller_set_name (PlayerController* self, const char* value);
const char* player_controller_get_mpris_name (PlayerController* self);
void player_controller_set_mpris_name (PlayerController* self, const char* value);
GAppInfo* player_controller_get_app_info (PlayerController* self);
void player_controller_set_app_info (PlayerController* self, GAppInfo* value);
gint player_controller_get_menu_offset (PlayerController* self);
void player_controller_set_menu_offset (PlayerController* self, gint value);
const char* player_controller_get_icon_name (PlayerController* self);
void player_controller_set_icon_name (PlayerController* self, const char* value);
MprisRoot* mpris_root_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path);
GType mpris_root_get_type (void) G_GNUC_CONST;
void mpris_root_Quit (MprisRoot* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void mpris_root_Quit_finish (MprisRoot* self, GAsyncResult* _res_, GError** error);
void mpris_root_Raise (MprisRoot* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void mpris_root_Raise_finish (MprisRoot* self, GAsyncResult* _res_, GError** error);
gboolean mpris_root_get_HasTracklist (MprisRoot* self);
void mpris_root_set_HasTracklist (MprisRoot* self, gboolean value);
gboolean mpris_root_get_CanQuit (MprisRoot* self);
void mpris_root_set_CanQuit (MprisRoot* self, gboolean value);
gboolean mpris_root_get_CanRaise (MprisRoot* self);
void mpris_root_set_CanRaise (MprisRoot* self, gboolean value);
char* mpris_root_get_Identity (MprisRoot* self);
void mpris_root_set_Identity (MprisRoot* self, const char* value);
char* mpris_root_get_DesktopEntry (MprisRoot* self);
void mpris_root_set_DesktopEntry (MprisRoot* self, const char* value);
MprisPlayer* mpris_player_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path);
GType mpris_player_get_type (void) G_GNUC_CONST;
void mpris_player_PlayPause (MprisPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void mpris_player_PlayPause_finish (MprisPlayer* self, GAsyncResult* _res_, GError** error);
void mpris_player_Next (MprisPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void mpris_player_Next_finish (MprisPlayer* self, GAsyncResult* _res_, GError** error);
void mpris_player_Previous (MprisPlayer* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void mpris_player_Previous_finish (MprisPlayer* self, GAsyncResult* _res_, GError** error);
GHashTable* mpris_player_get_Metadata (MprisPlayer* self);
void mpris_player_set_Metadata (MprisPlayer* self, GHashTable* value);
gint32 mpris_player_get_Position (MprisPlayer* self);
void mpris_player_set_Position (MprisPlayer* self, gint32 value);
char* mpris_player_get_PlaybackStatus (MprisPlayer* self);
void mpris_player_set_PlaybackStatus (MprisPlayer* self, const char* value);
GType free_desktop_properties_get_type (void) G_GNUC_CONST;
FreeDesktopProperties* free_desktop_properties_dbus_proxy_new (DBusGConnection* connection, const char* name, const char* path);
#define MPRIS2_CONTROLLER_root_interface "org.mpris.MediaPlayer2"
Mpris2Controller* mpris2_controller_new (PlayerController* ctrl);
Mpris2Controller* mpris2_controller_construct (GType object_type, PlayerController* ctrl);
void mpris2_controller_property_changed_cb (Mpris2Controller* self, const char* interface_source, GHashTable* changed_properties, char** invalid, int invalid_length1);
void mpris2_controller_initial_update (Mpris2Controller* self);
void mpris2_controller_transport_update (Mpris2Controller* self, TransportMenuitemaction command);
gboolean mpris2_controller_connected (Mpris2Controller* self);
gboolean mpris2_controller_was_successfull (Mpris2Controller* self);
void mpris2_controller_expose (Mpris2Controller* self);
MprisRoot* mpris2_controller_get_mpris2_root (Mpris2Controller* self);
MprisPlayer* mpris2_controller_get_player (Mpris2Controller* self);
PlayerController* mpris2_controller_get_owner (Mpris2Controller* self);
FreeDesktopProperties* mpris2_controller_get_properties_interface (Mpris2Controller* self);
PlayerItem* player_item_new (const char* type);
PlayerItem* player_item_construct (GType object_type, const char* type);
void player_item_reset (PlayerItem* self, GeeHashSet* attrs);
void player_item_update (PlayerItem* self, GHashTable* data, GeeHashSet* attributes);
gboolean player_item_populated (PlayerItem* self, GeeHashSet* attrs);
PlayerController* player_item_get_owner (PlayerItem* self);
const char* player_item_get_item_type (PlayerItem* self);
GType familiar_players_db_get_type (void) G_GNUC_CONST;
FamiliarPlayersDB* familiar_players_db_new (void);
FamiliarPlayersDB* familiar_players_db_construct (GType object_type);
void familiar_players_db_insert (FamiliarPlayersDB* self, const char* desktop);
gboolean familiar_players_db_already_familiar (FamiliarPlayersDB* self, const char* desktop);
GeeSet* familiar_players_db_records (FamiliarPlayersDB* self);
char* familiar_players_db_fetch_icon_name (const char* desktop_path);
GType fetch_file_get_type (void) G_GNUC_CONST;
FetchFile* fetch_file_new (const char* uri, const char* prop);
FetchFile* fetch_file_construct (GType object_type, const char* uri, const char* prop);
void fetch_file_fetch_data (FetchFile* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
void fetch_file_fetch_data_finish (FetchFile* self, GAsyncResult* _res_);
const char* fetch_file_get_uri (FetchFile* self);
const char* fetch_file_get_intended_property (FetchFile* self);


G_END_DECLS

#endif

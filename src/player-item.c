/* player-item.c generated by valac 0.12.0, the Vala compiler
 * generated from player-item.vala, do not modify */

/*
Copyright 2010 Canonical Ltd.

Authors:
    Conor Curran <conor.curran@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <glib.h>
#include <glib-object.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/dbusmenu-glib.h>
#include <libdbusmenu-glib/enum-types.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <libdbusmenu-glib/types.h>
#include <stdlib.h>
#include <string.h>
#include <gee.h>


#define TYPE_PLAYER_ITEM (player_item_get_type ())
#define PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_ITEM, PlayerItem))
#define PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_ITEM, PlayerItemClass))
#define IS_PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_ITEM))
#define IS_PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_ITEM))
#define PLAYER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_ITEM, PlayerItemClass))

typedef struct _PlayerItem PlayerItem;
typedef struct _PlayerItemClass PlayerItemClass;
typedef struct _PlayerItemPrivate PlayerItemPrivate;

#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_METADATA_MENUITEM (metadata_menuitem_get_type ())
#define METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitem))
#define METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))
#define IS_METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_METADATA_MENUITEM))
#define IS_METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_METADATA_MENUITEM))
#define METADATA_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))

typedef struct _MetadataMenuitem MetadataMenuitem;
typedef struct _MetadataMenuitemClass MetadataMenuitemClass;
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))

struct _PlayerItem {
	DbusmenuMenuitem parent_instance;
	PlayerItemPrivate * priv;
};

struct _PlayerItemClass {
	DbusmenuMenuitemClass parent_class;
};

struct _PlayerItemPrivate {
	PlayerController* _owner;
	gchar* _item_type;
};


static gpointer player_item_parent_class = NULL;

GType player_item_get_type (void) G_GNUC_CONST;
GType player_controller_get_type (void) G_GNUC_CONST;
#define PLAYER_ITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PLAYER_ITEM, PlayerItemPrivate))
enum  {
	PLAYER_ITEM_DUMMY_PROPERTY,
	PLAYER_ITEM_OWNER,
	PLAYER_ITEM_ITEM_TYPE
};
#define PLAYER_ITEM_EMPTY (-1)
PlayerItem* player_item_new (const gchar* type);
PlayerItem* player_item_construct (GType object_type, const gchar* type);
void player_item_reset (PlayerItem* self, GeeHashSet* attrs);
void player_item_update (PlayerItem* self, GHashTable* data, GeeHashSet* attributes);
GType metadata_menuitem_get_type (void) G_GNUC_CONST;
void metadata_menuitem_fetch_art (MetadataMenuitem* self, const gchar* uri, const gchar* prop);
gboolean player_item_populated (PlayerItem* self, GeeHashSet* attrs);
PlayerController* player_item_get_owner (PlayerItem* self);
static void player_item_set_owner (PlayerItem* self, PlayerController* value);
const gchar* player_item_get_item_type (PlayerItem* self);
static void player_item_set_item_type (PlayerItem* self, const gchar* value);
static GObject * player_item_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void player_item_finalize (GObject* obj);
static void _vala_player_item_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_player_item_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


PlayerItem* player_item_construct (GType object_type, const gchar* type) {
	PlayerItem * self = NULL;
	g_return_val_if_fail (type != NULL, NULL);
	self = (PlayerItem*) g_object_new (object_type, "item-type", type, NULL);
	return self;
}


PlayerItem* player_item_new (const gchar* type) {
	return player_item_construct (TYPE_PLAYER_ITEM, type);
}


void player_item_reset (PlayerItem* self, GeeHashSet* attrs) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (attrs != NULL);
	{
		GeeIterator* _tmp0_ = NULL;
		GeeIterator* _s_it;
		_tmp0_ = gee_abstract_collection_iterator ((GeeAbstractCollection*) attrs);
		_s_it = _tmp0_;
		while (TRUE) {
			gboolean _tmp1_;
			gpointer _tmp2_ = NULL;
			gchar* s;
			_tmp1_ = gee_iterator_next (_s_it);
			if (!_tmp1_) {
				break;
			}
			_tmp2_ = gee_iterator_get (_s_it);
			s = (gchar*) _tmp2_;
			dbusmenu_menuitem_property_set_int ((DbusmenuMenuitem*) self, s, PLAYER_ITEM_EMPTY);
			_g_free0 (s);
		}
		_g_object_unref0 (_s_it);
	}
}


/**
   * update()
   * Base update method for playeritems, takes the attributes and the incoming updates
   * and attmepts to update the appropriate props on the object. 
   * Album art is handled separately to deal with remote and local file paths.
   */
static gpointer _g_variant_ref0 (gpointer self) {
	return self ? g_variant_ref (self) : NULL;
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _result_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	g_strstrip (_result_);
	result = _result_;
	return result;
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	gchar* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = strstr ((gchar*) self, (gchar*) needle);
	result = _tmp0_ != NULL;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void player_item_update (PlayerItem* self, GHashTable* data, GeeHashSet* attributes) {
	gboolean _tmp20_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (data != NULL);
	g_return_if_fail (attributes != NULL);
	if (data == NULL) {
		g_warning ("player-item.vala:55: PlayerItem::Update -> The hashtable was null - ju" \
"st leave it!");
		return;
	}
	{
		GeeIterator* _tmp0_ = NULL;
		GeeIterator* _property_it;
		_tmp0_ = gee_abstract_collection_iterator ((GeeAbstractCollection*) attributes);
		_property_it = _tmp0_;
		while (TRUE) {
			gboolean _tmp1_;
			gpointer _tmp2_ = NULL;
			gchar* property;
			gchar** _tmp3_;
			gchar** _tmp4_ = NULL;
			gchar** input_keys;
			gint input_keys_length1;
			gint _input_keys_size_;
			gchar* _tmp5_;
			gchar* search_key;
			gconstpointer _tmp6_ = NULL;
			GVariant* _tmp7_;
			GVariant* v;
			gboolean _tmp8_;
			_tmp1_ = gee_iterator_next (_property_it);
			if (!_tmp1_) {
				break;
			}
			_tmp2_ = gee_iterator_get (_property_it);
			property = (gchar*) _tmp2_;
			_tmp4_ = _tmp3_ = g_strsplit (property, "-", 0);
			input_keys = _tmp4_;
			input_keys_length1 = _vala_array_length (_tmp3_);
			_input_keys_size_ = _vala_array_length (_tmp3_);
			_tmp5_ = g_strdup ((input_keys + (input_keys_length1 - 1))[0]);
			search_key = _tmp5_;
			_tmp6_ = g_hash_table_lookup (data, search_key);
			_tmp7_ = _g_variant_ref0 ((GVariant*) _tmp6_);
			v = _tmp7_;
			_tmp8_ = g_variant_is_of_type (v, G_VARIANT_TYPE_STRING);
			if (_tmp8_) {
				const gchar* _tmp9_ = NULL;
				gchar* _tmp10_ = NULL;
				gchar* update;
				gboolean _tmp11_;
				_tmp9_ = g_variant_get_string (v, NULL);
				_tmp10_ = string_strip (_tmp9_);
				update = _tmp10_;
				_tmp11_ = string_contains (property, "mpris:artUrl");
				if (_tmp11_) {
					PlayerItem* _tmp12_;
					MetadataMenuitem* _tmp13_;
					MetadataMenuitem* metadata;
					_tmp12_ = self;
					_tmp13_ = _g_object_ref0 (IS_METADATA_MENUITEM (_tmp12_) ? ((MetadataMenuitem*) _tmp12_) : NULL);
					metadata = _tmp13_;
					metadata_menuitem_fetch_art (metadata, update, property);
					_g_object_unref0 (metadata);
					_g_free0 (update);
					_g_variant_unref0 (v);
					_g_free0 (search_key);
					input_keys = (_vala_array_free (input_keys, input_keys_length1, (GDestroyNotify) g_free), NULL);
					_g_free0 (property);
					continue;
				}
				dbusmenu_menuitem_property_set ((DbusmenuMenuitem*) self, property, update);
				_g_free0 (update);
			} else {
				gboolean _tmp14_;
				_tmp14_ = g_variant_is_of_type (v, G_VARIANT_TYPE_INT32);
				if (_tmp14_) {
					gint32 _tmp15_;
					_tmp15_ = g_variant_get_int32 (v);
					dbusmenu_menuitem_property_set_int ((DbusmenuMenuitem*) self, property, (gint) _tmp15_);
				} else {
					gboolean _tmp16_;
					_tmp16_ = g_variant_is_of_type (v, G_VARIANT_TYPE_INT64);
					if (_tmp16_) {
						gint64 _tmp17_;
						_tmp17_ = g_variant_get_int64 (v);
						dbusmenu_menuitem_property_set_int ((DbusmenuMenuitem*) self, property, (gint) _tmp17_);
					} else {
						gboolean _tmp18_;
						_tmp18_ = g_variant_is_of_type (v, G_VARIANT_TYPE_BOOLEAN);
						if (_tmp18_) {
							gboolean _tmp19_;
							_tmp19_ = g_variant_get_boolean (v);
							dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) self, property, _tmp19_);
						}
					}
				}
			}
			_g_variant_unref0 (v);
			_g_free0 (search_key);
			input_keys = (_vala_array_free (input_keys, input_keys_length1, (GDestroyNotify) g_free), NULL);
			_g_free0 (property);
		}
		_g_object_unref0 (_property_it);
	}
	_tmp20_ = player_item_populated (self, attributes);
	dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) self, DBUSMENU_MENUITEM_PROP_VISIBLE, _tmp20_);
}


gboolean player_item_populated (PlayerItem* self, GeeHashSet* attrs) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (attrs != NULL, FALSE);
	{
		GeeIterator* _tmp0_ = NULL;
		GeeIterator* _prop_it;
		_tmp0_ = gee_abstract_collection_iterator ((GeeAbstractCollection*) attrs);
		_prop_it = _tmp0_;
		while (TRUE) {
			gboolean _tmp1_;
			gpointer _tmp2_ = NULL;
			gchar* prop;
			gint _tmp3_;
			_tmp1_ = gee_iterator_next (_prop_it);
			if (!_tmp1_) {
				break;
			}
			_tmp2_ = gee_iterator_get (_prop_it);
			prop = (gchar*) _tmp2_;
			_tmp3_ = dbusmenu_menuitem_property_get_int ((DbusmenuMenuitem*) self, prop);
			if (_tmp3_ != PLAYER_ITEM_EMPTY) {
				result = TRUE;
				_g_free0 (prop);
				_g_object_unref0 (_prop_it);
				return result;
			}
			_g_free0 (prop);
		}
		_g_object_unref0 (_prop_it);
	}
	result = FALSE;
	return result;
}


PlayerController* player_item_get_owner (PlayerItem* self) {
	PlayerController* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_owner;
	return result;
}


static void player_item_set_owner (PlayerItem* self, PlayerController* value) {
	PlayerController* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _g_object_ref0 (value);
	_g_object_unref0 (self->priv->_owner);
	self->priv->_owner = _tmp0_;
	g_object_notify ((GObject *) self, "owner");
}


const gchar* player_item_get_item_type (PlayerItem* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_item_type;
	return result;
}


static void player_item_set_item_type (PlayerItem* self, const gchar* value) {
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_item_type);
	self->priv->_item_type = _tmp0_;
	g_object_notify ((GObject *) self, "item-type");
}


static GObject * player_item_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PlayerItem * self;
	parent_class = G_OBJECT_CLASS (player_item_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = PLAYER_ITEM (obj);
	dbusmenu_menuitem_property_set ((DbusmenuMenuitem*) self, DBUSMENU_MENUITEM_PROP_TYPE, self->priv->_item_type);
	return obj;
}


static void player_item_class_init (PlayerItemClass * klass) {
	player_item_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PlayerItemPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_player_item_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_player_item_set_property;
	G_OBJECT_CLASS (klass)->constructor = player_item_constructor;
	G_OBJECT_CLASS (klass)->finalize = player_item_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_ITEM_OWNER, g_param_spec_object ("owner", "owner", "owner", TYPE_PLAYER_CONTROLLER, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_ITEM_ITEM_TYPE, g_param_spec_string ("item-type", "item-type", "item-type", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void player_item_instance_init (PlayerItem * self) {
	self->priv = PLAYER_ITEM_GET_PRIVATE (self);
}


static void player_item_finalize (GObject* obj) {
	PlayerItem * self;
	self = PLAYER_ITEM (obj);
	_g_object_unref0 (self->priv->_owner);
	_g_free0 (self->priv->_item_type);
	G_OBJECT_CLASS (player_item_parent_class)->finalize (obj);
}


GType player_item_get_type (void) {
	static volatile gsize player_item_type_id__volatile = 0;
	if (g_once_init_enter (&player_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PlayerItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) player_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PlayerItem), 0, (GInstanceInitFunc) player_item_instance_init, NULL };
		GType player_item_type_id;
		player_item_type_id = g_type_register_static (DBUSMENU_TYPE_MENUITEM, "PlayerItem", &g_define_type_info, 0);
		g_once_init_leave (&player_item_type_id__volatile, player_item_type_id);
	}
	return player_item_type_id__volatile;
}


static void _vala_player_item_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PlayerItem * self;
	self = PLAYER_ITEM (object);
	switch (property_id) {
		case PLAYER_ITEM_OWNER:
		g_value_set_object (value, player_item_get_owner (self));
		break;
		case PLAYER_ITEM_ITEM_TYPE:
		g_value_set_string (value, player_item_get_item_type (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_player_item_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PlayerItem * self;
	self = PLAYER_ITEM (object);
	switch (property_id) {
		case PLAYER_ITEM_OWNER:
		player_item_set_owner (self, g_value_get_object (value));
		break;
		case PLAYER_ITEM_ITEM_TYPE:
		player_item_set_item_type (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




/* familiar-players-db.c generated by valac 0.9.5, the Vala compiler
 * generated from familiar-players-db.vala, do not modify */

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
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>


#define TYPE_FAMILIAR_PLAYERS_DB (familiar_players_db_get_type ())
#define FAMILIAR_PLAYERS_DB(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDB))
#define FAMILIAR_PLAYERS_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBClass))
#define IS_FAMILIAR_PLAYERS_DB(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FAMILIAR_PLAYERS_DB))
#define IS_FAMILIAR_PLAYERS_DB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FAMILIAR_PLAYERS_DB))
#define FAMILIAR_PLAYERS_DB_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBClass))

typedef struct _FamiliarPlayersDB FamiliarPlayersDB;
typedef struct _FamiliarPlayersDBClass FamiliarPlayersDBClass;
typedef struct _FamiliarPlayersDBPrivate FamiliarPlayersDBPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _FamiliarPlayersDB {
	GObject parent_instance;
	FamiliarPlayersDBPrivate * priv;
};

struct _FamiliarPlayersDBClass {
	GObjectClass parent_class;
};

struct _FamiliarPlayersDBPrivate {
	GeeHashMap* players_DB;
	char* file_name;
	char* dir_name;
	GKeyFile* key_file;
	guint write_id;
};


static gpointer familiar_players_db_parent_class = NULL;

GType familiar_players_db_get_type (void) G_GNUC_CONST;
#define FAMILIAR_PLAYERS_DB_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_FAMILIAR_PLAYERS_DB, FamiliarPlayersDBPrivate))
enum  {
	FAMILIAR_PLAYERS_DB_DUMMY_PROPERTY
};
#define FAMILIAR_PLAYERS_DB_GROUP_NAME "Seen Database"
#define FAMILIAR_PLAYERS_DB_KEY_NAME "DesktopFiles"
static gboolean familiar_players_db_create_key_file (FamiliarPlayersDB* self);
static gboolean familiar_players_db_check_for_keys (FamiliarPlayersDB* self);
static gboolean familiar_players_db_load_data_from_key_file (FamiliarPlayersDB* self);
FamiliarPlayersDB* familiar_players_db_new (void);
FamiliarPlayersDB* familiar_players_db_construct (GType object_type);
static void _vala_array_add1 (char*** array, int* length, int* size, char* value);
static gboolean familiar_players_db_write_db (FamiliarPlayersDB* self);
gboolean familiar_players_db_already_familiar (FamiliarPlayersDB* self, const char* desktop);
static gboolean _familiar_players_db_write_db_gsource_func (gpointer self);
void familiar_players_db_insert (FamiliarPlayersDB* self, const char* desktop);
GeeSet* familiar_players_db_records (FamiliarPlayersDB* self);
static void familiar_players_db_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);



FamiliarPlayersDB* familiar_players_db_construct (GType object_type) {
	FamiliarPlayersDB * self;
	GeeHashMap* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	gboolean _tmp3_ = FALSE;
	gboolean _tmp4_ = FALSE;
	self = (FamiliarPlayersDB*) g_object_new (object_type, NULL);
	self->priv->write_id = (guint) 0;
	self->priv->players_DB = (_tmp0_ = gee_hash_map_new (G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, G_TYPE_BOOLEAN, NULL, NULL, NULL, NULL, NULL), _g_object_unref0 (self->priv->players_DB), _tmp0_);
	self->priv->dir_name = (_tmp1_ = g_build_filename (g_get_user_cache_dir (), "indicators", "sound", NULL), _g_free0 (self->priv->dir_name), _tmp1_);
	self->priv->file_name = (_tmp2_ = g_build_filename (self->priv->dir_name, "familiar-players-db.keyfile", NULL), _g_free0 (self->priv->file_name), _tmp2_);
	if (familiar_players_db_create_key_file (self)) {
		_tmp4_ = familiar_players_db_check_for_keys (self);
	} else {
		_tmp4_ = FALSE;
	}
	if (_tmp4_) {
		_tmp3_ = familiar_players_db_load_data_from_key_file (self);
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		g_debug ("familiar-players-db.vala:45: keyfiles in place and ready for action");
	} else {
		GKeyFile* _tmp5_;
		self->priv->key_file = (_tmp5_ = NULL, _g_key_file_free0 (self->priv->key_file), _tmp5_);
		g_warning ("familiar-players-db.vala:49: FamiliarPlayersDB:: problems loading key " \
"file - can't go any further");
	}
	return self;
}


FamiliarPlayersDB* familiar_players_db_new (void) {
	return familiar_players_db_construct (TYPE_FAMILIAR_PLAYERS_DB);
}


static gboolean familiar_players_db_create_key_file (FamiliarPlayersDB* self) {
	gboolean result = FALSE;
	GError * _inner_error_;
	gboolean _result_;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	_result_ = FALSE;
	if (g_file_test (self->priv->file_name, G_FILE_TEST_EXISTS)) {
		GKeyFile* _tmp0_;
		self->priv->key_file = (_tmp0_ = g_key_file_new (), _g_key_file_free0 (self->priv->key_file), _tmp0_);
		{
			gboolean _tmp1_;
			_tmp1_ = g_key_file_load_from_file (self->priv->key_file, self->priv->file_name, G_KEY_FILE_NONE, &_inner_error_);
			if (_inner_error_ != NULL) {
				if (_inner_error_->domain == G_KEY_FILE_ERROR) {
					goto __catch9_g_key_file_error;
				}
				if (_inner_error_->domain == G_FILE_ERROR) {
					goto __catch9_g_file_error;
				}
				g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
				g_clear_error (&_inner_error_);
				return FALSE;
			}
			_result_ = _tmp1_;
		}
		goto __finally9;
		__catch9_g_key_file_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("familiar-players-db.vala:61: FamiliarPlayersDB::create_key_file() - Ke" \
"yFileError");
				_g_error_free0 (e);
			}
		}
		goto __finally9;
		__catch9_g_file_error:
		{
			GError * e;
			e = _inner_error_;
			_inner_error_ = NULL;
			{
				g_warning ("familiar-players-db.vala:64: FamiliarPlayersDB::create_key_file() - Fi" \
"leError");
				_g_error_free0 (e);
			}
		}
		__finally9:
		if (_inner_error_ != NULL) {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return FALSE;
		}
	}
	result = _result_;
	return result;
}


static gboolean familiar_players_db_check_for_keys (FamiliarPlayersDB* self) {
	gboolean result = FALSE;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	{
		gboolean _tmp0_;
		_tmp0_ = g_key_file_has_key (self->priv->key_file, FAMILIAR_PLAYERS_DB_GROUP_NAME, FAMILIAR_PLAYERS_DB_KEY_NAME, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_KEY_FILE_ERROR) {
				goto __catch10_g_key_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return FALSE;
		}
		if (_tmp0_ == TRUE) {
			result = TRUE;
			return result;
		}
	}
	goto __finally10;
	__catch10_g_key_file_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			result = FALSE;
			_g_error_free0 (e);
			return result;
		}
	}
	__finally10:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	g_warning ("familiar-players-db.vala:79: Seen DB '%s' does not have key '%s' in gr" \
"oup '%s'", self->priv->file_name, FAMILIAR_PLAYERS_DB_KEY_NAME, FAMILIAR_PLAYERS_DB_GROUP_NAME);
	result = FALSE;
	return result;
}


static gboolean familiar_players_db_load_data_from_key_file (FamiliarPlayersDB* self) {
	gboolean result = FALSE;
	GError * _inner_error_;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	{
		char** _tmp1_;
		gint _desktops_size_;
		gint desktops_length1;
		gsize _tmp0_;
		char** desktops;
		desktops = (_tmp1_ = g_key_file_get_string_list (self->priv->key_file, FAMILIAR_PLAYERS_DB_GROUP_NAME, FAMILIAR_PLAYERS_DB_KEY_NAME, &_tmp0_, &_inner_error_), desktops_length1 = _tmp0_, _desktops_size_ = desktops_length1, _tmp1_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_KEY_FILE_ERROR) {
				goto __catch11_g_key_file_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return FALSE;
		}
		{
			char** s_collection;
			int s_collection_length1;
			int s_it;
			s_collection = desktops;
			s_collection_length1 = desktops_length1;
			for (s_it = 0; s_it < desktops_length1; s_it = s_it + 1) {
				char* s;
				s = g_strdup (s_collection[s_it]);
				{
					gee_abstract_map_set ((GeeAbstractMap*) self->priv->players_DB, s, GINT_TO_POINTER (TRUE));
					_g_free0 (s);
				}
			}
		}
		result = TRUE;
		desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
		return result;
	}
	goto __finally11;
	__catch11_g_key_file_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("familiar-players-db.vala:93: Error loading the Desktop string list");
			result = FALSE;
			_g_error_free0 (_error_);
			return result;
		}
	}
	__finally11:
	{
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
}


static void _vala_array_add1 (char*** array, int* length, int* size, char* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (char*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


static gboolean familiar_players_db_write_db (FamiliarPlayersDB* self) {
	gboolean result = FALSE;
	GError * _inner_error_;
	GKeyFile* keyfile;
	char** _tmp1_;
	gint _desktops_size_;
	gint desktops_length1;
	char** _tmp0_ = NULL;
	char** desktops;
	gsize data_length = 0UL;
	char* data;
	g_return_val_if_fail (self != NULL, FALSE);
	_inner_error_ = NULL;
	keyfile = g_key_file_new ();
	desktops = (_tmp1_ = (_tmp0_ = g_new0 (char*, 0 + 1), _tmp0_), desktops_length1 = 0, _desktops_size_ = desktops_length1, _tmp1_);
	{
		GeeSet* _tmp2_;
		GeeIterator* _tmp3_;
		GeeIterator* _key_it;
		_key_it = (_tmp3_ = gee_iterable_iterator ((GeeIterable*) (_tmp2_ = gee_map_get_keys ((GeeMap*) self->priv->players_DB))), _g_object_unref0 (_tmp2_), _tmp3_);
		while (TRUE) {
			char* key;
			if (!gee_iterator_next (_key_it)) {
				break;
			}
			key = (char*) gee_iterator_get (_key_it);
			_vala_array_add1 (&desktops, &desktops_length1, &_desktops_size_, g_strdup (key));
			_g_free0 (key);
		}
		_g_object_unref0 (_key_it);
	}
	g_key_file_set_string_list (keyfile, FAMILIAR_PLAYERS_DB_GROUP_NAME, FAMILIAR_PLAYERS_DB_KEY_NAME, (const gchar* const*) desktops, desktops_length1);
	data = NULL;
	{
		char* _tmp4_;
		data = (_tmp4_ = g_key_file_to_data (keyfile, &data_length, NULL), _g_free0 (data), _tmp4_);
	}
	goto __finally12;
	__catch12_g_key_file_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("familiar-players-db.vala:114: Problems dumping keyfile to a string");
			result = FALSE;
			_g_error_free0 (e);
			_g_free0 (data);
			desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
			_g_key_file_free0 (keyfile);
			return result;
		}
	}
	__finally12:
	if (_inner_error_ != NULL) {
		_g_free0 (data);
		desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
		_g_key_file_free0 (keyfile);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	if (g_mkdir_with_parents (self->priv->dir_name, 0700) != 0) {
		g_warning ("familiar-players-db.vala:119: Unable to make directory: %s", self->priv->dir_name);
		result = FALSE;
		_g_free0 (data);
		desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
		_g_key_file_free0 (keyfile);
		return result;
	}
	{
		gboolean _tmp5_;
		_tmp5_ = g_file_set_contents (self->priv->file_name, data, (gssize) data_length, &_inner_error_);
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch13_g_file_error;
			}
			_g_free0 (data);
			desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
			_g_key_file_free0 (keyfile);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return FALSE;
		}
		if (_tmp5_ == FALSE) {
			g_warning ("familiar-players-db.vala:125: Unable to write out file '%s'", self->priv->file_name);
		}
	}
	goto __finally13;
	__catch13_g_file_error:
	{
		GError * err;
		err = _inner_error_;
		_inner_error_ = NULL;
		{
			g_warning ("familiar-players-db.vala:129: Unable to write out file '%s'", self->priv->file_name);
			_g_error_free0 (err);
		}
	}
	__finally13:
	if (_inner_error_ != NULL) {
		_g_free0 (data);
		desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
		_g_key_file_free0 (keyfile);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	result = TRUE;
	_g_free0 (data);
	desktops = (_vala_array_free (desktops, desktops_length1, (GDestroyNotify) g_free), NULL);
	_g_key_file_free0 (keyfile);
	return result;
}


static gboolean _familiar_players_db_write_db_gsource_func (gpointer self) {
	gboolean result;
	result = familiar_players_db_write_db (self);
	return result;
}


void familiar_players_db_insert (FamiliarPlayersDB* self, const char* desktop) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (desktop != NULL);
	if (familiar_players_db_already_familiar (self, desktop) == FALSE) {
		char* _tmp0_;
		if (self->priv->write_id != 0) {
			g_source_remove (self->priv->write_id);
			self->priv->write_id = (guint) 0;
		}
		self->priv->write_id = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 60, _familiar_players_db_write_db_gsource_func, g_object_ref (self), g_object_unref);
		gee_abstract_map_set ((GeeAbstractMap*) self->priv->players_DB, _tmp0_ = g_strdup (desktop), GINT_TO_POINTER (TRUE));
		_g_free0 (_tmp0_);
	}
}


static char* bool_to_string (gboolean self) {
	char* result = NULL;
	if (self) {
		result = g_strdup ("true");
		return result;
	} else {
		result = g_strdup ("false");
		return result;
	}
}


gboolean familiar_players_db_already_familiar (FamiliarPlayersDB* self, const char* desktop) {
	gboolean result = FALSE;
	char* _tmp1_;
	GeeSet* _tmp0_;
	GeeSet* _tmp2_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (desktop != NULL, FALSE);
	g_debug ("familiar-players-db.vala:148: playerDB->already_familiar - result %s", _tmp1_ = bool_to_string (gee_collection_contains ((GeeCollection*) (_tmp0_ = gee_map_get_keys ((GeeMap*) self->priv->players_DB)), desktop)));
	_g_free0 (_tmp1_);
	_g_object_unref0 (_tmp0_);
	result = (_tmp3_ = gee_collection_contains ((GeeCollection*) (_tmp2_ = gee_map_get_keys ((GeeMap*) self->priv->players_DB)), desktop), _g_object_unref0 (_tmp2_), _tmp3_);
	return result;
}


GeeSet* familiar_players_db_records (FamiliarPlayersDB* self) {
	GeeSet* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = gee_map_get_keys ((GeeMap*) self->priv->players_DB);
	return result;
}


static void familiar_players_db_class_init (FamiliarPlayersDBClass * klass) {
	familiar_players_db_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FamiliarPlayersDBPrivate));
	G_OBJECT_CLASS (klass)->finalize = familiar_players_db_finalize;
}


static void familiar_players_db_instance_init (FamiliarPlayersDB * self) {
	self->priv = FAMILIAR_PLAYERS_DB_GET_PRIVATE (self);
}


static void familiar_players_db_finalize (GObject* obj) {
	FamiliarPlayersDB * self;
	self = FAMILIAR_PLAYERS_DB (obj);
	_g_object_unref0 (self->priv->players_DB);
	_g_free0 (self->priv->file_name);
	_g_free0 (self->priv->dir_name);
	_g_key_file_free0 (self->priv->key_file);
	G_OBJECT_CLASS (familiar_players_db_parent_class)->finalize (obj);
}


GType familiar_players_db_get_type (void) {
	static volatile gsize familiar_players_db_type_id__volatile = 0;
	if (g_once_init_enter (&familiar_players_db_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FamiliarPlayersDBClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) familiar_players_db_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FamiliarPlayersDB), 0, (GInstanceInitFunc) familiar_players_db_instance_init, NULL };
		GType familiar_players_db_type_id;
		familiar_players_db_type_id = g_type_register_static (G_TYPE_OBJECT, "FamiliarPlayersDB", &g_define_type_info, 0);
		g_once_init_leave (&familiar_players_db_type_id__volatile, familiar_players_db_type_id);
	}
	return familiar_players_db_type_id__volatile;
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





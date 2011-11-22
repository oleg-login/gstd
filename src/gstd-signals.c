/* gstd-signals.c generated by valac 0.14.0, the Vala compiler
 * generated from gstd-signals.vala, do not modify */

/*
 * gstd/src/gstd-signals.vala
 *
 * Posix signal handling for GStreamer daemon
 *
 * Use a separate thread to catch signals to avoid deadlock issues
 * that occur when a random GStreamer thread is allowed to catch signals.
 * Using a separate thread ensures the thread processing the signal is
 * not holding a lock on critical resource.
 *
 * Copyright (c) 2011, RidgeRun
 * All rights reserved.
 *
 * GPL2 license - See http://www.opensource.org/licenses/gpl-2.0.php for complete text.
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>


#define TYPE_GSTD_SIGNALS (gstd_signals_get_type ())
#define GSTD_SIGNALS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GSTD_SIGNALS, GstdSignals))
#define GSTD_SIGNALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GSTD_SIGNALS, GstdSignalsClass))
#define IS_GSTD_SIGNALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GSTD_SIGNALS))
#define IS_GSTD_SIGNALS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GSTD_SIGNALS))
#define GSTD_SIGNALS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GSTD_SIGNALS, GstdSignalsClass))

typedef struct _GstdSignals GstdSignals;
typedef struct _GstdSignalsClass GstdSignalsClass;
typedef struct _GstdSignalsPrivate GstdSignalsPrivate;

#define TYPE_FACTORY (factory_get_type ())
#define FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FACTORY, Factory))
#define FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FACTORY, FactoryClass))
#define IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FACTORY))
#define IS_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FACTORY))
#define FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FACTORY, FactoryClass))

typedef struct _Factory Factory;
typedef struct _FactoryClass FactoryClass;

struct _GstdSignals {
	GObject parent_instance;
	GstdSignalsPrivate * priv;
};

struct _GstdSignalsClass {
	GObjectClass parent_class;
};


static gpointer gstd_signals_parent_class = NULL;

GType gstd_signals_get_type (void) G_GNUC_CONST;
enum  {
	GSTD_SIGNALS_DUMMY_PROPERTY
};
GstdSignals* gstd_signals_new (void);
GstdSignals* gstd_signals_construct (GType object_type);
GType factory_get_type (void) G_GNUC_CONST;
guint factory_register_object (void* object, GDBusConnection* connection, const gchar* path, GError** error);
void gstd_signals_monitor (GstdSignals* self, GMainLoop* loop, Factory* factory, guint pollrate_ms);
static void gstd_signals_finalize (GObject* obj);


GstdSignals* gstd_signals_construct (GType object_type) {
	GstdSignals * self = NULL;
	self = (GstdSignals*) g_object_new (object_type, NULL);
	return self;
}


GstdSignals* gstd_signals_new (void) {
	return gstd_signals_construct (TYPE_GSTD_SIGNALS);
}


void gstd_signals_monitor (GstdSignals* self, GMainLoop* loop, Factory* factory, guint pollrate_ms) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (loop != NULL);
	g_return_if_fail (factory != NULL);
}


static void gstd_signals_class_init (GstdSignalsClass * klass) {
	gstd_signals_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = gstd_signals_finalize;
}


static void gstd_signals_instance_init (GstdSignals * self) {
}


static void gstd_signals_finalize (GObject* obj) {
	GstdSignals * self;
	self = GSTD_SIGNALS (obj);
	G_OBJECT_CLASS (gstd_signals_parent_class)->finalize (obj);
}


GType gstd_signals_get_type (void) {
	static volatile gsize gstd_signals_type_id__volatile = 0;
	if (g_once_init_enter (&gstd_signals_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GstdSignalsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gstd_signals_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GstdSignals), 0, (GInstanceInitFunc) gstd_signals_instance_init, NULL };
		GType gstd_signals_type_id;
		gstd_signals_type_id = g_type_register_static (G_TYPE_OBJECT, "GstdSignals", &g_define_type_info, 0);
		g_once_init_leave (&gstd_signals_type_id__volatile, gstd_signals_type_id);
	}
	return gstd_signals_type_id__volatile;
}




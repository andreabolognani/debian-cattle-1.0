
#ifndef __cattle_marshal_MARSHAL_H__
#define __cattle_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:CHAR,POINTER (./cattle-marshal.list:1) */
extern void cattle_marshal_BOOLEAN__CHAR_POINTER (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* BOOLEAN:POINTER (./cattle-marshal.list:2) */
extern void cattle_marshal_BOOLEAN__POINTER (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

G_END_DECLS

#endif /* __cattle_marshal_MARSHAL_H__ */


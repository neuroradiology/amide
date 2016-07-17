
#ifndef __amitk_marshal_MARSHAL_H__
#define __amitk_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* OBJECT:OBJECT (amitk_marshal.list:1) */
extern void amitk_marshal_OBJECT__OBJECT (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

/* OBJECT:NONE (amitk_marshal.list:2) */
extern void amitk_marshal_OBJECT__VOID (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint,
                                        gpointer      marshal_data);
#define amitk_marshal_OBJECT__NONE	amitk_marshal_OBJECT__VOID

/* NONE:POINTER (amitk_marshal.list:3) */
#define amitk_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER
#define amitk_marshal_NONE__POINTER	amitk_marshal_VOID__POINTER

/* NONE:POINTER,POINTER (amitk_marshal.list:4) */
extern void amitk_marshal_VOID__POINTER_POINTER (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);
#define amitk_marshal_NONE__POINTER_POINTER	amitk_marshal_VOID__POINTER_POINTER

/* NONE:NONE (amitk_marshal.list:5) */
#define amitk_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID
#define amitk_marshal_NONE__NONE	amitk_marshal_VOID__VOID

/* NONE:BOXED (amitk_marshal.list:6) */
#define amitk_marshal_VOID__BOXED	g_cclosure_marshal_VOID__BOXED
#define amitk_marshal_NONE__BOXED	amitk_marshal_VOID__BOXED

/* NONE:BOXED,BOXED (amitk_marshal.list:7) */
extern void amitk_marshal_VOID__BOXED_BOXED (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);
#define amitk_marshal_NONE__BOXED_BOXED	amitk_marshal_VOID__BOXED_BOXED

/* NONE:BOXED,DOUBLE (amitk_marshal.list:8) */
extern void amitk_marshal_VOID__BOXED_DOUBLE (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);
#define amitk_marshal_NONE__BOXED_DOUBLE	amitk_marshal_VOID__BOXED_DOUBLE

/* NONE:BOXED,DOUBLE,BOXED (amitk_marshal.list:9) */
extern void amitk_marshal_VOID__BOXED_DOUBLE_BOXED (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);
#define amitk_marshal_NONE__BOXED_DOUBLE_BOXED	amitk_marshal_VOID__BOXED_DOUBLE_BOXED

/* NONE:ENUM (amitk_marshal.list:10) */
#define amitk_marshal_VOID__ENUM	g_cclosure_marshal_VOID__ENUM
#define amitk_marshal_NONE__ENUM	amitk_marshal_VOID__ENUM

/* NONE:ENUM,BOXED (amitk_marshal.list:11) */
extern void amitk_marshal_VOID__ENUM_BOXED (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);
#define amitk_marshal_NONE__ENUM_BOXED	amitk_marshal_VOID__ENUM_BOXED

/* NONE:ENUM,BOXED,DOUBLE (amitk_marshal.list:12) */
extern void amitk_marshal_VOID__ENUM_BOXED_DOUBLE (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);
#define amitk_marshal_NONE__ENUM_BOXED_DOUBLE	amitk_marshal_VOID__ENUM_BOXED_DOUBLE

/* NONE:ENUM,POINTER,DOUBLE (amitk_marshal.list:13) */
extern void amitk_marshal_VOID__ENUM_POINTER_DOUBLE (GClosure     *closure,
                                                     GValue       *return_value,
                                                     guint         n_param_values,
                                                     const GValue *param_values,
                                                     gpointer      invocation_hint,
                                                     gpointer      marshal_data);
#define amitk_marshal_NONE__ENUM_POINTER_DOUBLE	amitk_marshal_VOID__ENUM_POINTER_DOUBLE

/* NONE:OBJECT (amitk_marshal.list:14) */
#define amitk_marshal_VOID__OBJECT	g_cclosure_marshal_VOID__OBJECT
#define amitk_marshal_NONE__OBJECT	amitk_marshal_VOID__OBJECT

/* NONE:OBJECT,BOOLEAN (amitk_marshal.list:15) */
extern void amitk_marshal_VOID__OBJECT_BOOLEAN (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);
#define amitk_marshal_NONE__OBJECT_BOOLEAN	amitk_marshal_VOID__OBJECT_BOOLEAN

/* NONE:OBJECT,BOXED (amitk_marshal.list:16) */
extern void amitk_marshal_VOID__OBJECT_BOXED (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);
#define amitk_marshal_NONE__OBJECT_BOXED	amitk_marshal_VOID__OBJECT_BOXED

/* NONE:OBJECT,ENUM (amitk_marshal.list:17) */
extern void amitk_marshal_VOID__OBJECT_ENUM (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);
#define amitk_marshal_NONE__OBJECT_ENUM	amitk_marshal_VOID__OBJECT_ENUM

/* NONE:OBJECT,ENUM,BOXED (amitk_marshal.list:18) */
extern void amitk_marshal_VOID__OBJECT_ENUM_BOXED (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);
#define amitk_marshal_NONE__OBJECT_ENUM_BOXED	amitk_marshal_VOID__OBJECT_ENUM_BOXED

/* NONE:OBJECT,ENUM,ENUM (amitk_marshal.list:19) */
extern void amitk_marshal_VOID__OBJECT_ENUM_ENUM (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);
#define amitk_marshal_NONE__OBJECT_ENUM_ENUM	amitk_marshal_VOID__OBJECT_ENUM_ENUM

/* NONE:UINT,UINT (amitk_marshal.list:20) */
extern void amitk_marshal_VOID__UINT_UINT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);
#define amitk_marshal_NONE__UINT_UINT	amitk_marshal_VOID__UINT_UINT

/* STRING:POINTER,STRING (amitk_marshal.list:21) */
extern void amitk_marshal_STRING__POINTER_STRING (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* POINTER:POINTER,POINTER (amitk_marshal.list:22) */
extern void amitk_marshal_POINTER__POINTER_POINTER (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* POINTER:POINTER,POINTER,POINTER (amitk_marshal.list:23) */
extern void amitk_marshal_POINTER__POINTER_POINTER_POINTER (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

G_END_DECLS

#endif /* __amitk_marshal_MARSHAL_H__ */


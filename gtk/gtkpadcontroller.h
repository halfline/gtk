/* GTK - The GIMP Toolkit
 * Copyright (C) 2016, Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author(s): Carlos Garnacho <carlosg@gnome.org>
 */

#ifndef __GTK_PAD_CONTROLLER_H__
#define __GTK_PAD_CONTROLLER_H__

#if !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#include <gdk/gdk.h>
#include <gtk/gtkeventcontroller.h>

G_BEGIN_DECLS

#define GTK_TYPE_PAD_CONTROLLER         (gtk_pad_controller_get_type ())
#define GTK_PAD_CONTROLLER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GTK_TYPE_PAD_CONTROLLER, GtkPadController))
#define GTK_PAD_CONTROLLER_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k), GTK_TYPE_PAD_CONTROLLER, GtkPadControllerClass))
#define GTK_IS_PAD_CONTROLLER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GTK_TYPE_PAD_CONTROLLER))
#define GTK_IS_PAD_CONTROLLER_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), GTK_TYPE_PAD_CONTROLLER))
#define GTK_PAD_CONTROLLER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GTK_TYPE_PAD_CONTROLLER, GtkPadControllerClass))

typedef struct _GtkPadController GtkPadController;
typedef struct _GtkPadControllerClass GtkPadControllerClass;
typedef struct _GtkPadActionEntry GtkPadActionEntry;

typedef enum {
  GTK_PAD_ACTION_BUTTON,
  GTK_PAD_ACTION_RING,
  GTK_PAD_ACTION_STRIP
} GtkPadActionType;

struct _GtkPadActionEntry {
  GtkPadActionType type;
  gint index;
  gint mode;
  gchar *label;
  gchar *action_name;
};

GDK_AVAILABLE_IN_3_22
GType gtk_pad_controller_get_type           (void) G_GNUC_CONST;

GDK_AVAILABLE_IN_3_22
GtkPadController *gtk_pad_controller_new    (GtkWindow        *window,
                                             GActionGroup     *group,
                                             GdkDevice        *pad);

GDK_AVAILABLE_IN_3_22
void  gtk_pad_controller_set_action_group   (GtkPadController *controller,
                                             GActionGroup     *group);
GDK_AVAILABLE_IN_3_22
void  gtk_pad_controller_set_action_entries (GtkPadController        *controller,
                                             const GtkPadActionEntry *entries,
                                             gint                     n_entries);
GDK_AVAILABLE_IN_3_22
void  gtk_pad_controller_set_action         (GtkPadController *controller,
                                             GtkPadActionType  type,
                                             gint              index,
                                             gint              mode,
                                             const gchar      *label,
                                             const gchar      *action_name);

G_END_DECLS

#endif /* __GTK_PAD_CONTROLLER_H__ */

/* GDK - The GIMP Drawing Kit
 * Copyright (C) 2016 Red Hat
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
 * Author: Carlos Garnacho <carlosg@gnome.org>
 */

#include "config.h"

#include "gdkdevicepad.h"
#include "gdkdevicepadprivate.h"
#include "gdkdeviceprivate.h"

G_DEFINE_INTERFACE (GdkDevicePad, gdk_device_pad, GDK_TYPE_DEVICE)

static void
gdk_device_pad_default_init (GdkDevicePadInterface *pad)
{
}

gint
gdk_device_pad_get_n_groups (GdkDevicePad *pad)
{
  GdkDevicePadInterface *iface = GDK_DEVICE_PAD_GET_IFACE (pad);

  g_return_val_if_fail (GDK_IS_DEVICE_PAD (pad), 0);

  return iface->get_n_groups (pad);
}

gint
gdk_device_pad_get_n_group_modes (GdkDevicePad *pad,
                                  gint          group)
{
  GdkDevicePadInterface *iface = GDK_DEVICE_PAD_GET_IFACE (pad);

  g_return_val_if_fail (GDK_IS_DEVICE_PAD (pad), 0);

  return iface->get_n_group_modes (pad, group);
}

gint
gdk_device_pad_get_n_features (GdkDevicePad        *pad,
                               GdkDevicePadFeature  feature)
{
  GdkDevicePadInterface *iface = GDK_DEVICE_PAD_GET_IFACE (pad);

  g_return_val_if_fail (GDK_IS_DEVICE_PAD (pad), 0);

  return iface->get_n_features (pad, feature);
}

gint
gdk_device_pad_get_feature_group (GdkDevicePad        *pad,
                                  GdkDevicePadFeature  feature,
                                  gint                 idx)
{
  GdkDevicePadInterface *iface = GDK_DEVICE_PAD_GET_IFACE (pad);

  g_return_val_if_fail (GDK_IS_DEVICE_PAD (pad), -1);

  return iface->get_feature_group (pad, feature, idx);
}

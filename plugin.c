/* GStreamer video parsers
 * Copyright (C) 2011 Mark Nauwelaerts <mark.nauwelaerts@collabora.co.uk>
 * Copyright (C) 2009 Tim-Philipp Müller <tim centricular net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
#include "gstvc1parse.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  return gst_element_register (plugin, "vaapiparse_vc1",
      GST_RANK_PRIMARY, GST_TYPE_VC1_PARSE);
}

GstPluginDesc gst_plugin_desc = {
  .major_version = GST_VERSION_MAJOR,
  .minor_version = GST_VERSION_MINOR,
  .name = "vaapivc1parser",
  .description =  "Temporal vc1parser for gstreamer-vaapi",
  .plugin_init = plugin_init,
  .version = "0.1",
  .license = "LGPL",
  .source = "none",
  .package = "none",
  .origin = "none",
};

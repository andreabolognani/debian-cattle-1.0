/* Cattle - Brainfuck language toolkit
 * Copyright (C) 2008-2014  Andrea Bolognani <eof@kiyuko.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Homepage: http://kiyuko.org/software/cattle
 */

#if !defined (__CATTLE_H_INSIDE__) && !defined (CATTLE_COMPILATION)
#error "Only <cattle/cattle.h> can be included directly."
#endif

#ifndef __CATTLE_VERSION_H__
#define __CATTLE_VERSION_H__

#include <glib.h>

G_BEGIN_DECLS

#define CATTLE_MAJOR_VERSION (1)
#define CATTLE_MINOR_VERSION (2)
#define CATTLE_MICRO_VERSION (0)

#define CATTLE_CHECK_VERSION(major,minor,micro) \
  (CATTLE_MAJOR_VERSION > (major) || \
  (CATTLE_MAJOR_VERSION == (major) && CATTLE_MINOR_VERSION > (minor)) || \
  (CATTLE_MAJOR_VERSION == (major) && CATTLE_MINOR_VERSION == (minor) && CATTLE_MICRO_VERSION >= (micro)))

extern const guint cattle_major_version;
extern const guint cattle_minor_version;
extern const guint cattle_micro_version;

gboolean cattle_check_version (guint required_major,
                               guint required_minor,
                               guint required_micro);

G_END_DECLS

#endif /* __CATTLE_VERSION_H__ */

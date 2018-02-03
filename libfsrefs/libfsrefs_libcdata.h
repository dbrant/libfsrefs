/*
 * The internal libcdata header
 *
 * Copyright (C) 2012-2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSREFS_LIBCDATA_H )
#define _LIBFSREFS_LIBCDATA_H

#include <common.h>

/* Define HAVE_LOCAL_LIBCDATA for local use of libcdata
 */
#if defined( HAVE_LOCAL_LIBCDATA )

#include <libcdata_array.h>
#include <libcdata_btree.h>
#include <libcdata_definitions.h>
#include <libcdata_list.h>
#include <libcdata_list_element.h>
#include <libcdata_range_list.h>
#include <libcdata_tree_node.h>
#include <libcdata_types.h>

#else

/* If libtool DLL support is enabled set LIBCDATA_DLL_IMPORT
 * before including libcdata.h
 */
#if defined( _WIN32 ) && defined( DLL_IMPORT )
#define LIBCDATA_DLL_IMPORT
#endif

#include <libcdata.h>

#endif /* defined( HAVE_LOCAL_LIBCDATA ) */

#endif /* !defined( _LIBFSREFS_LIBCDATA_H ) */


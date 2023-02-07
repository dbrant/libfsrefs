/*
 * Debug functions
 *
 * Copyright (C) 2012-2023, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBFSREFS_DEBUG_H )
#define _LIBFSREFS_DEBUG_H

#include <common.h>
#include <types.h>

#include "libfsrefs_libbfio.h"
#include "libfsrefs_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if defined( HAVE_DEBUG_OUTPUT )

void libfsrefs_debug_print_mft_attribute_data_flags(
      uint16_t mft_attribute_data_flags );

void libfsrefs_debug_print_file_attribute_flags(
      uint32_t file_attribute_flags );

void libfsrefs_debug_print_index_node_flags(
      uint32_t index_node_flags );

void libfsrefs_debug_print_index_value_flags(
      uint32_t index_value_flags );

const char *libfsrefs_debug_print_attribute_type(
             uint32_t attribute_type );

const char *libfsrefs_debug_print_file_name_attribute_namespace(
             uint8_t name_namespace );

int libfsrefs_debug_print_read_offsets(
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

#endif

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFSREFS_DEBUG_H ) */


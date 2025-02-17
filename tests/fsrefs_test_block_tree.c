/*
 * Library block_tree functions testing program
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

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fsrefs_test_libcerror.h"
#include "fsrefs_test_libfsrefs.h"
#include "fsrefs_test_macros.h"
#include "fsrefs_test_memory.h"
#include "fsrefs_test_unused.h"

#include "../libfsrefs/libfsrefs_block_descriptor.h"
#include "../libfsrefs/libfsrefs_block_tree.h"
#include "../libfsrefs/libfsrefs_block_tree_node.h"
#include "../libfsrefs/libfsrefs_definitions.h"

#if defined( __GNUC__ ) && !defined( LIBFSREFS_DLL_IMPORT )

/* Tests the libfsrefs_block_tree_initialize function
 * Returns 1 if successful or 0 if not
 */
int fsrefs_test_block_tree_initialize(
     void )
{
	libcerror_error_t *error           = NULL;
	libfsrefs_block_tree_t *block_tree = NULL;
	int result                         = 0;

#if defined( HAVE_FSREFS_TEST_MEMORY )
	int number_of_malloc_fail_tests    = 2;
	int number_of_memset_fail_tests    = 1;
	int test_number                    = 0;
#endif

	/* Test block_tree initialization
	 */
	result = libfsrefs_block_tree_initialize(
	          &block_tree,
	          0x800000000UL,
	          0x4000,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "block_tree",
	 block_tree );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsrefs_block_tree_free(
	          &block_tree,
	          NULL,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "block_tree",
	 block_tree );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfsrefs_block_tree_initialize(
	          NULL,
	          0x800000000UL,
	          0x4000,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	block_tree = (libfsrefs_block_tree_t *) 0x12345678UL;

	result = libfsrefs_block_tree_initialize(
	          &block_tree,
	          0x800000000UL,
	          0x4000,
	          &error );

	block_tree = NULL;

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_FSREFS_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfsrefs_block_tree_initialize with malloc failing
		 */
		fsrefs_test_malloc_attempts_before_fail = test_number;

		result = libfsrefs_block_tree_initialize(
		          &block_tree,
		          0x800000000UL,
		          0x4000,
		          &error );

		if( fsrefs_test_malloc_attempts_before_fail != -1 )
		{
			fsrefs_test_malloc_attempts_before_fail = -1;

			if( block_tree != NULL )
			{
				libfsrefs_block_tree_free(
				 &block_tree,
				 NULL,
				 NULL );
			}
		}
		else
		{
			FSREFS_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FSREFS_TEST_ASSERT_IS_NULL(
			 "block_tree",
			 block_tree );

			FSREFS_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfsrefs_block_tree_initialize with memset failing
		 */
		fsrefs_test_memset_attempts_before_fail = test_number;

		result = libfsrefs_block_tree_initialize(
		          &block_tree,
		          0x800000000UL,
		          0x4000,
		          &error );

		if( fsrefs_test_memset_attempts_before_fail != -1 )
		{
			fsrefs_test_memset_attempts_before_fail = -1;

			if( block_tree != NULL )
			{
				libfsrefs_block_tree_free(
				 &block_tree,
				 NULL,
				 NULL );
			}
		}
		else
		{
			FSREFS_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FSREFS_TEST_ASSERT_IS_NULL(
			 "block_tree",
			 block_tree );

			FSREFS_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FSREFS_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( block_tree != NULL )
	{
		libfsrefs_block_tree_free(
		 &block_tree,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsrefs_block_tree_free function
 * Returns 1 if successful or 0 if not
 */
int fsrefs_test_block_tree_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfsrefs_block_tree_free(
	          NULL,
	          NULL,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfsrefs_block_tree_get_block_descriptor_by_offset function
 * Returns 1 if successful or 0 if not
 */
int fsrefs_test_block_tree_get_block_descriptor_by_offset(
     void )
{
	libcerror_error_t *error                      = NULL;
	libfsrefs_block_descriptor_t *block_descriptor = NULL;
	libfsrefs_block_tree_t *block_tree             = NULL;
	off64_t block_offset                          = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libfsrefs_block_tree_initialize(
	          &block_tree,
	          0x800000000UL,
	          0x4000,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "block_tree",
	 block_tree );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsrefs_block_tree_get_block_descriptor_by_offset(
	          block_tree,
	          0,
	          &block_descriptor,
	          &block_offset,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "block_descriptor",
	 block_descriptor );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfsrefs_block_tree_get_block_descriptor_by_offset(
	          NULL,
	          0,
	          &block_descriptor,
	          &block_offset,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfsrefs_block_tree_get_block_descriptor_by_offset(
	          block_tree,
	          0,
	          NULL,
	          &block_offset,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfsrefs_block_tree_get_block_descriptor_by_offset(
	          block_tree,
	          0,
	          &block_descriptor,
	          NULL,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfsrefs_block_tree_free(
	          &block_tree,
	          NULL,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "block_tree",
	 block_tree );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( block_tree != NULL )
	{
		libfsrefs_block_tree_free(
		 &block_tree,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsrefs_block_tree_insert_block_descriptor_by_offset function
 * Returns 1 if successful or 0 if not
 */
int fsrefs_test_block_tree_insert_block_descriptor_by_offset(
     void )
{
	libcerror_error_t *error                               = NULL;
	libfsrefs_block_descriptor_t *block_descriptor          = NULL;
	libfsrefs_block_descriptor_t *existing_block_descriptor = NULL;
	libfsrefs_block_tree_t *block_tree                      = NULL;
	libfsrefs_block_tree_node_t *leaf_block_tree_node       = NULL;
	int leaf_value_index                                   = 0;
	int result                                             = 0;

	/* Initialize test
	 */
	result = libfsrefs_block_tree_initialize(
	          &block_tree,
	          0x800000000UL,
	          0x4000,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "block_tree",
	 block_tree );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsrefs_block_descriptor_initialize(
	          &block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "block_descriptor",
	 block_descriptor );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsrefs_block_tree_insert_block_descriptor_by_offset(
	          block_tree,
	          0,
	          block_descriptor,
	          &leaf_value_index,
	          &leaf_block_tree_node,
	          &existing_block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "leaf_value_index",
	 leaf_value_index,
	 0 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "leaf_block_tree_node",
	 leaf_block_tree_node );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "existing_block_descriptor",
	 existing_block_descriptor );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsrefs_block_tree_insert_block_descriptor_by_offset(
	          block_tree,
	          0,
	          NULL,
	          &leaf_value_index,
	          &leaf_block_tree_node,
	          &existing_block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "leaf_value_index",
	 leaf_value_index,
	 0 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "leaf_block_tree_node",
	 leaf_block_tree_node );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "existing_block_descriptor",
	 existing_block_descriptor );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfsrefs_block_tree_insert_block_descriptor_by_offset(
	          NULL,
	          0,
	          block_descriptor,
	          &leaf_value_index,
	          &leaf_block_tree_node,
	          &existing_block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfsrefs_block_tree_insert_block_descriptor_by_offset(
	          block_tree,
	          0,
	          block_descriptor,
	          NULL,
	          &leaf_block_tree_node,
	          &existing_block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfsrefs_block_tree_insert_block_descriptor_by_offset(
	          block_tree,
	          0,
	          block_descriptor,
	          &leaf_value_index,
	          NULL,
	          &existing_block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libfsrefs_block_tree_insert_block_descriptor_by_offset(
	          block_tree,
	          0,
	          block_descriptor,
	          &leaf_value_index,
	          &leaf_block_tree_node,
	          NULL,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSREFS_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libfsrefs_block_descriptor_free(
	          &block_descriptor,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "block_descriptor",
	 block_descriptor );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsrefs_block_tree_free(
	          &block_tree,
	          NULL,
	          &error );

	FSREFS_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "block_tree",
	 block_tree );

	FSREFS_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( block_descriptor != NULL )
	{
		libfsrefs_block_descriptor_free(
		 &block_descriptor,
		 NULL );
	}
	if( block_tree != NULL )
	{
		libfsrefs_block_tree_free(
		 &block_tree,
		 NULL,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFSREFS_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FSREFS_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FSREFS_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FSREFS_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FSREFS_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FSREFS_TEST_UNREFERENCED_PARAMETER( argc )
	FSREFS_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFSREFS_DLL_IMPORT )

	FSREFS_TEST_RUN(
	 "libfsrefs_block_tree_initialize",
	 fsrefs_test_block_tree_initialize );

	FSREFS_TEST_RUN(
	 "libfsrefs_block_tree_free",
	 fsrefs_test_block_tree_free );

	FSREFS_TEST_RUN(
	 "libfsrefs_block_tree_get_block_descriptor_by_offset",
	 fsrefs_test_block_tree_get_block_descriptor_by_offset );

	FSREFS_TEST_RUN(
	 "libfsrefs_block_tree_insert_block_descriptor_by_offset",
	 fsrefs_test_block_tree_insert_block_descriptor_by_offset );

#endif /* defined( __GNUC__ ) && !defined( LIBFSREFS_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBFSREFS_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBFSREFS_DLL_IMPORT ) */
}


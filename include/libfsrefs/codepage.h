/*
 * Codepage definitions for libfsrefs
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

#if !defined( _LIBFSREFS_CODEPAGE_H )
#define _LIBFSREFS_CODEPAGE_H

#include <libfsrefs/types.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* The codepage definitions
 */
enum LIBFSREFS_CODEPAGES
{
	LIBFSREFS_CODEPAGE_ASCII			= 20127,

	LIBFSREFS_CODEPAGE_ISO_8859_1			= 28591,
	LIBFSREFS_CODEPAGE_ISO_8859_2			= 28592,
	LIBFSREFS_CODEPAGE_ISO_8859_3			= 28593,
	LIBFSREFS_CODEPAGE_ISO_8859_4			= 28594,
	LIBFSREFS_CODEPAGE_ISO_8859_5			= 28595,
	LIBFSREFS_CODEPAGE_ISO_8859_6			= 28596,
	LIBFSREFS_CODEPAGE_ISO_8859_7			= 28597,
	LIBFSREFS_CODEPAGE_ISO_8859_8			= 28598,
	LIBFSREFS_CODEPAGE_ISO_8859_9			= 28599,
	LIBFSREFS_CODEPAGE_ISO_8859_10			= 28600,
	LIBFSREFS_CODEPAGE_ISO_8859_11			= 28601,
	LIBFSREFS_CODEPAGE_ISO_8859_13			= 28603,
	LIBFSREFS_CODEPAGE_ISO_8859_14			= 28604,
	LIBFSREFS_CODEPAGE_ISO_8859_15			= 28605,
	LIBFSREFS_CODEPAGE_ISO_8859_16			= 28606,

	LIBFSREFS_CODEPAGE_KOI8_R			= 20866,
	LIBFSREFS_CODEPAGE_KOI8_U			= 21866,

	LIBFSREFS_CODEPAGE_WINDOWS_874			= 874,
	LIBFSREFS_CODEPAGE_WINDOWS_932			= 932,
	LIBFSREFS_CODEPAGE_WINDOWS_936			= 936,
	LIBFSREFS_CODEPAGE_WINDOWS_949			= 949,
	LIBFSREFS_CODEPAGE_WINDOWS_950			= 950,
	LIBFSREFS_CODEPAGE_WINDOWS_1250			= 1250,
	LIBFSREFS_CODEPAGE_WINDOWS_1251			= 1251,
	LIBFSREFS_CODEPAGE_WINDOWS_1252			= 1252,
	LIBFSREFS_CODEPAGE_WINDOWS_1253			= 1253,
	LIBFSREFS_CODEPAGE_WINDOWS_1254			= 1254,
	LIBFSREFS_CODEPAGE_WINDOWS_1255			= 1255,
	LIBFSREFS_CODEPAGE_WINDOWS_1256			= 1256,
	LIBFSREFS_CODEPAGE_WINDOWS_1257			= 1257,
	LIBFSREFS_CODEPAGE_WINDOWS_1258			= 1258
};

#define LIBFSREFS_CODEPAGE_US_ASCII			LIBFSREFS_CODEPAGE_ASCII

#define LIBFSREFS_CODEPAGE_ISO_WESTERN_EUROPEAN		LIBFSREFS_CODEPAGE_ISO_8859_1
#define LIBFSREFS_CODEPAGE_ISO_CENTRAL_EUROPEAN		LIBFSREFS_CODEPAGE_ISO_8859_2
#define LIBFSREFS_CODEPAGE_ISO_SOUTH_EUROPEAN		LIBFSREFS_CODEPAGE_ISO_8859_3
#define LIBFSREFS_CODEPAGE_ISO_NORTH_EUROPEAN		LIBFSREFS_CODEPAGE_ISO_8859_4
#define LIBFSREFS_CODEPAGE_ISO_CYRILLIC			LIBFSREFS_CODEPAGE_ISO_8859_5
#define LIBFSREFS_CODEPAGE_ISO_ARABIC			LIBFSREFS_CODEPAGE_ISO_8859_6
#define LIBFSREFS_CODEPAGE_ISO_GREEK			LIBFSREFS_CODEPAGE_ISO_8859_7
#define LIBFSREFS_CODEPAGE_ISO_HEBREW			LIBFSREFS_CODEPAGE_ISO_8859_8
#define LIBFSREFS_CODEPAGE_ISO_TURKISH			LIBFSREFS_CODEPAGE_ISO_8859_9
#define LIBFSREFS_CODEPAGE_ISO_NORDIC			LIBFSREFS_CODEPAGE_ISO_8859_10
#define LIBFSREFS_CODEPAGE_ISO_THAI			LIBFSREFS_CODEPAGE_ISO_8859_11
#define LIBFSREFS_CODEPAGE_ISO_BALTIC			LIBFSREFS_CODEPAGE_ISO_8859_13
#define LIBFSREFS_CODEPAGE_ISO_CELTIC			LIBFSREFS_CODEPAGE_ISO_8859_14

#define LIBFSREFS_CODEPAGE_ISO_LATIN_1			LIBFSREFS_CODEPAGE_ISO_8859_1
#define LIBFSREFS_CODEPAGE_ISO_LATIN_2			LIBFSREFS_CODEPAGE_ISO_8859_2
#define LIBFSREFS_CODEPAGE_ISO_LATIN_3			LIBFSREFS_CODEPAGE_ISO_8859_3
#define LIBFSREFS_CODEPAGE_ISO_LATIN_4			LIBFSREFS_CODEPAGE_ISO_8859_4
#define LIBFSREFS_CODEPAGE_ISO_LATIN_5			LIBFSREFS_CODEPAGE_ISO_8859_9
#define LIBFSREFS_CODEPAGE_ISO_LATIN_6			LIBFSREFS_CODEPAGE_ISO_8859_10
#define LIBFSREFS_CODEPAGE_ISO_LATIN_7			LIBFSREFS_CODEPAGE_ISO_8859_13
#define LIBFSREFS_CODEPAGE_ISO_LATIN_8			LIBFSREFS_CODEPAGE_ISO_8859_14
#define LIBFSREFS_CODEPAGE_ISO_LATIN_9			LIBFSREFS_CODEPAGE_ISO_8859_15
#define LIBFSREFS_CODEPAGE_ISO_LATIN_10			LIBFSREFS_CODEPAGE_ISO_8859_16

#define LIBFSREFS_CODEPAGE_KOI8_RUSSIAN			LIBFSREFS_CODEPAGE_KOI8_R
#define LIBFSREFS_CODEPAGE_KOI8_UKRAINIAN		LIBFSREFS_CODEPAGE_KOI8_U

#define LIBFSREFS_CODEPAGE_WINDOWS_THAI			LIBFSREFS_CODEPAGE_WINDOWS_874
#define LIBFSREFS_CODEPAGE_WINDOWS_JAPANESE		LIBFSREFS_CODEPAGE_WINDOWS_932
#define LIBFSREFS_CODEPAGE_WINDOWS_CHINESE_SIMPLIFIED	LIBFSREFS_CODEPAGE_WINDOWS_936
#define LIBFSREFS_CODEPAGE_WINDOWS_KOREAN		LIBFSREFS_CODEPAGE_WINDOWS_949
#define LIBFSREFS_CODEPAGE_WINDOWS_CHINESE_TRADITIONAL	LIBFSREFS_CODEPAGE_WINDOWS_950
#define LIBFSREFS_CODEPAGE_WINDOWS_CENTRAL_EUROPEAN	LIBFSREFS_CODEPAGE_WINDOWS_1250
#define LIBFSREFS_CODEPAGE_WINDOWS_CYRILLIC		LIBFSREFS_CODEPAGE_WINDOWS_1251
#define LIBFSREFS_CODEPAGE_WINDOWS_WESTERN_EUROPEAN	LIBFSREFS_CODEPAGE_WINDOWS_1252
#define LIBFSREFS_CODEPAGE_WINDOWS_GREEK		LIBFSREFS_CODEPAGE_WINDOWS_1253
#define LIBFSREFS_CODEPAGE_WINDOWS_TURKISH		LIBFSREFS_CODEPAGE_WINDOWS_1254
#define LIBFSREFS_CODEPAGE_WINDOWS_HEBREW		LIBFSREFS_CODEPAGE_WINDOWS_1255
#define LIBFSREFS_CODEPAGE_WINDOWS_ARABIC		LIBFSREFS_CODEPAGE_WINDOWS_1256
#define LIBFSREFS_CODEPAGE_WINDOWS_BALTIC		LIBFSREFS_CODEPAGE_WINDOWS_1257
#define LIBFSREFS_CODEPAGE_WINDOWS_VIETNAMESE		LIBFSREFS_CODEPAGE_WINDOWS_1258

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBFSREFS_CODEPAGE_H ) */


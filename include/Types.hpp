/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// Этот файл распространяется под лицензией Mozilla Public License 2.0.

#ifndef _TYPES_H
#define _TYPES_H

typedef __INT8_TYPE__ INT8;
typedef __INT16_TYPE__ INT16;
typedef __INT32_TYPE__ INT32;
typedef __INT64_TYPE__ INT64;
typedef __UINT8_TYPE__ UINT8;
typedef __UINT16_TYPE__ UINT16;
typedef __UINT32_TYPE__ UINT32;
typedef __UINT64_TYPE__ UINT64;

typedef INT32 LONG;
typedef UINT32 ULONG;

typedef INT32 BOOL;

typedef void* LPVOID;
typedef const LPVOID LPCVOID;
typedef void* HANDLE;

typedef INT8* LPINT8;
typedef INT16* LPINT16;
typedef INT32* LPINT32;
typedef INT64* LPINT64;
typedef UINT8* LPUINT8;
typedef UINT16* LPUINT16;
typedef UINT32* LPUINT32;
typedef UINT64* LPUINT64;

typedef const LPINT8 LPCINT8;
typedef const LPINT16 LPCINT16;
typedef const LPINT32 LPCINT32;
typedef const LPINT64 LPCINT64;
typedef const LPUINT8 LPCUINT8;
typedef const LPUINT16 LPCUINT16;
typedef const LPUINT32 LPCUINT32;
typedef const LPUINT64 LPCUINT64;

typedef char CHAR;
typedef unsigned char UCHAR;
typedef wchar_t WCHAR;

typedef CHAR* LPCHAR;
typedef UCHAR* LPUCHAR;
typedef WCHAR* LPWCHAR;

typedef const LPCHAR LPCCHAR;
typedef const LPUCHAR LPCUCHAR;
typedef const LPWCHAR LPCWCHAR;

#define TRUE BOOL(1)
#define FALSE BOOL(0)
#define NULL 0

#endif
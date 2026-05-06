/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// Этот файл распространяется под лицензией Mozilla Public License 2.0.

#include <Types.hpp>
#include <ExChar.hpp>

UINT8 EncoderUTF::ToUtf32(LPCINT8 Buffer, LPINT32 Sym)
{
	INT8 byte1 = Buffer[0];

	if ((byte1 & 0x80) == 0)
	{
		*Sym = (INT32)byte1;
		return 1;
	}
	else if ((byte1 & 0xE0) == 0xC0)
	{
		INT8 byte2 = Buffer[1];
		*Sym = ((byte1 & 0x1F) << 6) | (byte2 & 0x3F);
		return 2;
	}
	else if ((byte1 & 0xF0) == 0xE0)
	{
		INT8 byte2 = Buffer[1];
		INT8 byte3 = Buffer[2];
		*Sym = ((byte1 & 0x0F) << 12) | ((byte2 & 0x3F) << 6) | (byte3 & 0x3F);
		return 3;
	}
	else if ((byte1 & 0xF8) == 0xF0)
	{
		INT8 byte2 = Buffer[1];
		INT8 byte3 = Buffer[2];
		INT8 byte4 = Buffer[3];
		*Sym = ((byte1 & 0x07) << 18) | ((byte2 & 0x3F) << 12) | ((byte3 & 0x3F) << 6) | (byte4 & 0x3F);
		return 4;
	}
	return 0;
}

UINT8 EncoderUTF::ToUtf32(LPCUINT16 Buffer, LPINT32 Sym)
{
	UINT16 w1 = Buffer[0];
	
	if (w1 < 0xD800 || w1 > 0xDFFF)
	{
		*Sym = (INT32)w1;
		return 1;
	}
	else if (w1 >= 0xD800 && w1 <= 0xDBFF)
	{
		UINT16 w2 = Buffer[1];
		if (w2 >= 0xDC00 && w2 <= 0xDFFF)
		{
			*Sym = 0x10000 + ((w1 - 0xD800) << 10) + (w2 - 0xDC00);
			return 2;
		}
	}
	
	return 0;
}

UINT8 EncoderUTF::ToUtf8(LPCINT32 Buffer, LPINT8 Sym)
{
	INT32 code = Buffer[0];
	if (code <= 0x0000007F) // 1 символ
	{
		Sym[0] = (INT8)code;
		return 1;
	}
	else if (code <= 0x000007FF) // 2 символа
	{
		Sym[0] = (INT8)(0xC0 | (code >> 6));
		Sym[1] = (INT8)(0x80 | (code & 0x3F));
		return 2;
	}
	else if (code <= 0x0000FFFF) // 3 символа
	{
		Sym[0] = (INT8)(0xE0 | (code >> 12));
		Sym[1] = (INT8)(0x80 | ((code >> 6) & 0x3F));
		Sym[2] = (INT8)(0x80 | (code & 0x3F));
		return 3;
	}
	else if (code <= 0x0010FFFF) // 4 символа
	{
		Sym[0] = (INT8)(0xF0 | (code >> 18));
		Sym[1] = (INT8)(0x80 | ((code >> 12) & 0x3F));
		Sym[2] = (INT8)(0x80 | ((code >> 6) & 0x3F));
		Sym[3] = (INT8)(0x80 | (code & 0x3F));
		return 4;
	}

	return 0;
}

UINT8 EncoderUTF::ToUtf16(LPCINT32 Buffer, LPUINT16 Sym)
{
	INT32 code = Buffer[0];

	if (code <= (INT32)0x0000FFFF) // 2 байта
	{
		Sym[0] = (INT16)code;
		return 1;
	}
	else if (code <= (INT32)0x0010FFFF) // 4 байта
	{
		INT32 adaptive = code - 0x10000;
		Sym[0] = (INT16)(0xD800 + (adaptive >> 10));
		Sym[1] = (INT16)(0xDC00 + (adaptive & 0x3FF));
		return 2;
	}

	return 0;
}
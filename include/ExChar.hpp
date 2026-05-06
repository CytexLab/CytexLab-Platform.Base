/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

// Этот файл распространяется под лицензией Mozilla Public License 2.0.

#ifndef _EXCHAR_H
#define _EXCHAR_H

#include "Types.hpp"

class ExChar
{
private:
	INT32 code;

public:
	ExChar() : code(0) {}
	ExChar(INT32 Code) : code(Code) {}
	ExChar(const ExChar& Sym) {this->code  = Sym.Code();}

	ExChar& operator=(INT32 Code) {this->code = Code; return *this;}
	ExChar& operator=(ExChar& Sym) {this->code = Sym.Code(); return *this;}

	INT32 Code() const {return code;}
};

class EncoderUTF
{
public:
	static UINT8 ToUtf32(LPCINT8 Sym, LPINT32 Code);
	static UINT8 ToUtf32(LPCUINT16 Sym, LPINT32 Code);
	static UINT8 ToUtf16(LPCINT32 Sym, LPUINT16 Code);
	static UINT8 ToUtf8(LPCINT32 Sym, LPINT8 Code);
};

#endif
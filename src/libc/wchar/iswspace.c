// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <wchar.h>
#include <wctype.h>

/* Our definition of whitespace is the Unicode White_Space property,
 * minus non-breaking spaces (U+00A0, U+2007, and U+202F) and script-
 * specific characters with non-blank glyphs (U+1680 and U+180E). */

int iswspace(wint_t wc)
{
    static const wchar_t spaces[] = {' ',     '\t',     '\n',     '\r',     11,     12,     0x0085, 0x2000,
                                     0x2001, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2008, 0x2009,
                                     0x200a, 0x2028, 0x2029, 0x205f, 0x3000, 0};
    return wc && wcschr(spaces, (wchar_t)wc);
}

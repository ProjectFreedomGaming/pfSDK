// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <wctype.h>

int iswcntrl(wint_t wc)
{
    return (unsigned)wc < 32 || (unsigned)(wc - 0x7f) < 33 || (unsigned)(wc - 0x2028) < 2 ||
           (unsigned)(wc - 0xfff9) < 3;
}

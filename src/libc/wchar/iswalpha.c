// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <wctype.h>

static const unsigned char table[] = {
#include "alpha.h"
};

int iswalpha(wint_t wc)
{
    if(wc < 0x20000)
    {
        return (table[(wint_t)(table[wc >> 8] * 32) + ((wc & 255) >> 3)] >> (wc & 7)) & 1;
    }
    if(wc < 0x2fffe)
    {
        return 1;
    }
    return 0;
}

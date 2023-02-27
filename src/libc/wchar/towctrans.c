// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <string.h>
#include <wctype.h>

wint_t towctrans(wint_t wc, wctrans_t trans)
{
    if(trans == (wctrans_t)1)
    {
        return towupper(wc);
    }

    if(trans == (wctrans_t)2)
    {
        return towlower(wc);
    }

    return wc;
}

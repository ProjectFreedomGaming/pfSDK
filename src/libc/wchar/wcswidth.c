// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <wchar.h>

int wcswidth(const wchar_t* wcs, size_t n)
{
    int l = 0;
    int k = 0;

    for(; n-- && *wcs && (k = wcwidth(*wcs)) >= 0; l += k, wcs++)
    {
        ;
    }

    return (k < 0) ? k : l;
}

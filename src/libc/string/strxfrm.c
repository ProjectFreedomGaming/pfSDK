// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <string.h>

size_t strxfrm(char* restrict dest, const char* restrict src, size_t n)
{
    size_t l = strlen(src);
    if(n > l)
    {
        strcpy(dest, src);
    }

    return l;
}

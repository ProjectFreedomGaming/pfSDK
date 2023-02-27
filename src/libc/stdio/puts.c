// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <stdio.h>

int puts(const char* str)
{
    int r = 0;

    for(const char* c = str; *c != 0; c++)
    {
        putchar((int)*c);
        r++;
    }

    // puts adds a newline
    if(r)
    {
        putchar('\n');
        r++;
    }

    return r ? r : EOF;
}

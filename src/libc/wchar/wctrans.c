// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <string.h>
#include <wctype.h>

wctrans_t wctrans(const char* class)
{
    if(!strcmp(class, "toupper"))
    {
        return (wctrans_t)1;
    }

    if(!strcmp(class, "tolower"))
    {
        return (wctrans_t)2;
    }

    return 0;
}

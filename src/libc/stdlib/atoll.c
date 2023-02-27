// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

long long atoll(const char* str)
{
    long long val = 0;
    bool neg = false;

    while(isspace(*str))
    {
        str++;
    }

    switch(*str)
    {
        case '-':

            neg = true;
        // Intentional fallthrough
        case '+':
            str++;
        default:
            // Intentional fallthrough
            ;
    }

    while(isdigit(*str))
    {
        val = (10 * val) + (*str++ - '0');
    }

    return neg ? -val : val;
}

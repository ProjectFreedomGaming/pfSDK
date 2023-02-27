// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <stddef.h>

char* strncat(char* dest, const char* src, size_t len)
{
    char *rdest = dest;
    
    while (*dest)
        dest++;
    
    while ((len != 0) && (*dest++ = *src++)) {
        --len;
    }

    dest[dest - rdest] = '\0';
    
    return rdest;
}

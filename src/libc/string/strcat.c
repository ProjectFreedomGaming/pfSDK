// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

char* strcat(char* dest, const char* src)
{
    char *rdest = dest;
    
    while (*dest)
        dest++;
    
    while ((*dest++ = *src++))
        ;
    
    return rdest;
}

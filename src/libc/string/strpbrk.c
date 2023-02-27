// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <string.h>

char* strpbrk(const char* s, const char* b)
{
    s += strcspn(s, b);
    return *s ? (char*)(uintptr_t)s : 0;
}

// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <string.h>

void* __attribute__((weak)) memmove(void* s1, const void* s2, size_t n)
{
    return memcpy(s1, s2, n);
}

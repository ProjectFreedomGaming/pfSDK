// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <stdlib.h>

__attribute__((weak, noreturn)) void _Exit(int ec)
{
    // __libc_fini_array

    (void)ec;

    while(1)
    {
        ;
    }
}

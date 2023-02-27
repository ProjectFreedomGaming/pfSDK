// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((noreturn, weak)) void __assert_fail(const char* expr, const char* file,
                                                   unsigned int line, const char* function)
{
    printf("Assertion failed: %s (%s: %s: %u)\r\n", expr, file, function, line);
    abort();
}

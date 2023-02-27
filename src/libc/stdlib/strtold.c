// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <stdlib.h>

long double strtold(const char* __restrict nptr, char** __restrict endptr)
{
    return (long double)strtod(nptr, endptr);
}

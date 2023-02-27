// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#define _GNU_SOURCE
#include <time.h>

char* asctime(const struct tm* tm)
{
    static char buf[26];
    return asctime_r(tm, buf);
}

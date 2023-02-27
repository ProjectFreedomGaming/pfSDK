// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <errno.h>
#include <stdlib.h>

__attribute__((weak, noreturn)) void abort(void)
{
    _Exit(ENOTSUP);
}

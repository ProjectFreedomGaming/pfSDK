// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <wctype.h>

int iswdigit(wint_t wc)
{
    return (unsigned)wc - '0' < 10;
}

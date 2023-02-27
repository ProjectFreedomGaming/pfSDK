// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <wctype.h>

int iswgraph(wint_t wc)
{
    /* ISO C defines this function as: */
    return !iswspace(wc) && iswprint(wc);
}

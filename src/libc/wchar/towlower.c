// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include "_towcase.h"
#include <ctype.h>

wint_t towlower(wint_t wc)
{
    return (wint_t)(wc < 128 ? (wint_t)tolower((int)wc) : (wint_t)__towcase((wchar_t)wc, 1));
}

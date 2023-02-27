// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Based on code Copyright 2021-2022 Tom Storey

#include <printf.h>
#include <stdio.h>

extern long write(int, const char*, unsigned long);

void _putchar(char ch)
{
    (void)write(1, &ch, 1);
}

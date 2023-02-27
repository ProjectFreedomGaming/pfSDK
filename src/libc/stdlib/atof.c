// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <stdlib.h>

double atof(const char* src)
{
    return strtod(src, NULL);
}

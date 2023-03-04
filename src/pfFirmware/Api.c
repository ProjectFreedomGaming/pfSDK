// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <pfSDK/Api.h>

#include "Io.h"
#include "Flip.h"

// -- Singleton pointer to the API functions.
pfAPI pf_content = {
    &ioPutChar,
    &flipWaitVSync,
    &flipSetClearColor,
    &flipClearScreen,
    &flipSwapBuffers
};

pfAPI *pf = &pf_content;

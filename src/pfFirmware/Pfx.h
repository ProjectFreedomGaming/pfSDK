// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __PF_FIRMWARE_PFX_H
#define __PF_FIRMWARE_PFX_H

#include "pfSDK/Types.h"

// -- Functions
void pfxWaitVSync(void);
void pfxSetClearColor(byte r, byte g, byte b);
void pfxClearScreen(void);
void pfxSwapBuffers(void);

#endif
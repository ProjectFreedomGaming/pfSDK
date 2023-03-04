// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __PF_FIRMWARE_FLIP_H
#define __PF_FIRMWARE_FLIP_H

#include "pfSDK/Types.h"

// -- Functions
void flipWaitVSync(void);
void flipSetClearColor(byte r, byte g, byte b);
void flipClearScreen(void);
void flipSwapBuffers(void);

#endif
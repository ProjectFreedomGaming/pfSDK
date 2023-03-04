// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Flip.h"

#include <pfSDK/Hardware/Registers.h>

// -- Functions
void flipWaitVSync(void)
{
    word previous_vsync = PF_READ_WORD(PF_FLIP_VSYNC_COUNT);
    while (PF_READ_WORD(PF_FLIP_VSYNC_COUNT) == previous_vsync) { }
}

void flipSetClearColor(byte r, byte g, byte b)
{
    PF_WRITE_WORD(PF_FLIP_COLOR_RG, (r << 8) | g);
    PF_WRITE_WORD(PF_FLIP_COLOR_BA, (b << 8) | 255);
}

void flipClearScreen(void)
{
    PF_WRITE_WORD(PF_FLIP_CONTROL, PF_FLIP_CONTROL_CLEAR_SCREEN);
}

void flipSwapBuffers(void)
{
    PF_WRITE_WORD(PF_FLIP_CONTROL, PF_FLIP_CONTROL_SWAP_BUFFER);    
}

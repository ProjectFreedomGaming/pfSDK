// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Pfx.h"

#include <pfSDK/Hardware/Registers.h>

// -- Functions
void pfxWaitVSync(void)
{
    word previous_vsync = PF_READ_WORD(PF_PFX1_VSYNC_COUNT);
    while (PF_READ_WORD(PF_PFX1_VSYNC_COUNT) == previous_vsync) { }
}

void pfxSetClearColor(byte r, byte g, byte b)
{
    PF_WRITE_WORD(PF_PFX1_COLOR_RG, (r << 8) | g);
    PF_WRITE_WORD(PF_PFX1_COLOR_BA, (b << 8) | 255);
}

void pfxClearScreen(void)
{
    PF_WRITE_WORD(PF_PFX1_CONTROL, PF_PFX1_CONTROL_CLEAR_SCREEN);
}

void pfxSwapBuffers(void)
{
    PF_WRITE_WORD(PF_PFX1_CONTROL, PF_PFX1_CONTROL_SWAP_BUFFER);    
}

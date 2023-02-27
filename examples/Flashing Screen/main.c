// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <pfSDK/Api.h>
#include <pfSDK/Types.h>

int main(void)
{
    byte r = 0;
    byte g = 0;
    byte b = 0;
    
    // -- main() cannot return right now.
    while(1) {
        pf->pfxWaitVSync();

        pf->pfxSetClearColor(r, g, b);
        pf->pfxClearScreen();
        
        r += 12;
        g += 4;
        b += 34;

        pf->pfxSwapBuffers();
    }

    return 0;
}

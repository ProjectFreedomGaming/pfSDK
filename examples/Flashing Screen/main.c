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
        pf->flipWaitVSync();

        pf->flipSetClearColor(r, g, b);
        pf->flipClearScreen();
        
        r += 12;
        g += 4;
        b += 34;

        pf->flipSwapBuffers();
    }

    return 0;
}

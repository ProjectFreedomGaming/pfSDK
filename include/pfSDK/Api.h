// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef __PF_API_H
#define __PF_API_H

#include <pfSDK/Types.h>

// -- List of all API functions available in the BootRom.
// -- The order of these methods CANNOT change after release to preserve backward compatibility.
typedef struct pfAPI
{
    void (*ioPutChar)(char c);
    void (*flipWaitVSync)(void);
    void (*flipSetClearColor)(byte r, byte g, byte b);
    void (*flipClearScreen)(void);
    void (*flipSwapBuffers)(void);
} pfAPI;

// -- Singleton pointer to the API functions.
extern pfAPI* pf;

#endif

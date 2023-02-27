// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include "Io.h"

#include <pfSDK/Hardware/Registers.h>

// -- Functions
void ioPutChar(char c)
{
    PF_WRITE_WORD(PF_IO_SYM_LOG_CHAR, c);
}

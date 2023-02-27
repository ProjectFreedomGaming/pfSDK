// SPDX-FileCopyrightText: 2023-present pfSimulator contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PF_HW_REGISTERS_H
#define PF_HW_REGISTERS_H

#include "pfSDK/Types.h"
#include "pfSDK/Hardware/Memory.h"

// -- Macros
#define PF_READ_WORD(offset)            *(volatile word*)(PF_CUSTOM_CHIPS_BASE + (pointer)offset)
#define PF_WRITE_WORD(offset, value)    *(volatile word*)(PF_CUSTOM_CHIPS_BASE + (pointer)offset) = value

// -- IO
#define PF_IO_SYM_LOG_CHAR              PF_IO_BASE + (pointer)0x00000000

// -- PFX1
#define PF_PFX1_STATUS                  PF_PFX1_BASE + (pointer)0x00000000
#define PF_PFX1_CONTROL                 PF_PFX1_BASE + (pointer)0x00000002
#define PF_PFX1_VSYNC_COUNT             PF_PFX1_BASE + (pointer)0x00000004
#define PF_PFX1_COLOR_RG                PF_PFX1_BASE + (pointer)0x00000006
#define PF_PFX1_COLOR_BA                PF_PFX1_BASE + (pointer)0x00000008

// -- PFX1 CONTROL REGISTER
#define PF_PFX1_CONTROL_CLEAR_SCREEN    0x0001
#define PF_PFX1_CONTROL_SWAP_BUFFER     0x0002

#endif

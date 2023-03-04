// SPDX-FileCopyrightText: 2023-present pfSimulator contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef PF_HW_MEMORY_H
#define PF_HW_MEMORY_H

// -- Total RAM is 16Mb
#define PF_TOTAL_RAM               (1024 * 1024 * 16)

#define PF_EVT_SIZE                (64*4)

// -- Registers base addresses
#define PF_CUSTOM_CHIPS_BASE            (pointer)0x00FFC000
#define PF_IO_BASE                      (pointer)0x00000000
#define PF_FLIP_BASE                    (pointer)0x00003000

#endif

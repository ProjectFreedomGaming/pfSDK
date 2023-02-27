# SPDX-FileCopyrightText: 2023-present pfSDK contributors
#
# SPDX-License-Identifier: GPL-3.0-or-later

all:
	@$(MAKE) -C crt0
	@$(MAKE) -C libc
	@$(MAKE) -C pfFirmware

clean:
	@$(MAKE) -C crt0 clean
	@$(MAKE) -C libc clean
	@$(MAKE) -C pfFirmware clean

install:
	@$(MAKE) -C crt0 install
	@$(MAKE) -C libc install
	@$(MAKE) -C pfFirmware install

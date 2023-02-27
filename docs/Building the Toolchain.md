# Building the toolchain

You should **NOT** have to build the toolchain yourself since the binaries for the MC68000 toolchains are already provided in the `bin` folder. You may need to rebuild those to, for example, update them to new version or fix issues with different OS versions.

### Building on macOS

First if you don't already have **brew** installed, head over to [its website](https://brew.sh) and install it. You'll also need a [supported](Installing%20Python.md) version of Python.

A build script `pfBuildToolChain` is provided in the bin folder. It takes a destination folder as its single argument and will created a folder named `pfSDKToolchain` inside that folder with the build results. Be careful that the destination folder does not contain any spaces sin its path.

The resulting executables can then be found in `pfSDKToolchain/m68k-eabi-elf`.

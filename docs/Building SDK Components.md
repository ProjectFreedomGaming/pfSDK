# Building SDK Components

The SDK is made of 3 main components: **libc**, **crt0** and **pfFirmware**. You shouldn't need to modify those during regular development, but you're more than welcome to if you want **:)**

### crt0

`crt0` handles bootstrapping the **68000** when the `pfx` starts or reboots.

Its source code is located in `src/crt0`. Using a **Terminal** window you can just `cd` into this folder and simply do:

```console
make
```

If you want a clean start, you can clean the build folder with:
```
make clean
```

and if you want to use you modification in a project you can install the new `crt0` with:
```
make install
```

### libc

`libc` is a bare bones standard C library which contains things like string, math and input output methods.

The source code is located in `src/libc`. Using a **Terminal** window you can just `cd` into this folder and simply do:

```console
make
```

If you want a clean start, you can clean the build folder with:
```
make clean
```

and if you want to use you modification in a project you can install the new `libc` with:
```
make install
```

### pfFirmware

`pfFirmware` contains the actual SDK API implementation. It is currently linked with the rom file used for the application but will eventually be part of the firmware built in to the `pfx` core.

The source code is located in `src/pfFirmware`. Using a **Terminal** window you can just `cd` into this folder and simply do:

```console
make
```

If you want a clean start, you can clean the build folder with:
```
make clean
```

and if you want to use you modification in a project you can install the new `pfFirmware` with:
```
make install
```

### Building everything

To build all the components at once by `cd` into the `src` folder and using the same `make`, `make clean` and `make install` commands.


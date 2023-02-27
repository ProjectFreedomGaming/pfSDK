# Getting Started

### Installing the SDK

You will need a [supported](Installing%20Python.md) version of **Python** and then make sure your environment is setup correctly.

### Installing on macOS

In order to setup the environment, you can simply add the following to your `.zshrc` file:

```
# -- Setup path to pfSDK
. ~/Documents/Code/Project\ Freedom/pfSDK/bin/macOS/pfSetupEnv.sh
```

### Making your first project

The examples folder contains some simple projects that may help you get started in the beginning.

Let's look at the `Flashing Screen` example. The project folder contains a source `.c` file for the code and a `Makefile` to build the project.

The source code for this example is pretty simple:
```c
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
```

After including the required headers for the api and some custom types, we need to define at least on function named `main()`. The function doesn't take any arguments at the moment. It returns a non-zero value if something went wrong but for the time being, returning from `main()` is actually an undefined behavior so in this example we never return.

Inside `main()` we do a few things and call some api functions. `pf` is the main pointer for the table of all api functions.

In order to build the project we also have a `Makefile`:
```
# -- Name of the rom we are building.
ROM_TARGET = flashingscreen.pfxrom

# -- Finally the common makefile should be included last.
include $(PF_SDK_ROOT)/src/common.mk
```

The makefile system from the **SDK** takes care of a lot of the heavy lifting here. All that is needed is to specify the name of the rom as `ROM_TARGET` and then include the **SDK**'s comman makefile.

You can build your project by opening a terminal window in your porject folder and simply typing:
```console
make
```

This will automatically make a rom inside a build folder named `_build` using any `.c` or `.S` found in your project's folder or any subfolder.

To test your project, you can run it under the simulator by typing:
 ```
 make sim
 ```

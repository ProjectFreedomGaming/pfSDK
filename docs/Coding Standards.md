## Introduction

This documents describes the **pfSDK** coding standards. Some of it comes from experience, some of it is arbitrary and was only chosen because of personal preferences.

Either way, it is the law of the land and must be strictly adhered to when contributing code to **pfSDK**. This document may be modified at times to reflect any changes or evolutions.

If existing code and this document differ, this document is the prevailing authority and the code should be updated.

## Overall Philosophy

The main points dictating the overall philosophy for the **pfSDK** are:

* **Be consistent:** Sticking to this document will help in that respect but in general, stick to one style/method/process. Code should be easy to navigate because it is consistent and familiar.
* **Fail early:** If something has gone wrong or is not the way it should be, don't assume calling code will deal with the situation. Fail early and fail hard to prevent unpredictable states or behavior.
* **Make your code defensive**: Don't assume any state, any input or any return values. Unless something is documented and guaranteed to work a specific way, test it and assert to make sure it is even if it's just in debug builds.
* **Don't let your API be used incorrectly:** Function signatures should be non-ambiguous to make sure users of your classes cannot use them incorrectly. Be verbose, be descriptive and don't allow arguments to have multiple meanings/uses.
* **Don't live with broken windows:** Formatting, naming and any other standards can be a pain sometimes. But committing code that doesn't adhere to the standard or that contains some hack of some sort is an invitation for others to think it's ok to do it too. Fix it before you commit your code.
* **Don't repeat yourself:** Duplicated code makes it harder to debug, optimise and read the code. Fixes and optimisations also have to be applied in multiple places. Copies of the same code can be made easier to read by all calling the same function instead.

## Style & Formatting

### Files

* **Header files** use the `.h` extension.
* **Source files** use the `.c`, `.s` or `.S` extensions for **C**, **assembly** and **pre-processed assembly** respectively.

#### Standard header

This is the standard header used by the **pfSDK**:

```
// SPDX-FileCopyrightText: 2023-present pfSDK contributors
//
// SPDX-License-Identifier: GPL-3.0-or-later
```

### Naming conventions

* **Function** use the `lowerCamelCase` convention.
* **Variables** use the `snake_case` convention.
* **Static/Local Functions and Variables** are prefixed with '_'.
* **Struct names** use the `UpperCamelCase`.
* **Macros** use the `UPPER_CASE_SNAKE` convention.
* **Enums** values have the prefix `k` and use `UpperCamelCase` as in `kValueName`.
* **Use meaningful, pronounceable and intention revealing names for functions and variables**. Function names should always read like actions and variables like object names.
* **Don't use short form or single letter names for variables.** Everything should be spelled out.
* **Function names should try to explain the arguments used after them.** C doesn't support named arguments. This makes code very hard to read when looking at a calling function since arguments after the first one do not have any context. Therefore, we try to add the description in the function name itself:
* **SDK function and types are prefixed** with `pf`.
* **SDK macros are prefixed** with `PF_`.

```
// --- Like this
void processElementAndLogMessagesIn(const Element* element, MessageLog* log)
{
    int start_index = 0;
    for (int index = start_index; index < 12; ++index) {
        ...
    }
}

// --- NOT like this
void process(const Element* element, MessageLog* log)
{
    int idx = 0;
    for (int i = idx; i < 12; ++i) {
        ...
    }
}
```

While this can get pretty hard to read past a certain number of arguments, it highlights a good reason for functions to only have up to two or three arguments if possible (See below in the **Coding Conventions** section).

### Whitespace

* **Tabs** are 4 characters and should be spaces only.
* **Line-endings** should be OS X/UNIX (LF).
* **Last line of all files should be a newline.** Some compilers, like clang, complain if that's not the case.
* **Pointer symbols** should be attached to the type:

```
character* otherVar = NULL;       // --- Like this
MyType* aFunction(MyOtherType* aVar);

character *otherVar = NULL;       // --- NOT like this
MyType *aFunction(MyOtherType *aVar);
```

### Code Layout

* **`{ }` are always required for blocks**, even single lines or the cases content in switch statements.
* **Function declaration** use curly brackets on separate lines:
```
void myFunction()
{
    ...
}
```

* **statements** use an open curly bracket on the same like as the statement and have a space between them and the parenthesis:

```
if (true) {
    ...
}
else {
    ...
}

while (1) {
    ...
}

for (...) {
    ...
}

switch (c) {
    case 0: {
        ...
        break;
    }
    case 1: {
        ...
        break;
    }
    default: {
        ...
    }
}
```

* **`return` statements** don't use any parenthesis.

```
// --- Like this
return local_log.count == 3;

// --- NOT like this
return (local_log.count == 3);
```

* **Do not to declare multiple pointers on one line**, even if they have the same type. This will makes it visually go against having the `*` symbols being attached to the type name and not the variable. Regular local variables (i.e. not pointers) can be defined on one line.

```
// --- Like this
Type* one_reference;
Type* another_Reference;

// --- NOT like this
Type* one_reference, *another_reference;
```

* **Keep vertical distance short.** Concepts that are closely related should be kept close together. This takes precedence over line length. While being able to compare files side by side is useful is a few limited cases, we prefer to **NOT** to put a hard limit on line length. A soft limit is set at 120 characters but again, vertical distance for readability is more important that artificially staying below this limit.
* **When local variables are used in `if ()`, `for ()` or `return` statements**, they should be initialized on the line right above those statements, if possible, with no blank line between the two.

```
// --- Like this
const char* messages = local_log.messages;
for (int index = 0; index < 10; ++index) {
    char text = message[index];
    if (text == '\0') {
        ...
    }
}

int count = local_log.count;
printf("%ld", count);

const char* result = local_log.warning_as_string;
return result;

// --- NOT like this
int count = local_log.count;
const char* messages = local_log.messages;

for (int index = 0; index < 10; ++index) {
    char text = message[index];

    if (text == '\0') {
        ...
    }
}

printf("%ld", count);

return local_log.warning_as_string;
```

* **Limit Variable Scope.** Similarly to trying to limit vertical distance, objects should not stay around longer than they need to so variables should always be declared as late as possible. Any variables only used inside a given scope should be declared inside that scope, unless the scope is a loop and the variable's value is unaffected by the loop in which case it is more optimal to declare the object outside of the loop.

```
// --- Like this
Formatter formatter = newFormatter();
for (int index = 0; index < 10; ++index) {
    const char* formatted_version = formatter.format(test[index]);
    ...
}

// --- NOT like this
const char* formatted_version = NULL;
for (int index = 0; index < 10; ++index) {
    Formatter formatter = newFormatter();

    formatted_version = formatter.format(test[index]);
    ...
}
```

* **Local variables can be used to store returned values** from functions to help document the code. Naming the variable can help the reader understand what intent is and contributes to make the code read like a sentence.

```
// --- Like this
const char* formattedText = newStringByFormatting("Hello");
log.addMessage(formattedText);

// --- Instead of like this
log.addMessage(newStringByFormatting("Hello"));
```

Performance critical code may avoid doing this though, in order to avoid creating a variable on the stack.

### Includes

* **Header files** should always contains a include guard macro, named after the file it is in, at the top level underneath the file header. The macro has a prefix of two underscores.

```
#ifndef __PF_ASSERT_H
#define __PF_ASSERT_H

...

#endif
```

* `<>` should be used for includes SDK paths, always including the top folder/module name for the include file.

```
// --- Like this
#include <pfSDK/Memory.h>

// --- NOT like this
#include "Memory.h"
```

* **Includes should be placed in reverse order of locality** with other modules/libs first, same library/module second and finally system includes last. This helps insure that application headers are more likely to include any dependencies/forward declarations they need and not get those dependencies resolved by chance from previous include statements.
* **Group includes by module** and separate each group by a blank line.  
* **Each module/library should have a single include file**, named after the module or library and which includes all the relevant include files for that module/library.
* **Forward declare** in header files, underneath all include statements, when possible instead of including, to reduce include complexity.
* For example, in a file from the `Persistence` library:

```
#include <Persistence/PersistentObject.hpp>

#include <ParentFolder/DecimalNumber.hpp>
#include <ParentFolder/String.hpp>

#include <stdio.h>

// -- Forward Declarations
typedef struct PersistentContext PersistentContext;    
```

## Code Conventions

### Functions

* **Functions should be small**, have ideally 2-3 arguments at the most, do only one thing and have no hidden side effects.

### Memory Management & Pointers

* **Try no to use static/global data.** This can cause issues with multi-threading and is a good rule even if the code is not multi-threaded.

### Miscellaneous

* **Always use pre-increment operator instead of the post increment, when possible.** Pre-increment is often [faster](http://blog2.emptycrate.com/content/why-i-faster-i-c) than post-increment. This is usually optimized nowadays but it's a good habit to retain if the chronology of the increment does not matter.
* **Boolean tests do not test against `true` or `false`** and should just use `!` or nothing.

```
    // --- Like this
    if (!correct) {
        ...
    }
    else if (finished) {
        ...
    }

    // --- NOT like this
    if (correct == false) {
        ...
    }
    else if (finished == true) {
        ...
    }
```

* **Pointers tests always test against `NULL`** and should not just use `!` or nothing.

```
    // --- Like this
    if (correct == NULL) {
        ...
    }
    else if (finished != NULL) {
        ...
    }

    // --- NOT like this
    if (!correct) {
        ...
    }
    else if (finished) {
        ...
    }
```


### Comments

* **Code comments should use `// -- My comment.`** and not the block notation `/* ... */`. This allows for easily commenting out block of code during development.
* **Avoid using comments**. Comments are just lies waiting to happen because they usually rot faster than the code itself. Comments can be used for macro-level documentation but definitely not for explaining step by step how code works.
* **Let the code be the comments** by using descriptive names and break up code into sub-functions instead.

```
// --- Like this
float time_in_seconds = 0.0f;

if (!found_items) {
    parseItemsInList(list);

    time = time + 1.0f;
    ...
}

// --- NOT like this
// -- Time in seconds
float time = 0.0f;

// -- If we found some items
if (!found) {
    int c = 0;

    // -- We go thru every item and parse it
    for (int i = 0; i < 20; ++i) {
        item[i]->parse();
    }

    // -- We increment the time
    time = time + 1.0f;
    ...
}
```

* **Using comments for TODO is ok**. They can even be committed to source control.

```
// -- TODO: Optimise this.
```

* **Use comments only to explain context.** When something is non-obvious or might not seem logical at first sight.

```
File* file = newFile(this->filePath->asUTF8());
...

// -- This is misleading. It doesn't actually save anything to disk.
// -- Instead, real saving takes place when the file is closed. #ugh
file->save();
```

## Source Control & Versioning

* **Always commit one change at a time.** Don't do huge mega commits with tons of different changes in them. If, while developing something, you find the need for some other new functionality then stash your changes, commit the new functionality and pick back up the original change afterward.
* **Do not commit code with commented out sections**, or code that doesn't build or code that doesn't pass all the unit tests.
* **Use [git-flow](http://nvie.com/posts/a-successful-git-branching-model/)**. Many git clients support it natively.
* **Always work in a local branch** and not in the develop branch directly.
* **Use Semver version numbers** that are in the form x.y.z(b) where x is the main version number (1-~), y is the feature number (0-~), z is the hot fix number (0-~) and b is the build number.
* **Increase the feature number** if the change contains new features with or without bug fixes.
* **Increase the hot fix number** if the change only contains bug fixes.
* **Increase the build number** at every new user-facing build.
* **Unless you have direct push access** you should push your changes and commits via a pull request. Pull requests should only contain commits related to one task and only one task.

## Development Rules

* **Use tracer bullets.** When developing new systems, and especially collections of interconnected systems that depend on each other. Try to get a dumbed-down stubbed version of the overall system working right away. Things can be hardcoded to begin with, a lot of functionality could be missing but aim to get a working system as quickly as possible.
* **Try to keep existing code running at all times.** Don't embark on a huge task that will break your local codebase for days. Try to break up the task into smaller ones that can each be implemented while keeping the code, and the unit tests if any, working.

## Compilation

* **All compiler warnings or static analyser warnings** should be treated as errors.

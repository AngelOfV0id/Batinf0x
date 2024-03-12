# Batinf0x

**[EN](README.md) / [RU](README-RU.md)**

**Batinf0x** is a tiny console utility for Windows which
displays some information about the system battery and AC power status.\
It is written in pure C and uses `GetSystemPowerStatus()` function
to read the required information.\
I have written this utility just for fun, no more.

GCC, TCC or any other good C compiler is required to build the program.
After setting up compiler, then configure and run `make.bat` script.

Run `batinf0x -v` or `batinf0x --version` to display program version.

**Batinf0x** is a free and open source software and is distributed
under the terms of [The Unlicense](unlicense.txt).

Here is an example of Batinf0x console output:

```
AC power: offline.
Battery is discharging.
Battery life: 99% - high.
Battery life time: 03:08:48.
```
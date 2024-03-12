@echo off

set VERSION=\"1.0\"
set CC=tcc
set DEFINES=-DVERSION=%VERSION%
set ARCH=-m32
set LIBS=
set CCFLAGS=%ARCH% %LIBS% %DEFINES%
set SOURCE=batinf0x.c
set TARGET=batinf0x.exe

set COMMAND=%CC% %SOURCE% %CCFLAGS% -o %TARGET%

echo %COMMAND%
%COMMAND%

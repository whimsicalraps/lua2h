# Compile .lua to .luac and store in (C style) .h

Simple utility program for including compiled lua code in C projects.

Most of this is covered by luac, but in order to wrap the resulting
binary data in a c header it seemed easier to just do the compilation
directly. Key benefit is that the length of the chunk is returned as
part of the lua_dump process plus the process of compiling is dead
simple.

Principally this is useful in a context where you don't have a FS
and can't use fopen fwrite libc functions. This is relevant to the
crow project running on an Cortex-M microcontroller with no FS.

Usage:
lua2h <output_file>.h <input_file>.lua

Makes a separate header file for each lua file, each containing:

```
#pragma once

char[] output_file     = {the, chunks};
int    output_file_len = length;
```

Your program can then just `#include <output_file>.h` then use
#include <output_file.h>
luaL_loadbuffer(L, <output_file>
                 , <output_file_len>
                 , "output_file"
                 );
lua_pcall(L,0,0,0);

# Notes on GDB and Valgrind

## Compiling code

Compile with the `-g` flag to include debugging information.

```bash
gcc -Wall -g *.c -o <executable-name>
```

## Using GDB

To debug the executable `my_program`, run
```bash
gdb ./my_program
```

You will be presented with a gdb prompt, for example
```
GNU gdb (Ubuntu 8.1-0ubuntu3.2) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./linked_list...done.
(gdb) _
```

Type `run` to start the program.

## GDB Commands

- `help` - general help
- `help <command>` - help with a specific command
- `run` - start running the program
- `where` - print the stack trace
- `p v` (or `print`) - prints value of variable `v`
- `s` (or `step`) - go to next instruction, "step" into functions
- `n` (or `next`) - go to next instruction, don't step into functions.
- `c` (or `continue`) - resume execution`

See [this gdb cheatsheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf) for more commands.

# Using Valgrind to check for memory errors

Among other things, valgrind can examine your program for memory leaks (allocating without freeing), and reading/writing
from memory that the program does not have access to.

To run the leak check, and print all errors, run
```bash
valgrind -v --leak-check=full --show-leak-kinds=all <program-name>
```


# Hello World, C!

This is the first project made with C and consists of knowing some of its bases.

# Learning Objectives

* Why C programming is awesome
* Who invented C
* Who are Dennis Ritchie, Brian Kernighan and Linus Torvalds
* What happens when you type gcc main.c
* What is an entry point
* What is main
* How to print text using printf, puts and putchar
* How to get the size of a specific type using the unary operator sizeof
* How to compile using gcc
* What is the default program name when compiling with gcc
* What is the official Holberton C coding style and how to check your code with betty-style
* How to find the right header to include in your source code when using a standard library - function
* How does the main function influence the return value of the program

# Tasks

## Preprocessor

Write a script that runs a C file through the preprocessor and save the result into another file.

* The C file name will be saved in the variable `$CFILE`
* The output should be saved in the file `c`

**Solution:** [0-preprocessor](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/0-preprocessor)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.c 
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/0x00$ export CFILE=main.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./0-preprocessor 
$ amonkeyprogrammer@ubuntu:~/c/0x00$ tail c
# 942 "/usr/include/stdio.h" 3 4

# 2 "main.c" 2


# 3 "main.c"
int main(void)
{
 return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/0x00$ 
```

## Compiler

Write a script that compiles a C file but does not link.

* The C file name will be saved in the variable `$CFILE`
* The output file should be named the same as the C file, but with the extension `.o` instead of `.c`. 
    * Example: if the C file is `main.c`, the output file should be `main.o`

**Solution:** [1-compiler](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/1-compiler)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ export CFILE=main.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./1-compiler 
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ls
0-preprocessor  1-compiler   c            main.o
Makefile               100-intel      main.c  main.s
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat -v main.o | head
^?ELF^B^A^A^@^@^@^@^@^@^@^@^@^A^@>^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^P^B^@^@^@^@^@^@^@^@^@^@@^@^@^@^@^@@^@^K^@^H^@UHM-^IM-eM-8^@^@^@^@]M-C^@GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609^@^T^@^@^@^@^@^@^@^AzR^@^Ax^P^A^[^L^G^HM-^P^A^@^@^\^@^@^@^\^@^@^@^@^@^@^@^K^@^@^@^@A^N^PM-^F^BC^M^FF^L^G^H^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^D^@M-qM-^?^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^B^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^E^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^F^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^C^@^D^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^H^@^@^@^R^@^A^@^@^@^@^@^@^@^@^@^K^@^@^@^@^@^@^@^@main.c^@main^@^@^@^@ ^@^@^@^@^@^@^@^B^@^@^@^B^@^@^@^@^@^@^@^@^@^@^@^@.symtab^@.strtab^@.shstrtab^@.text^@.data^@.bss^@.comment^@.note.GNU-stack^@.rela.eh_frame^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^[^@^@^@^A^@^@^@^F^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@@^@^@^@^@^@^@^@^K^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@!^@^@^@^A^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@K^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@'^@^@^@^H^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@K^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@,^@^@^@^A^@^@^@0^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@K^@^@^@^@^@^@^@5^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@5^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@J^@^@^@^A^@^@^@^B^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-^@^@^@^@^@^@^@^@8^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^H^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@E^@^@^@^D^@^@^@@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M- ^A^@^@^@^@^@^@^X^@^@^@^@^@^@^@    ^@^@^@^F^@^@^@^H^@^@^@^@^@^@^@^X^@^@^@^@^@^@^@^Q^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-8^A^@^@^@^@^@^@T^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^B^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-8^@^@^@^@^@^@^@M-X^@^@^@^@^@^@^@
^@^@^@^H^@^@^@^H^@^@^@^@^@^@^@^X^@^@^@^@^@^@^@  ^@^@^@^C^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@M-^P^A^@^@^@^@^@^@^M^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@$ amonkeyprogrammer@ubuntu:~/c/0x00$
```

## Assembler

Write a script that generates the assembly code of a C code and save it in an output file.

* The C file name will be saved in the variable `$CFILE`
* The output file should be named the same as the C file, but with the extension `.s` instead of `.c`. 
    * Example: if the C file is `main.c`, the output file should be `main.s`

**Solution:** [2-assembler](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/2-assembler)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ export CFILE=main.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./2-assembler
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ls
0-preprocessor  1-compiler  2-assembler c  main.c  main.s  Makefile
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.s
    .file   "main.c"
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    pushq   %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp
    .cfi_def_cfa_register 6
    movl    $0, %eax
    popq    %rbp
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
    .section    .note.GNU-stack,"",@progbits
$ amonkeyprogrammer@ubuntu:~/c/0x00$
```

## Name

Write a script that compiles a C file and creates an executable named `cisfun`.

* The C file name will be saved in the variable `$CFILE`

**Solution:** [3-name](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/0-preprocessor)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ export CFILE=main.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./3-name 
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ls
0-preprocessor  1-compiler   3-name  cisfun  main.o  Makefile
100-intel       2-assembler  c       main.c  main.s
$ amonkeyprogrammer@ubuntu:~/c/0x00$
```

## Hello, puts

Write a C program that prints exactly `"Programming is like building a multilingual puzzle`, followed by a new line.

* Use the function `puts`
* You are not allowed to use `printf`
* Your program should end with the value `0`

**Solution:** [4-puts.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/4-puts.c)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ gcc 4-puts.c && ./a.out
"Programming is like building a multilingual puzzle
$ amonkeyprogrammer@ubuntu:~/c/0x00$ echo $?
0
$ amonkeyprogrammer@ubuntu:~/c/0x00$ 
```

## Hello, printf

Write a C program that prints exactly `with proper grammar, but the outcome is a piece of art,`, followed by a new line.

* Use the function `printf`
* You are not allowed to use the function `puts`
* Your program should return `0`
* Your program should compile without warning when using the `-Wall gcc` option

**Solution:** [5-printf.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/5-printf.c)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ gcc -Wall 5-printf.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./a.out 
with proper grammar, but the outcome is a piece of art,
$ amonkeyprogrammer@ubuntu:~/c/0x00$ echo $?
0
$ amonkeyprogrammer@ubuntu:~/c/0x00$ 
```

## Size is not grandeur, and territory does not make a nation

Write a C program that prints the size of various types on the computer it is compiled and run on.


* You should produce the exact same output as in the example
* Warnings are allowed
* Your program should return `0`
* You might have to install the package `libc6-dev-i386` on your Linux (Vagrant) to test the `-m32 gcc` option

**Solution:** [6-size.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/6-size.c)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ gcc 6-size.c -m32 -o size32 2> /tmp/32
$ amonkeyprogrammer@ubuntu:~/c/0x00$ gcc 6-size.c -m64 -o size64 2> /tmp/64
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./size32
Size of a char: 1 byte(s)
Size of an int: 4 byte(s)
Size of a long int: 4 byte(s)
Size of a long long int: 8 byte(s)
Size of a float: 4 byte(s)
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./size64
Size of a char: 1 byte(s)
Size of an int: 4 byte(s)
Size of a long int: 8 byte(s)
Size of a long long int: 8 byte(s)
Size of a float: 4 byte(s)
$ amonkeyprogrammer@ubuntu:~/c/0x00$ echo $?
0
$ amonkeyprogrammer@ubuntu:~/c/0x00$
```

## Intel

Write a script that generates the assembly code (Intel syntax) of a C code and save it in an output file.

* The C file name will be saved in the variable `$CFILE`.
* The output file should be named the same as the C file, but with the extension `.s` instead of `.c`.
    * Example: if the C file is `main.c`, the output file should be `main.s`

**Solution:** [100-intel](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/100-intel)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ export CFILE=main.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.c
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./100-intel 
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat main.s
    .file   "main.c"
    .intel_syntax noprefix
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    push    rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    mov rbp, rsp
    .cfi_def_cfa_register 6
    mov eax, 0
    pop rbp
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
    .section    .note.GNU-stack,"",@progbits
$ amonkeyprogrammer@ubuntu:~/c/0x00$ 
```

## UNIX is basically a simple operating system, but you have to be a genius to understand the simplicity

Write a C program that prints exactly `and that piece of art is useful" - Dora Korpar, 2015-10-19`, followed by a new line, to the standard error.

* You are not allowed to use any functions listed in the NAME section of the man (3) `printf` or man (3) `puts`
* Your program should return 1
* Your program should compile without any warnings when using the `-Wall gcc` option

**Solution:** [101-quote.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/101-quote.c)

```
$ amonkeyprogrammer@ubuntu:~/c/0x00$ gcc -Wall -o quote 101-quote.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./quote
and that piece of art is useful" - Dora Korpar, 2015-10-19
$ amonkeyprogrammer@ubuntu:~/c/0x00$ echo $?
1
$ amonkeyprogrammer@ubuntu:~/c/0x00$ ./quote 2> q
$ amonkeyprogrammer@ubuntu:~/c/0x00$ cat q
and that piece of art is useful" - Dora Korpar, 2015-10-19
$ amonkeyprogrammer@ubuntu:~/c/0x00$ grep printf < 101-quote.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ grep put < 101-quote.c
$ amonkeyprogrammer@ubuntu:~/c/0x00$ 
```

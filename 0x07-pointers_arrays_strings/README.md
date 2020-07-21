# Even more pointers, arrays and strings

# Learning Objectives

* What are pointers to pointers and how to use them
* What are multidimensional arrays and how to use them
* What are the most common C standard library functions to manipulate strings

# Tasks

## memset

Write a function that fills memory with a constant byte.

* Prototype: `char *_memset(char *s, char b, unsigned int n);`
* The `_memset()` function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `b`
* Returns a pointer to the memory area `s`

**Solution:** [0-memset.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/0-memset.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
        unsigned int i;

        i = 0;
        while (i < size)
        {
                if (i % 10)
                {
                        printf(" ");
                }
                if (!(i % 10) && i)
                {
                        printf("\n");
                }
                printf("0x%02x", buffer[i]);
                i++;
        }
        printf("\n");
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0x00};

    simple_print_buffer(buffer, 98);
    _memset(buffer, 0x01, 95);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);    
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-memset.c -o 0-memset
$ amonkeyprogrammer@ubuntu:~/0x07$ ./0-memset 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
-------------------------------------------------
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01 0x01
0x01 0x01 0x01 0x01 0x01 0x00 0x00 0x00
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## memcpy

Write a function that copies memory area.

* Prototype: `char *_memcpy(char *dest, char *src, unsigned int n);`
* The `_memcpy()` function copies `n` bytes from memory area `src` to memory area `dest`
* Returns a pointer to `dest`

**Solution:** [1-memcpy.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/1-memcpy.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 1-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", buffer[i]);
        i++;
    }
    printf("\n");
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0};
    char buffer2[98] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    simple_print_buffer(buffer, 98);
    _memcpy(buffer + 50, buffer2, 10);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);    
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-memcpy.c -o 1-memcpy
$ amonkeyprogrammer@ubuntu:~/0x07$ ./1-memcpy 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
-------------------------------------------------
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x01 0x02 0x03 0x04 0x05 0x07 0x07 0x08 0x09 0x0a
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## strchr

Write a function that locates a character in a string.

* Prototype: `char *_strchr(char *s, char c);`
* Returns a pointer to the first occurrence of the character `c` in the string `s`, or `NULL` if the character is not found

**Solution:** [2-strchr.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/2-strchr.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 2-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello";
    char *f;

    f = _strchr(s, 'l');

    if (f != NULL)
    {
        printf("%s\n", f);
    }
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-strchr.c -o 2-strchr
$ amonkeyprogrammer@ubuntu:~/0x07$ ./2-strchr 
llo
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## strspn

Write a function that gets the length of a prefix substring.

* Prototype: `unsigned int _strspn(char *s, char *accept);`
* Returns the number of bytes in the initial segment of `s` which consist only of bytes from `accept`

**Solution:** [3-strspn.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/3-strspn.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 3-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "oleh";
    unsigned int n;

    n = _strspn(s, f);
    printf("%u\n", n);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 3-main.c 3-strspn.c -o 3-strspn
$ amonkeyprogrammer@ubuntu:~/0x07$ ./3-strspn 
5
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## strpbrk

Write a function that searches a string for any of a set of bytes.

* Prototype: `char *_strpbrk(char *s, char *accept);`
* The `_strpbrk()` function locates the first occurrence in the string `s` of any of the bytes in the string `accept`
* Returns a pointer to the byte in `s` that matches one of the bytes in `accept`, or `NULL` if no such byte is found

**Solution:** [4-strpbrk.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/4-strpbrk.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 4-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strpbrk(s, f);
    printf("%s\n", t);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 4-main.c 4-strpbrk.c -o 4-strpbrk
$ amonkeyprogrammer@ubuntu:~/0x07$ ./4-strpbrk 
llo, world
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## strstr

Write a function that locates a substring.

* Prototype: `char *_strstr(char *haystack, char *needle);`
* The `_strstr()` function finds the first occurrence of the substring `needle` in the string `haystack`. The terminating null bytes (`\0`) are not compared
* Returns a pointer to the beginning of the located substring, or `NULL` if the substring is not found.

**Solution:** [5-strstr.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/5-strstr.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 5-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strstr(s, f);
    printf("%s\n", t);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 5-main.c 5-strstr.c -o 5-strstr
$ amonkeyprogrammer@ubuntu:~/0x07$ ./5-strstr 
world
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## Chess is mental torture

Write a function that prints the chessboard.

* Prototype: `void print_chessboard(char (*a)[8]);`

**Solution:** [7-print_chessboard.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/7-print_chessboard.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 7-main.c 
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char board[8][8] = {
        {'r', 'k', 'b', 'q', 'k', 'b', 'k', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'K', 'B', 'Q', 'K', 'B', 'K', 'R'},
    };
    print_chessboard(board);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 7-main.c 7-print_chessboard.c -o 7-print_chessboard
$ amonkeyprogrammer@ubuntu:~/0x07$ ./7-print_chessboard 
rkbqkbkr
pppppppp




PPPPPPPP
RKBQKBKR
$ amonkeyprogrammer@ubuntu:~/c/curriculum_by_$ amonkeyprogrammer/holbertonschool-low_level_programming/0x07$
```

## The line of life is a ragged diagonal between duty and desire

Write a function that prints the sum of the two diagonals of a square matrix of integers.

* Prototype: `void print_diagsums(int *a, int size);`
* Format: see example
* You are allowed to use the standard library

Note that in the following example we are casting an `int[][]` into an `int*`. This is not something you should do. The goal here is to make sure you understand how an array of array is stored in memory.

**Solution:** [8-print_diagsums.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/8-print_diagsums.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 8-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int c3[3][3] = {
        {0, 1, 5},
        {10, 11, 12},
        {1000, 101, 102},
    };
    int c5[5][5] = {
        {0, 1, 5, 12124, 1234},
        {10, 11, 12, 123521, 12512},
        {1000, 101, 102, 12545, 214543435},
        {100, 1012451, 11102, 12545, 214543435},
        {10, 12401, 10452, 11542545, 1214543435},
    };
    print_diagsums((int *)c3, 3);
    print_diagsums((int *)c5, 5);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 8-main.c 8-print_diagsums.c -o 8-print_diagsums
$ amonkeyprogrammer@ubuntu:~/0x07$ ./8-print_diagsums 
113, 1016
1214556093, 1137318
$ amonkeyprogrammer@ubuntu:~/0x07$
```

## Double pointer, double fun

Write a function that sets the value of a pointer to a char.

* Prototype: `void set_string(char **s, char *to);`

**Solution:** [9-set_string.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x07-pointers_arrays_strings/9-set_string.c)

```
$ amonkeyprogrammer@ubuntu:~/0x07$ cat 9-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s0 = "Anne Cognet";
    char *s1 = "Asaia Palacios";

    printf("%s, %s\n", s0, s1);
    set_string(&s1, s0);
    printf("%s, %s\n", s0, s1);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x07$ gcc -Wall -pedantic -Werror -Wextra 9-main.c 9-set_string.c -o 9-set_string
$ amonkeyprogrammer@ubuntu:~/0x07$ ./9-set_string 
Anne Cognet, Asaia Palacios
Anne Cognet, Anne Cognet
$ amonkeyprogrammer@ubuntu:~/0x07$
```

# Functions, nested loops

# Learning Objectives

* What are nested loops and how to use them
* What is a function and how do you use functions
* What is the difference between a declaration and a definition of a function
* What is a prototype
* Scope of variables
* What are the `gcc` flags `-Wall -Werror -pedantic -Wextra`
* What are header files and how to to use them with `#include`

# Tasks

## _putchar

Write a program that prints `Holberton`, followed by a new line.

* The program should return `0`

**Solution:** [0-holberton.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/0-holberton.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$  gcc -Wall -pedantic -Werror -Wextra _putchar.c 0-holberton.c -o 0-holberton
$ amonkeyprogrammer@ubuntu:~/0x02$ ./0-holberton 
Holberton
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## I sometimes suffer from insomnia. And when I can't fall asleep, I play what I call the alphabet game

Write a function that prints the alphabet, in lowercase, followed by a new line.

* Prototype: `void print_alphabet(void);`
* You can only use `_putchar` twice in your code

**Solution:** [1-alphabet.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/1-alphabet.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 1-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_alphabet();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 1-main.c 1-alphabet.c -o 1-alphabet
$ amonkeyprogrammer@ubuntu:~/0x02$ ./1-alphabet 
abcdefghijklmnopqrstuvwxyz
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## 10 x alphabet

Write a function that prints 10 times the alphabet, in lowercase, followed by a new line.

* Prototype: `void print_alphabet_x10(void);`
* You can only use `_putchar` twice in your code

**Solution:** [2-print_alphabet_x10.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/2-print_alphabet_x10.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 2-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_alphabet_x10();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 2-main.c 2-print_alphabet_x10.c -o 2-alphabet_x10
$ amonkeyprogrammer@ubuntu:~/0x02$ ./2-alphabet_x10 
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
$ amonkeyprogrammer@ubuntu:~/0x02$ 
```

## islower

Write a function that checks for lowercase character. 

* Prototype: `int _islower(int c);`
* Returns `1` if `c` is lowercase
* Returns `0` otherwise

**Solution:** [3-islower.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/3-islower.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 3-main.c 
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _islower('H');
    _putchar(r + '0');
    r = _islower('o');
    _putchar(r + '0');
    r = _islower(108);
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 3-main.c 3-islower.c -o 3-islower
$ amonkeyprogrammer@ubuntu:~/0x02$ ./3-islower 
011
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## isalpha

Write a function that checks for alphabetic character.

* Prototype: `int _isalpha(int c);`
* Returns `1` if `c` is a letter, lowercase or uppercase
* Returns `0` otherwise

**Solution:** [4-isalpha.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/4-isalpha.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 4-main.c 
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _isalpha('H');
    _putchar(r + '0');
    r = _isalpha('o');
    _putchar(r + '0');
    r = _isalpha(108);
    _putchar(r + '0');
    r = _isalpha(';');
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 4-main.c 4-isalpha.c -o 4-isalpha
$ amonkeyprogrammer@ubuntu:~/0x02$ ./4-isalpha 
1110
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## Sign

Write a function that prints the sign of a number.

* Prototype: `int print_sign(int n);`
* Returns `1` and prints `+` if `n` is greater than zero
* Returns `0` and prints `0` if `n` is zero
* Returns `-1` and prints `-` if `n` is less than zero

**Solution:** [5-sign.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/5-sign.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 5-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = print_sign(98);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    r = print_sign(0);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    r = print_sign(0xff);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    r = print_sign(-1);
    _putchar(',');
    _putchar(' ');
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 5-main.c 5-sign.c -o 5-sign
$ amonkeyprogrammer@ubuntu:~/0x02$ ./5-sign 
+, 1
0, 0
+, 1
-, /
$ amonkeyprogrammer@ubuntu:~/0x02$ 
```

## There is no such thing as absolute value in this world. You can only estimate what a thing is worth to you

Write a function that computes the absolute value of an integer.

* Prototype: `int _abs(int)`;

**Solution:** [6-abs.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/6-abs.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 6-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = _abs(-1);
    printf("%d\n", r);
    r = _abs(0);
    printf("%d\n", r);
    r = _abs(1);
    printf("%d\n", r);
    r = _abs(-98);
    printf("%d\n", r);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 6-main.c 6-abs.c -o 6-abs
$ amonkeyprogrammer@ubuntu:~/0x02$ ./6-abs 
1
0
1
98
$ amonkeyprogrammer@ubuntu:~/0x02$ 
```

## There are only 3 colors, 10 digits, and 7 notes; it's what we do with them that's important

Write a function that prints the last digit of a number.

* Prototype: `int print_last_digit(int);`
* Returns the value of the last digit

**Solution:** [7-print_last_digit.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/7-print_last_digit.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 7-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    print_last_digit(98);
    print_last_digit(0);
    r = print_last_digit(-1024);
    _putchar('0' + r);
    _putchar('\n');
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 7-main.c 7-print_last_digit.c -o 7-last_digit
$ amonkeyprogrammer@ubuntu:~/0x02$ ./7-last_digit 
8044
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## I'm federal agent Jack Bauer, and today is the longest day of my life

Write a function that prints every minute of the day of Jack Bauer, starting from 00:00 to 23:59.

* Prototype: `void jack_bauer(void);`

**Solution:** [8-24_hours.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/8-24_hours.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 8-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    jack_bauer();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 8-main.c 8-24_hours.c -o 8-24
$ amonkeyprogrammer@ubuntu:~/0x02$ ./8-24 | head
00:00
00:01
00:02
00:03
00:04
00:05
00:06
00:07
00:08
00:09
$ amonkeyprogrammer@ubuntu:~/0x02$ ./8-24 | tail
23:50
23:51
23:52
23:53
23:54
23:55
23:56
23:57
23:58
23:59
$ amonkeyprogrammer@ubuntu:~/0x02$ ./8-24 | wc -l
1440
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## Learn your times table

Write a function that prints the 9 times table, starting with 0.

* Prototype: `void times_table(void);`
* Format: see example

**Solution:** [9-times_table.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/9-times_table.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 9-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    times_table();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c/curriculum_by_$ amonkeyprogrammer/holbertonschool-low_level_programming/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 9-main.c 9-times_table.c -o 9-times_table
ulien@ubuntu:~/0x02$ ./9-times_table | cat -e
0,  0,  0,  0,  0,  0,  0,  0,  0,  0$
0,  1,  2,  3,  4,  5,  6,  7,  8,  9$
0,  2,  4,  6,  8, 10, 12, 14, 16, 18$
0,  3,  6,  9, 12, 15, 18, 21, 24, 27$
0,  4,  8, 12, 16, 20, 24, 28, 32, 36$
0,  5, 10, 15, 20, 25, 30, 35, 40, 45$
0,  6, 12, 18, 24, 30, 36, 42, 48, 54$
0,  7, 14, 21, 28, 35, 42, 49, 56, 63$
0,  8, 16, 24, 32, 40, 48, 56, 64, 72$
0,  9, 18, 27, 36, 45, 54, 63, 72, 81$
$ amonkeyprogrammer@ubuntu:~/0x02$ ./9-times_table | tr ' ' . | cat -e
0,..0,..0,..0,..0,..0,..0,..0,..0,..0$
0,..1,..2,..3,..4,..5,..6,..7,..8,..9$
0,..2,..4,..6,..8,.10,.12,.14,.16,.18$
0,..3,..6,..9,.12,.15,.18,.21,.24,.27$
0,..4,..8,.12,.16,.20,.24,.28,.32,.36$
0,..5,.10,.15,.20,.25,.30,.35,.40,.45$
0,..6,.12,.18,.24,.30,.36,.42,.48,.54$
0,..7,.14,.21,.28,.35,.42,.49,.56,.63$
0,..8,.16,.24,.32,.40,.48,.56,.64,.72$
0,..9,.18,.27,.36,.45,.54,.63,.72,.81$
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## a + b

Write a function that adds two integers and returns the result.

* Prototype: `int add(int, int);`

**Solution:** [10-add.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/10-add.c)

```
$ amonkeyprogrammer@ubuntu:~/$ cat 10-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int n;

    n = add(89, 9);
    printf("%d\n", n);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 10-main.c 10-add.c -o 10-add
$ amonkeyprogrammer@ubuntu:~/0x02$ ./10-add 
98
$ amonkeyprogrammer@ubuntu:~/0x02$ 
```

## Holberton School, 98 Battery Street, the OG

Write a function that prints all natural numbers from `n` to `98`, followed by a new line.

* Prototype: `void print_to_98(int n);`
* Numbers must be separated by a comma, followed by a space
* Numbers should be printed in order
* The first printed number should be the number passed to your function
* The last printed number should be `98`
* You are allowed to use the standard library

**Solution:** [11-print_to_98.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/11-print_to_98.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 11-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_to_98(0);
    print_to_98(98);
    print_to_98(111);
    print_to_98(81);
    print_to_98(-10);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 11-main.c 11-print_to_98.c -o 11-98
$ amonkeyprogrammer@ubuntu:~/0x02$ ./11-98 
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
98
111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98
81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
$ amonkeyprogrammer@ubuntu:~/0x02$ 
```

## The World looks like a multiplication-table, or a mathematical equation, which, turn it how you will, balances itself

Write a function that prints the `n` times table, starting with 0.

* Prototype: `void print_times_table(int n);`
* If `n` is greater than `15` or less than `0` the function should not print anything
* Format: see example

**Solution:** [100-times_table.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/100-times_table.c)

```
$ amonkeyprogrammer@ubuntu:~/0x02$ cat 100-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_times_table(3);
    _putchar('\n');
    print_times_table(5);
    _putchar('\n');
    print_times_table(98);
    _putchar('\n');
    print_times_table(12);  
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 100-main.c 100-times_table.c -o 100-times_table
$ amonkeyprogrammer@ubuntu:~/0x02$ ./100-times_table 
0,   0,   0,   0
0,   1,   2,   3
0,   2,   4,   6
0,   3,   6,   9

0,   0,   0,   0,   0,   0
0,   1,   2,   3,   4,   5
0,   2,   4,   6,   8,  10
0,   3,   6,   9,  12,  15
0,   4,   8,  12,  16,  20
0,   5,  10,  15,  20,  25


0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
0,   2,   4,   6,   8,  10,  12,  14,  16,  18,  20,  22,  24
0,   3,   6,   9,  12,  15,  18,  21,  24,  27,  30,  33,  36
0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48
0,   5,  10,  15,  20,  25,  30,  35,  40,  45,  50,  55,  60
0,   6,  12,  18,  24,  30,  36,  42,  48,  54,  60,  66,  72
0,   7,  14,  21,  28,  35,  42,  49,  56,  63,  70,  77,  84
0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96
0,   9,  18,  27,  36,  45,  54,  63,  72,  81,  90,  99, 108
0,  10,  20,  30,  40,  50,  60,  70,  80,  90, 100, 110, 120
0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132
0,  12,  24,  36,  48,  60,  72,  84,  96, 108, 120, 132, 144
$ amonkeyprogrammer@ubuntu:~/0x02$ ./100-times_table | tr ' ' . | cat -e
0,...0,...0,...0$
0,...1,...2,...3$
0,...2,...4,...6$
0,...3,...6,...9$
$
0,...0,...0,...0,...0,...0$
0,...1,...2,...3,...4,...5$
0,...2,...4,...6,...8,..10$
0,...3,...6,...9,..12,..15$
0,...4,...8,..12,..16,..20$
0,...5,..10,..15,..20,..25$
$
$
0,...0,...0,...0,...0,...0,...0,...0,...0,...0,...0,...0,...0$
0,...1,...2,...3,...4,...5,...6,...7,...8,...9,..10,..11,..12$
0,...2,...4,...6,...8,..10,..12,..14,..16,..18,..20,..22,..24$
0,...3,...6,...9,..12,..15,..18,..21,..24,..27,..30,..33,..36$
0,...4,...8,..12,..16,..20,..24,..28,..32,..36,..40,..44,..48$
0,...5,..10,..15,..20,..25,..30,..35,..40,..45,..50,..55,..60$
0,...6,..12,..18,..24,..30,..36,..42,..48,..54,..60,..66,..72$
0,...7,..14,..21,..28,..35,..42,..49,..56,..63,..70,..77,..84$
0,...8,..16,..24,..32,..40,..48,..56,..64,..72,..80,..88,..96$
0,...9,..18,..27,..36,..45,..54,..63,..72,..81,..90,..99,.108$
0,..10,..20,..30,..40,..50,..60,..70,..80,..90,.100,.110,.120$
0,..11,..22,..33,..44,..55,..66,..77,..88,..99,.110,.121,.132$
0,..12,..24,..36,..48,..60,..72,..84,..96,.108,.120,.132,.144$
$ amonkeyprogrammer@ubuntu:~/0x02$
```

## Nature made the natural numbers; All else is the work of women

If we list all the natural numbers below `10` that are multiples of `3` or `5`, we get `3`, `5`, `6` and `9`. The sum of these multiples is `23`. Write a program that computes and prints the sum of all the multiples of `3` or `5` below `1024` (excluded), followed by a new line.

* You are allowed to use the standard library

**Solution:** [101-natural.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/101-natural.c)

## In computer class, the first assignment was to write a program to print the first 100 Fibonacci numbers. Instead, I wrote a program that would steal passwords of students. My teacher gave me an A

Write a program that prints the first 50 Fibonacci numbers, starting with `1` and `2`, followed by a new line.

* The numbers must be separated by comma, followed by a space `,` 
* You are allowed to use the standard library

**Solution:** [102-fibonacci.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/102-fibonacci.c)

## Even Liber Abbaci

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with `1` and `2`, the first 10 terms will be: `1, 2, 3, 5, 8, 13, 21, 34, 55, 89`. By considering the terms in the Fibonacci sequence whose values do not exceed 4,000,000, write a program that finds and prints the sum of the even-valued terms, followed by a new line.

* You are allowed to use the standard library

**Solution:** [103-fibonacci.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x02-functions_nested_loops/103-fibonacci.c)

# More functions and nested loops project

# Learning Objectives

* What are nested loops and how to use them
* What is a function and how do you use functions
* What is the difference between a declaration and a definition of a function
* What is a prototype
* Scope of variables
* What are the gcc flags -Wall -Werror -pedantic -Wextra
* What are header files and how to to use them with #include

# Tasks

## isupper

Write a function that checks for uppercase character.

* Prototype: `int _isupper(int c);`
* Returns `1` if `c` is uppercase
* Returns `0` otherwise

**Solution:** [0-isupper.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/0-isupper.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = 'A';
    printf("%c: %d\n", c, _isupper(c));
    c = 'a';
    printf("%c: %d\n", c, _isupper(c));
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-isupper.c -o 0-isuper
$ amonkeyprogrammer@ubuntu:~/0x04$ ./0-isuper 
A: 1
a: 0
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## isdigit

Write a function that checks for a digit (0 through 9).

* Prototype: `int _isdigit(int c);`
* Returns `1` if `c` is a digit
* Returns `0` otherwise

**Solution:** [1-isdigit.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/1-isdigit.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 1-main.c 
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char c;

    c = '0';
    printf("%c: %d\n", c, _isdigit(c));
    c = 'a';
    printf("%c: %d\n", c, _isdigit(c));
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-isdigit.c -o 1-isdigit
$ amonkeyprogrammer@ubuntu:~/0x04$ ./1-isdigit 
0: 1
a: 0
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## Collaboration is multiplication

Write a function that multiplies two integers.

* Prototype: `int mul(int a, int b);`

**Solution:** [2-mul.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/2-mul.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 2-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    printf("%d\n", mul(98, 1024));
    printf("%d\n", mul(-402, 4096));
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-mul.c -o 2-mul
$ amonkeyprogrammer@ubuntu:~/0x04$ ./2-mul 
100352
-1646592
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## The numbers speak for themselves

Write a function that prints the numbers, from `0` to `9`, followed by a new line.

* Prototype: `void print_numbers(void);`
* You can only use `_putchar` twice in your code

**Solution:** [3-print_numbers.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/3-print_numbers.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 3-main.c 
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_numbers();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 3-main.c 3-print_numbers.c -o 3-print_numbers
$ amonkeyprogrammer@ubuntu:~/0x04$ ./3-print_numbers | cat -e
0123456789$
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## I believe in numbers and signs

Write a function that prints the numbers, from `0` to `9`, followed by a new line.

* Prototype: `void print_most_numbers(void);`
* Do not print `2` and `4`
* You can only use `_putchar` twice in your code

**Solution:** [4-print_most_numbers.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/4-print_most_numbers.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 4-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_most_numbers();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 4-main.c 4-print_most_numbers.c -o 4-print_most_numbers
$ amonkeyprogrammer@ubuntu:~/0x04$ ./4-print_most_numbers 
01356789
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## Numbers constitute the only universal language

Write a function that prints 10 times the numbers, from `0` to `14`, followed by a new line.

* Prototype: `void more_numbers(void);`
* You can only use `_putchar` three times in your code

**Solution:** [5-more_numbers.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/5-more_numbers.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 5-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    more_numbers();
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 5-main.c 5-more_numbers.c -o 5-more_numbers
$ amonkeyprogrammer@ubuntu:~/0x04$ ./5-more_numbers 
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
01234567891011121314
$ amonkeyprogrammer@ubuntu:~/0x04
```

## The shortest distance between two points is a straight line

Write a function that draws a straight line in the terminal.

* Prototype: `void print_line(int n);`
* You can only use `_putchar` function to print
* Where `n` is the number of times the character `_` should be printed
* The line should end with a `\n`
* If `n` is `0` or less, the function should only print `\n`

**Solution:** [6-print_line.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/6-print_line.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 6-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_line(0);
    print_line(2);
    print_line(10);
    print_line(-4);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 6-main.c 6-print_line.c -o 6-lines
$ amonkeyprogrammer@ubuntu:~/0x04$ ./6-lines | cat -e
$
__$
__________$
$
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## I feel like I am diagonally parked in a parallel universe

Write a function that draws a diagonal line on the terminal.

* Prototype: `void print_diagonal(int n);`
* You can only use `_putchar` function to print
* Where `n` is the number of times the character `\` should be printed
* The diagonal should end with a `\n`
* If `n` is `0` or less, the function should only print a `\n`

**Solution:** [7-print_diagonal.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/7-print_diagonal.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 7-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_diagonal(0);
    print_diagonal(2);
    print_diagonal(10);
    print_diagonal(-4);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 7-main.c 7-print_diagonal.c -o 7-diagonals
$ amonkeyprogrammer@ubuntu:~/0x04$ ./7-diagonals | cat -e
$
\$
 \$
\$
 \$
  \$
   \$
    \$
     \$
      \$
       \$
        \$
         \$
$
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## You are so much sunshine in every square inch

Write a function that prints a square, followed by a new line.

* Prototype: `void print_square(int size);`
* You can only use `_putchar` function to print
* Where `size` is the size of the square
* If `size` is `0` or less, the function should print only a new line
* Use the character `#` to print the square

**Solution:** [8-print_square.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/8-print_square.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 8-main.c 
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_square(2);
    print_square(10);
    print_square(0);
    return (0);
}

$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 8-main.c 8-print_square.c -o 8-squares
$ amonkeyprogrammer@ubuntu:~/0x04$ ./8-squares 
##
##
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########

$ amonkeyprogrammer@ubuntu:~/0x04$
```

## Fizz-Buzz

The “Fizz-Buzz test” is an interview question designed to help filter out the 99.5% of programming job candidates who can’t seem to program their way out of a wet paper bag.

Write a program that prints the numbers from `1` to `100`, followed by a new line. But for multiples of three print `Fizz` instead of the number and for the multiples of five print `Buzz`. For numbers which are multiples of both three and five print `FizzBuzz`.

* Each number or word should be separated by a space
* You are allowed to use the standard library

**Solution:** [9-fizz_buzz.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/9-fizz_buzz.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra 9-fizz_buzz.c -o 9-fizz_buzz
$ amonkeyprogrammer@ubuntu:~/0x04$ ./9-fizz_buzz 
1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz 31 32 Fizz 34 Buzz Fizz 37 38 Fizz Buzz 41 Fizz 43 44 FizzBuzz 46 47 Fizz 49 Buzz Fizz 52 53 Fizz Buzz 56 Fizz 58 59 FizzBuzz 61 62 Fizz 64 Buzz Fizz 67 68 Fizz Buzz 71 Fizz 73 74 FizzBuzz 76 77 Fizz 79 Buzz Fizz 82 83 Fizz Buzz 86 Fizz 88 89 FizzBuzz 91 92 Fizz 94 Buzz Fizz 97 98 Fizz Buzz
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## Triangles

Write a function that prints a triangle, followed by a new line.

* Prototype: `void print_triangle(int size);`
* You can only use `_putchar` function to print
* Where `size` is the size of the triangle
* If `size` is `0` or less, the function should print only a new line
* Use the character `#` to print the triangle

**Solution:** [10-print_triangle.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/10-print_triangle.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 10-main.c 
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_triangle(2);
    print_triangle(10);
    print_triangle(1);
    print_triangle(0);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 10-main.c 10-print_triangle.c -o 10-triangles
$ amonkeyprogrammer@ubuntu:~/0x04$ ./10-triangles 
 #
##
         #
        ##
       ###
      ####
     #####
    ######
   #######
  ########
 #########
##########
#

$ amonkeyprogrammer@ubuntu:~/0x04$ ./10-triangles | tr ' ' . | cat -e
.#$
##$
.........#$
........##$
.......###$
......####$
.....#####$
....######$
...#######$
..########$
.#########$
##########$
#$
$
$ amonkeyprogrammer@ubuntu:~/0x04$
```

## The problem of distinguishing prime numbers from composite numbers and of resolving the latter into their prime factors is known to be one of the most important and useful in arithmetic

The prime factors of `1231952` are `2`, `2`, `2`, `2`, `37` and `2081`. 

Write a program that finds and prints the largest prime factor of the number `612852475143`, followed by a new line.

* You are allowed to use the standard library
* Your program will be compiled with this command: `gcc -Wall -pedantic -Werror -Wextra 100-prime_factor.c -o 100-prime_factor -lm`

**Solution:** [100-prime_factor.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/100-prime_factor.c)

## Numbers have life; they're not just symbols on paper

Write a function that prints an integer.

* Prototype: `void print_number(int n);`
* You can only use `_putchar` function to print
* You are not allowed to use `long`
* You are not allowed to use arrays or pointers
* You are not allowed to hard-code special values

**Solution:** [101-print_number.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x04-more_functions_nested_loops/101-print_number.c)

```
$ amonkeyprogrammer@ubuntu:~/0x04$ cat 101-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    print_number(98);
    _putchar('\n');
    print_number(402);
    _putchar('\n');
    print_number(1024);
    _putchar('\n');
    print_number(0);
    _putchar('\n');
    print_number(-98);
    _putchar('\n');
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x04$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 101-main.c 101-print_number.c -o 101-print_numbers
$ amonkeyprogrammer@ubuntu:~/0x04$ ./101-print_numbers 
98
402
1024
0
-98
$ amonkeyprogrammer@ubuntu:~/0x04$
```

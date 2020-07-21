# Recursion

# Learning Objectives

* What is recursion
* How to implement recursion
* In what situations you should implement recursion
* In what situations you shouldn’t implement recursion

# Tasks

## She locked away a secret, deep inside herself, something she once knew to be true... but chose to forget

Write a function that prints a string, followed by a new line.

* Prototype: `void _puts_recursion(char *s);`

**Solution:** [0-puts_recursion.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/0-puts_recursion.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 0-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    _puts_recursion("Betty Holberton");
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts_recursion
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./0-puts_recursion 
Betty Holberton
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## Why is it so important to dream? Because, in my dreams we are together

Write a function that prints a string in reverse.

* Prototype: `void _print_rev_recursion(char *s);`

**Solution:** [1-print_rev_recursion.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/1-print_rev_recursion.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 1-main.c
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    _print_rev_recursion("\nColton Walker");
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra _putchar.c 1-main.c 1-print_rev_recursion.c -o 1-print_rev_recursion
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./1-print_rev_recursion 
reklaW notloC
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## Dreams feel real while we're in them. It's only when we wake up that we realize something was actually strange

Write a function that returns the length of a string.

* Prototype: `int _strlen_recursion(char *s);`

**Solution:** [2-strlen_recursion.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/2-strlen_recursion.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 2-main.c 
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

    n = _strlen_recursion("Corbin Coleman");
    printf("%d\n", n);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra  2-main.c 2-strlen_recursion.c -o 2-strlen_recursion
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./2-strlen_recursion 
14
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## You mustn't be afraid to dream a little bigger, darling

Write a function that returns the factorial of a given number.

* Prototype: `int factorial(int n);`
* If `n` is lower than `0`, the function should return `-1` to indicate an error
* Factorial of `0` is `1`

**Solution:** [3-factorial.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/3-factorial.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 3-main.c
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

    r = factorial(1);
    printf("%d\n", r);
    r = factorial(5);
    printf("%d\n", r);
    r = factorial(10);
    printf("%d\n", r);
    r = factorial(-1024);
    printf("%d\n", r);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra 3-main.c 3-factorial.c -o 3-factorial
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./3-factorial 
1
120
3628800
-1
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## Once an idea has taken hold of the brain it's almost impossible to eradicate

Write a function that returns the value of x raised to the power of y.

* Prototype: `int _pow_recursion(int x, int y);`
* If `y` is lower than `0`, the function should return `-1`

**Solution:** [4-pow_recursion.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/4-pow_recursion.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 4-main.c
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

    r = _pow_recursion(1, 10);
    printf("%d\n", r);
    r = _pow_recursion(1024, 0);
    printf("%d\n", r);
    r = _pow_recursion(2, 16);
    printf("%d\n", r);
    r = _pow_recursion(5, 2);
    printf("%d\n", r);
    r = _pow_recursion(5, -2);
    printf("%d\n", r);
    r = _pow_recursion(-5, 3);
    printf("%d\n", r);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra 4-main.c 4-pow_recursion.c -o 4-pow
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./4-pow 
1
1
65536
25
-1
-125
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## Your subconscious is looking for the dreamer 

Write a function that returns the natural square root of a number.

* Prototype: `int _sqrt_recursion(int n);`
* If `n` does not have a natural square root, the function should return `-1`

**Solution:** [5-sqrt_recursion.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/5-sqrt_recursion.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 5-main.c 
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

    r = _sqrt_recursion(1);
    printf("%d\n", r);
    r = _sqrt_recursion(1024);
    printf("%d\n", r);
    r = _sqrt_recursion(16);
    printf("%d\n", r);
    r = _sqrt_recursion(17);
    printf("%d\n", r);
    r = _sqrt_recursion(25);
    printf("%d\n", r);
    r = _sqrt_recursion(-1);
    printf("%d\n", r);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. gcc -Wall -pedantic -Werror -Wextra 5-main.c 5-sqrt_recursion.c -o 5-sqrt
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./5-sqrt 
1
32
4
-1
5
-1
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## Inception. Is it possible?

Write a function that returns `1` if the input integer is a [prime number](https://en.wikipedia.org/wiki/Prime_number), otherwise return `0`.

* Prototype: `int is_prime_number(int n);`

**Solution:** [6-is_prime_number.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/6-is_prime_number.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 6-main.c
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

    r = is_prime_number(1);
    printf("%d\n", r);
    r = is_prime_number(1024);
    printf("%d\n", r);
    r = is_prime_number(16);
    printf("%d\n", r);
    r = is_prime_number(17);
    printf("%d\n", r);
    r = is_prime_number(25);
    printf("%d\n", r);
    r = is_prime_number(-1);
    printf("%d\n", r);
    r = is_prime_number(113);
    printf("%d\n", r);
    r = is_prime_number(7919);
    printf("%d\n", r);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra 6-main.c 6-is_prime_number.c -o 6-prime
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./6-prime 
0
0
0
1
0
0
1
1
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

## They say we only use a fraction of our brain's true potential. Now that's when we're awake. When we're asleep, we can do almost anything

Write a function that returns `1` if a string is a palindrome and `0` if not.

* Prototype: `int is_palindrome(char *s);`
* An empty string is a palindrome

**Solution:** [7-is_palindrome.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x08-recursion/7-is_palindrome.c)

```
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ cat 7-main.c
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

    r = is_palindrome("level");
    printf("%d\n", r);
    r = is_palindrome("redder");
    printf("%d\n", r);
    r = is_palindrome("holberton");
    printf("%d\n", r);
    r = is_palindrome("step on no pets");
    printf("%d\n", r);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ gcc -Wall -pedantic -Werror -Wextra 7-main.c 7-is_palindrome.c -o 7-palindrome
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$ ./7-palindrome 
1
1
0
1
$ amonkeyprogrammer@ubuntu:~/0x08. Recursion$
```

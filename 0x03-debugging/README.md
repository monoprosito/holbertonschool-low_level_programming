# Debugging project

Debugging is the process of finding and fixing errors in software that prevents it from running correctly. As you become a more advanced programmer and an industry engineer, you will learn how to use debugging tools such as `gdb` or built-in tools that IDEs have. However, it’s important to understand the concepts and processes of debugging manually.

# Learning Objectives

* What is debugging
* What are some methods of debugging manually
* How to read the error messages

# Tasks

## Multiple mains

In most projects, we often give you only one main file to test with. For example, this main file is a test for a `positive_or_negative()` function similar to the one you worked with in [an earlier C task](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x01-variables_if_else_while/0-positive_or_negative.c):

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat main.c
#include "holberton.h"

/**
* main - tests function that prints if integer is positive or negative
* Return: 0
*/

int main(void)
{
        int i;

        i = 98;
        positive_or_negative(i);

        return (0);
}
$ amonkeyprogrammer@ubuntu:/debugging$
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat holberton.h
#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>

void positive_or_negative(int i);

#endif /* HOLBERTON_H */
$ amonkeyprogrammer@ubuntu:/debugging$ 
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ gcc -Wall -pedantic -Werror -Wextra positive_or_negative.c main.c
$ amonkeyprogrammer@ubuntu:/debugging$ ./a.out
98 is positive
$ amonkeyprogrammer@ubuntu:/debugging$
```

Based on the `main.c` file above, create a file named `0-main.c`. This file must test that the function `positive_or_negative()` gives the correct output when given a case of `0`.

You are not coding the solution / function, you’re just testing it! However, you can adapt your function from [Positive or Negative task](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x01-variables_if_else_while/0-positive_or_negative.c) to compile with this main file to test locally.

* You only need to upload `0-main.c` and `holberton.h` for this task. We will provide our own `positive_or_negative()` function.
* You are not allowed to add or remove lines of code, you may change only **one** line in this task.

**Solution:** [0-main.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x03-debugging/0-main.c), [holberton.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x03-debugging/holberton.h)

```
$ amonkeyprogrammer@ubuntu:/debugging$ gcc -Wall -pedantic -Werror -Wextra positive_or_negative.c 0-main.c -o 0-main
$ amonkeyprogrammer@ubuntu:/debugging$ ./0-main
0 is zero
$ amonkeyprogrammer@ubuntu:/debugging$ wc -l 0-main.c
16 1-main.c
$ amonkeyprogrammer@ubuntu:/debugging$ 
```

## Like, comment, subscribe

Copy this main file. Comment out (don’t delete it!) the part of the code that is causing the output to go into an infinite loop.

* Don’t add or remove any lines of code, as we will be checking your line count. You are only allowed to comment out existing code.
* You do not have to compile with `-Wall -Werror -Wextra -pedantic` for this task.

**Solution:** [1-main.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x03-debugging/1-main.c)

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat 1-main.c
#include <stdio.h>

/**
* main - causes an infinite loop
* Return: 0
*/

int main(void)
{
        int i;

        printf("Infinite loop incoming :(\n");

        i = 0;

        while (i < 10)
        {
                putchar(i);
        }

        printf("Infinite loop avoided! \\o/\n");

        return (0);
}
$ amonkeyprogrammer@ubuntu:/debugging$
```

Your output should look like this:

```
$ amonkeyprogrammer@ubuntu:/debugging$ gcc 1-main.c -o 1-main
$ amonkeyprogrammer@ubuntu:/debugging$ ./1-main
Infinite loop incoming :(
Infinite loop avoided! \o/
$ amonkeyprogrammer@ubuntu:/debugging$ wc -l 1-main.c
24 1-main.c
$ amonkeyprogrammer@ubuntu:/debugging$
```

## 0 > 972?

This program prints the largest of three integers.

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat 2-main.c
#include <stdio.h>
#include "holberton.h"

/**
* main - prints the largest of 3 integers
* Return: 0
*/

int main(void)
{
        int a, b, c;
        int largest;

        a = 972;
        b = -98;
        c = 0;

        largest = largest_number(a, b, c);

        printf("%d is the largest number\n", largest);

        return (0);
}
$ amonkeyprogrammer@ubuntu:/debugging$
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat 2-largest_number.c
#include "holberton.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
    int largest;

    if (a > b && b > c)
    {
        largest = a;
    }
    else if (b > a && a > c)
    {
        largest = b;
    }
    else
    {
        largest = c;
    }

    return (largest);
}

$ amonkeyprogrammer@ubuntu:/debugging$
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ gcc -Wall -Werror -Wextra -pedantic 2-largest_number.c 2-main.c -o 2-main
$ amonkeyprogrammer@ubuntu:/debugging$ ./2-main
0 is the largest number
$ amonkeyprogrammer@ubuntu:/debugging$
```

? That’s definitely not right.

Fix the code in `2-largest_number.c` so that it correctly prints out the largest of three numbers, no matter the case.

* Line count will not be checked for this task.

**Solution:** [2-largest_number.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/0-preprocessor), [holberton.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x03-debugging/holberton.h)

## Leap year

This program converts a date to the day of year and determines how many days are left in the year, taking leap year into consideration.

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat 3-main_a.c
#include <stdio.h>
#include "holberton.h"

/**
* main - takes a date and prints how many days are left in the year, taking
* leap years into account
* Return: 0
*/

int main(void)
{
    int month;
    int day;
    int year;

    month = 4;
    day = 01;
    year = 1997;

    printf("Date: %02d/%02d/%04d\n", month, day, year);

    day = convert_day(month, day);

    print_remaining_days(month, day, year);

    return (0);
}

$ amonkeyprogrammer@ubuntu:/debugging$
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat 3-convert_day.c
#include "holberton.h"

/**
* convert_day - converts day of month to day of year, without accounting
* for leap year
* @month: month in number format
* @day: day of month
* Return: day of year
*/

int convert_day(int month, int day)
{
    switch (month)
    {
        case 2:
            day = 31 + day;
            break;
        case 3:
            day = 59 + day;
            break;
        case 4:
            day = 90 + day;
            break;
        case 5:
            day = 120 + day;
            break;
        case 6:
            day = 151 + day;
            break;
        case 7:
            day = 181 + day;
            break;
        case 8:
            day = 212 + day;
            break;
        case 9:
            day = 243 + day;
            break;
        case 10:
            day = 273 + day;
            break;
        case 11:
            day = 304 + day;
            break;
        case 12:
            day = 334 + day;
            break;
        default:
            break;
    }
    return (day);
}

$ amonkeyprogrammer@ubuntu:/debugging$
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ cat 3-print_remaining_days.c
#include <stdio.h>
#include "holberton.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
    if ((year % 4 == 0 || year % 400 == 0) && !(year % 100 == 0))
    {
        if (month >= 2 && day >= 60)
        {
            day++;
        }

        printf("Day of the year: %d\n", day);
        printf("Remaining days: %d\n", 366 - day);
    }
    else
    {
        if (month == 2 && day == 60)
        {
            printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
        }
        else
        {
            printf("Day of the year: %d\n", day);
            printf("Remaining days: %d\n", 365 - day);
        }
    }
}

$ amonkeyprogrammer@ubuntu:/debugging$
```

```
$ amonkeyprogrammer@ubuntu:/debugging$ gcc -Wall -Werror -Wextra -pedantic 3-convert_day.c 3-print_remaining_days.c 3-main_a.c -o 3-main_a 
$ amonkeyprogrammer@ubuntu:/debugging$ ./3-main_a
Date: 04/01/1997
Day of the year: 91
Remaining days: 274
$ amonkeyprogrammer@ubuntu:/debugging$
```

Output looks good for `04/01/1997`! Let’s make a new main file `3-main_b.c` to try a case that is a leap year: `02/29/2000`.

```
$ amonkeyprogrammer@ubuntu:/debugging$ gcc -Wall -Werror -Wextra -pedantic 3-convert_day.c 3-print_remaining_days.c 3-main_b.c -o 3-main_b 
$ amonkeyprogrammer@ubuntu:/debugging$ ./3-main_b
Date: 02/29/2000
Invalid date: 02/29/2000
$ amonkeyprogrammer@ubuntu:/debugging$
```

? That doesn’t seem right.

Fix the `print_remaining_days()` function so that the output works correctly for all dates and all leap years.

* Line count will not be checked for this task.
* You can assume that all test cases have valid months (i.e. the value of `month` will never be less than `1` or greater than `12`) and valid days (i.e. the value of `day` will never be less than `1` or greater than `31`).
* You can assume that all test cases have valid month/day combinations (i.e. there will never be a June 31st or November 31st, etc.), but not all month/day/year combinations are valid (i.e. February 29, 1991 or February 29, 2427).

**Solution:** [3-print_remaining_days.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x03-debugging/3-print_remaining_days.c), [holberton.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x03-debugging/holberton.h)

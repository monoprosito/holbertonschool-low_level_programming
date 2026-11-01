# More malloc, free

# Learning Objectives

* How to use the `exit` function
* What are the functions `calloc` and `realloc` from the standard library and how to use them

# Tasks

## Trust no one

Write a function that allocates memory using malloc.

* Prototype: `void *malloc_checked(unsigned int b);`
* Returns a pointer to the allocated memory
* if `malloc` fails, the `malloc_checked` function should cause normal process termination with a status value of `98`

**Solution:** [0-malloc_checked.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0C-more_malloc_free/0-malloc_checked.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *c;
    int *i;
    float *f;
    double *d;

    c = malloc_checked(sizeof(char) * 1024);
    printf("%p\n", (void *)c);
    i = malloc_checked(sizeof(int) * 402);
    printf("%p\n", (void *)i);
    f = malloc_checked(sizeof(float) * 100000000);
    printf("%p\n", (void *)f);
    d = malloc_checked(INT_MAX);
    printf("%p\n", (void *)d);
    free(c);
    free(i);
    free(f);
    free(d);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-malloc_checked.c -o a
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ ./a 
0x1e39010
0x1e39830
0x7f31f6c19010
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ echo $?
98
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$
```

## string_nconcat

Write a function that concatenates two strings.

* Prototype: `char *string_nconcat(char *s1, char *s2, unsigned int n);`
* The returned pointer shall point to a newly allocated space in memory, which contains `s1`, followed by the first `n` bytes of `s2`, and null terminated
* If the function fails, it should return `NULL`
* If `n` is greater or equal to the length of `s2` then use the entire string `s2`
* if `NULL` is passed, treat it as an empty string

**Solution:** [1-string_nconcat.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0C-more_malloc_free/1-string_nconcat.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ cat 1-main.c
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *concat;

    concat = string_nconcat("Holberton ", "School !!!", 6);
    printf("%s\n", concat);
    free(concat);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-string_nconcat.c -o b
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ ./b 
Holberton School
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$
```

## _calloc

Write a function that allocates memory for an array, using malloc.

* Prototype: `void *_calloc(unsigned int nmemb, unsigned int size);`
* The `_calloc` function allocates memory for an array of `nmemb` elements of `size` bytes each and returns a pointer to the allocated memory.
* The memory is set to zero
* If `nmemb` or `size` is `0`, then `_calloc` returns `NULL`
* If `malloc` fails, then `_calloc` returns `NULL`

**Solution:** [2-calloc.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0C-more_malloc_free/2-calloc.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ cat 2-main.c
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *a;

    a = _calloc(98, sizeof(char));
    strcpy(a, "Holberton");
    strcpy(a + 9, " School! :)\n");
    a[97] = '!';
    simple_print_buffer(a, 98);
    free(a);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-calloc.c -o c
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ ./c
0x48 0x6f 0x6c 0x62 0x65 0x72 0x74 0x6f 0x6e 0x20
0x53 0x63 0x68 0x6f 0x6f 0x6c 0x21 0x20 0x3a 0x29
0x0a 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x21
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$
```

## array_range

Write a function that creates an array of integers.

* Prototype: `int *array_range(int min, int max);`
* The array created should contain all the values from `min` (included) to `max` (included), ordered from `min` to `max`
* Return: the pointer to the newly created array
* If `min` > `max`, return `NULL`
* If `malloc` fails, return `NULL`

**Solution:** [3-array_range.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0C-more_malloc_free/3-array_range.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ cat 3-main.c
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(int *buffer, unsigned int size)
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
    int *a;

    a = array_range(0, 10);
    simple_print_buffer(a, 11);
    free(a);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ gcc -Wall -pedantic -Werror -Wextra 3-main.c 3-array_range.c -o d
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ ./d 
0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09
0x0a
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$
```

## _realloc

Write a function that reallocates a memory block using malloc and free

* Prototype: `void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);`
* where `ptr` is a pointer to the memory previously allocated with a call to `malloc`: `malloc(old_size)`
* `old_size` is the size, in bytes, of the allocated space for `ptr`
* and `new_size` is the new size, in bytes of the new memory block
* The contents will be copied to the newly allocated space, in the range from the start of `ptr` up to the minimum of the old and new sizes
* If `new_size` > `old_size`, the “added” memory should not be initialized
* If `new_size` == `old_size` do not do anything and return ptr
* If `ptr` is `NULL`, then the call is equivalent to `malloc(new_size)`, for all values of `old_size` and `new_size`
* If `new_size` is equal to zero, and `ptr` is not `NULL`, then the call is equivalent to `free(ptr)`. Return `NULL`
* Don’t forget to free `ptr` when it makes sense

**Solution:** [100-realloc.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0C-more_malloc_free/100-realloc.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ cat 100-main.c
#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *p;
    int i;

    p = malloc(sizeof(char) * 10);
    p = _realloc(p, sizeof(char) * 10, sizeof(char) * 98);
    i = 0;
    while (i < 98)
    {
        p[i++] = 98;
    }
    simple_print_buffer(p, 98);
    free(p);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ gcc -Wall -pedantic -Werror -Wextra 100-main.c 100-realloc.c -o e
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$ ./e 
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
0x62 0x62 0x62 0x62 0x62 0x62 0x62 0x62
$ amonkeyprogrammer@ubuntu:~/0x0b. more malloc, free$
```

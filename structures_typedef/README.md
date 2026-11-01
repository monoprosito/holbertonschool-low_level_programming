# Structures, typedef

# Learning Objectives

* What are structures, when, why and how to use them
* How to use `typedef`

# Tasks

## Django

Define a new type struct dog with the following elements:

* `name`, type = `char *`
* `age`, type = `float`
* `owner`, type = `char *`

**Solution:** [dog.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0E-structures_typedef/dog.h)

```
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ cat 0-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Django";
    my_dog.age = 3.5;
    my_dog.owner = "Jay";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ make
gcc -Wall -pedantic -Werror -Wextra 0-main.c -o a
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ ./a 
My name is Django, and I am 3.5 :) - Woof!
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$
```

## A dog is the only thing on earth that loves you more than you love yourself

Write a function that initialize a variable of type `struct dog`

* Prototype: `void init_dog(struct dog *d, char *name, float age, char *owner);`

**Solution:** [1-init_dog.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0E-structures_typedef/1-init_dog.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ cat 1-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Django", 3.5, "Jay");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-init_dog.c -o b
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ ./b 
My name is Django, and I am 3.5 :) - Woof!
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ 
```

## A dog will teach you unconditional love. If you can have that in your life, things won't be too bad

Write a function that prints a struct dog

* Prototype: `void print_dog(struct dog *d);`
* Format: see example below
* You are allowed to use the standard library
* If an element of `d` is `NULL`, print `(nil)` instead of this element. (if `name` is `NULL`, print `Name: (nil)`)
* If `d` is `NULL` print nothing.

**Solution:** [2-print_dog.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0E-structures_typedef/2-print_dog.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ cat 2-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Django";
    my_dog.age = 3.5;
    my_dog.owner = "Jay";
    print_dog(&my_dog);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-print_dog.c -o c
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ ./c 
Name: Django
Age: 3.500000
Owner: Jay
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$
```

## Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read

Define a new type `dog_t` as a new name for the type `struct dog`.

**Solution:** [dog.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0E-structures_typedef/dog.h)

```
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ cat 3-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t my_dog;

    my_dog.name = "Django";
    my_dog.age = 3.5;
    my_dog.owner = "Jay";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra 3-main.c -o d
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ ./d 
My name is Django, and I am 3.5 :) - Woof!
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ 
```

## A door is what a dog is perpetually on the wrong side of

Write a function that creates a new dog.

* Prototype: `dog_t *new_dog(char *name, float age, char *owner);`
* You have to store a copy of `name` and `owner`
* Return `NULL` if the function fails

**Solution:** [4-new_dog.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0E-structures_typedef/4-new_dog.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ cat 4-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Django", 3.5, "Jay");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra 4-main.c 4-new_dog.c -o e
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ ./e
My name is Django, and I am 3.5 :) - Woof!
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$
```

## How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg

Write a function that frees dogs.

* Prototype: `void free_dog(dog_t *d);`

**Solution:** [5-free_dog.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0E-structures_typedef/5-free_dog.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ cat 5-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Django", 3.5, "Jay");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    free_dog(my_dog);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra 5-main.c 5-free_dog.c 4-new_dog.c -o f
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$ valgrind ./f
==22840== Memcheck, a memory error detector
==22840== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==22840== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==22840== Command: ./f
==22840== 
My name is Django, and I am 3.5 :) - Woof!
==22840== 
==22840== HEAP SUMMARY:
==22840==     in use at exit: 0 bytes in 0 blocks
==22840==   total heap usage: 4 allocs, 4 frees, 1,059 bytes allocated
==22840== 
==22840== All heap blocks were freed -- no leaks are possible
==22840== 
==22840== For counts of detected and suppressed errors, rerun with: -v
==22840== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x0d. structures, typedef$
```

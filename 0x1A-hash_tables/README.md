# Hash tables

# Learning Objectives

* What is a hash function
* What makes a good hash function
* What is a hash table, how do they work and how to use them
* What is a collision and what are the main ways of dealing with collisions in the context of a hash table
* What are the advantages and drawbacks of using hash tables
* What are the most common use cases of hash tables

# Tasks

## >>> ht = {}

Write a function that creates a hash table.

* Prototype: `hash_table_t *hash_table_create(unsigned long int size);`
    * where `size` is the size of the array
* Returns a pointer to the newly created hash table
* If something went wrong, your function should return `NULL`

**Solution:** [0-hash_table_create.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/0-hash_table_create.c)

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 0-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    printf("%p\n", (void *)ht);
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-hash_table_create.c -o a
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ ./a 
0x238a010
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ valgrind ./a
==7602== Memcheck, a memory error detector
==7602== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==7602== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==7602== Command: ./a
==7602== 
0x51fc040
==7602== 
==7602== HEAP SUMMARY:
==7602==     in use at exit: 8,208 bytes in 2 blocks
==7602==   total heap usage: 2 allocs, 0 frees, 8,208 bytes allocated
==7602== 
==7602== LEAK SUMMARY:
==7602==    definitely lost: 16 bytes in 1 blocks
==7602==    indirectly lost: 8,192 bytes in 1 blocks
==7602==      possibly lost: 0 bytes in 0 blocks
==7602==    still reachable: 0 bytes in 0 blocks
==7602==         suppressed: 0 bytes in 0 blocks
==7602== Rerun with --leak-check=full to see details of leaked memory
==7602== 
==7602== For counts of detected and suppressed errors, rerun with: -v
==7602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

## djb2

Write a hash function implementing the djb2 algorithm.

* Prototype: `unsigned long int hash_djb2(const unsigned char *str);`

**Solution:** [1-djb2.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/1-djb2.c)

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 1-djb2.c 
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ 
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 1-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s;

    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-djb2.c -o b
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ ./b 
6953392314605
3749890792216096085
5861846
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

## key -> index

Write a function that gives you the index of a key.

* Prototype: `unsigned long int key_index(const unsigned char *key, unsigned long int size);`
    * where `key` is the key
    * and `size` is the size of the array of the hash table
* This function should use the `hash_djb2` function that you wrote earlier
* Returns the index at which the key/value pair should be stored in the array of the hash table

**Solution:** [2-key_index.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/2-key_index.c)

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 2-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    char *s;
    unsigned long int hash_table_array_size;

    hash_table_array_size = 1024;
    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));  
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 1-djb2.c 2-key_index.c -o c
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ ./c 
6953392314605
237
3749890792216096085
341
5861846
470
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

## >>> ht['betty'] = 'holberton'

Write a function that adds an element to the hash table.

* Prototype: `int hash_table_set(hash_table_t *ht, const char *key, const char *value);`
    * Where `ht` is the hash table you want to add or update the key/value to
    * `key` is the key. `key` can not be an empty string
    * and `value` is the value associated with the key. `value` must be duplicated. `value` can be an empty string
* Returns: `1` if it succeeded, `0` otherwise
* In case of collision, add the new node at the beginning of the list

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 3-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "holberton");
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c -o d
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

Here are some strings that collide using the djb2 algorithm:

* **hetairas** collides with **mentioner**
* **heliotropes** collides with **neurospora**
* **depravement** collides with **serafins**
* **stylist** collides with **subgenera**
* **joyful** collides with **synaphea**
* **redescribed** collides with **urites**
* **dram** collides with **vivency**

**Solution:** [3-hash_table_set.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/3-hash_table_set.c)

## >>> ht['betty']

Write a function that retrieves a value associated with a key.

* Prototype: `char *hash_table_get(const hash_table_t *ht, const char *key);`
    * where `ht` is the hash table you want to look into
    * and `key` is the key you are looking for
* Returns the value associated with the element, or `NULL` if `key` couldn’t be found

**Solution:** [4-hash_table_get.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/4-hash_table_get.c)

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 4-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Jennie", "and Jay love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Holberton");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_set(ht, "c", "isfun");

    value = hash_table_get(ht, "python");
    printf("%s:%s\n", "python", value);
    value = hash_table_get(ht, "Jennie");
    printf("%s:%s\n", "Jennie", value);
    value = hash_table_get(ht, "N");
    printf("%s:%s\n", "N", value);
    value = hash_table_get(ht, "Asterix");
    printf("%s:%s\n", "Asterix", value);
    value = hash_table_get(ht, "Betty");
    printf("%s:%s\n", "Betty", value);
    value = hash_table_get(ht, "98");
    printf("%s:%s\n", "98", value);
    value = hash_table_get(ht, "c");
    printf("%s:%s\n", "c", value);
    value = hash_table_get(ht, "javascript");
    printf("%s:%s\n", "javascript", value);
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c -o e
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ ./e 
python:awesome
Jennie:and Jay love asm
N:queens
Asterix:Obelix
Betty:Holberton
98:Battery Street
c:isfun
javascript:(null)
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

## >>> print(ht)

Write a function that prints a hash table.

* Prototype: `void hash_table_print(const hash_table_t *ht);`
    * where `ht` is the hash table
* You should print the key/value in the order that they appear in the array of hash table
    * Order: array, list
* Format: see example
* If `ht` is NULL, don’t print anything

**Solution:** [5-hash_table_print.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/5-hash_table_print.c)

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 5-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Jennie", "and Jay love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Holberton");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c -o f
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ ./f 
{}
{'Betty': 'Holberton', 'python': 'awesome', 'Jennie': 'and Jay love asm', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Asterix': 'Obelix'}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

## >>> del ht

Write a function that deletes a hash table.

* Prototype: `void hash_table_delete(hash_table_t *ht);`
    * where `ht` is the hash table

**Solution:** [6-hash_table_delete.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1A-hash_tables/6-hash_table_delete.c)

```
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ cat 6-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *key;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Jennie", "and Jay love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Holberton");
    hash_table_set(ht, "98", "Battery Streetz");
    key = strdup("Tim");
    value = strdup("Britton");
    hash_table_set(ht, key, value);
    key[0] = '\0';
    value[0] = '\0';
    free(key);
    free(value);
    hash_table_set(ht, "98", "Battery Street"); 
    hash_table_set(ht, "hetairas", "Jennie");
    hash_table_set(ht, "hetairas", "Jennie Z");
    hash_table_set(ht, "mentioner", "Jennie");
    hash_table_set(ht, "hetairas", "Jennie Z Chu");
    hash_table_print(ht);
    hash_table_delete(ht);
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra 6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c 6-hash_table_delete.c -o g
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$ valgrind ./g
==6621== Memcheck, a memory error detector
==6621== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==6621== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==6621== Command: ./g
==6621== 
{'Betty': 'Holberton', 'mentioner': 'Jennie', 'hetairas': 'Jennie Z Chu', 'python': 'awesome', 'Jennie': 'and Jay love asm', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Tim': 'Britton', 'Asterix': 'Obelix'}
==6621== 
==6621== HEAP SUMMARY:
==6621==     in use at exit: 0 bytes in 0 blocks
==6621==   total heap usage: 37 allocs, 37 frees, 8,646 bytes allocated
==6621== 
==6621== All heap blocks were freed -- no leaks are possible
==6621== 
==6621== For counts of detected and suppressed errors, rerun with: -v
==6621== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x1A. Hash tables$
```

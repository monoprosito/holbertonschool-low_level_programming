# More singly linked lists

# Learning Objectives

* How to use linked lists
* Start to look for the right source of information without too much help

# Tasks

## Print list

Write a function that prints all the elements of a listint_t list.

* Prototype: `size_t print_listint(const listint_t *h);`
* Return: the number of nodes
* Format: see example
* You are allowed to use `printf`

**Solution:** [0-print_listint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/0-print_listint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 0-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *new;
    listint_t hello = {8, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->n = 9;
    new->next = head;
    head = new;
    n = print_listint(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-print_listint.c -o a
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./a 
9
8
-> 2 elements
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## List length

Write a function that returns the number of elements in a linked `listint_t` list.

* Prototype: `size_t listint_len(const listint_t *h);`

**Solution:** [1-listint_len.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/1-listint_len.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 1-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *new;
    listint_t hello = {8, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->n = 9;
    new->next = head;
    head = new;
    n = listint_len(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-listint_len.c -o b
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./b 
-> 2 elements
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Add node

Write a function that adds a new node at the beginning of a `listint_t` list.

* Prototype: `listint_t *add_nodeint(listint_t **head, const int n);`
* Return: the address of the new element, or `NULL` if it failed

**Solution:** [2-add_nodeint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/2-add_nodeint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 2-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-add_nodeint.c 0-print_listint.c -o c
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./c 
1024
402
98
4
3
2
1
0
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Add node at the end

Write a function that adds a new node at the end of a `listint_t` list.

* Prototype: `listint_t *add_nodeint_end(listint_t **head, const int n);`
* Return: the address of the new element, or `NULL` if it failed

**Solution:** [3-add_nodeint_end.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/3-add_nodeint_end.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 3-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 3-main.c 3-add_nodeint_end.c 0-print_listint.c -o d
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./d 
0
1
2
3
4
98
402
1024
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Free list

Write a function that frees a `listint_t` list.

* Prototype: `void free_listint(listint_t *head);`

**Solution:** [4-free_listint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/4-free_listint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 4-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    free_listint(head);
    head = NULL;
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 4-main.c 3-add_nodeint_end.c 0-print_listint.c 4-free_listint.c -o e
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ valgrind ./e 
==3643== Memcheck, a memory error detector
==3643== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3643== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3643== Command: ./e
==3643== 
0
1
2
3
4
98
402
1024
==3643== 
==3643== HEAP SUMMARY:
==3643==     in use at exit: 0 bytes in 0 blocks
==3643==   total heap usage: 9 allocs, 9 frees, 1,152 bytes allocated
==3643== 
==3643== All heap blocks were freed -- no leaks are possible
==3643== 
==3643== For counts of detected and suppressed errors, rerun with: -v
==3643== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Free

Write a function that frees a `listint_t` list.

* Prototype: `void free_listint2(listint_t **head);`
* The function sets the `head` to `NULL`

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 5-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    free_listint2(&head);
    printf("%p\n", (void *)head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 5-main.c 3-add_nodeint_end.c 0-print_listint.c 5-free_listint2.c -o f
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ valgrind ./f 
==3843== Memcheck, a memory error detector
==3843== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3843== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3843== Command: ./f
==3843== 
0
1
2
3
4
98
402
1024
(nil)
==3843== 
==3843== HEAP SUMMARY:
==3843==     in use at exit: 0 bytes in 0 blocks
==3843==   total heap usage: 9 allocs, 9 frees, 1,152 bytes allocated
==3843== 
==3843== All heap blocks were freed -- no leaks are possible
==3843== 
==3843== For counts of detected and suppressed errors, rerun with: -v
==3843== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Pop

Write a function that deletes the head node of a `listint_t` linked list, and returns the head node’s data (n).

* Prototype: `int pop_listint(listint_t **head);`
* if the linked list is empty return `0`

**Solution:** [6-pop_listint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/6-pop_listint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 6-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    int n;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    n = pop_listint(&head);
    printf("- %d\n", n);
    print_listint(head);
    n = pop_listint(&head);
    printf("- %d\n", n);
    print_listint(head);
    free_listint2(&head);
    printf("%p\n", (void *)head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 6-main.c 3-add_nodeint_end.c 0-print_listint.c 5-free_listint2.c 6-pop_listint.c -o g
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ valgrind ./g 
==4369== Memcheck, a memory error detector
==4369== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==4369== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==4369== Command: ./g
==4369== 
0
1
2
3
4
98
402
1024
- 0
1
2
3
4
98
402
1024
- 1
2
3
4
98
402
1024
(nil)
==4369== 
==4369== HEAP SUMMARY:
==4369==     in use at exit: 0 bytes in 0 blocks
==4369==   total heap usage: 9 allocs, 9 frees, 1,152 bytes allocated
==4369== 
==4369== All heap blocks were freed -- no leaks are possible
==4369== 
==4369== For counts of detected and suppressed errors, rerun with: -v
==4369== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Get node at index

Write a function that returns the nth node of a listint_t linked list.

* Prototype: `listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);`
* where `index` is the index of the node, starting at `0`
* if the node does not exist, return `NULL`

**Solution:** [7-get_nodeint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/7-get_nodeint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 7-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    listint_t *node;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    node = get_nodeint_at_index(head, 5);
    printf("%d\n", node->n);
    print_listint(head);
    free_listint2(&head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 7-main.c 3-add_nodeint_end.c 0-print_listint.c 5-free_listint2.c 7-get_nodeint.c -o h
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./h 
0
1
2
3
4
98
402
1024
98
0
1
2
3
4
98
402
1024
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Sum list

Write a function that returns the sum of all the data (n) of a `listint_t` linked list.

* Prototype: `int sum_listint(listint_t *head);`
* if the list is empty, return `0`

**Solution:** [8-sum_listint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/8-sum_listint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 8-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;
    int sum;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    sum = sum_listint(head);
    printf("sum = %d\n", sum);
    free_listint2(&head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/c0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 8-main.c 3-add_nodeint_end.c 5-free_listint2.c 8-sum_listint.c -o i
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./i 
sum = 1534
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Insert

Write a function that inserts a new node at a given position.

* Prototype: `listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);`
* where `idx` is the index of the list where the new node should be added. Index starts at `0`
* Returns: the address of the new node, or `NULL` if it failed
* if it is not possible to add the new node at index `idx`, do not add the new node and return `NULL`

**Solution:** [9-insert_nodeint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/9-insert_nodeint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 9-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    printf("-----------------\n");
    insert_nodeint_at_index(&head, 5, 4096);
    print_listint(head);
    free_listint2(&head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 9-main.c 3-add_nodeint_end.c 0-print_listint.c 5-free_listint2.c 9-insert_nodeint.c -o j
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ ./j 
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
4096
98
402
1024
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Delete at index

Write a function that deletes the node at index index of a `listint_t` linked list.

* Prototype: `int delete_nodeint_at_index(listint_t **head, unsigned int index);`
* where `index` is the index of the node that should be deleted. Index starts at `0`
* Returns: ``1`` if it succeeded, ``-1`` if it failed

**Solution:** [10-delete_nodeint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/10-delete_nodeint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 10-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 5);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 10-main.c 3-add_nodeint_end.c 0-print_listint.c 5-free_listint2.c 10-delete_nodeint.c -o k
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ valgrind ./k 
==5571== Memcheck, a memory error detector
==5571== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==5571== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==5571== Command: ./k
==5571== 
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
402
1024
-----------------
1
2
3
4
402
1024
-----------------
2
3
4
402
1024
-----------------
3
4
402
1024
-----------------
4
402
1024
-----------------
402
1024
-----------------
1024
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
-----------------
==5571== 
==5571== HEAP SUMMARY:
==5571==     in use at exit: 0 bytes in 0 blocks
==5571==   total heap usage: 9 allocs, 9 frees, 1,152 bytes allocated
==5571== 
==5571== All heap blocks were freed -- no leaks are possible
==5571== 
==5571== For counts of detected and suppressed errors, rerun with: -v
==5571== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

## Reverse list

Write a function that reverses a listint_t linked list.

* Prototype: `listint_t *reverse_listint(listint_t **head);`
* Returns: a pointer to the first node of the reversed list
* You are not allowed to use more than `1` loop.
* You are not allowed to use `malloc`, `free` or arrays
* You can only declare a maximum of two variables in your function

**Solution:** [100-reverse_listint.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x13-more_singly_linked_lists/100-reverse_listint.c)

```
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ cat 100-main.c 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    reverse_listint(&head);
    print_listint(head);    
    free_listint2(&head);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ gcc -Wall -pedantic -Werror -Wextra 100-main.c 3-add_nodeint_end.c 0-print_listint.c 5-free_listint2.c 100-reverse_listint.c -o l
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$ valgrind ./l 
==3117== Memcheck, a memory error detector
==3117== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3117== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3117== Command: ./l
==3117== 
0
1
2
3
4
98
402
1024
1024
402
98
4
3
2
1
0
==3117== 
==3117== HEAP SUMMARY:
==3117==     in use at exit: 0 bytes in 0 blocks
==3117==   total heap usage: 9 allocs, 9 frees, 1,152 bytes allocated
==3117== 
==3117== All heap blocks were freed -- no leaks are possible
==3117== 
==3117== For counts of detected and suppressed errors, rerun with: -v
==3117== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ amonkeyprogrammer@ubuntu:~/0x13. More singly linked lists$
```

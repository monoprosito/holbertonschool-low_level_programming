# Search Algorithms

# Learning Objectives

* What is a search algorithm
* What is a linear search
* What is a binary search
* What is the best search algorithm to use depending on your needs

# Tasks

## Linear search

Write a function that searches for a value in an array of integers using the [Linear search algorithm](https://en.wikipedia.org/wiki/Linear_search)

* Prototype: `int linear_search(int *array, size_t size, int value);`
* Where `array` is a pointer to the first element of the array to search in
* `size` is the number of elements in `array`
* And `value` is the value to search for
* Your function must return the first index where `value` is located
* If `value` is not present in `array` or if `array` is NULL, your function must return `-1`
* Every time you compare a value in the array to the value you are searching, you have to print this value (see example below)

**Solution:** [0-linear.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/0-linear.c)

```
$ amonkeyprogrammer@0x1E-search_algorithms$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        10, 1, 42, 3, 4, 42, 6, 7, -1, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, linear_search(array, size, 3));
    printf("Found %d at index: %d\n\n", 42, linear_search(array, size, 42));
    printf("Found %d at index: %d\n", 999, linear_search(array, size, 999));
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear.c -o 0-linear
$ amonkeyprogrammer@0x1E-search_algorithms$ ./0-linear 
Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Value checked array[3] = [3]
Found 3 at index: 3

Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Found 42 at index: 2

Value checked array[0] = [10]
Value checked array[1] = [1]
Value checked array[2] = [42]
Value checked array[3] = [3]
Value checked array[4] = [4]
Value checked array[5] = [42]
Value checked array[6] = [6]
Value checked array[7] = [7]
Value checked array[8] = [-1]
Value checked array[9] = [9]
Found 999 at index: -1
```

## Binary search

Write a function that searches for a value in a sorted array of integers using the [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)

* Prototype: `int binary_search(int *array, size_t size, int value);`
* Where `array` is a pointer to the first element of the array to search in
* `size` is the number of elements in `array`
* And ``value` is the value to search for
* Your function must return the index where `value` is located
* You can assume that `array` will be sorted in ascending order
* You can assume that `value` won’t appear more than once in `array`
* If `value` is not present in `array` or if `array` is `NULL`, your function must return -1
* You must print the array being searched every time it changes. (e.g. at the beginning and when you search a subarray) (See example)

**Solution:** [1-binary.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/1-binary.c)

```
$ amonkeyprogrammer@0x1E-search_algorithms$ cat 1-main.c 
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 2, binary_search(array, size, 2));
    printf("Found %d at index: %d\n\n", 5, binary_search(array, 5, 5));
    printf("Found %d at index: %d\n", 999, binary_search(array, size, 999));
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@0x1E-search_algorithms$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-binary.c -o 1-binary
$ amonkeyprogrammer@0x1E-search_algorithms$ ./1-binary 
Searching in array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Searching in array: 0, 1, 2, 3
Searching in array: 2, 3
Found 2 at index: 2

Searching in array: 0, 1, 2, 3, 4
Searching in array: 3, 4
Searching in array: 4
Found 5 at index: -1

Searching in array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Searching in array: 5, 6, 7, 8, 9
Searching in array: 8, 9
Searching in array: 9
Found 999 at index: -1
```

## Big O #0

What is the `time complexity` (worst case) of a linear search in an array of size `n`?

**Solution:** [2-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/2-O)

## Big O #1

What is the `space complexity` (worst case) of an iterative linear search algorithm in an array of size `n`?

**Solution:** [3-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/3-O)

## Big O #2

What is the `time complexity` (worst case) of a binary search in an array of size `n`?

**Solution:** [4-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/4-O)

## Big O #3

What is the `space complexity` (worst case) of a binary search in an array of size `n`?

**Solution:** [5-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/5-O)

## Big O #4

What is the space complexity of this function / algorithm?

**Solution:** [6-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/6-O)

```C
int **allocate_map(int n, int m)
{
     int **map;

     map = malloc(sizeof(int *) * n);
     for (size_t i = 0; i < n; i++)
     {
          map[i] = malloc(sizeof(int) * m);
     }
     return (map);
}
```

## Big O #5

What is the `time complexity` (average case) of a jump search in an array of size `n`, using `step = sqrt(n)`?

**Solution:** [101-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/101-O)

## Big O #6

What is the `time complexity` (average case) of a jump search in a singly linked list of size n, using `step = sqrt(n)`?

**Solution:** [107-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/107-O)

## Big O #7

What is the `time complexity` (average case) of a jump search in a skip list of size n, with an express lane using `step = sqrt(n)`?

**Solution:** [108-O](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1E-search_algorithms/108-O)

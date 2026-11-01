# Static Libraries

# Learning Objectives

* What is a static library, how does it work, how to create one, and how to use it
* Basic usage of `ar`, `ranlib`, `nm`

# Tasks

## A library is not a luxury but one of the necessities of life

Create the static library `libholberton.a` containing all the functions listed below:

```
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
```

**Solution:** [libholberton.a](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x09-static_libraries/libholberton.a), [holberton.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x09-static_libraries/holberton.h)

```
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ ar -t libholberton.a 
0-isupper.o
0-memset.o
0-strcat.o
1-isdigit.o
1-memcpy.o
1-strncat.o
100-atoi.o
2-strchr.o
2-strlen.o
2-strncpy.o
3-islower.o
3-puts.o
3-strcmp.o
3-strspn.o
4-isalpha.o
4-strpbrk.o
5-strstr.o
6-abs.o
9-strcpy.o
_putchar.o
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ nm libholberton.a 

0-isupper.o:
0000000000000000 T _isupper

0-memset.o:
0000000000000000 T _memset

0-strcat.o:
0000000000000000 T _strcat

1-isdigit.o:
0000000000000000 T _isdigit

1-memcpy.o:
0000000000000000 T _memcpy

1-strncat.o:
0000000000000000 T _strncat

100-atoi.o:
0000000000000000 T _atoi

2-strchr.o:
0000000000000000 T _strchr

2-strlen.o:
0000000000000000 T _strlen

2-strncpy.o:
0000000000000000 T _strncpy

3-islower.o:
0000000000000000 T _islower

3-puts.o:
                 U _putchar
0000000000000000 T _puts

3-strcmp.o:
0000000000000000 T _strcmp

3-strspn.o:
0000000000000000 T _strspn

4-isalpha.o:
0000000000000000 T _isalpha

4-strpbrk.o:
0000000000000000 T _strpbrk

5-strstr.o:
0000000000000000 T _strstr

6-abs.o:
0000000000000000 T _abs

9-strcpy.o:
0000000000000000 T _strcpy

_putchar.o:
0000000000000000 T _putchar
                 U write
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ cat main.c 
#include "holberton.h"

int main(void)
{
    _puts("\"At the end of the day, my goal was to be the best hacker\"\n\t- Kevin Mitnick");
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ gcc main.c -L. -lholberton -o quote
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ ./quote 
"At the end of the day, my goal was to be the best hacker"
    - Kevin Mitnick
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$
```

## Without libraries what have we? We have no past and no future

Create a script called `create_static_lib.sh` that creates a static library called `liball.a` from all the `.c` files that are in the current directory.

**Solution:** [create_static_lib.sh](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x09-static_libraries/create_static_lib.sh)

```
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ ls *.c
0-isupper.c  0-strcat.c  1-isdigit.c  1-strncat.c  2-strlen.c   3-islower.c  3-strcmp.c  4-isalpha.c  5-strstr.c  9-strcpy.c  _putchar.c
0-memset.c   100-atoi.c  1-memcpy.c   2-strchr.c   2-strncpy.c  3-puts.c     3-strspn.c  4-strpbrk.c  6-abs.c
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ ./create_static_lib.sh 
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ ls *.a
liball.a
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$ ar -t liball.a
0-isupper.o
0-memset.o
0-strcat.o
100-atoi.o
1-isdigit.o
1-memcpy.o
1-strncat.o
2-strchr.o
2-strlen.o
2-strncpy.o
3-islower.o
3-puts.o
3-strcmp.o
3-strspn.o
4-isalpha.o
4-strpbrk.o
5-strstr.o
6-abs.o
9-strcpy.o
_putchar.o
$ amonkeyprogrammer@ubuntu:~/0x09. Static Librairies$
```

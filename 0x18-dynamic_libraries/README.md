# Dynamic libraries

# Learning Objectives

* What is a dynamic library, how does it work, how to create one, and how to use it
* What is the environment variable `$LD_LIBRARY_PATH` and how to use it
* What are the differences between static and shared libraries
* Basic usage `nm`, `ldd`, `ldconfig`

# Tasks

## A library is not a luxury but one of the necessities of life

Create the dynamic library libholberton.so containing all the functions listed below:

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

If you haven’t coded all of the above functions create empty ones, with the right prototype.
Don’t forget to push your `holberton.h` file in your repository, containing at least all the prototypes of the above functions.

```
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ ls -la lib*
-rwxrwxr-x 1 $ amonkeyprogrammer $ amonkeyprogrammer 13632 Jan  7 06:25 libholberton.so
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ nm -D libholberton.so 
0000000000000a90 T _abs
0000000000000aa9 T _atoi
0000000000202048 B __bss_start
                 w __cxa_finalize
0000000000202048 D _edata
0000000000202050 B _end
00000000000011f8 T _fini
                 w __gmon_start__
0000000000000900 T _init
0000000000000bd7 T _isalpha
0000000000000c04 T _isdigit
0000000000000c25 T _islower
0000000000000c46 T _isupper
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 w _Jv_RegisterClasses
0000000000000c67 T _memcpy
0000000000000caa T _memset
0000000000000ce9 T _putchar
0000000000000d0e T _puts
0000000000000d4a T _strcat
0000000000000dcf T _strchr
0000000000000e21 T _strcmp
0000000000000e89 T _strcpy
0000000000000eeb T _strlen
0000000000000f15 T _strncat
0000000000000fa5 T _strncpy
0000000000001029 T _strpbrk
000000000000109d T _strspn
0000000000001176 T _strstr
                 U write
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    printf("%d\n", _strlen("Holberton"));
    return (EXIT_SUCCESS);
}
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ gcc -Wall -pedantic -Werror -Wextra -L. 0-main.c -lholberton -o len
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ ldd len 
    linux-vdso.so.1 =>  (0x00007fff5d1d2000)
    libholberton.so => not found
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f74c6bb9000)
    /lib64/ld-linux-x86-64.so.2 (0x0000556be5b82000)
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ ldd len
    linux-vdso.so.1 =>  (0x00007fff41ae9000)
    libholberton.so => ./libholberton.so (0x00007fd4bf2d9000)
    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd4beef6000)
    /lib64/ld-linux-x86-64.so.2 (0x0000557566402000)
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ ./len 
9
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$
```

**Solution:** [libholberton.so](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/libholberton.so), [holberton.h](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/holberton.h)

## Without libraries what have we? We have no past and no future

Create a script that creates a dynamic library called `liball.so` from all the `.c` files that are in the current directory.

**Solution:** [1-create_dynamic_lib.sh](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/1-create_dynamic_lib.sh)

```
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ ls *.c
abs.c   isalpha.c  islower.c  memcpy.c  putchar.c  strcat.c  strcmp.c  strlen.c   strncpy.c  strspn.c
atoi.c  isdigit.c  isupper.c  memset.c  puts.c     strchr.c  strcpy.c  strncat.c  strpbrk.c  strstr.c
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ ./1-create_dynamic_lib.sh 
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$ nm -D --defined-only liball.so 
0000000000000a90 T _abs
0000000000000aa9 T _atoi
0000000000202048 B __bss_start
0000000000202048 D _edata
0000000000202050 B _end
00000000000011f8 T _fini
0000000000000900 T _init
0000000000000bd7 T _isalpha
0000000000000c04 T _isdigit
0000000000000c25 T _islower
0000000000000c46 T _isupper
0000000000000c67 T _memcpy
0000000000000caa T _memset
0000000000000ce9 T _putchar
0000000000000d0e T _puts
0000000000000d4a T _strcat
0000000000000dcf T _strchr
0000000000000e21 T _strcmp
0000000000000e89 T _strcpy
0000000000000eeb T _strlen
0000000000000f15 T _strncat
0000000000000fa5 T _strncpy
0000000000001029 T _strpbrk
000000000000109d T _strspn
0000000000001176 T _strstr
$ amonkeyprogrammer@ubuntu:~/0x18. Dynamic libraries$
```

## Let's call C functions from Python

Create a dynamic library that contains C functions that can be called from Python. See example for more detail.

**Solution:** [100-operations.so](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/100-operations.so)

```
$ amonkeyprogrammer@ubuntu:~/0x18$ cat 100-tests.py
import random
import ctypes

cops = ctypes.CDLL('./100-operations.so')
a = random.randint(-111, 111)
b = random.randint(-111, 111)
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
$ amonkeyprogrammer@ubuntu:~/0x16. Doubly linked lists$ python3 100-tests.py 
66 + -76 = -10
66 - -76 = 142
66 x -76 = -5016
66 / -76 = 0
66 % -76 = 66
$ amonkeyprogrammer@ubuntu:~/0x18$ python3 100-tests.py 
-34 + -57 = -91
-34 - -57 = 23
-34 x -57 = 1938
-34 / -57 = 0
-34 % -57 = -34
$ amonkeyprogrammer@ubuntu:~/0x18$ python3 100-tests.py 
-5 + -72 = -77
-5 - -72 = 67
-5 x -72 = 360
-5 / -72 = 0
-5 % -72 = -5
$ amonkeyprogrammer@ubuntu:~/0x18$ python3 100-tests.py 
39 + -62 = -23
39 - -62 = 101
39 x -62 = -2418
39 / -62 = 0
39 % -62 = 39
$ amonkeyprogrammer@ubuntu:~/0x18$
```

## Code injection: Win the Giga Millions!

I bought a ticket for the Giga Millions and chose these numbers: 9, 8, 10, 24, 75 + 9. If you could run two commands on the same server where the Giga Millions program runs, could you make me win the Jackpot?

* Our mole got us a copy of the program, you can download it [here](https://github.com/holbertonschool/0x18.c). Our mole also gave us a piece of documentation:

```
/* Giga Millions program                                                                                    
  * Players may pick six numbers from two separate pools of numbers:                                                
  * - five different numbers from 1 to 75 and                                                                       
  * - one number from 1 to 15                                                                                       
  * You win the jackpot by matching all six winning numbers in a drawing.                                           
  * Your chances to win the jackpot is 1 in 258,890,850                                                             
  *                                                                                           

  * usage: ./gm n1 n2 n3 n4 n5 bonus
```

* You can’t modify the program `gm` itself as Master Sysadmin Sylvain (MSS) always checks its [MD5](https://github.com/holbertonschool/0x18.c/blob/master/101-md5_gm) before running it
* The system is an `Linux Ubuntu 16.04`
* The server has internet access
* Our mole will be only able to run two commands from a shell script, without being detected by MSS
* Your shell script should be maximum 3 lines long. You are not allowed to use `;`, `&&`, `||`, `|`, `\`` (it would be detected by MSS), and have a maximum of two commands
* Our mole has only the authorization to upload one file on the server. It will be your shell script
* Our mole will run your shell script this way: `mss@gm_server$ . ./101-make_me_win.sh`
* Our mole will run your shell script from the same directory containing the program `gm`, exactly 98 seconds before MSS runs `gm` with my numbers: `./gm 9 8 10 24 75 9`
* MSS will use the same terminal and session than our mole
* Before running the `gm` program, MSS always check the content of the directory
* MSS always exit after running the program `gm`
* TL;DR; This is what is going to happen

```
mss@gm_server$ . ./101-make_me_win.sh
mss@gm_server$ rm 101-make_me_win.sh
mss@gm_server$ ls -la
. .. gm
mss@gm_server$ history -c
mss@gm_server$ clear
mss@gm_server$ ls -la
. .. gm
mss@gm_server$ md5sum gm
d52e6c18e0723f5b025a75dea19ef365  gm
mss@gm_server$ ./gm 9 8 10 24 75 9
--> Please make me win!
mss@gm_server$ exit
```

**Solution:** [101-make_me_win.sh](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/101-make_me_win.sh)

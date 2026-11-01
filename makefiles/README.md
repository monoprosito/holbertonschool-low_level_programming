# Makefiles

# Learning Objectives

* What are `make`, Makefiles
* When, why and how to use Makefiles
* What are rules and how to set and use them
* What are explicit and implicit rules
* What are the most common / useful rules
* What are variables and how to set and use them

# Tasks

## make -f 0-Makefile

Create your first Makefile.

Requirements:

* name of the executable: `holberton`
* rules: `all`
    * The `all` rule builds your executable
* variables: none

**Solution:** [0-Makefile](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1C-makefiles/0-Makefile)

```
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 0-Makefile 
gcc main.c holberton.c -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ ./holberton 
j#0000000000000000000000000000000000000
j#000000000000000000@Q**g00000000000000
j#0000000000000000*]++]4000000000000000
j#000000000000000k]++]++*N#000000000000
j#0000000000000*C+++]++]++]J*0000000000
j#00000000000@+]++qwwwp=]++++]*00000000
j#0000000000*+++]q#0000k+]+]++]4#000000
j#00000000*C+]+]w#0000*]+++]+]++0000000
j#0000we+]wW000***C++]++]+]++++40000000
j#000000000*C+]+]]+]++]++]++]+q#0000000
j#0000000*]+]+++++++]++]+++]+++J0000000
j#000000C++]=]+]+]+]++]++]+]+]+]=000000
j#00000k+]++]+++]+]++qwW0000000AgW00000
j#00000k++]++]+]+++qW#00000000000000000
j#00000A]++]++]++]++J**0000000000000000
j#000000e]++]+++]++]++]J000000000000000
j#0000000A]++]+]++]++]++000000000000000
j#000000000w]++]+]++]+qW#00000000000000
j#00000000000w]++++]*0##000000000000000
j#0000000000000Ag]+]++*0000000000000000
j#00000000000000000we]+]Q00000000000000
j#0000000000000@@+wgdA]+J00000000000000
j#0000000000000k?qwgdC=]4#0000000000000
j#00000000000000w]+]++qw#00000000000000
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$
```

## make -f 1-Makefile

Requirements:

* name of the executable: `holberton`
* rules: `all`
    * The `all` rule builds your executable
* variables: `CC`, `SRC`
    * `C`: the compiler to be used
    * `SRC`: the `.c` files

**Solution:** [1-Makefile](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1C-makefiles/1-Makefile)

```
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 1-Makefile
gcc main.c holberton.c -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 1-Makefile
gcc main.c holberton.c -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$
```

## make -f 2-Makefile

Create your first useful Makefile.

Requirements:

* name of the executable: `holberton`
* rules: `all`
    * The `all` rule builds your executable
* variables: `CC`, `SRC`, `OBJ`, `NAME`
    * `CC`: the compiler to be used
    * `SRC`: the `.c` files
    * `OBJ`: the `.o` files
    * `NAME`: the name of the executable
* The `all` rule should recompile only the updated source files
* You are not allowed to have a list of all the ``.o`` files

**Solution:** [2-Makefile](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1C-makefiles/2-Makefile)

```
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 2-Makefile
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ echo "/* Holberton */" >> main.c
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 2-Makefile
gcc    -c -o main.o main.c
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$
```

## make -f 3-Makefile

Requirements:

* name of the executable: `holberton`
* rules: `all`, `clean`, `oclean`, `fclean`, `re`
    * `all`: builds your executable
    * `clean`: deletes all Emacs and Vim temporary files along with the executable
    * `oclean`: deletes the object files
    * `fclean`: deletes the Emacs temporary files, the executable, and the object files
    * `re`: forces recompilation of all source files
* variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`
    * `CC`: the compiler to be used
    * `SRC`: the `.c` files
    * `OBJ`: the `.o` files
    * `NAME`: the name of the executable
    * `RM`: the program to delete files
* The `all` rule should recompile only the updated source files
* The `clean`, `oclean`, `fclean`, `re` rules should never fail
* You are not allowed to have a list of all the `.o` files

**Solution:** [3-Makefile](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1C-makefiles/3-Makefile)

```
$ amonkeyprogrammer@ubuntu:~/holberton/curriculum_by_$ amonkeyprogrammer/holbertonschool-low_level_programming/0x1C. Makefiles$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
holberton.c
main.c
main.c~
m.h
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make all -f 3-Makefile
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ ls -1
0-Makefile
1-Makefile
2-Makefile
3-Makefile
holberton
holberton.c
holberton.o
main.c
main.c~
main.o
m.h
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make clean -f 3-Makefile 
rm -f *~ holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make oclean -f 3-Makefile 
rm -f main.o holberton.o
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make fclean -f 3-Makefile 
rm -f *~ holberton
rm -f main.o holberton.o
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make all -f 3-Makefile
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make all -f 3-Makefile
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make re -f 3-Makefile
rm -f main.o holberton.o
gcc    -c -o main.o main.c
gcc    -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$
```

## A complete Makefile

Requirements:

* name of the executable: `holberton`
* rules: `all`, `clean`, `fclean`, `oclean`, `re`
    * `all`: builds your executable
    * `clean`: deletes all Emacs and Vim temporary files along with the executable
    * `oclean`: deletes the object files
    * `fclean`: deletes the Emacs temporary files, the executable, and the object files
    * `re`: forces recompilation of all source files
* variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`, `CFLAGS`
    * `CC`: the compiler to be used
    * `SRC`: the `.c` files
    * `OBJ`: the `.o` files
    * `NAME`: the name of the executable
    * `RM`: the program to delete files
    * `CFLAGS`: your favorite compiler flags: `-Wall` `-Werror` `-Wextra` `-pedantic`
* The `all` rule should recompile only the updated source files
* The `clean`, `oclean`, `fclean`, `re` rules should never fail
* You are not allowed to have a list of all the `.o` files

**Solution:** [4-Makefile](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1C-makefiles/4-Makefile)

```
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$ make all -f 4-Makefile
gcc -Wall -Werror -Wextra -pedantic   -c -o main.o main.c
gcc -Wall -Werror -Wextra -pedantic   -c -o holberton.o holberton.c
gcc main.o holberton.o -o holberton
$ amonkeyprogrammer@ubuntu:~/0x1C. Makefiles$
```

## make -f 100-Makefile

Requirements:

* name of the executable: `holberton`
* rules: `all`, `clean`, `fclean`, `oclean`, `re`
    * `all`: builds your executable
    * `clean`: deletes all Emacs and Vim temporary files along with the executable
    * `oclean`: deletes the object files
    * `fclean`: deletes the Emacs temporary files, the executable, and the object files
    * `re`: forces recompilation of all source files
* variables: `CC`, `SRC`, `OBJ`, `NAME`, `RM`, `CFLAGS`
    * `CC`: the compiler to be used
    * `SRC`: the `.c` files
    * `OBJ`: the `.o` files
    * `NAME`: the name of the executable
    * `RM`: the program to delete files
    * `CFLAGS`: your favorite compiler flags: `-Wall` `-Werror` `-Wextra` `-pedantic`
* The `all` rule should recompile only the updated source files
* The `clean`, `oclean`, `fclean`, `re` rules should never fail
* You are not allowed to have a list of all the `.o` files
* You have to use `$(RM)` for the cleaning up rules, but you are not allowed to set the `RM` variable
* You are not allowed to use the string `$(CC)` more than once in your Makefile
* You are only allowed to use the string `$(RM)` twice in your Makefile
* You are not allowed to use the string `$(CFLAGS)` (but the compiler should still use the flags you set in this variable)
* You are not allowed to have an `$(OBJ)` rule
* You are not allowed to use the `%.o`: `%.c` rule
* Your Makefile should work even if there is a file in the folder that has the same name as one of your rule
* Your Makefile should not compile if the header file `m.h` is missing

**Solution:** [100-Makefile](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x1C-makefiles/100-Makefile)

# argc, argv

# Learning Objectives

* How to use arguments passed to your program
* What are two prototypes of `main` that you know of, and in which case do you use one or the other
* How to use `__attribute__((unused))` or `(void)` to compile functions with unused variables or parameters

# Tasks

## It ain't what they call you, it's what you answer to

Write a program that prints its name, followed by a new line.

* If you rename the program, it will print the new name, without having to compile it again
* You should not remove the path before the name of the program

**Solution:** [0-whatsmyname.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0A-argc_argv/0-whatsmyname.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ gcc -Wall -pedantic -Werror -Wextra 0-whatsmyname.c -o mynameis
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mynameis 
./mynameis
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ mv mynameis mynewnameis
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mynewnameis 
./mynewnameis
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$
```

## Silence is argument carried out by other means

Write a program that prints the number of arguments passed into it.

* Your program should print a number, followed by a new line

**Solution:** [1-args.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0A-argc_argv/1-args.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ gcc -Wall -pedantic -Werror -Wextra 1-args.c -o nargs
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./nargs 
0
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./nargs hello
1
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./nargs "hello, world"
1
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./nargs hello, world
2
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$
```

## The best argument against democracy is a five-minute conversation with the average voter

Write a program that prints all arguments it receives.

* All arguments should be printed, including the first one
* Only print one argument per line, ending with a new line

**Solution:** [2-args.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0A-argc_argv/2-args.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ gcc -Wall -pedantic -Werror -Wextra 2-args.c -o args
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./args 
./args
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./args You can do anything, but not everything.
./args
You
can
do
anything,
but
not
everything.
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ 
```

## Neither irony nor sarcasm is argument

Write a program that multiplies two numbers.

* Your program should print the result of the multiplication, followed by a new line
* You can assume that the two numbers and result of the multiplication can be stored in an integer
* If the program does not receive two arguments, your program should print `Error`, followed by a new line, and return `1`

**Solution:** [3-mul.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0A-argc_argv/3-mul.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ gcc -Wall -pedantic -Werror -Wextra 3-mul.c -o mul
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mul 2 3
6
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mul 2 -3
-6
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mul 2 0
0
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mul 245 3245342
795108790
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./mul
Error
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ 
```

## To infinity and beyond

Write a program that adds positive numbers.

* Print the result, followed by a new line
* If no number is passed to the program, print `0`, followed by a new line
* If one of the number contains symbols that are not digits, print `Error`, followed by a new line, and return `1`
* You can assume that numbers and the addition of all the numbers can be stored in an `int`

**Solution:** [4-add.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x0A-argc_argv/4-add.c)

```
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ gcc -Wall -pedantic -Werror -Wextra 4-add.c -o add
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./add 1 1
2
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./add 1 10 100 1000
1111
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./add 1 2 3 e 4 5
Error
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ ./add
0
$ amonkeyprogrammer@ubuntu:~/0x0A. argc, argv$ 
```

# File I/O

# Learning Objectives

* Look for the right source of information online
* How to create, open, close, read and write files
* What are file descriptors
* What are the 3 standard file descriptors, what are their purpose and what are their `POSIX` names
* How to use the I/O system calls `open`, `close`, `read` and `write`
* What are and how to use the flags `O_RDONLY`, `O_WRONLY`, `O_RDWR`
* What are file permissions, and how to set them when creating a file with the `open` system call
* What is a system call
* What is the difference between a function and a system call

# Tasks

## Tread lightly, she is near

Write a function that reads a text file and prints it to the POSIX standard output.

* Prototype: `ssize_t read_textfile(const char *filename, size_t letters);`
* where letters is the number of letters it should read and print
* returns the actual number of letters it could read and print
* if the file can not be opened or read, return `0`
* if `filename` is `NULL` return `0`
* if `write` fails or does not write the expected amount of bytes, return `0`

**Solution:** [0-read_textfile.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x15-file_io/0-read_textfile.c)

```
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat Requiescat 
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
    }
    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-read_textfile.c -o a
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ./a Requiescat 
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.
(printed chars: 114)
Requiescat
by Oscar Wilde

Tread lightly, she is near
Under the snow,
Speak gently, she can hear
The daisies grow.

All her bright golden hair
Tarnished with rust,
She that was young and fair
Fallen to dust.

Lily-like, white as snow,
She hardly knew
She was a woman, so
Sweetly she grew.

Coffin-board, heavy stone,
Lie on her breast,
I vex my heart alone,
She is at rest.

Peace, Peace, she cannot hear
Lyre or sonnet,
All my life's buried here,
Heap earth upon it.

(printed chars: 468)
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$
```

## Under the snow

Create a function that creates a file.

* Prototype: `int create_file(const char *filename, char *text_content);`
* where `filename` is the name of the file to create and `text_content` is a `NULL` terminated string to write to the file
* Returns: `1` on success, `-1` on failure (file can not be created, file can not be written, `write` “fails”, etc…)
* The created file must have those permissions: `rw-------`. If the file already exists, do not change the permissions.
* if the file already exists, truncate it
* if `filename` is `NULL` return `-1`
* if `text_content` is `NULL` create an empty file

**Solution:** [1-create_file.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x15-file_io/1-create_file.c)

```
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat 1-main.c
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = create_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra 1-main.c 1-create_file.c -o b
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ./b hello world
-> 1)
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ls -l hello
-rw------- 1 $ amonkeyprogrammer $ amonkeyprogrammer 5 Dec  3 14:28 hello
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat hello 
world$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permis$
```

## Speak gently, she can hear

Write a function that appends text at the end of a file.

* Prototype: `int append_text_to_file(const char *filename, char *text_content);`
* where `filename` is the name of the file and `text_content` is the `NULL` terminated string to add at the end of the file
* Return: `1` on success and `-1` on failure
* Do not create the file if it does not exist
* If `filename` is `NULL` return `-1`
* If `text_content` is `NULL`, do not add anything to the file. Return `1` if the file exists and `-1` if the file does not exist or if you do not have the required permissions to write the file

**Solution:** [2-append_text_to_file.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x00-hello_world/0-preprocessor)

```
$ amonkeyprogrammer@ubuntu:~/c/curriculum_by_$ amonkeyprogrammer/holbertonschool-low_level_programming/0x15. File descriptors and permissions$ cat 2-main.c
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = append_text_to_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ echo -n Hello > hello
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ls -l hello
-rw-rw-r-- 1 $ amonkeyprogrammer $ amonkeyprogrammer 5 Dec  3 14:48 hello
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-append_text_to_file.c -o c
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ./c hello " World!
> "
-> 1)
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat hello 
Hello World!
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$
```

## cp

Write a program that copies the content of a file to another file.

* Usage: `cp file_from file_to`
* if the number of argument is not the correct one, exit with code `97` and print `Usage: cp file_from file_to`, followed by a new line, on the `POSIX` standard error
* if `file_to` already exists, truncate it
* if `file_from` does not exist, or if you can not read it, exit with code `98` and print `Error: Can't read from file NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error
    * where `NAME_OF_THE_FILE` is the first argument passed to your program
* if you can not create or if `write` to `file_to` fails, exit with code `99` and print `Error: Can't write to NAME_OF_THE_FILE`, followed by a new line, on the `POSIX` standard error
    * where `NAME_OF_THE_FILE` is the second argument passed to your program
* if you can not close a file descriptor , exit with code `100` and print `Error: Can't close fd FD_VALUE`, followed by a new line, on the `POSIX` standard error
    * where `FD_VALUE` is the value of the file descriptor
* Permissions of the created file: `rw-rw-r--`. If the file already exists, do not change the permissions
* You must read `1,024` bytes at a time from the `file_from` to make less system calls. Use a buffer
* You are allowed to use `dprintf`

**Solution:** [3-cp.c](https://github.com/monoprosito/holbertonschool-low_level_programming/blob/master/0x15-file_io/3-cp.c)

```
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra 3-cp.c -o cp
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat incitatous 
Why you should think twice before putting pictures on social media.
(What you always wanted to know about @Incitatous)
#PrivacyAware
http://imgur.com/a/Mq1tc
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ./cp incitatous Incitatous
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ ls -l Incitatous 
-rw-rw-r-- 1 $ amonkeyprogrammer $ amonkeyprogrammer 158 Dec  3 15:39 Incitatous
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$ cat Incitatous 
Why you should think twice before putting pictures on social media.
(What you always wanted to know about @Incitatous)
#PrivacyAware
http://imgur.com/a/Mq1tc
$ amonkeyprogrammer@ubuntu:~/0x15. File descriptors and permissions$
```

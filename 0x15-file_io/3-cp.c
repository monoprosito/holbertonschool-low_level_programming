#include <stdio.h>
#include "holberton.h"

/**
  * main - Entry point
  * @argc: The argument count
  * @argv: The argument vector
  *
  * Return: ...
  */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp %s %s\n", argv[1], argv[2]);
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}

/**
  * copy_file - ...
  * @src: ...
  * @dest: ...
  *
  * Return: ...
  */
int copy_file(const char *src, const char *dest)
{
	int ofd, tfd, readed = 0;
	char buff[1024];

	ofd = open(src, O_RDONLY);
	if (!src || ofd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	tfd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (tfd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		exit(99);
	}

	while ((readed = read(ofd, buff, 1024)) > 0)
		write(tfd, buff, readed);

	if (close(ofd) == -1 || close(tfd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %d\n", tfd);
		exit(100);
	}

	return (0);
}

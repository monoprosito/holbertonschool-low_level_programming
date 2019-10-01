#include "holberton.h"

/**
  * print_rev - Prints a string in reverse
  * @s: The string to print
  *
  * Return: void
  */
void print_rev(char *s)
{
	int c = 0;

	for (; *s != '\0'; s++)
	{
		c++;
	}

	for (; c >= 0; s--)
	{
		_putchar(*s);
		c--;
	}

	_putchar('\n');
}


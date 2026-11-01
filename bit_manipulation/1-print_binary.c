#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
  * print_binary - Prints the binary representation of a number
  * @n: The number to representing in binary
  *
  * Return: Nothing
  */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	_divide(n);
}

/**
  * _divide - ...
  * @n: ...
  *
  * Return: ...
  */
void _divide(unsigned long int n)
{
	if (n < 1)
		return;

	_divide(n >> 1);

	if (n & 1)
		_putchar('1');
	else
		_putchar('0');
}

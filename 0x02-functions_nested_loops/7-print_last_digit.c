#include "holberton.h"

/**
  * print_last_digit - Prints the last digit of a number
  * @n: The number to be treated
  *
  * Return: Value of the last digit of number
  */
int print_last_digit(int n)
{
	int l;

	if (n < 0)
	{
		n = n * -1;
	}

	l = n % 10;
	_putchar(l + '0');

	return (l);
}


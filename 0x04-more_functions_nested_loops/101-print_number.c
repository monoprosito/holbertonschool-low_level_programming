#include "holberton.h"

/**
  * print_number - Prints an integer.
  * @n: The integer to prints.
  *
  * Return: Nothing!
  */
void print_number(int n)
{
	unsigned int k = 0;

	if (n < 0)
		n *= -1, _putchar('-');

	k = n / 10;

	if (k != 0)
		print_number(k);

	_putchar(n % 10 + '0');

}

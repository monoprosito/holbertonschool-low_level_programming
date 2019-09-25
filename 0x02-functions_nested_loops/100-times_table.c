#include "holberton.h"

/**
  * print_times_table - Prints a multiplication table up to param
  * @n: The number to be treated
  *
  * Return: Number matrix
  */
void print_times_table(int n)
{
	int x, y, z;

	if (n < 15 && n > 0)
	{
		for (x = 0; x <= n; x++)
		{
			for (y = 0; y <= n; y++)
			{
				z = x * y;

				if (z > 99)
				{
					print_three_digits(z);
				}
				else if (z > 9)
				{
					print_two_digits(z);
				}
				else
				{
					if (y != 0)
					{
						print_spaces();
					}

					_putchar(z + '0');
				}
			}

			_putchar('\n');
		}
	}
}

/**
  * print_spaces - Print one digit format
  *
  * Return: empty
  */
void print_spaces(void)
{
	_putchar(',');
	_putchar(32);
	_putchar(32);
	_putchar(32);
}

/**
  * print_two_digits - Print two digits format
  * @n: The number to be treated
  *
  * Return: empty
  */
void print_two_digits(int n)
{
	int un = n % 10;
	int doz = (n / 10) % 10;

	_putchar(',');
	_putchar(32);
	_putchar(32);
	_putchar(doz + '0');
	_putchar(un + '0');
}

/**
  * print_three_digits - Print three digits format
  * @n: The number to be treated
  *
  * Return: empty
  */
void print_three_digits(int n)
{
	int un = n % 10;
	int doz = (n / 10) % 10;
	int hund = n / 100;

	_putchar(',');
	_putchar(32);
	_putchar(hund + '0');
	_putchar(doz + '0');
	_putchar(un + '0');
}

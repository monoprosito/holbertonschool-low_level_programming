#include <stdio.h>

/**
  * main - Prints the alphabetic in lower and upper case
  *
  * Return: Always (Success)
  */
int main(void)
{
	char c, d;

	d = 'z';

	for (c = 'a'; c <= d; c++)
	{
		putchar(c);

		if (c == 'z')
		{
			c = 'A';
			d = 'Z';
		}
	}

	putchar('\n');

	return (0);
}


#include "holberton.h"

int calc_signs(int num, int min, int mor);

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 0;
	int mor = 0;
	int isi;

	while (s[c])
	{
		if (s[c] == 43)
		{
			mor++;
		}

		if (s[c] == 45)
		{
			min++;
		}

		if (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
		}
		else
		{
			if ((s[c - 1] >= 48 && s[c - 1] <= 57) && (isi == 1))
			{
				break;
			}
		}
		c++;
	}

	if (c == 0)
		return (0);

	ni = calc_signs(ni, min, mor);

	return (ni);
}

/**
 * calc_signs - Convert a num to positive or negative
 * @num: The num to be convert
 * @min: Negative quantity
 * @mor: Positive quantity
 *
 * Return: A integer
 */
int calc_signs(int num, int min, int mor)
{
	int i, r;
	int x = 1;
	int y = 1;

	for (i = 0; i < min; i++)
	{
		x *= -1;
	}

	for (i = 0; i < mor; i++)
	{
		y *= 1;
	}

	r = (x * y) * num;
	return (r);
}


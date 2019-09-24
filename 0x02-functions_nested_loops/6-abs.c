#include "holberton.h"

/**
  * _abs - Computes the absolute value of an integer.
  *
  * Return: Absolute value of number or zero
  */
int _abs(int c)
{
	if (c < 0)
	{
		int abs_val = c * -1;
		return (abs_val);
	}

	return (0);
}

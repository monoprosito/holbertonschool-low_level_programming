#include "holberton.h"
#include <stdlib.h>

/**
  * array_range - ...
  * @min: ...
  * @max: ...
  *
  * Return: integer value
  */
int *array_range(int min, int max)
{
	int *a;

	if (min > max)
		return (NULL);

	a = malloc(max - min);

	while (min <= max)
	{
		a[min] = min;
		min++;
	}

	return (a);
}

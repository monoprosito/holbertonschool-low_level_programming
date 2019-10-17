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

	a = malloc(sizeof(int) * (max - min));

	if (a == NULL)
		return (NULL);

	while (min <= max)
	{
		a[min] = min;
		min++;
	}

	return (a);
}

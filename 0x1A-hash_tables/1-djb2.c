#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
  * hash_djb2 - A hash function with the djb2 algorithm.
  * @str: The value to which the function
  *
  * Return: A number representing the given string
  */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

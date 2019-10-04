#include "holberton.h"

/**
  * leet - ...
  * @s: ...
  *
  * Return: ...
  */
char *leet(char *s)
{
	int a = 0;

	while (s[a])
	{
		if (s[a] == 65 || s[a] == 97)
		{
			s[a] = 52;
		}

		a++;
	}

	return (s);
}


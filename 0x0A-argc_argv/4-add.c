#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * main - Prints the sum of args positive numbers
  * @argc: argument count
  * @argv: argument vector
  *
  * Return: Always zero
  */
int main(int argc, char *argv[])
{
	int i, sum = 0;
	char *h;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			h = argv[i];

			while (*h)
			{
				if (*h >= 48 && *h <= 57)
				{
					sum += atoi(h);
				}
				else
				{
					printf("Error\n");
					return (0);
				}
				h++;
			}
			h++;
		}
		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}

	return (0);
}


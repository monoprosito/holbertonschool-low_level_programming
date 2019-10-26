#include <stdio.h>
#include "variadic_functions.h"

/**
  * print_strings - ...
  * @separator: ...
  * @n: ...
  *
  * Return: ...
  */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;
	char *string;

	if (n > 0)
	{
		va_start(args, n);

		while (i < n)
		{
			string = va_arg(args, char *);
			if (string == NULL)
				printf("%s", "(nil)");
			else
				printf("%s", string);

			if (i != n - 1 && separator != NULL)
				printf("%s", separator);

			i++;
		}

		va_end(args);
	}

	printf("\n");
}

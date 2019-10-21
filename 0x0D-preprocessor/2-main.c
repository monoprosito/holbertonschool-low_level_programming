#include <stdio.h>

#ifndef __FILE__
#define __FILE__
#endif

/**
  * main - Prints the file name of the program
  *
  * Return: Always zero
  */
int main(void)
{
	printf("%s", __FILE__);
	return (0);
}

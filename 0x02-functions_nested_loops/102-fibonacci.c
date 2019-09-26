#include <stdio.h>

int main(void)
{
	int a, c  = 1;
	int b, r = 0;

	while (a <= 52)
	{
		if (a >= 2)
		{
			r = b + c;
			b = c;
			c = r;
			printf("%d", r);
			
			if (a < 52)
			{
				printf(", ");
			}
		}

		a++;
	}

	return (0);
}

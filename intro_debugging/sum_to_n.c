#include <stdio.h>

int sum_to_n(int n)
{
    int i;
    int sum = 0;

    for (i = 1; i <= n; i++)
        sum += i;

    return sum;
}

/* -- DO NOT Modify the code below this line -- */

int main(void)
{
    printf("%d\n", sum_to_n(10));
    return 0;
}

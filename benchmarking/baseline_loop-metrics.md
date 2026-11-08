#include <stdio.h>
#include <time.h>

#define ITERATION_COUNT 100000000UL

int main(void)
{
    volatile unsigned long long result;
    clock_t start;
    clock_t end;
    double elapsed;
    unsigned long i;

    result = 0;

    start = clock();

    for (i = 0; i < ITERATION_COUNT; i++)
        result += (unsigned long long)(i % 3);

    end = clock();

    elapsed = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("Iterations: %lu\n", (unsigned long)ITERATION_COUNT);
    printf("Execution time: %.6f seconds\n", elapsed);

    return 0;
}

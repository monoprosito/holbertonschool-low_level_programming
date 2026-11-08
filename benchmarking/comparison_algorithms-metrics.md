#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 50000

static int data[ARRAY_SIZE];

static void initialize_data(void)
{
    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
        data[i] = i;
}

static int count_even_naive(void)
{
    int count;
    int i;
    int j;

    count = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (data[j] % 2 == 0)
                count++;
        }
    }

    return count;
}

static int count_even_single_pass(void)
{
    int count;
    int i;

    count = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (data[i] % 2 == 0)
            count++;
    }

    return count;
}

int main(void)
{
    clock_t start;
    clock_t end;
    double elapsed_a;
    double elapsed_b;
    int result_a;
    int result_b;

    initialize_data();

    start = clock();
    result_a = count_even_naive();
    end = clock();
    elapsed_a = (double)(end - start) / (double)CLOCKS_PER_SEC;

    start = clock();
    result_b = count_even_single_pass();
    end = clock();
    elapsed_b = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("Naive algorithm result: %d\n", result_a);
    printf("Naive algorithm time: %.6f seconds\n", elapsed_a);
    printf("Single-pass algorithm result: %d\n", result_b);
    printf("Single-pass algorithm time: %.6f seconds\n", elapsed_b);

    return 0;
}

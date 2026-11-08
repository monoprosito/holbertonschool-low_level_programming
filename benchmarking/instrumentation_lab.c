#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int state) {
    state = (state * 1103515245u) + 12345u;
    return state;
}

static void build_dataset(void) {
    unsigned int state;
    int i;
    
    state = SEED_VALUE;
    for (i = 0; i < DATASET_SIZE; i++) {
        state = next_value(state);
        dataset[i] = (int)(state % 100000);
    }
}

static void process_dataset(void) {
    int i;
    int v;
    
    for (i = 0; i < DATASET_SIZE; i++) {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void) {
    unsigned long sum;
    int i;
    
    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];
    return sum;
}

int main(void) {
    unsigned long checksum;
    struct timespec start_total, end_total;
    struct timespec start_part, end_part;
    double total_sec, build_sec, process_sec, reduce_sec;

    clock_gettime(CLOCK_MONOTONIC, &start_total);

    clock_gettime(CLOCK_MONOTONIC, &start_part);
    build_dataset();
    clock_gettime(CLOCK_MONOTONIC, &end_part);
    build_sec = (end_part.tv_sec - start_part.tv_sec) + 
                (end_part.tv_nsec - start_part.tv_nsec) / 1000000000.0;

    clock_gettime(CLOCK_MONOTONIC, &start_part);
    process_dataset();
    clock_gettime(CLOCK_MONOTONIC, &end_part);
    process_sec = (end_part.tv_sec - start_part.tv_sec) + 
                  (end_part.tv_nsec - start_part.tv_nsec) / 1000000000.0;

    clock_gettime(CLOCK_MONOTONIC, &start_part);
    checksum = reduce_checksum();
    clock_gettime(CLOCK_MONOTONIC, &end_part);
    reduce_sec = (end_part.tv_sec - start_part.tv_sec) + 
                 (end_part.tv_nsec - start_part.tv_nsec) / 1000000000.0;

    clock_gettime(CLOCK_MONOTONIC, &end_total);
    total_sec = (end_total.tv_sec - start_total.tv_sec) + 
                (end_total.tv_nsec - start_total.tv_nsec) / 1000000000.0;

    if (checksum == 0ul) 
        printf("impossible\n");

    printf("TOTAL seconds: %.6f\n", total_sec);
    printf("BUILD_DATA seconds: %.6f\n", build_sec);
    printf("PROCESS seconds: %.6f\n", process_sec);
    printf("REDUCE seconds: %.6f\n", reduce_sec);

    return 0;
}


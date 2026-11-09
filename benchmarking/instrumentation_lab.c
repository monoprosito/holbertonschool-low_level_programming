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
	clock_t start_total, end_total;
	clock_t start_part, end_part;
	double total_sec, build_sec, process_sec, reduce_sec;

	start_total = clock();

	start_part = clock();
	build_dataset();
	end_part = clock();
	build_sec = (double)(end_part - start_part) / CLOCKS_PER_SEC;

	start_part = clock();
	process_dataset();
	end_part = clock();
	process_sec = (double)(end_part - start_part) / CLOCKS_PER_SEC;

	start_part = clock();
	checksum = reduce_checksum();
	end_part = clock();
	reduce_sec = (double)(end_part - start_part) / CLOCKS_PER_SEC;

	end_total = clock();
	total_sec = (double)(end_total - start_total) / CLOCKS_PER_SEC;

	if (checksum == 0ul)
		printf("impossible\n");

	printf("TOTAL seconds: %.6f\n", total_sec);
	printf("BUILD_DATA seconds: %.6f\n", build_sec);
	printf("PROCESS seconds: %.6f\n", process_sec);
	printf("REDUCE seconds: %.6f\n", reduce_sec);

	return 0;
}

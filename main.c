#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "util/bubble_sort.h"
#include "util/arrays.h"

#define BILLION 1000000000L

uint64_t getSeconds(struct timespec start, struct timespec end) {
  return BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
}

void varietySort(int n) {
  int* arrayOne = GenerateArray(n);
  int* arrayTwo = CopyArray(arrayOne, n);
  int* arrayThree = CopyArray(arrayOne, n);
  int* arrayFour = CopyArray(arrayOne, n);

  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);
  ForwardBubbleSort(arrayOne, n);
  clock_gettime(CLOCK_MONOTONIC, &end);
  if (IsSorted(arrayOne, n)) {
    printf("Forward \t%d\t%llu\n", n, (long long unsigned int) getSeconds(start, end));
  }

  clock_gettime(CLOCK_MONOTONIC, &start);
  BackwardBubbleSort(arrayTwo, n);
  clock_gettime(CLOCK_MONOTONIC, &end);
  if (IsSorted(arrayTwo, n)) {
    printf("Backward\t%d\t%llu\n", n, (long long unsigned int) getSeconds(start, end));
  }

  clock_gettime(CLOCK_MONOTONIC, &start);
  PingPongBubbleSort(arrayThree, n);
  clock_gettime(CLOCK_MONOTONIC, &end);
  if (IsSorted(arrayThree, n)) {
    printf("PingPong\t%d\t%llu\n", n, (long long unsigned int) getSeconds(start, end));
  }

  clock_gettime(CLOCK_MONOTONIC, &start);
  RandomBubbleSort(arrayFour, n);
  clock_gettime(CLOCK_MONOTONIC, &end);
  if(IsSorted(arrayFour, n)) {
    printf("Random\t%d\t%llu\n", n, (long long unsigned int) getSeconds(start, end));
  }
}

int main(int argc, char **argv) {
  srand(time(NULL));
  printf("Algorithm\tInputSize\tRunTime\n");

  for(int i = 2; i <= 100; i++) {
    varietySort(i);
  }

  for (int i = 1000; i <= 30000; i+=1000) {
    for (int j = 0; j < 10; j++) {
      varietySort(i);
    }
  }

  return 0;
}

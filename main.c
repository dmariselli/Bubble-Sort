#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "util/bubble_sort.h"
#include "util/arrays.h"

double getSeconds(clock_t start, clock_t end) {
  return (double) (end - start) / CLOCKS_PER_SEC;
}

void varietySort(int* array, int n) {
  clock_t start = clock();
  ForwardBubbleSort(array, n);
  clock_t end = clock();
  if (IsSorted(array, n)) {
    printf("Forward\t%d\t%g\n", n, getSeconds(start, end));
  }

  start = clock();
  BackwardBubbleSort(array, n);
  end = clock();
  if (IsSorted(array, n)) {
    printf("Backward\t%d\t%g\n", n, getSeconds(start, end));
  }

  start = clock();
  PingPongBubbleSort(array, n);
  end = clock();
  if (IsSorted(array, n)) {
    printf("PingPong\t%d\t%g\n", n, getSeconds(start, end));
  }
}

int main(int argc, char **argv) {
  printf("Algorithm\tInputSize\tRunTime\n");

  for (int i = 10; i <= 100000; i*=10) {
    int* array = GenerateArray(i);
    varietySort(array, i);
  }
  
  return 0;
}

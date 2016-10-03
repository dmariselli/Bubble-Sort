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

void varietySort(int n) {
  int* arrayOne = GenerateArray(n);
  int* arrayTwo = CopyArray(arrayOne, n);
  int* arrayThree = CopyArray(arrayOne, n);
  int* arrayFour = CopyArray(arrayOne, n);

  clock_t start = clock();
  ForwardBubbleSort(arrayOne, n);
  clock_t end = clock();
  if (IsSorted(arrayOne, n)) {
    printf("Forward\t%d\t%g\n", n, getSeconds(start, end));
  }

  start = clock();
  BackwardBubbleSort(arrayTwo, n);
  end = clock();
  if (IsSorted(arrayTwo, n)) {
    printf("Backward\t%d\t%g\n", n, getSeconds(start, end));
  }

  start = clock();
  PingPongBubbleSort(arrayThree, n);
  end = clock();
  if (IsSorted(arrayThree, n)) {
    printf("PingPong\t%d\t%g\n", n, getSeconds(start, end));
  }

  start = clock();
  RandomBubbleSort(arrayFour, n);
  end = clock();
  if(IsSorted(arrayFour, n)) {
    printf("Random\t%d\t%g\n", n, getSeconds(start, end));
  }
}

int main(int argc, char **argv) {
  srand(time(NULL));
  printf("Algorithm\tInputSize\tRunTime\n");

  for (int i = 10; i <= 100000; i*=10) {
    varietySort(i);
  }
  
  return 0;
}

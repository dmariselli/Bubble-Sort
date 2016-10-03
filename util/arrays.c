#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrays.h"

bool IsSorted(int* array, int length) {
  for (int i = 1; i < length; i++) {
    if (array[i-1] > array[i]) {
      return false;
    }
  }
  return true;
}

void PrintArray(int* array, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int* GenerateArray(int n) {
  int* a = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; i ++) {
    a[i] = rand();
  }
  return a;
}

int* CopyArray(int* old, int length) {
  int* new = (int*) malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++) {
    new[i] = old[i];
  }
  return new;
}

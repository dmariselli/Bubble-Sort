#include "bubble_sort.h"

void ForwardBubbleSort(int* array, int length) {
  for (int i = 0; i < length-1; i++) {
    for (int j = 0; j < length-1-i; j++) {
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

void BackwardBubbleSort(int* array, int length) {
  for (int i = length-1; i > 0; i--) {
    for (int j = length-1; j > i; j--) {
      if (array[j-1] > array[j]) {
        int temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      }
    }
  }
}

void PingPongBubbleSort(int* array, int length) {
  for (int i = 0; i < length-1; i++) {
    int start = 0;
    int end = length - 1;
    if (i%2 == 0) {
      for (int j = start; j < end; j++) {
        if (array[j] > array[j+1]) {
          int temp = array[j];
          array[j] = array[j+1];
          array[j+1] = temp;
        }
      }
      end--;
    }
    else {
      for (int j = end; j > start; j--) {
        if (array[j-1] > array[j]) {
          int temp = array[j-1];
          array[j-1] = array[j];
          array[j] = temp;
        }
      }
      start++;
    }
  }
}
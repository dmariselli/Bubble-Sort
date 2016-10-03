#ifndef UTIL_BUBBLE_SORT_H_
#define UTIL_BUBBLE_SORT_H_

// Implementation of bubble sort in the standard way
void ForwardBubbleSort(int* array, int length);

// Implementation of bubble sort going from the end of the array to the beginning
void BackwardBubbleSort(int* array, int length);

// Implementation of bubble sort that bounces back and forth from the front to the end of the array and back
void PingPongBubbleSort(int* array, int length);

// Implementation of bubble sort that randomly chooses a point in the array and its neighbor to switch with
void RandomBubbleSort(int* array, int length);

#endif

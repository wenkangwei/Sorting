
#ifndef SORTING_H
#define SORTING_H
#include <stdlib.h>
#include <stdio.h>
#include "HeapSort.h"

void bubble_Sort(int *arr, int len);
void selection_Sort(int *arr, int len);
void insertion_Sort(int *arr, int len);
void shell_Sort(int *arr, int len);
void quick_Sort(int *arr, int begin, int end);
// void merge_Sort(int *arr, int len);
void merge_Sort(int *arr, int len,int step,int groupNum);
heap heap_Sort(int *arr, int len);
#endif
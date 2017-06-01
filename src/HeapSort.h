#ifndef HEAP_SORT_H
#define HEAP_SORT_H 

typedef	 int* heap;
heap create_heap(int *arr, int len);
void insert_heap(heap hp, int value, int loc);
int archieve_root(heap root,int ArrLen);
heap heap_Sort(int *arr, int len);


#endif

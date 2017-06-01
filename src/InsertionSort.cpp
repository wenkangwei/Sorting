#include "Sorting.h"

void insertion_Sort(int *arr, int len)
{

	int temp;
	int j;
	// move to next location
	for (int i = 0; i < len; ++i)
	{
		// store the value of the location
		temp=arr[i];
		// compare the current element with the last elements
		for (j = i;j-1>=0&&temp<arr[j-1] ; j--)
		{
			arr[j]=arr[j-1];
		}
		arr[j]=temp;



	}



}
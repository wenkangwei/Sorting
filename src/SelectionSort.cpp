#include "Sorting.h"

void selection_Sort(int *arr, int len)
{
	int temp;
	int min;
	for (int i = 0; i < len; ++i)
	{
		min=arr[i];
		for (int j = i+1; j <len ; ++j)
		{
			if (arr[j]<min)
			{
				temp=min;
				min=arr[j];
				arr[j]=temp;
				arr[i]=min;
			}
		}
	}



}
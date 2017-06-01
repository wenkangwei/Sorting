#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"


void merge(int *merged, int *arr1, int *arr2, int size1,int size2)
{
	int result[size1+size2];
	int p1=0;
	int p2=0;	
	int p=0;
	while(p1<size1&&p2<size2)
	{
		if (arr1[p1]<arr2[p2])
		{
			result[p++]=arr1[p1++];
		}
		else
		{
			result[p++]=arr2[p2++];

		}

	}

	while(p1<size1)
		result[p++]=arr1[p1++];
	while(p2<size2)
			result[p++]=arr2[p2++];

	for (int i = 0; i < size1+size2; ++i)
	{
		merged[i]=result[i];
	}


}

void merge_Sort(int *arr, int len,int step,int groupNum)
{
	int group;
	int base=0;
	// groupNum render the amount of the group from the last time

	if(groupNum%2!=0) 
		group=(groupNum+1)/2;
	else
		group=groupNum/2;

	printf("Group Num: %d\n", group );
	for (int i = 0; i < group; ++i)
	{
		// find the base of the current group
		base=i*2*step;
		// judge whether the index exceeds the length of the array
		if (base+step<len)
		{
			
		printf("Group base: %d\n", base );
		merge(arr+base,arr+base,arr+base+step,step,step);
		}
		else
		{		//	if the index exceeds the maximum index, don't merge
				merge(arr+base,arr+base,arr+base,step,0);
		}

	}
		if(group>1)
			merge_Sort(arr,len,step*2, group);

}




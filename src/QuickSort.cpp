#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"


void quick_Sort(int *arr,int begin, int end);

void display(int arr[],int begin,int end)
{
int i;
for(i=begin;i<=end;i++)
printf ("%d ",arr[i]);
}



void quick_Sort(int *arr,int begin, int end)
{
	int pivot;
	int temp;
	int left,right;
	bool flag=false;
	left=begin;
	right=end;
	pivot=right;
	if (begin>=end)
	{
		return;
	}

	while(!flag)
	{

	printf("left: %d\n",left );
	printf("right:%d\n",right );

	// limit the minimum value of right and move right
	while(arr[right]>=arr[pivot]&&right>begin)
		right--;

	// limit the maximum value of left and move left
	while(arr[left]<=arr[pivot]&&left<end)
		left++;
	

	if (right>left)
	{
		
		temp=arr[right];
		arr[right]=arr[left];
		arr[left]=temp;
		
	}
	else
	{

		temp=arr[pivot];
		arr[pivot]=arr[left];
		arr[left]=temp;
		pivot=left;
		flag=true;
	}
	
	

	}
	quick_Sort(arr,begin,pivot-1);	
	quick_Sort(arr,pivot+1,end);
	

}


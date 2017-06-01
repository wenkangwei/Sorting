

#include "Sorting.h"



heap create_heap(int *arr, int len)
{
	heap top;
	int temp;
	top=arr;
	
	for (int i = 0; i < len; ++i)
	{
		insert_heap(top,arr[i],i);
		
	}
	return top;
}

/*
* insert data to heap
*/

void insert_heap(heap hp, int value, int loc)
{
	int i=0;
	int temp;
	int parent;

		// if location is valid
	if (loc>=0)
	{
			if (loc==0)
		{
			hp[loc]=value;
			return;
		}
			hp[loc]=value;

	while (loc>0)
	{
		// compare the value of new location with the value of the parent
			parent=(loc-1)/2;	
			if (hp[parent]<hp[loc])
			{
				hp[loc]=hp[parent];
				hp[parent]=value;
				
			}
			// move location upward in the heap
			loc=parent;
			
		
	}
	}
	else{
		printf("invalid location !\n");
	}


	
	

}

/*
* archieve root value and delete it from heap
*/

int archieve_root(heap root,int ArrLen)
{
	int top=0;
	int right=2, left=1;
	int result;
	result=root[top];
	if (ArrLen<=0)
	{
		printf("Please create heap first!\n");
		return 0;
	}
	while(top<ArrLen)
	{
		left=top*2+1;
		right=left+1;
		printf("Top value: %d\n",root[top] );
		printf("Top: %d  left: %d Right:%d \n",top,left,right );
		if (left<ArrLen)
		{
			if (right<ArrLen&&root[right]>root[left])
			{
				// when left and right children exist
				
				root[top]=root[right];
				top=right;
			}

			else
			{
				root[top]=root[left];
				top=left;
				
			}
		}
		else
		{
			// set the deleted value to zero if location isn't root
			if (top>0)
				{
					root[top]=0;
				}			
			break;
		}
		
	}

	return result;

}



/*
*	Heap sort and return sorted array
*/
heap heap_Sort(int *arr, int len)
{
	int temp[len];
	int heapLen=len;
	heap hp=create_heap(arr, len);

	for (int i = 0; i < len; ++i)
	{
	temp[len-1-i]=archieve_root(hp,len);
	
	}
	for (int i = 0; i < len; ++i)
	{
		arr[i]=temp[i];
	
	}


	
	return arr;
}
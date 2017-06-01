#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Sorting.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int length;
	int sorting=0;
	printf("Please choose one sorting algorithm:\n");
	scanf("%d",&sorting);
	if (sorting<1||sorting>6)
	{
		printf("invaild choice, Please input number from 1 to 6\n");
	}

	else
	{
	printf("Please input array length:\n");
	cin>>length;
	
	int array[length];
	printf("Please input data:\n");
	for(int i=0;i<length;i++)
	cin>>array[i];
	switch(sorting)
	{
		case 1:
			bubble_Sort(array,length);
			printf("Bubble Sort:\n");
			break;
		case 2:
			insertion_Sort(array,length);	
			printf("Insertion Sort:\n");
			break;
		case 3:
			selection_Sort(array,length);
			printf("Selection Sort:\n");
			break;
		case 4:
			quick_Sort(array,0,length-1);
			printf("Quick Sort:\n");
			break;
		case 5:
			merge_Sort(array,length,1,length);
			printf("Merge Sort:\n");
			break;
		case 6:
			heap_Sort(array,length);
			printf("Heap Sort:\n");
			break;
		default:
			
			break;
	}
		

		for(int j=0;j<length;j++)
			printf("%d\n", array[j] );
	
	
	
	
	// 
	// 
	// for(int j=0;j<length;j++)
	// 	printf("%d\n", array[j] );

	// 
	// 	insertion_Sort(array,length);
	// 	for(int j=0;j<length;j++)
	// 		printf("%d\n", array[j] );

	// 
	// 		selection_Sort(array,length);
	// 		for(int j=0;j<length;j++)
	// 			printf("%d\n", array[j] );
		// 
		// 
		// for(int j=0;j<length;j++)
		// 	printf("%d\n", array[j] );

		// 		
		// 

		// for(int j=0;j<length;j++)
		// 	printf("%d\n", array[j] );

		
}

	return 0;
}
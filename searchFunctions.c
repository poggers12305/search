#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "listFunctions.h"
#include "searchFunctions.h"

bool binarySearch(LIST *data, int key, int *location)
// Ask for number to search using binary search algorithm
{
	bool res=0;
	nodePtr mid, low, high;
	
	// initialize node pointers
	low = data->head;
	high = data->tail;
	
	// start binary search
	while (low->num<=high->num && key!=mid->num)  
	{
		// find middle node
		mid = findMid(data, low->index, high->index);	
	
		if (mid==high && mid==low && mid->num!=key)
		{
			return res;
		}
		if (mid->num == key)
		{
			res=1;
			*location = mid->index; 
		} 
		else if (mid->num > key)
		{
			high = mid->prev;
		}
		else if (mid->num < key)
		{
			low = mid->next;
		}
	} 
	return res;
}

nodePtr findMid(LIST *L, int l, int h)
{
	int x, i;
	nodePtr thisNode;
	thisNode = L->head;
	x = (l+h)/2;
	while (thisNode->index != x)
	{
		thisNode = thisNode->next;
	} 
	return thisNode;	
}

bool linearSearch(LIST *data, int key, int *location)
{
	bool res=0;
	nodePtr thisNode;
	thisNode = data->head;
	while (thisNode!=NULL && res!=1)
	{
		if (thisNode->num == key)
		{
			res=1;
			*location = thisNode->index; 
		}
		thisNode = thisNode->next;
	}
	return res;
}

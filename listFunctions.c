
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "listFunctions.h"
#include "searchFunctions.h"

void createList(LIST *L)
{
	int i, random[SIZE];
	nodePtr existing = L->head;
	// generate and sort 10 random numbers 
	numberData(random);
	// store sorted array data to list
	for (i=0; i<SIZE; i++)
	{
		if (L->count<10)
		// IF: no existing list
		{
			storeToList(L,random[i]);
		}
		else if (L->count==10)
		// ELSE IF: overwrite data in existing list
		{
			existing->num = random[i];
			existing = existing->next;
		}
	}
	return;
}

void numberData(int num[])
{
	int i;
	// get 10 random numbers
	getRandom(num);
	// sort in ascending order
	sortArray(num);	
	return;
}

void getRandom(int arr[])
{
	int i;
	time_t t;
	srand((unsigned) time(&t));
	for (i=0; i<SIZE; i++)
	{
		arr[i] = rand()%101;
	}
}

void sortArray(int arr[])
{
	int i, j, temp;
	for (i=0; i<SIZE; i++)
	{
    	for (j=i+1; j<SIZE; j++)
		{
	        if (arr[i] > arr[j])
	        {
	            temp = arr[i];
	            arr[i] = arr[j];
	            arr[j] = temp;
	        }
        }
    }
}

void storeToList(LIST *L, int x)
{
	nodePtr newNode = (nodePtr)malloc(sizeof(nodePtr));
	
	if (L->head==NULL) 
	// IF: no existing nodes
	{
		// create new node
		newNode->num = x;
		newNode->prev = NULL;
		newNode->next = NULL;
		newNode->index = L->count;
		L->head = newNode;
		L->tail = newNode;
		L->count++;
	}
	else
	// ELSE: there are existing nodes
	{
		// create succeeding node
		newNode->num = x;
		newNode->next = NULL;
		newNode->prev = L->tail;
		newNode->index = L->count;
		L->tail->next = newNode;
		L->tail = newNode;
		L->count++;
	}
	return;
}

void clearData(LIST *L)
// remove element at the rear/end/last of the list
{
	int i;
	for (i=1; i<=10; i++)
	{
		nodePtr preNode;
		if (L->head==L->tail)
		// IF: only one existing node in list
		{
			free(L->head);
			free(L->tail);
			L->head = NULL;
			L->tail = NULL;
			L->count = 0;
		}
		else
		// ELSE
		{
			preNode = L->tail->prev;
			free(L->tail);
			preNode->next = NULL;
			L->tail = preNode;
			// decrement node count
			L->count--;
		}
	}
	return;
}

void displayList(LIST *L)
{
	nodePtr thisNode;
	thisNode = L->head;
	if (L->head==NULL)
	// IF: no existing nodes
	{
	
		printf("List is empty!");	
	}
	// ELSE: there are existing nodes
	else
	{
		printf("\nLOCATION:\t");
		// display location
		while(thisNode!=NULL)
		{
			printf("%2d  ",thisNode->index);
			thisNode = thisNode->next;
		}
		
		thisNode = L->head;
		
		printf("\nDATA:\t\t");
		// display data
		while(thisNode!=NULL)
		{
			printf("%2d  ",thisNode->num);
			thisNode = thisNode->next;
		}
	}
	printf("\n");
	return;
}

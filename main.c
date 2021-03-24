#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "listFunctions.h"
#include "searchFunctions.h"

#define FALSE 0
#define TRUE 1

void displayMenu();

int main() 
{
	
	// initialization of list
	LIST *list = (LIST*)malloc(sizeof(LIST));
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	
	int ch, x, location, r=TRUE;
	while (r)
	{
		do
		{
			displayMenu();
			if (!scanf("%d", &ch))
			{
				printf("\nInvalid Input. Program terminated.");
				return 0;
			}
			else if (ch<1 || ch>5)
			{
				printf("\n\n\tNot within range. Try again.");
				getch();
				system("cls");
			} 
		} while (ch<1 || ch>5);
		
		switch(ch)
		{
			// Create List
			case 1: createList(list); 
					printf("\nNew list created!\n");
					displayList(list);
					break;
			
			// Display List
			case 2: if (list->head==NULL)
					{
						printf("\nList is empty. Please create list.\n");
					} 
					else
					{
						printf("\nHere is your current data set:\n");
						displayList(list); 
					}
					break;
			
			// Binary Search
			case 3: if (list->head==NULL)
					{
						printf("\nList is empty. Please create list.\n");
					} 
					else 
					{
						displayList(list);
						printf("\nEnter number to search:  ");
						if (!scanf("%d", &x))
						{
							printf("\nInvalid Input. Program terminated.");
							return 0;
						} 
						else
						{
							if (binarySearch(list, x, &location)==1)
							{
								printf("SEARCH FOUND in location %d", location);
							}
							else
							{
								printf("SEARCH NOT FOUND");
							}
						}
					}
					break;
			
			// Linear Search
			case 4: if (list->head==NULL)
					{
						printf("\nList is empty. Please create list.\n");
					} 
					else 
					{
						displayList(list);
						printf("\nEnter number to search:  ");
						if (!scanf("%d", &x))
						{
							printf("\nInvalid Input. Program terminated.");
							return 0;
						} 
						else
						{
							if (linearSearch(list, x, &location)==1)
							{
								printf("SEARCH FOUND in location %d", location);
								nodePtr thisNode = list->head;
								int n=1;
								// node containing key
								while (thisNode->index != location)
								{
									thisNode = thisNode->next;
								}
								thisNode = thisNode->next;
								while (thisNode->num==x)
								{
									printf("\nSEARCH FOUND in location %d", location+n);
									thisNode = thisNode->next;
									n++;
								} 
							}
							else
							{
								printf("SEARCH NOT FOUND");
							}
						} 
					}
					break;
			
			// Exit
			case 5: r=FALSE;
					break;
		}
		if (r)
		{
			printf("\n\n\t");
			system("pause");
			system("cls");
		}	
	}
	printf("\nThank you and Goodbye!");
	return 0;
}

void displayMenu()
{
	printf("\n[1]\tCreate List");
	printf("\n[2]\tDisplay List");
	printf("\n[3]\tBinary Search");
	printf("\n[4]\tLinear Search");
	printf("\n[5]\tExit");
	printf("\n\nEnter your choice:\t");
	
}

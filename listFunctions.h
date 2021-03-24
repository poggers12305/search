
#ifndef LISTFUNCTIONS_H
#define LISTFUNCTIONS_H

typedef struct node* nodePtr;

typedef struct node
{
	int num;
	int index;
	nodePtr prev, next;
} NODE;

typedef struct list
{
	int count;
	nodePtr head, tail;
} LIST;

#define SIZE 10

void createList(LIST *L);
void numberData(int num[]);
void getRandom(int arr[]);
void sortArray(int arr[]);
void storeToList(LIST *L, int x);
void clearData(LIST *L);
void displayList(LIST *L);


#endif

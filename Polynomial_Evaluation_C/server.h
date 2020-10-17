#include<stdio.h>
#include<stdlib.h>

// Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node *head;
	int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize(); 

/*Inserts data at the end of the List*/
void insert_at_end(List *list, int data);

/* Evaluates the polynomial for a given x */
long long int evaluate(List *list, int x);

/* deallocates resources held by the list */
void list_destroy(List* list);


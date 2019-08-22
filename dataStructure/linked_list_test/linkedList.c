#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
   int data;
   int key;
   struct node *next;
}node;


void printList(node* link)
{
	printf("[");
	while(link != NULL)
	{
		printf("(%d,%d),",link->key,link->data);
		link = link->next;
	}
	printf("]\n");
}

node* createLink(node * link)
{
	link = ( node*) malloc(sizeof( node));
	if(link!=NULL)
	{
		link->key = 0;
		link->data = 0;
		link->next = NULL;
	}
	return link;

}

void addLink(int data,int key,node *link)
{
	node *curr = link;
	
	while(curr->next!=NULL)
	{
		curr = curr->next;
	}
	curr->next = malloc(sizeof(node));
	curr = curr->next;
	curr->key = key;
	curr->data = data;
	curr->next = NULL;
}
void reverseLink(node **link)
{
	node* prev   = NULL;
	node* current = *head_ref;
	node* next;

	while (current != NULL) 
	{
		next  = current->next;
		current->next = prev;   
		prev = current;
		current = next;
   	}
	*head_ref = prev;
}

int main()
{
	node * link = NULL;
	link = createLink(link);
	addLink(5,0,link);
	addLink(10,0,link);
	printList(link);
	
	reverseLink(&link);
	printList(link);
	

	

	return 0;

}

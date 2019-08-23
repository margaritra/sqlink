#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
   int data;
   struct node *next;
}node;

struct node *root;


node* insertfirst(node* first,int data)
{
	first = malloc(sizeof(node));
	if(first!=NULL)
	{
		first->data = data;
		first->next = NULL;
		root = first;
	}
	return first;
}

node* addnode(node* firstNode, int data)
{
	if(firstNode!=NULL)
	{
		if(root == NULL)
		{
			root = firstNode;//only once
		}
		else
		{
			node * p;
			p = root;
			node * last = malloc(sizeof(node));
			if(last!=NULL)
			{
				last->data = data;
				last->next = NULL;
			}
			while(p->next!=NULL)
			{
				p = p->next;
			}
			p->next = last;
			return last;
		}
	}

}




void addLoop(node * loopnode)
{
	node* temp = root;
	if(loopnode!=NULL)
	{
		loopnode->next = temp->next;
	}
}

void reverseList(node *list)
{
	node * prev = NULL;
	node* curr = list;
	node * next ;

	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	root = prev;
}


int findMiddle(node* link)
{
	int i,mid;
	int count = 1;
	if(link!=NULL)
	{
		for(i = 0;link->next!=NULL;i++)
		{
			link = link->next;
			count++;
		}
		mid = count/2;
	}
	link = root;
	for(i = 1;i<=mid;i++)
	{
		if(i == mid)
		{
			return link->data;
		}
		link = link->next;
	}
}

int findLoop(node* link)
{
	node *p = link;
	node *q = link;
	while(p!=NULL & q!=NULL & q->next!=NULL)
	{
		p = p->next;
		q = q->next->next;
		if(p == q)
		{
			return 1;
		}
	}
	return 0;
}

void connectLinkedLists(node* first,node *first2)
{
	int i;
	for(i = 0;i<2;i++)
	{
		first= first->next;
	}
	if(first!=NULL && first2!=NULL)
	{
		first2 = first2->next;
		first2->next = first->next;
	}
}

int lengthList(node * list)
{
	int count = 1;
	int i;
	if(list!=NULL)
	{
		for(i = 0;list->next!=NULL;i++)
		{
			list = list->next;
			count++;
		}
		return count;

	}
}

node* commonNode(node* first,node* first2)
{
	if(first!=NULL & first2!=NULL)
	{
		int len1 ,len2,diff;
		int i;
		len1  = lengthList(first);
		printf("the length of first linked list is: %d\n",len1);

		len2  = lengthList(first2);
		printf("the length of second linked list is: %d\n",len2);

		if(len1>len2)
		{
			diff = len1-len2;
			for (i = 0;i<diff;i++)
			{
				first = first->next;
			}
		}
		else if(len1<len2)
		{
			diff = len2-len1;
			for (i = 0; i<diff ;i++)
			{
				first2= first2->next;
			}
		}
		else if(len1==len2)
		{
			diff = len2-len1;
		}
		node* p = first;
		node* q = first2;
		while(p!=NULL & q!=NULL)
		{
			p = p->next;
			q = q->next;
			if(p == q)
			{
				return p;
			}
		}

	}
	
}

void printList(node* link)
{
	printf("[");
	while(link != NULL)
	{
		printf("(%d),",link->data);
		link = link->next;
	}
	printf("]\n");
}

int main()
{
	node * first = NULL;
	node * first2 = NULL;
	node* midnode = NULL;
	node * mycommonNode= NULL;
	node * temp = malloc(sizeof(node));
	node* forLooop = NULL;
	int mid ;
	int len;
	int res = 0;
	first = insertfirst(first,5);

	addnode(first,10);
	addnode(first,15);
	addnode(first,25);
	addnode(first,35);

	first2 = insertfirst(first2,7);

	addnode(first2,17);
	connectLinkedLists(first,first2);

	mycommonNode = commonNode(first,first2);

	printf("the common node is: %d\n",mycommonNode->data);

	printList(root);
	
	mid = findMiddle(root);
	printf("the middle is: %d\n",mid);
	
	//printList(root);

	reverseList(root);
	printf("The reversed linked list is :");
	printList(root);

	forLooop = addnode(first,25);
	addLoop(forLooop);
	
	res = findLoop(root);
	if(res ==1)
	{
		printf("There is a loop in a linked list !\n");
	}
	else
	{
		printf("There is NO a loop in a linked list !\n");
	}
	

	

	return 0;

}

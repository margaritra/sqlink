#include <stdlib.h>
#include<stdio.h>
#include"bst.h"

typedef struct node{
	int data;   
	struct node* leftChild;
	struct node* rightChild;
}node;

typedef struct tree{
	node *root;
}tree;


tree* bstCreateRoot()
{
	tree* newTree;
	newTree = malloc(sizeof(tree));


	if(newTree!=NULL)
	{
		newTree->root = NULL;
		return newTree;	
	}
	return NULL;
}

void bstAdd(tree *t, int val)
{
	node* myNode;
	node *current;
   	node *parent;
	
	node *firstNode = malloc(sizeof(node));

	if(firstNode!=NULL)
	{
		firstNode->data = val;
		firstNode->leftChild = NULL;
		firstNode->rightChild = NULL;	
	}

	if(t->root == NULL)
	{	
		t->root = firstNode;
	}
	else
	{
		current = t->root;
		while(1) 
		{       
			         
			parent = current;

         		//go to left of the tree
         		if(val <= parent->data) 
			{                
            
            			//insert to the left
            			if(current->leftChild == NULL) 
				{
					parent->leftChild = firstNode;
					break;
            			}
				else
				{
					current = current->leftChild;
				}

         		}
			else if (val > parent->data)
			{
            
				//insert to the right
				if(current->rightChild == NULL) 
				{
					parent->rightChild = firstNode;
					break;
				}
				else
				{
					current = current->rightChild;
				}

			}
		}
	}
}

static void printInorder(node* root,treePrint printFunc) 
{ 
	if (root == NULL) 
	{
		return; 
	}
 
	printInorder(root->leftChild,printFunc); 

	printFunc(root->root->data);

	printInorder(root->root->rightChild,printFunc); 
} 


void bstwalk(tree* root,treePrint printFunc,Order myorder)
{
	if(root==NULL)
	{
		return;
	}
	else if(myorder==0)
	{
		printInorder(root->root,printFunc);
	}
	else if(myorder==1)
	{
		
		return;
	}
	else if(myorder==2)
	{
		
		return;
	}
}

/*

AdtStatus nodeDelete(tree *t, int val)
{
	
	return AllocationError;
}



static void print_AD(darray *dArr)
{
	
	int i;
	if(dArr!=NULL)
	{
		for(i=0;i<dArr->index;i++)
		{
			printf("*******************************************\n");
			printf("array :%d \n",dArr->arr[i]);
			printf("*******************************************\n");
		}
	}
}


AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
	int i = 0;  
	if(dArr)
	{
		if(dArr->arr)
		{
			for(i;i<dArr->index;i++)
			{
				destroyFunc(dArr->arr[i],context);
			}
		free(dArr->arr);
		}
	free(dArr);
	return OK;
	}
	return AllocationError;
}
*/

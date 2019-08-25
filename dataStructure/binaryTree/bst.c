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

static void printInorder(node* t,treePrint fun) 
{ 
	if (t == NULL) 
	{
		return; 
	}

	printInorder(t->leftChild,fun); 

	fun(t->data);

	printInorder(t->rightChild,fun); 
}  

static void printPreorder(node* t,treePrint fun) 
{ 
	if (t == NULL) 
	{
		return; 
	}
 
	fun(t->data);

	printPreorder(t->leftChild,fun); 

	printPreorder(t->rightChild,fun); 
}

static void printPostorder(node* t,treePrint fun) 
{ 
	if (t == NULL) 
	{
		return; 
	}
 
	printPostorder(t->leftChild,fun); 

	printPostorder(t->rightChild,fun); 

	fun(t->data);
}


void bstwalk(tree* t,treePrint printFunc,Order myorder)
{
	if(t==NULL)
	{
		return;
	}
	else if(myorder==0)
	{
		printf("*************Inorder*************\n");
		printInorder(t->root,printFunc);
		printf("\n*********************************\n");
	}
	else if(myorder==1)
	{
		printf("*************Preorder*************\n");
		printPreorder(t->root,printFunc);
		printf("\n**********************************\n");
	}
	else if(myorder==2)
	{
		printf("*************Postorder*************\n");
		printPostorder(t->root,printFunc);
		printf("\n***********************************\n");
	}
}



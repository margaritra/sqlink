#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

//root->root->data
void printNode(void* mynode)
{

	int* nd = (int*)mynode;
	printf("%d\n",nd);
}



void testFunc()
{
	tree *myroot;

	myroot = bstCreateRoot();

	bstAdd(myroot, 5);
	bstAdd(myroot, 10);
	bstwalk(printNode,0);
	
	
	}


int main()
{
	testFunc();
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

//root->root->data
void printNode(int value)
{
	printf("%d,",value);
}


void testFunc()
{
	tree *myroot;

	myroot = bstCreateRoot();

	bstAdd(myroot, 5);
	bstAdd(myroot, 10);
	bstAdd(myroot, 7);
	bstAdd(myroot, 4);
	bstAdd(myroot, 1);
	bstAdd(myroot, 3);
	bstwalk(myroot,printNode,0);
	bstwalk(myroot,printNode,1);
	bstwalk(myroot,printNode,2);

	//bstwalk(myroot,destroytree,0);
	
	
}


int main()
{
	testFunc();
	return 0;
}

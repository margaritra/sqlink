#ifndef H_BST
#define H_BST
#include <stdlib.h>
typedef enum  {Inorder, Preorder,Postorder} Order;

typedef struct tree tree;

typedef void (* treePrint)(int data);

tree* bstCreateRoot();
void bstAdd(tree *root, int val);

void printTheTree(tree* root);

void bstwalk(tree *t,treePrint printFunc,Order myorder);
#endif  

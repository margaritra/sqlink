
#ifndef H_BST
#define H_BST
#include <stdlib.h>
typedef enum  {Inorder, Preorder,Postorder} Order;

typedef void (* treePrint)(void* mytree);

typedef struct tree tree;


tree* bstCreateRoot();
void bstAdd(tree *root, int val);

void printTheTree(tree* root);

void bstwalk(treePrint printFunc,Order myorder);
#endif  
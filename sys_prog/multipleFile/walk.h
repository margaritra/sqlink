
#ifndef WALK_HEAD
#define WALK_HEAD


typedef struct node 
{
   char *data;
   struct node *next;
}node;

struct node *root;

node* walkDir(char *basedir,node* list);
#endif



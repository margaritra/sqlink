#include "hash_table.h"
#include<stdlib.h>

static char *mystrdup(char *s) {
	char *b;
	if (!(b = malloc(strlen((char*)s) + 1))) return NULL;
	strcpy(b, s);
	return b;
}

/*static hash_size def_hashfunc(const void *key) {
	hash_size hash = 0;
	while (*key) hash += (void)*key++;
	return hash;
}*/

HASHTBL *hashtbl_create(hash_size size, elemntHash hashFunc, elemntCompare compareFunc) 
{
	HASHTBL *hashtbl;

	if (!(hashtbl = malloc(sizeof(HASHTBL)))) 
		return NULL;

	if (!(hashtbl->nodes = calloc(size, sizeof(struct hashnode_s*)))) 
	{
		free(hashtbl);
		return NULL;
	}

	// added because calloc's 0s are not necessarily NULL
	for (int i = 0; i < size; i++) {
		hashtbl->nodes[i] = NULL;
	}

	hashtbl->size = size;

	hashtbl->hashFunc = hashFunc;
	hashtbl->compareFunc = compareFunc;

	return hashtbl;
}

void hashtbl_destroy(HASHTBL *hashtbl, elemntDestroy freeElement) 
{
	hash_size n;
	struct hashnode_s *node, *oldnode;

	for (n = 0; n<hashtbl->size; ++n) 
	{
		node = hashtbl->nodes[n];
		while (node) 
		{
			freeElement(node);
			/*free(node->key);
			oldnode = node;
			node = node->next;
			free(oldnode);*/
		}
	}

	free(hashtbl->nodes);
	free(hashtbl);
}

static void update(HASHTBL *hashtbl, struct hashnode_s *node, void* data, hash_size hash)
{
	node->data = data;
	node->next = hashtbl->nodes[hash];
	hashtbl->nodes[hash] = node;
}

int hashtbl_insert(HASHTBL *hashtbl,void *key, void *data) 
{
	struct hashnode_s *node;
	hash_size hash = hashtbl->hashFunc(key) % hashtbl->size; /*returnd index to insert the node*/
	int res= -1;

	node = hashtbl->nodes[hash];
	while (node) 
	{
		res = hashtbl->compareFunc(node->key, key);
		if(res == 0)
		{
			update(hashtbl,node,data,hash);
			break;
		}

		node = node->next;
	}
	if(res == -1)
	{
		if (!(node = malloc(sizeof(struct hashnode_s)))) 
		return -1;

		update(hashtbl,node,data,hash);
	}


	return 0;
}

void *hashtbl_find(HASHTBL *hashtbl, void *keys) 
{
	struct hashnode_s *node;
	hash_size hash = hashtbl->hashFunc(keys) % hashtbl->size;
	int res = -1;

	node = hashtbl->nodes[hash];
	while (node) 
	{
		res = hashtbl->compareFunc(node->key, keys);
		if(res == 0)
			return node;

		node = node->next;
	}

	return NULL;
}



void hashTableForEach(struct hashnode_s *node,elemntPrint printFunc)
{
	printFunc(node,printFunc);
}
#include "hash_table.h"
#include<stdlib.h>

HASHTBL *hashtbl_create(hash_size size, elemntHash hashFunc, elemntCompare compareFunc) 
{
	int i;
	HASHTBL *hashtbl;
	hashtbl = malloc(sizeof(HASHTBL));

	if (hashtbl==NULL) 
	{
		return NULL;
	}
	hashtbl->nodes = calloc(size,sizeof(hashnode_s*));

	if (hashtbl->nodes==NULL) 
	{
		free(hashtbl);
		return NULL;
	}

	for (i = 0; i < size; i++) 
	{
		hashtbl->nodes[i] = 0;
	}

	hashtbl->size = size;

	hashtbl->hashFunc = hashFunc;
	hashtbl->compareFunc = compareFunc;

	return hashtbl;
}

int initNode(hashnode_s *node,void*key,void *data,int sizeofkey,int sizeofdata)
{
	node->key = malloc(sizeofkey);
	if (node->key == NULL) 
	{
		return -1;
	}

	memcpy(node->key, key, sizeofkey);

	node->data = malloc(sizeofdata);
	if (node->data == NULL) 
	{
			return -1;
	}
	memcpy(node->data, data, sizeofdata);
	return 1;
}

AdtStatus hashtbl_insert(HASHTBL *hashtbl,void *key, void *data,int sizeofkey,int sizeofdata) 
{
	hashnode_s *node;
	hash_size hash = hashtbl->hashFunc(key) % hashtbl->size; /*returnd index to insert the node*/
	int res= -1;
	
	node = hashtbl->nodes[hash];
	
	while (node!=NULL) 
	{
		res = hashtbl->compareFunc(node->key, key);
		if(res == 0)
		{	
			free(node->key);
			free(node->data);
			initNode(node,key,data,sizeofkey,sizeofdata);
			node->next = NULL;
			return OK;
		}
		
		if(res == -1)
		{
			node = node->next;
			while(node!=NULL)
			{
				node = node->next;
			}
			node = malloc(sizeof(hashnode_s));
			initNode(node,key,data,sizeofkey,sizeofdata);
			node->next = NULL;
			hashtbl->nodes[hash]->next = node;
			return OK;
		}

	}

	if(res == -1)//insert in linked list first time
	{
		node = malloc(sizeof(hashnode_s));
		if (node==NULL) 
		{
			return -1;
		}
		initNode(node,key,data,sizeofkey,sizeofdata);
		node->next = NULL;
		hashtbl->nodes[hash] = node;
		return OK;
	
	}


	return Error;
}

void *hashtbl_find(HASHTBL *hashtbl, void *keys,elemntPrint printFunc) 
{
	struct hashnode_s *node;
	hash_size hash = hashtbl->hashFunc(keys) % hashtbl->size;
	int res = -1;

	node = hashtbl->nodes[hash];
	while (node!=NULL) 
	{
		res = hashtbl->compareFunc(node->key, keys);
		if(res == 0)
		{
			printf("The element is found :");
			printFunc(node->key,node->data);
			return node;
		}
		node = node->next;
	}
	printf("There is no such element!\n");
	return NULL;
}



void hashTableForEach(HASHTBL *hash,elemntPrint printFunc)
{
	int i;
	hashnode_s *currNode;
	for(i= 0;i<hash->size;i++)
	{
		currNode = hash->nodes[i];
		while(currNode!=NULL)
		{
			printFunc(currNode->key,currNode->data);
			currNode = currNode->next;
		}
	}
}

AdtStatus deleteHash(HASHTBL *hashtbl,void *key,elemntPrint printFunc)
{
	hashnode_s *node = NULL;
	hashnode_s * current = NULL;

	hash_size hash = hashtbl->hashFunc(key) % hashtbl->size; /*returnd index to insert the node*/
	node = hashtbl->nodes[hash];
	int res = -1;
	
	while (node!=NULL) 
	{
		res = hashtbl->compareFunc(node->key, key);
		if(res == 0)
		{
			if(current!=NULL)
			{
				current->next = node->next;		
			}
			else
			{
				hashtbl->nodes[hash] = node->next;
			}
			printf("The element found and deleted!\n");
			printFunc(node->key,node->data);
			free(node);
			return OK;
		}
		else
		{
			current = node;
			node = node->next;
		}
	}
	printf("The element is not found!\n");
	return Error;
}

void funcdestroy(hashnode_s *node)
{
	free(node->key);
	free(node->data);
}

void hashtbl_destroy(HASHTBL *hashtbl) 
{
	int i;
	hashnode_s *node;

	for (i = 0; i < hashtbl->size; i++) 
	{
		node = hashtbl->nodes[i];
		while (node!=NULL)
		{
			funcdestroy(node);
			node = node->next;
		}
	}

	free(hashtbl->nodes);
	free(hashtbl);
}

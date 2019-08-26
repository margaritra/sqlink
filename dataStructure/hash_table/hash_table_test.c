#include<stdio.h>
#include<stdlib.h>
#include"hash_table.h"

static void testFunc();
void freeElemnt(void *elemnt);
int compareElemnts(void *elemnt_A, void* elemnt_B);
hash_size def_hashfunc(void *key);
void hashPrint(void *hash);

int main()
{
	testFunc();
	return 0;
}

void testFunc()
{
	int choice=0;
	HASHTBL *hashtbl = NULL;
	hashtbl = hashtbl_create(10, def_hashfunc, compareElemnts);
	hashtbl_insert(hashtbl, "328865587", "margo");
	hashTableForEach(hashtbl->nodes,hashPrint);

}

void freeElemnt(void *elemnt)
{
	struct hashnode_s *oldnode;
	struct hashnode_s *elemnt1 = (struct hashnode_s*) elemnt;
	char *key = (char*) elemnt1->key;
	char *data = (char*) elemnt1->data;

	free(elemnt1->key);
	oldnode = elemnt1;
	elemnt1 = elemnt1->next;
	free(oldnode);
}

int compareElemnts(void *elemnt_A, void* elemnt_B)
{
	char* str1 = (char*) elemnt_A;
	char* str2 = (char*) elemnt_B;

	if (!strcmp(str1, str2)) 
	{
			return 0;
	}

	return -1;
}

hash_size def_hashfunc(void *key) 
{
	hash_size hash = 0;
	char* myKey = (char*) key;
	while (*myKey) 
		hash += (char)*myKey++;
	return hash;
}

void hashPrint(void *hash)
{
	struct hashnode_s* myhash = (struct hashnode_s*) hash;
	char *stam = (char*) myhash->key;
	printf("%s\n", stam);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash_table.h"

static void testFunc();
int compareElemnts(void *elemnt_A, void* elemnt_B);
hash_size def_hashfunc(void *key);
void hashPrint(void *key,void* data);

int main()
{
	testFunc();
	return 0;
}

void testFunc()
{
	HASHTBL *hashtbl;

	char *key = "72";
	char*data ="borodin";

	hashtbl = hashtbl_create(10, def_hashfunc, compareElemnts);

	hashtbl_insert(hashtbl, key, data,strlen(key),strlen(data));

	key = "27";//for insert the data with the same index in next node
	data ="ttttttt";

	hashtbl_insert(hashtbl, key, data,strlen(key),strlen(data));

	key = "27";//for inser the data with the same index in the same node
	data ="tdfgttttt";

	hashtbl_insert(hashtbl, key, data,strlen(key),strlen(data));

	key = "328865565";//for insert the data with the another index
	data ="rita";

	hashtbl_insert(hashtbl, key, data,strlen(key),strlen(data));

	hashTableForEach(hashtbl,hashPrint);

	hashtbl_find(hashtbl,"72",hashPrint);

	deleteHash(hashtbl,"72",hashPrint);

	printf("the result after delete:\n ");

	hashTableForEach(hashtbl,hashPrint);

	hashtbl_destroy(hashtbl);
}

int compareElemnts(void *elemnt_A, void* elemnt_B)
{
	char* str1 = (char*) elemnt_A;
	char* str2 = (char*) elemnt_B;

	if (strcmp(str1, str2)==0) 
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
		hash += *myKey++;
	return hash;
}

void hashPrint(void* key,void* data)
{
	 char* mykey = (char*) key;
	 char* mydata = (char*) data;
	
	printf("%s , %s\n", mykey,mydata);
}









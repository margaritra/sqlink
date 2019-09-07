
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "multFileDetc.h"
#include "hash_table.h"
#include "walk.h"



void testFunc();
int compareElemnts(void *elemnt_A, void* elemnt_B);
hash_size def_hashfunc(void *key);
void hashPrint(void *key,void* data);
int lengthList(node * list);


void test(int argc, char *argv[])
{
	HASHTBL *hashtbl;
	unsigned char *key;
	char *data ;
	int status;
	int sizeofEntireList;
	int file_descript;

	if(argc != 2) 
	{ 
        printf("Must specify the directory\n");
        exit(-1);
    }

    printf("using directory:\t%s\n", argv[1]);

	file_descript = open(argv[1], O_RDONLY);

    if(file_descript < 0) 
	{
		exit(-1);
	}
	//module for ops
	node * listofFiles = NULL;
	char *basedir = argv[1];
	listofFiles = walkDir(basedir,listofFiles); //return the node *listofFiles
	sizeofEntireList = lengthList(listofFiles);
	hashtbl = hashtbl_create(sizeofEntireList, def_hashfunc, compareElemnts);

	while(listofFiles != NULL)
	{
		key = getMd5FromFile(listofFiles->data);
		data = listofFiles->data;
		status = hashtbl_insert(hashtbl, key, data,strlen(key),strlen(data));
		if(status ==2)
		{
			printf("as %s!!!\n",listofFiles->data);
		}
		listofFiles = listofFiles->next;
	}
	hashtbl_destroy(hashtbl);
}


int main(int argc, char *argv[])
{
    test(argc,argv);
    return 0;
}

int lengthList(node * list)
{
	int count = 1;
	int i;
	if(list!=NULL)
	{
		for(i = 0;list->next!=NULL;i++)
		{
			list = list->next;
			count++;
		}
		return count;

	}
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







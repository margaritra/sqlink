
#ifndef HASH_TABELE_INCLUDE_GUARD
#define HASH_TABELE_INCLUDE_GUARD

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef size_t hash_size;//unsigned long
typedef enum  {OK, Error} AdtStatus;
typedef int(*elemntCompare)(void *elemnt_A, void* elemnt_B);

typedef size_t (*elemntHash)(void *key);
typedef void(*elemntPrint)(void *key,void *data);

typedef struct hashnode_s {
	void *key;
	void *data;
	struct hashnode_s *next;
}hashnode_s;

typedef struct hashtbl {
	hash_size size;
	struct hashnode_s **nodes;
	elemntHash hashFunc;
	elemntCompare compareFunc;
} HASHTBL;

HASHTBL *hashtbl_create(hash_size size, elemntHash hashFunc, elemntCompare compareFunc);
void hashtbl_destroy(HASHTBL *hashtbl);
AdtStatus hashtbl_insert(HASHTBL *hashtbl, void *key, void *data,int sizeofkey,int sizeofdata);
void *hashtbl_find(HASHTBL *hashtbl, void *keys,elemntPrint printFunc) ;
void hashTableForEach(HASHTBL *hash,elemntPrint printFunc);
AdtStatus deleteHash(HASHTBL *hashtbl,void *key,elemntPrint printFunc);

#endif


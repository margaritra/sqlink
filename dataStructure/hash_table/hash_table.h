
#ifndef HASH_TABELE_INCLUDE_GUARD
#define HASH_TABELE_INCLUDE_GUARD

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef size_t hash_size;

typedef void(*elemntDestroy)(void *elemnt);
typedef int(*elemntCompare)(void *elemnt_A, void* elemnt_B);

typedef size_t (*elemntHash)(void *key);
typedef void(*elemntPrint)(struct hashnode_s *node,void *hash);

struct hashnode_s {
	void *key;
	void *data;
	struct hashnode_s *next;
};

typedef struct hashtbl {
	hash_size size;
	struct hashnode_s **nodes;
	elemntHash hashFunc;
	elemntCompare compareFunc;
} HASHTBL;

HASHTBL *hashtbl_create(hash_size size, elemntHash hashFunc, elemntCompare compareFunc);
void hashtbl_destroy(HASHTBL *hashtbl, elemntDestroy freeElement);
int hashtbl_insert(HASHTBL *hashtbl, void *key, void *data);
void *hashtbl_find(HASHTBL *hashtbl, void *keys);


#endif


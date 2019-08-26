 /*based on code from http://en.literateprograms.org/Hash_table_(C)

 Copyright (c) 2010 the authors listed at the following URL, and/or
 the authors of referenced articles or incorporated external code:
 http://en.literateprograms.org/Hash_table_(C)?action=history&offset=20100122102906

 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/

// Retrieved from: http://en.literateprograms.org/Hash_table_(C)?oldid=16632 

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


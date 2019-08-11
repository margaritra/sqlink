
#ifndef DA_H
#define DA_H


typedef struct { 

	int *arr;
	int capacity;
	int index;
} da_t;

da_t* my_create(int capacity);
int my_insert(da_t *arr,int num);
void print_da(da_t* array);
void destroy_da(da_t* array);


#endif

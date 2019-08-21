/****************************************************************************
    Created by: Yuval Shaul.
    Creation date:      12.8.2019
    Description: Dynamic array, that grows and shrinks automatically.
*****************************************************************************/
#ifndef H_DARRAY
#define H_DARRAY
#include <stdlib.h>
typedef enum  {OK, AllocationError} AdtStatus;
typedef void (* elementDestroy)(void *_elem, void *context);
typedef int (* elementCompare)(void *_elemA, void *_elemB);
/* forward declaration of the darray type */
typedef struct darray darray;
AdtStatus darrayCreate(darray **dArr, size_t initial_capacity);
AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context);
darray *   darrayAdd(darray *dArr,  void  *_item);
AdtStatus   darrayDelete(darray *dArr,  void **_item);
AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item);
AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item);
int   darrayItemsNum(darray *dArr, int*  _numOfItems);
AdtStatus darraySort(darray *dArr); /* correct this !!! */
#endif  
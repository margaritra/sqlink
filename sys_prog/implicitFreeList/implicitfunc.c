#include <stdio.h>
#define SET_FREE(header) ((header) & 0xefffffff)
#define SET_OCCUPIED((header) | 0x80000000)
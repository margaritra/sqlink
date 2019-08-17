#ifndef DA_H
#define DA_H



typedef struct { 
	int m_nf;
	int *m_arr;
	
} bitmap;

bitmap* createBitmap(int nf);
int isbit(bitmap* bm ,int n);
int bitON(bitmap* bm ,int n);
int bitOFF(bitmap* bm ,int n);
int isVaidOperation(int n,int nf);
#endif


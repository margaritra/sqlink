#ifndef DA_H
#define DA_H



typedef struct { 
	int m_nf;
	int *m_arr;
	
} bitmap;

bitmap* createBitmap(int nf);
int Int2Bin(int n);
int Bin2Int(int bin);
int isbit(bitmap* bm ,int n);

#endif

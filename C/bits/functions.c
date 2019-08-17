#include <stdio.h>
#include <stdlib.h>
#include "head.h"

bitmap* createBitmap(int nf)
{
	bitmap* m_nf = malloc(sizeof(bitmap));
	int size;
	if(m_nf!=0)
	{
		m_nf->m_nf = nf;
		size = nf/8;
		if(nf%8==0)
		{
			m_nf->m_arr = calloc(size,sizeof(int));
			if(m_nf->m_arr!=0)
			{
				return m_nf;
			}
		}
		else
		{
			size += 1;
			m_nf->m_arr = calloc(size,sizeof(int));
			if(m_nf->m_arr!=0)
			{
				return m_nf;
			}
		}
	}
}

int isbit(bitmap* bm ,int n)
{
	int location_byte = 0;
	int loc_bit = 0;
	unsigned int ezer = 1;
	int for_shift ;
	int total ;
	int nf = bm->m_nf ;
	
	if(!isVaidOperation(n,bm->m_nf))
	{
		return -1;
	}

	location_byte = n/8;
	loc_bit = n%8;
	loc_bit =loc_bit-1;
	for_shift = ezer<<loc_bit;
	printf("\n");
	
	total = bm->m_arr[location_byte] & for_shift;

	if (total == '\x00' )
	{
		printf("*************************************\n");
		printf("The status: %d bit is OFF!\n",n);
		printf("*************************************\n\n");
		
		return 0;
	}
	else
	{
		printf("*************************************\n");
		printf("The status : %d bit is ON! \n",n);
		printf("*************************************\n\n");
		printf("\n");
		return 1;
	}
	
}


int bitON(bitmap* bm ,int n)
{
	unsigned int ezer = 1;
	int location_byte = 0;
	int loc_bit = 0;
	int for_shift =0;
	int nf = bm->m_nf ;

	if(!isVaidOperation(n,bm->m_nf))
	{
		return -1;
	}
	
	location_byte = n/8;
	loc_bit = n%8;

	loc_bit =loc_bit-1;
	for_shift = ezer<<loc_bit;
	bm->m_arr[location_byte] = bm->m_arr[location_byte] | for_shift;
	return isbit(bm,n);

}


int bitOFF(bitmap* bm ,int n)
{
	unsigned int ezer = 255;
	unsigned int ezer2 = 1;	
	int for_shift;
	int location_byte = 0;
	int loc_bit = 0;
	int i = 1;

	if(!isVaidOperation(n,bm->m_nf))
	{
		return -1;
	}

	location_byte = n/8;
	loc_bit = n%8;

	for_shift = ezer<<loc_bit;

	if(n!=1)
	{
		for_shift = for_shift | ezer2;
	}

	for(i;i<loc_bit-1;i++)
	{
		ezer2 = 1;
		ezer2 = ezer2<<i;
		for_shift = for_shift | ezer2;
	}
	ezer = for_shift;

	bm->m_arr[location_byte] = bm->m_arr[location_byte] & ezer;
	return isbit(bm,n);
}

int isVaidOperation(int n,int nf)
{
	int size;
	int bits;
	size = nf/8;
	if(n>nf)
	{
		printf("Your location is out of boundary,\n Please enter the valid location!\n");
		return 0;
	}
	return 1;
}



static int Int2Bin(int n)
{
	int a[100];
	int i = 0;

	
	if(n>=0)
	{
		for(i=0;n>0;i++)    
		{    
			a[i]=n%2;    
			n=n/2;    
		}

	        printf("\n The Binary number is = "); 
		for(i =i-1; i>=0 ;i--)
		{
			printf("%d",a[i]);
		} 
		printf("\n");
	}
	if(n<0)
	{
		return 0;   
	}
}









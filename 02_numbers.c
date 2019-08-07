#include <stdio.h>

int poli(int k);
int asc(int num);
int perf_num(int if_perf);
int revr(int if_rev);
int primer(int if_prim);

 
int main () {
	
   int result,k,h ,result1,result2,result3,perf,if_rev,if_prim,result4= 0;

   printf("enter polindrome: ") ;

   scanf("%d",&k);

   result = poli(k);
	
   printf("%d\n",result);

   printf("enter number: ") ;

   scanf("%d",&h);

   result1 = asc(h);
	
   printf("%d\n",result1);

   printf("enter number: ") ;

   scanf("%d",&perf);

   result2 = perf_num(perf);
	
   printf("%d\n",result2);

   printf("enter number: ") ;

   scanf("%d",&if_rev);

   result3 = revr(if_rev);
	
   printf("%d\n",result3);

   printf("enter number: ") ;

   scanf("%d",&if_prim);

   result4 = primer(if_prim);
	
   printf("%d\n",result4);
	
	
   
   return 0;
}

int poli(int k)//121
{

	int temp,r = 0;
	temp = k;
 //for example :121
   while (temp != 0)//12!=0,
   {
      r = r * 10;//0,10,120
      r = r + temp%10;//1,12,121
      temp = temp/10;//12,1,0
   }
 
   if (k == r)//121==121
      {
	return 1;}
	
   else   
  
  return 0;
 

}



int asc(int num)
{
	int temp,r ,k,max= 0;
	temp = num;
	//1234
	while(temp!=0)//
	{
		r = temp%10;//4
		
		
		k = temp/10;//123
		k = k%10;//3
		temp = temp/10;//123	
		
		if(r>k)
		{
			max=k;//3,2,1
		}
		else
		{return 0;}

	}
	return 1;


}

int perf_num(int if_perf)//if_perf = 6
{
	int temp,sum= 0;
	int i = 1;
	
	for (i ;i<if_perf;i++)
	{
		if(if_perf%i == 0)//yes,
		{
			
			sum+=i;//1
			//printf("%d\n",sum);
		
		}
		
	}
	if(sum == if_perf)
		{
			return 1;
		}
	else
		{
			return 0;
		}

}


int revr(int k)//121
{

	int temp,r = 0;
	temp = k;

   while (temp != 0)
   {
      r = r * 10;
      r = r + temp%10;
      temp = temp/10;
   }
 
 return r;
 

}

int primer(int if_prim)
{
	int i = 3;

	
	if(if_prim %2 == 0)
	{
		return 0;
	}
	else 
	{
		for(i ;i<if_prim;i++)
		{
			if(if_prim %i == 0)
			{
				return 0;
			}
			
		}
		return 1;
	}




}
















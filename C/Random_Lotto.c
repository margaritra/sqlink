

#include <stdio.h>     
#include <stdlib.h>    
#include <time.h>  

int fun_rand();
void my_print(int *arr,int size);
int my_2d_array(int *arr,int size);


int main ()
{
  int result = 0;
  int arr[6];
  int size = 6;
  int i = 0;
  srand (time(NULL));

  for (i;i<size;i++)
  {
    arr[i] = fun_rand();
  }

  my_print(arr,size);
  my_2d_array(arr,size);

  return 0;
}

int fun_rand()
{
    int iSecret = 0;

    
    iSecret = rand() % 49 + 1;
    
  return iSecret;
}

void my_print(int *arr,int size)
{
  int i = 0;
  for(i;i<size;i++)
  {
    printf("%d ",arr[i]);
    
  }
  printf("\n");
}

int my_2d_array(int *arr,int size)
{
   int i = 0;
   int j = 1;
   int num = 0;
   int index = 0;
   int first = 0;
   int last = 0;

   char a[5][10] = { {'-','-','-','-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-','-','-','-'},
                     {'-','-','-','-','-','-','-','-','-',' '}};
   
  for(index;index<6;index++)
  {
    num = arr[index];
    first = num/10;
    last = num%10;
    a[first][last-1] = '+';
    
  }
 /* output each array element's value */
   
   for ( i = 0; i < 5; i++ ) 
   {
      for ( j = 0; j < 10; j++ ) 
      {
         printf("%c", a[i][j] );
      }
      printf("\n");
   }
  





  
}

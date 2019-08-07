#include <stdio.h>
 
void print(int *arr,int size);

int my_sort_zeros(int *arr,int size);

int my_sort_numbers(int *arr1 ,int size1);

int my_sort_even_odd(int *num,int size);

int freq(int *num2,int size);



int main () {

int size = 8;

int size1 = 4;

int arr[8] = {0,0,1,0,1,0,0,0};

int arr1[4] = {1,2,3,4};

int size2 = 6;

int i = 0;

int num[5];

int num2[6];

int result = 0;





print(arr,size);

my_sort_zeros(arr,size);

my_sort_numbers(arr1,size1);

for(i;i<size2;i++)

{
	printf("enter number: ") ;

	scanf("%d",&num[i]);
	
}

my_sort_even_odd(num,size2);

i = 0;

for(i;i<size2;i++)

{
	printf("enter number: ") ;

	scanf("%d",&num2[i]);
	
}

result = freq(num2,size2);

printf("result : %d\n",result) ;

}

void print(int *arr,int size)
{
	int i = 0;

	for (i;i<size;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");


}

int my_sort_zeros(int *arr,int size)
{

	int temp = 0,temp1 = 0,count_zeros = 0;
	int i = 0;
	
	for(i;i<size;i++)
	{
		if(arr[i]==0)
		{
			count_zeros+=1;
			
		}
		
	}

	//printf("%d\n",	count_zeros);
	
	for(temp;temp<count_zeros;temp++)
	{
		arr[temp] = 0;
	}
	temp1 = count_zeros;

	for(temp1;temp1<size;temp1++)
	{	
		arr[temp1] = 1;
	}

	print(arr,size);

}

int my_sort_numbers(int *arr1,int size1)
{
	int i = 1;
	int count_changes = 0;
	int temp = 0;
	
	for(i;i<size1;i++)
	{
		if(arr1[i-1] > arr1[i])//5,1
		{
			temp = arr1[i-1];//5,1
			
			arr1[i-1] = arr1[i]; //

			arr1[i] = temp;

			count_changes++;
			
		}
		if (count_changes == 0)
		{

			break;
			
		}

	}

		
	print(arr1,size1);

}




int my_sort_even_odd(int *num,int size)
{
	int i = 0;
	int count_even = 0;
	int temp = 0;
	
	
	for(i;i<size;i++)
	{
		if(num[i]%2 == 0)
		{
			count_even++;
		}
	
	}
	
	i = 1;
	for(i;i<size;i++)
	{
		if (num[i-1]%2!=0 && num[i]%2==0)
		{
			temp = num[i-1];
			num[i-1] = num[i];
			num[i] = temp;
		}
		
	
	}

	i = 0;
	for(i;i<count_even;i++)
	{	
		if(num[i] % 2 == 0)
		{	
			break;
		}
	}

	print(num,size);
	

}


int freq(int *num2,int size)
{
	int i = 0;
	int temp = 0;
	int j = 0;
	int count = 0;
        int min = 0;
	int max = 0;
	int x = 0;

		
	for(i;i<size;i++)//2//3
	{
		temp = num2[i];
		j = i+1;
		for (j;j<size;j++)
		{
			if(temp==num2[j])
			{
				count+=1;
			}
			
		}
		min = count;
		

		if(max < min)
		{
			max = min;
			x = temp;
		}
		count = 0;
		
	}
	
	return x;
	

}










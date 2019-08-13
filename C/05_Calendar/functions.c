#include <stdio.h>
#include <stdlib.h>
#include "head.h"


calendar_t* create_ad(int capacity)
{
	calendar_t * meet ;
	if(meet!=NULL)
	{
		meet = malloc(sizeof(calendar_t));
		meet->capacity = capacity;
		meet->index = 0;

		meet->meeting = malloc(capacity*sizeof(intPtr));//sizeof(intPtr)
		return meet;
	}
}

meeting_t* create_meet()
{
	meeting_t* meeting ;
	float start;
	float end ;
	int room;
    	meeting = malloc(sizeof(meeting_t));
	if(meeting!=NULL)
	{
		printf("Enter the start ,end and room number: \n");    
		scanf("%f%f%d",&start,&end,&room); 
		//bdika from 0 to 24
		meeting->start_h = start;
		meeting->end_h = end;
		meeting->room = room;
	}
	
	return meeting;
}

void shift_right(calendar_t* calebdar,int i)
{
	meeting_t temp = meets[0];
	meeting_t temp2;

	//meets[0] = NULL;
	for(int i=1;i<size;i++)
	{
		temp2 = meets[i];
		meets[i] = temp;
		temp = temp2;
	}
}


int insert_appointment(calendar_t *calendar , meeting_t* meet)
{
	intPtr* temp;
	temp = calendar->meeting;

	if(calendar->meeting!=NULL && calendar!=NULL && meet!=NULL)
	{
		if(calendar->index==0)//first insert
		{
			calendar->meeting[0] = meet;//10 -11
			calendar->index++;
			return 1;
		}

		else //x inserts
		{
			if(calendar->capacity <= calendar->index)//if index>meetingsAmount
			{
				calendar->meeting = realloc(calendar->meet,calendar->capacity*2*sizeof(intPtr));//(ptr, size)
				calendar->capacity *= 2;
       		}

			if(calendar->meeting!=NULL)
			{
				for(int i=0;i<calendar->index;i++)
				{	
					if(i == calendar->index-1 && calendar->meeting[i]->end_h > meet->start_h)
					{
				
						calendar->meeting[i] = meet;
						calendar->index++;
						return 1;

					}
	
					else if(calendar->meeting[i]->end_h < meet->start_h && calendar->meeting[i+1]->start_h > meet->end_h )
					{
						shift_right(calendar->meeting[i],(calendar->index)-i);
						calendar->meeting[i] = meet;
						calendar->index++;
						return 1;
					}
					else if(calendar->meeting[i]->start_h > meet->end_h && i == 0)
					{
						shift_right(calendar->meeting[i],(calendar->index)-i);
						calendar->meeting[i] = meet;
						calendar->index++;
						return 1;
					}
					
				}
			calendar->meeting[calendar->index-1] = meet;//if index>meetingsAmount && if index<meetingsAmount
			calendar->index++;
			return 1;
			}
			else
			{
				calendar->meeting = temp;
				return 0;
			}
		}
    }
    return 0;
}



void print_AD(calendar_t * calendar)
{
	if(calendar!=NULL)
	{
		for(int i=0;i<calendar->index;i++)
		{
			printf("*******************************************\n");
			printf("start :%f\n",calendar->meeting[i]->start_h);
			printf("end :  %f\n",calendar->meeting[i]->end_h);
			printf("room : %d\n",calendar->meeting[i]->room);
			printf("*******************************************\n");
		}
	}
}
/*
void destroy_da(calendar_t * calendar)
{
	if((calendar->meeting)!=0)
	{
		for(int i = 0;i<calendar->index;i++)
		{
			free(calendar->meeting[i]);
		}
		free(calendar->meeting);
	}
	if (calendar!=0)
	{
		free(calendar);
	}
	
}

*/





	


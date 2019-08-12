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
	meeting_t meeting ;
	float start;
	float end ;
	int room;
    meeting = malloc(sizeof(meeting_t));
	if(meeting!=NULL)
	{
		printf("Enter the start ,end and room number: ");    
		scanf("%d",&start,&end,&room); 
		//bdikat from 0 to 24
		meeting->start_h = start;
		meeting->end_h = end;
		meeting->room = room;
	}
	
	return meeting;
}

int insert_appointment(calendar_t calendar , meeting_t* meet)
{
	
	temp = calendar->meeting;

	if(calendar->meeting!=NULL && calendar!=NULL && meet!=NULL)
		{
			if(calendar->index==0)//first insert
			{
				calendar->meeting[0] = meet;//10 -11
				(calendar->index)++;
			}
			else //x inserts
			{
				if(calendar->capacity < calendar->index)//if index>capacity
				{
					calendar->meeting = realloc(calendar->capacity*2,sizeof(intPtr));
					calendar->capacity *= 2;
				}
				
				if(calendar->meeting!=NULL)
				{
					for(int i=0;i<calendar->index;i++){
						if(calendar->meeting[i]->end_h < meet->end_h){
							shift_right(&calendar->meeting[i],(calendar->index)-i)
							calendar->meeting[i] = meet;
							calendar->index++;
							return 1;
						}
					}
					calendar->meeting[calendar->index] = meet;
					calendar->index++;
				}
				else
				{
					calendar->meeting = temp;
					return 0;
				}						
			}
		}
	}
	return 0;
}

void shift_right(meeting_t* meets,int size)
{
	meeting_t temp = meets[0];
	meeting_t temp2;

	meets[0] = NULL;
	for(int i=1;i<size;i++){
		temp2 = meets[i];
		meets[i] = temp;
		temp = temp2;
	}
}

void print_AD(calendar_t * calendar)
{
	if(calendar!=NULL)
	{
		for(int i=1;i<calendar->index;i++)
		{
			printf("*******************************************\n");
			printf("start :%d\n",calendar->meeting[i]->start_h);
			printf("end :%d\n",calendar->meeting[i]->end_h);
			printf("room :%d\n",calendar->meeting[i]->room);
			printf("*******************************************\n");
		}
	}
}

void destroy_da(calendar_t * calendar)
{
	if((calendar->meeting)!=0)
	{
		for(int i = 0;i<calendar->index;i++)
		{
			free(calendar->meeting[i]);
		}
	}
	if (calendar!=0)
	{
		free(calendar);
	}
	
}







	


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

meating_t* create_meet()
{
	meeting_t * meeting ;
	float start;
	float end ;
	int room;

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

int insert_appointment(calendar_t calendar , meeting_t* meet, int if_first)
{
	if(calendar->meeting!=NULL && calendar!=NULL && meet!=NULL)
		{
			if(if_first!=0)//first insert
			{
				calendar->meeting[index] = meet;
				index++;
			}
			else //x inserts
			{
				if(meet->end_h < calendar->meeting[index]->start_h)
				{
					//left shift
				}
				if(meet->start_h > calendar->meeting[index]->end_h)
				{
					//right shift
				}
			}
			if(calendar->capasity =< calendar->index)
			{
				calendar->meeting = realloc(calendar->capasity*2,*sizeof(intPtr));
				if(calendar->meeting!=NULL)
				{
					printf("in my_insert realloc : \n");
					calendar->capasity =* 2;
					//result of shift right or left 
					calendar->index++;	
				}
				else
				{
					//ip->arr=temp;
					return 0;
				}
				
			}
			return 1;
		}
	return 0;
}







	

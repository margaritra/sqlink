#include <stdio.h>
#include <stdlib.h>
#include "head.h"


int main()
{
	
	cTime_t* time = 0 ;
   	cDate_t *date = 0;

	time = malloc(sizeof(cTime_t));
	date = malloc(sizeof(cDate_t));

	if(time!= NULL)
	{
		time = createTime(time);
	}

	//date =  createDate();
	printTime(time);

	//test
	int hour = 0;
	int minute = 0;
	int seconds = 0;
	int nDay = 0;
	
	hour = retrieveHour(time);
	minute = retrieveMinute(time);
	seconds = retrieveSecond(time);
	//test
	//printf("test %02d:%02d:%02d\n",hour,minute,seconds);
	
	cTime_t* anotherTime = malloc(sizeof(cTime_t));
	if(anotherTime!= NULL)
	{
		anotherTime = createTime(anotherTime);
		printTime(time);
		printTime(anotherTime);
	}


	time = additionTime(time,anotherTime);
	printf("\n\n");
	printTime(time);

	if(date!= NULL)
	{
		date = changeDate(date);
	}
	printDate(date);

	nDay = retrieveDay(date);
	//printf("nDay : %d\n",nDay);


	int nMon = retrieveMonthDig(date);
	//printf("nMon : %d\n",nMon);

	int nYear = retrieveYear(date);
	//printf("nYear : %d\n",nYear);

	int nDayOfYear =retrieveDayOfYear(date);
	//printf("nDayOfYear : %d\n",nDayOfYear);


	int ifYearLeap = retrieveifYearLeap(date);
	//printf("ifYearLeap : %d\n",ifYearLeap);

	char *nameOfMonth = retrieveNameOfMonth( date);
	//printf("nameOfMonth : %s\n",nameOfMonth);

	free(time);
	free(anotherTime);
	free(date);
	return 0;
}

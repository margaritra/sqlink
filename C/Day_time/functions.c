#include <stdio.h>
#include <stdlib.h>
#include "head.h"
#include <time.h> 

static char* putMonth(int month);

cTime_t* createTime(cTime_t* time)
{
	
	int hour;
	int minute;
	int seconds;
    	
	
	
	printf("Enter the hour ,minute and seconds: \n");    
	scanf("%d%d%d",&hour,&minute,&seconds); 
	if((hour>=0 && hour<24) && (minute>=0 && minute <=60) && (seconds>=0 && seconds <=60))
	{
		time->hour = hour;
		time->minute = minute;
		time->seconds = seconds;
	}
	else
	{
		printf("ERROR\n");
		return 0;
	}
	return time;
}

void printTime(cTime_t* time)
{
	char *am_pm; 
	if(time!=NULL)
	{
		printf("************format 1***********************\n");
		printf("format = 1:  %02d:%02d:%02d\n",time->hour,time->minute,time->seconds);
		printf("*******************************************\n");
		//am pm
		if(time->hour>=0 && time->hour<=11)
		{
			am_pm = "PM";
		}
		else
		{
			am_pm = "AM";
		}

		printf("************format 2************************\n");
		printf("format = 2:  %02d:%02d:%02d %s\n",time->hour,time->minute,time->seconds,am_pm);
		printf("*******************************************\n");
	}
}


int retrieveHour(cTime_t* time)
{
	if(time!=NULL)
	{
		return time->hour;
	}
	return 0;
}

int retrieveMinute(cTime_t* time)
{
	if(time!=NULL)
	{
		return time->minute;
	}	
	return 0;
}

int retrieveSecond(cTime_t* time)
{
	if(time!=NULL)
	{
		return time->seconds;
	}	
	return 0;
}

cTime_t* additionTime(cTime_t* time,cTime_t* anothertime)
{
	if(time!=NULL && anothertime!=NULL)
	{
		int s1 = time->seconds;
		int s2 = anothertime->seconds;

		int m1 = time->minute;
		int m2 = anothertime->minute;

		int h1 = time->hour;
		int h2 = anothertime->hour;

		int s3=(s1+s2)%60;
		int m3=(m1+m2+((s1+s2)/60))%60;
		int h3=(h1+h2+((m1+m2)/60));
		
		if(h3 >= 24)
		{
			h3 = h3-24;
		}

		time->seconds = s3;
		time->minute = m3;
		time->hour = h3;
		
		//printf("test :%d %d %d\n",h3,m3,s3);
	}
	return time;
}

cDate_t* changeDate(cDate_t* date)
{
	int year;
	int month;
	int day;
    	
	
	
	printf("Enter the year ,month and day: \n");    
	scanf("%d%d%d",&year,&month,&day); 
	if((month>=1 && month <= 12) && (year >=1999 && year <= 2020) && (day>=1 && day <=31))
	{
		if(month == 4 || month == 9 || month == 6 || month == 11)
		{
			if(date->month == 31)
			{
				printf("ERROR\n");
				return 0;
			}

		}
		date->year = year;
		date->month = month;
		date->day = day;
	}
	else
	{
		printf("ERROR\n");
		return 0;
	}
	return date;
}


static char* putMonth(int month)
{
	char *s1 ;
	switch(month)
   {
	case 1:
		s1 = "Jan";
	       return s1;
	       break;
	case 2:
		s1 = "Feb";
	       return s1;
	       break;
	case 3:
	       s1 ="Mar";
	       return s1;
		break;
	case 4:
	       s1 ="Apr";
	       return s1;
		break;
	case 5:
	       s1 ="May";
	       return s1;
		break;
	case 6:
	       s1 ="Jun";
	       return s1;
		break;
	case 7:
	       s1 ="Jul";
	       return s1;
		break;
	case 8:
	       s1 ="Aug";
	       return s1;
		break;
	case 9:
	       s1 ="Sep";
	       return s1;
		break;
	case 10:
	       s1 ="Oct";
	       return s1;
		break;
	case 11:
	       s1 ="Nov";
	       return s1;
		break;
	case 12:
	       s1 ="Dec";
	       return s1;
		break;
      }
}




void printDate(cDate_t* date)
{
	if(date!=NULL)
	{
		int nYear = date->year%10;
		char *result = putMonth(date->month);
		
		//printf("%s\n",result);
		printf("\n\n\n");


		printf("************a***********************\n");
		printf("a):  dd:%2d mon:%2d year:%2d %02d/%s/%02d\n",date->day,date->month,nYear,date->day,result,date->year);
		printf("\n");
		printf("*******************************************\n");

		printf("************b************************\n");
		printf("b):  dd:%2d mon:%2d year:%2d %02d/%02d/%02d   European\n",date->day,date->month,nYear,date->day,date->month,date->year);
		printf("\n");
		printf("*******************************************\n");

		printf("************c************************\n");
		printf("c):  mon:%2d dd:%2d year:%2d %02d/%02d/%02d   American\n",date->month,date->day,nYear,date->month,date->day,date->year);
		printf("\n");
		printf("*******************************************\n");
	}
}


int retrieveDay(cDate_t* date)
{
	if(date!=NULL)
	{
		return date->day;
	}
	return 0;
}

int retrieveMonthDig(cDate_t* date)
{
	if(date!=NULL)
	{
		return date->month;
	}
	return 0;
}

int retrieveYear(cDate_t* date)
{
	if(date!=NULL)
	{
		return date->year;
	}
	return 0;
}

int retrieveDayOfYear(cDate_t* date)
{
    
    	int doy = 0;
	int day = date->day;
	int mon = date->month;
	int year = date->year;
	int days_in_feb = 28;
	doy = day;
    
    switch(mon)
    {
        case 2:
            doy += 31;
		return doy;
            break;
        case 3:
            doy += 31+days_in_feb;
		return doy;
            break;
        case 4:
            doy += 31+days_in_feb+31;
		return doy;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
		return doy;
            break;
        case 6:
            doy += 31+days_in_feb+31+30+31;
		return doy;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
		return doy;
            break;            
        case 8:
            doy += 31+days_in_feb+31+30+31+30+31;
		return doy;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
		return doy;
            break;
        case 10:
            doy += 31+days_in_feb+31+30+31+30+31+31+30;  
		return doy;          
            break;            
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31; 
		return doy;           
            break;                        
        case 12:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31+30;  
		return doy;          
            break;                                    
    }
}

int retrieveifYearLeap(cDate_t* date)
{
	if(date!=NULL)
	{
		if(date->year%4 == 0)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}



char* retrieveNameOfMonth(cDate_t* date)
{
	if(date!=NULL)
	{
		char *result = putMonth(date->month);
		return result;
	}
	return 0;
}




















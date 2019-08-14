
#ifndef DA_H
#define DA_H


typedef struct { 
	int hour;
	int minute;
	int seconds;
} cTime_t;


typedef struct { 

	int year;
	int month;
	int day;

} cDate_t;

cTime_t* createTime(cTime_t* time);
void printTime(cTime_t* time);
int retrieveHour(cTime_t* time);
int retrieveMinute(cTime_t* time);
int retrieveSecond(cTime_t* time);
cTime_t* additionTime(cTime_t* time,cTime_t* anothertime);
cDate_t* changeDate(cDate_t* date);
void printDate(cDate_t* date);
int retrieveDay(cDate_t* date);
int retrieveMonthDig(cDate_t* date);
int retrieveYear(cDate_t* date);
int retrieveDayOfYear(cDate_t* date);
int retrieveifYearLeap(cDate_t* date);
char* retrieveNameOfMonth(cDate_t* date);

#endif


#ifndef DA_H
#define DA_H

//typedef int* intPtr;
//int * intPtr , => int *arr
//int ** arr;
typedef meeting_t* intPtr;

typedef struct { 
	
	intPtr *meeting; //meeting_t** meeting
	int capacity;
	int index;

	
	
} calendar_t;

typedef struct { 
	float start_h;
	float end_h;
	int room;
	
} meeting_t;


meeting_t* create_ad(int capacity);//scanf(sizeofmeetings)
meeting_t* create_meet();//int *num,scanf()sahaa start,end,heder
int insert_appointment(meeting_t* start_h);//by hour//mahnis iashar be seder nahon//right shift//
void Remove_appointment(meeting_t* start_h);//by hour//left shift//free()
//void Find_appointment(meeting_t* start_h);//by hour
void destroy_AD(meeting_t* meet);
void print_AD(meeting_t* meet);



#endif


# include <iostream>
# include <string>
#include "car_t_head.h"
using namespace std;

int car_t::d_id=1;

size_t car_t::m_capacity=1500;


bool car_t::operator< (const  car_t& car)const
{
    if(this->capacity<car.capacity){
        return true;
    }
    return false;
}

bool car_t::compareStrings(const  car_t& car)
{
   int res= this->name.compare(car.name);
   if(res!=0){
       return false;
   }
   return true;
}
#pragma once
# include <iostream>
# include <string>
using namespace std;



class car_t{
   public:
       inline car_t();
       inline car_t(size_t capacity);
       inline car_t(const car_t & car);
       inline car_t& operator= (const  car_t& car);
       bool operator< (const  car_t& car)const;
       bool compareStrings(const  car_t& car);
       inline const string getName()const;
       inline const string getType() const;
       inline const size_t getCapacity() const;
       inline const int getId() const;
   protected:
        ~car_t(){};
        void  setType(string t){type=t;};
        void  setName(string t){name=t;};
   private:
       const int id;
       static int d_id;
       string type;
       string name;
       size_t capacity;
       static size_t m_capacity;
};

inline car_t::car_t():id(d_id++){
           capacity=m_capacity;
}
inline car_t::car_t(size_t capacity):id(d_id++){
           capacity=capacity;
}
inline car_t::car_t(const car_t & car):id(d_id++){
           capacity=car.capacity;
}
inline car_t& car_t::operator= (const  car_t& car)
{
    capacity=car.capacity;
}

inline const string car_t::getName()const
{
    return name;
}
inline const string car_t::getType() const
{
    return type;
};
inline const size_t car_t::getCapacity() const
{
    return capacity;
}
inline const int car_t::getId() const
{
    return id;
}


class private_t: public car_t{
  public:
   ~private_t(){};
   private_t(){
       speed=0;
       setType("auto");
       setName("manual");
   };
    private_t(size_t capacity):car_t(capacity){
       speed=0;
       setType("auto");
       setName("manual");
   };
   size_t getSpeed()const{return speed;};
   void accelerate(){speed+=10;};
   void reduceSpeed()
   {
        if(speed!=0)
            speed-=10;
    };
  private:
    size_t speed;
};




class bus_t: public car_t{
  public:
   ~bus_t(){};
   bus_t(){
       setType("gear");
       setName("bus");
       seats=0;
       line=0;
   };
    bus_t(size_t capacity,size_t st,size_t ln):car_t(capacity)
    {
       setType("gear");
       setName("bus");
       seats=st;
       line=ln;
   };
   size_t getSeats()const{return seats;};
   size_t getLine()const{return line;};
   size_t setSeats(size_t se){seats=se;};
   size_t setLine(size_t le){line=le;};
  private:
    size_t seats;
    size_t line;
};
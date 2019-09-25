# include <iostream>
# include <string>
#include "car_t_head.h"
using namespace std;


void Ctor();
void ctorChar();
void assign();
void opSmall();
void compType();
void setStr();
void compareStr();

int main()
{
   int choose = 1;
   int option =0;
   while (choose)
   {
       cout << "choose an option: "<< endl;
       cout << "1 :Default constructor "<< endl;
       cout << "2 :Constructor From capacity"<< endl;
       cout << "3 :assign"<< endl;
       cout << "4 :operator <"<< endl;
       cout << "5 :compType"<< endl;
       cout << "0 :Exit"<< endl;
       cin >> option;
       switch(option)
       {
           case 1:     Ctor();
               break;
           case 2:     ctorChar();
               break;
           case 3:     assign();
               break;
           case 4:     opSmall();
               break;
           case 5:     compType();
               break;
           default:    choose=0;
               break;
       }
   }
}

void Ctor(){
   bus_t bus;
   private_t car;
   cout<<bus.getName()<<endl;
   cout<<car.getName()<<endl;
}
void ctorChar(){
   size_t capacity;
   cout<<"enter the capacity of car: ";
   cin>>capacity;
   private_t car(capacity);
   cout<<"enter the capacity for bus: ";
   cin>>capacity;
   bus_t bus(capacity,5,5);
   cout<<car.getCapacity()<<endl;
   cout<<bus.getCapacity()<<endl;
}
void assign(){
private_t car1(1200);
private_t car2(1400);
cout<<"first car"<<car1.getCapacity()<<endl;
cout<<"second car"<<car2.getCapacity()<<endl;
car1=car2;
cout<<"first car"<<car1.getCapacity()<<endl;
}
void opSmall(){
  private_t car1(1200);
  private_t car2(800);
  cout<<"first car"<<car1.getCapacity()<<endl;
cout<<"second car"<<car2.getCapacity()<<endl;
 cout<<"if the first smaller than the second- "<<(car1<car2)<<endl;
}
void compType(){
   bus_t bus1,bus2;
cout<<"if the both objects are the bus? "<<(bus1.compareStrings(bus2))<<endl;
}
void getid()
{
  cout << "Create First bus: " << endl << "ID: ";
  bus_t b1;
  cout << b1.getId() << endl;
  cout << "Create Second bus: " << endl << "ID: ";
  bus_t b2;
  cout << b2.getId() << endl;
  cout << "Create First car: " << endl << "ID: ";
  private_t p1;
  cout << p1.getId() << endl;
}
//
//  Mechanic.cpp
//  assignment3
//
//  Created by Adham Ali on 19/03/2023.
//

#include "Mechanic.hpp"

//initilaizing in the constructor
Mechanic::Mechanic() : Person()
{
  counter = 0;
    // making a dynamic array of size 20
  apps = new Appointment[20];
}


//setters
void Mechanic::setCounter(int c)
{
    counter = c;
    
}
void Mechanic::setApps(Appointment *a)
{
    apps = a;
    
}

//getters
int Mechanic::getCounter()
{
    return counter;
    
}
Appointment *Mechanic::getApps()
{
    return apps;
    
}

// which time is suitable for customer and the mechanic
bool Mechanic::isAvailable(Appointment ap)
{
  for (int i = 0; i < counter; i++) {
    if (apps[i].hour == ap.hour && apps[i].min == ap.min) {
      return false;
    }
  }

  return true;
}

void Mechanic::addApp(int h, int m) {
  apps[counter].hour = h;
  apps[counter].min = m;
  counter++;
}

void Mechanic::printInfo()
{
    //polymirphisim
  Person::printInfo();
  cout << "Number of appointments = " << counter << endl;
  for (int i = 0; i < counter; i++) {
    cout << apps[i].hour << " : " << apps[i].min << endl;
  }
  cout << endl;
}

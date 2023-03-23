//
//  Customer.cpp
//  assignment3
//
//  Created by Adham Ali on 19/03/2023.
//

#include "Customer.hpp"

// constructor that intialize every attribute
Customer::Customer() : Person()
{
  mechanicID = "";
  appointment.hour = 0;
  appointment.min = 0;
}

//getters
string Customer::getMechanicID()
{
    return mechanicID;
    
}
Appointment Customer::getAppointment()
{
    return appointment;
    
}

//setters
void Customer::setMechanicID(string n)
{
    mechanicID = n;
    
}
void Customer::setAppointment(Appointment app)
{
    appointment = app;
    
}

//overloading operators
bool Customer::operator==(Customer &c)
{
  if (appointment.hour == c.appointment.hour &&
      appointment.min == c.appointment.min)
    return true;
  else
    return false;
}

bool Customer::operator>(Customer &c)
{
  if (appointment.hour > c.appointment.hour)
    return true;
  else if (appointment.hour < c.appointment.hour)
    return false;
  else {
    if (appointment.min > c.appointment.min)
      return true;
    else
      return false;
  }
}

bool Customer::operator<(Customer &c)
{
  if (appointment.hour < c.appointment.hour)
    return true;
  else if (appointment.hour > c.appointment.hour)
    return false;
  else {
    if (appointment.min < c.appointment.min)
      return true;
    else
      return false;
  }
}

//print function
void Customer::printInfo()
{
    //polymerphisim
  Person::printInfo();

  cout << "Mechanic ID : " << mechanicID << " @ " << appointment.hour << ":" << appointment.min<<endl<<endl;
}

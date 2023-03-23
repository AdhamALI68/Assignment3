//
//  Customer.hpp
//  assignment3
//
//  Created by Adham Ali on 19/03/2023.
//

#ifndef Customer_hpp
#define Customer_hpp
#include "Person.hpp"

// attributes of customer class that is inherited from person class
class Customer : public Person {
private:
  string mechanicID;
  Appointment appointment;

public:
  Customer();

  string getMechanicID();
  Appointment getAppointment();

  void setMechanicID(string n);
  void setAppointment(Appointment app);

  // operator overloading
  bool operator==(Customer &c);
  bool operator>(Customer &c);
  bool operator<(Customer &c);

  // print info
  void printInfo();
};


#endif /* Customer_hpp */

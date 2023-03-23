//
//  Mechanic.hpp
//  assignment3
//
//  Created by Adham Ali on 19/03/2023.
//

#ifndef Mechanic_hpp
#define Mechanic_hpp
#include "Person.hpp"


// attributes of mechanic class that is inherited from person class
class Mechanic : public Person {
private:
  int counter;
  Appointment *apps;

public:
  Mechanic();

  void setCounter(int c);
  void setApps(Appointment *a);

  int getCounter();
  Appointment *getApps();

  bool isAvailable(Appointment ap);
  void addApp(int h, int m);

  void printInfo();
};


#endif /* Mechanic_hpp */

//
//  Person.hpp
//  assignment3
//
//  Created by Adham Ali on 19/03/2023.
//

#ifndef Person_hpp
#define Person_hpp

#pragma once
#include "Appointment.h"
#include <iostream>
#include <string>
using namespace std;

// attributes of class person
class Person {
private:
  string name;
  string id;
  int age;

public:
  Person();

  void setName(string n);
  void setID(string n);
  void setAge(int a);

  string getName();
  string getID();
  int getAge();

  void printInfo();
};

#endif /* Person_hpp */

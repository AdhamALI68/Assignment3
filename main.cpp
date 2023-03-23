//
//  main.cpp
//  assignment3
//
//  Created by Adham Ali on 19/03/2023.
//

#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queue.hpp"
#include <fstream>

int main() {
  // open the mechanics.txt file to read all mechnics data
  ifstream in("/Users/maha/Downloads/AUC_CS2_Ass3/mechanics.txt");
    
    //checking that the file is opened
  if (in.fail())
  {
    cout << "fail to open this file" << endl;
    return 0;
  }
  //  read from the file number of mechanics in n
  int n;
  in >> n;
  // create an array of mechanics object
  Mechanic *mechanics = new Mechanic[n];
  string name, id;
  int age;
  int l, hr, min;
  // loop on the mechnics
  for (int i = 0; i < n; i++) {
    // read name
    in >> name;
    mechanics[i].setName(name);
    // read age
    in >> age;
    mechanics[i].setAge(age);
    // read id
    in >> id;
    mechanics[i].setID(id);
    // read number of appointments
    in >> l;
    // loop l iterations to read all appointments
    for (int j = 0; j < l; j++) {
      in >> hr;
      in >> min;
      mechanics[i].addApp(hr, min);
    }
  }
  // close the file
  in.close();
  // print all mechanics
  cout << "Available Mechanic List : " << endl;
  for (int i = 0; i < n; i++) {
    mechanics[i].printInfo();
  }
  cout << "////////////////////////" << endl;
  // open customers file
  in.open("/Users/maha/Desktop/Fundamentals of Computing II/assignment3/assignment3/customers.txt");
  if (in.fail()) {
    cout << "fail to open this file" << endl;
    return 0;
  }
  //  read number of customers in NC
  int NC;
  in >> NC;
  // create an array of customer object
  Customer *customers = new Customer[NC];
  for (int i = 0; i < NC; i++)
  {
    in >> name;
    customers[i].setName(name);
    in >> age;
    customers[i].setAge(age);
    in >> id;
    customers[i].setID(id);
    // read appointment data
    in >> hr;
    in >> min;
    // assign this appointment to the customer
    Appointment app1;
    app1.hour = hr;
    app1.min = min;
    customers[i].setAppointment(app1);
  }
  in.close();

  // Sort customers based on appointment time
  for (int i = 0; i < NC - 1; i++)
  {
    for (int j = 0; j < NC - 1; j++)
    {
      if (customers[j] > customers[j + 1])
      {
        swap(customers[j], customers[j + 1]);
      }
    }
  }

  // loop on customers array and put it in a queue
  Queue<Customer> qC;
  for (int i = 0; i < NC; i++)
  {
    qC.push(customers[i]);
  }

  // loop on mechanics array and put it in a queue
  Queue<Mechanic> qM;
  for (int i = 0; i < n; i++) {
    qM.push(mechanics[i]);
  }

  // loop on queue till it is empty
  cout << "Customers After Adding Appointment : " << endl;
  while (!qC.isEmpty())
  {
    // read the first customer to assign it to a new mechanic
    Customer t = qC.pop();
    // loop on the mechnic queue till finding first suitable one
    for (int i = 0; i < qM.length(); i++) {
      Mechanic c = qM.pop();

      if (c.isAvailable(t.getAppointment())) {
        t.setMechanicID(c.getID());
        t.printInfo();
        qM.push(c);
        break;
      }

      qM.push(c);
    }
  }
    return 0;
}

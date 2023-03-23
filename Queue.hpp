//
//  Queue.hpp
//  assignment3
//
//  Created by Adham Ali on 22/03/2023.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include<string>
using namespace std;
template <class Type>

class Queue {
private:
  // create a dynamic array of any type Type
  Type *a;
  int rear;
  int front;
  int nItems;

public:
  Queue() {
    // i initailzed the array size to 100
    a = new Type[100];
    rear = -1;
    front = 0;
    nItems = 0;
  }
  void push(Type x) {
   
    if (rear == 99)
      rear = 0;
    else
      rear++;
    a[rear] = x;

    nItems++;
  }
  Type pop() {
    Type x = a[front];
  
    if (front == 99)
      front = 0;
    else
      front++;

    nItems--;

    return x;
  }
  bool isEmpty() {
    if (nItems == 0)
      return true;
    else
      return false;
  }
  int length() { return nItems; }
};

#endif /* Queue_hpp */

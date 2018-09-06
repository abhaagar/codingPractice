
#ifndef BASE_H
#define BASE_H

#include<iostream>

using namespace std;

class A {
   private:
      int data;
   public:
      //virtual void printData();
      void printData();
      A(int data);
      ~A();
};

#endif 

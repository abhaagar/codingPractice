#include<iostream>
#include"base.h"

#ifndef DERIVED_H
#define DERIVED_H

class B : public A {
   private:
      int data;
   public:
      B(int data);
      ~B();
      void printData();
};

#endif

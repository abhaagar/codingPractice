
#include<iostream>
#include"base.h"

using namespace std;

void A::printData() {
   cout << "Class A :" << data <<endl;
}

A::A(int data) {
   cout << "Initializing the object of class A" << endl;
   this->data = data;
}

A::~A() {
   cout << "About to destruct the object of class A" << endl;
}

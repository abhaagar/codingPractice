#include<iostream>
#include"derived.h"

using namespace std;

void B::printData() {
   cout << "Class B :" << data << endl;
}
B::B(int data) : A(data) {
   //A(data);
   cout << "Initializing the object of class B" << endl;
   this->data = data;
}
B::~B() {
   cout << "About to destruct the object of class B" << endl;
 
}

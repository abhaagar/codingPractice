#include<iostream>
#include"derived.h"

int main() {
   B b(34);
   A * a = &b;
   a->printData();
   cout << sizeof(b) << " " << sizeof(*a) << endl;
   return 0;
}

#include<iostream>

using namespace std;

class A {
   public:
      virtual void printData1() {
         cout << "Class A1\n" ;
      }
      virtual void printData2() {
         cout << "Class A2\n" ;
      }
};

class B : public A {
   public:
      virtual void printData1() {
         cout << "Class B1\n";
      }
      virtual void printData2() {
         cout << "Class B2\n";
      }
};

int main() {
   B b;
   A *a = &b;
   a->printData1();
   a->printData2();
   return 0;
}

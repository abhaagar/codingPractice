#include<iostream>
using namespace std;
class A {
   public:
      int a;
      A() {
         cout << "Constructor A\n";
      }
      ~A() {
         cout << "Destructor A\n";
      }
};


class B {
   public:
      A *a;
      B() {
         cout << "Constructor B\n";
         a = new A;
      }
      ~B() {
         cout << "Destructor B\n";
         //delete a;
      }
};
void func() {
   //B *b = new B;
   B b;
   1/0;
}

int main() {
   func();
   return 0;
}

#include<iostream>
using namespace std;
class A {
   public:
      A(int _a=0) {
         cout << "Constructed A\n";
      }
};

class B {
   A a;
};

class C {
      A a;
      int c;
   public:
      C() {
         c=0;
      }
};
int main() {
   B b;
   C c;
   return 0;
}

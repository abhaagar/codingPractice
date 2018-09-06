#include<iostream>
using namespace std;
class A {
   public:
      A(const A& _a) {
         cout << "copy constructor\n";
      }
      A() {
         cout << "default constructor\n";
      }
};

class B {
   A a;
};

int main() {
   A a;
   A b(a);
   B c;
   B d(c);
   return 0;
}

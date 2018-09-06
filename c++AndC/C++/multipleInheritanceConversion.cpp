#include<iostream>
using namespace std;
class A {
      int a;
   public:
      virtual void drawA() { }
};

class B {
   float b;
   public:
      virtual void drawB() { }
};

class C : public A,B {
   char c;
   public:
      virtual void drawC() { }
};


int main() {
   C c;
   C *c1 = &c;
   A *a = &c;
   //B *b = &c;
   // inaccessible base.
   B *b = (B*)(((char*)&c)+sizeof(A));
   B *b1 = c1;
   return 0;
}

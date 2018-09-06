// C-style casting (Type)
// C++ style casting static_cast<Type>, dynamic_cast<Type>
#include<iostream>
using namespace std;
class A {
   int a;
   public:
      virtual void assign() {a=2;}
};

class B: public A {
   int b;
   public:
      void assign() { b = 2;}
};

class C {
   int a;
   public:
      virtual void assign() {a=2;}
};
int main() {
   A a;
   C *c = dynamic_cast<C*>(&a);
   if(c==NULL) {
      cout << "A->C type casting unsuccessful\n";
   }

   B *b = dynamic_cast<B*>(&a);
   if(b==NULL) {
      cout << "A->B dynamic type casting unsuccessful\n";
   }

   B *b1 = static_cast<B*>(&a);
   if(b1==NULL) {
      cout << "A->B static type casting unsuccessful\n";
   }

   return 0;
}

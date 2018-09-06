class A {
   public:
      int a1;
      int a2; 
};

class B : public A {
   public:
      int b1;
      int b2;
};

class C {
   public:
      int c1;
      int c2;
};
int main() {
   //B b;
   //A *a = dynamic_cast<A*>(&b);
   //A *a = &b;
   A a;
   C *c = static_cast<C*>(&a);
   return 0;
}

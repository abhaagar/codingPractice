class X {
   public:
   int x1;
   int x2;
   int x3;
   int x4;
};

class A : virtual public X {
   public:
   int a1;
   int a2;
   int a3;
   int a4;
};

class C : virtual public X {
   public:
   int c1;
   int c2;
   int c3;
   int c4;
};

class B : public A,C {
   public:
   int b1;
   int b2;
   int b3;
   int b4;
};

int main() {
   B b;
   //return b.a1+b.a2+b.a3+b.a4+b.c1+b.c2+b.c3+b.c4+b.b1+b.b2+b.b3+b.b4+b.x1+b.x2+b.x3+b.x4;
   return b.a1+b.a2+b.a3+b.a4+b.b1+b.b2+b.b3+b.b4+b.x1+b.x2+b.x3+b.x4;
}

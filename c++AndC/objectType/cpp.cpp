
class A {
   public:
   int a;
};

class B: public A {
   public:
   int b;
};

int main() {
   A* A1 = new B();
   A1->a = 2;
   return 0;
}

class A{
   public:
      int a;
      void virtual set1() {
      //void set1() {
         a=1;
      }
      void virtual set2() {
      //void set2() {
         a=2;
      }
      void virtual set3() {
      //void set3() {
         a=3;
      }
};

class B : public A {
   public:
      int b;
      void set1() {
         b=1;
      }
      void set2() {
         b=2;
      }
      void set3() {
         b=3;
      }
};

int main() {
   B b;
   A *a = &b;
   a->set1();
   a->set2();
   a->set3();
   return 0;
}



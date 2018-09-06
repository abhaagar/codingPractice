#include<iostream>
using namespace std;

class A {
   private:
      int _a;
   public:
      int *a() {
         return &_a;
      }
};

int main() {
   A aa;
   cout << *(aa.a()) << endl; 
   *(aa.a()) = 2;
   cout << *(aa.a()) << endl; 
   return 0;
}

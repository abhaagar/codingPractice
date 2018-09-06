#include<iostream>
using  namespace std;
void recover(const int&) {

}
void f(int), g(int);

class Z{
   public:
      Z(){
        cout << "construted the object of Z" << endl;
      }
      ~Z(){
        cout << "destruted the object of Z" << endl;
      }
};
int main() {
   try {
      f(0);
   } catch (const int& rx) {
        cout << "exception caught" << endl;
        recover(rx);
   }
   return 0;
}
void f(int i) {
   Z z1;
   g(i);
   Z z2;
   g(i-1);
}
void g(int j) {
   if (j < 0)
   throw 5;
}

#include<iostream>

using namespace std;

double division(int a, int b) {
   if(b==0) {
      throw "Diviision by zero condition";
   }
   return a/b;
}

void divide() {
   division(2,0);
}

int main() {
   divide();
   cout << "this should not have been printed" << endl;
   return 0;
}

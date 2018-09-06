int B(int a, int b) {
   return 0;
}

int A(int c) {
  int a=2,b;
  b=B(2,3);
  int d=9;
  return a+b+c+d;
}

int main(){

   return A(8);
}

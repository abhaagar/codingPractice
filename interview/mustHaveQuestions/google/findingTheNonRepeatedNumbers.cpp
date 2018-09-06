#include<iostream>
int main() {
   int num;
   std::cin >> num;
   int array[2*num+2];
   int xo=0;
   for(int i=0; i<2*num+2; ++i) {
      std::cin >> array[i];
      xo ^= array[i];
   }
   int leastSetBitNum = xo & ~(xo-1);
   int x=0, y=0;
   for(int i=0; i<2*num+2; ++i) {
      if(leastSetBitNum & array[i]) {
          x ^=array[i];
      } else {
          y ^=array[i];
      }
   }
   if(x<y)
      std::cout << x << " " << y << std::endl;
   else
      std::cout << y << " " << x << std::endl;
   return 0;
}

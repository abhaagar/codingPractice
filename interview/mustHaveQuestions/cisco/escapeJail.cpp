#include<iostream>

int main() {
   int X, Y, N;
   std::cin >> X >> Y >> N;
   //int  *walls = (int*) malloc(sizeof(int)*N);
   int num;
   int jumps = 0;
   for(int i=0; i<N; ++i) {
      std::cin >> num;
      if(num<X) {
         jumps += 1;
      } else { 
        if((num-X)%(X-Y)==0) 
          jumps += (num-X)/(X-Y)+1;
        else
          jumps += (num-X)/(X-Y)+2;
      }
   }
   std::cout << jumps << std::endl;
   return 0;
}

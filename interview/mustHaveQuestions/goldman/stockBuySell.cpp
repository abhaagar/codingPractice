#include<iostream>

int main() {
   int N;
   std::cin >> N;
   int num;
   std::cin >> num;
   int min = num, max = num;
   for(int i=1; i<N; ++i) {
      std::cin >> num;
      if(max>num) {
         if(min!=max)
            std::cout << min << " " << max << std::endl; 
         min = num;
         max = num;
         continue;
      } 
      if(max<num) {
         max = num;
      }
   }
   if(min!=max)
      std::cout << min << " " << max << std::endl; 

   return 0;
}

#include<iostream>

int main() {
   int N;
   std::cin >> N;
   int element;
   std::cin >> element;
   int min = element, max = element;
   int maxSoFar = 0;
   for(int i=1; i<N; ++i) {
      std::cin >> element;
      if(element>max) {
         max = element; 
       } else if(element<min) {
         if(maxSoFar<max-min) {
            maxSoFar = max-min;
         }
         min = element;
         max = element;
       }
   }
   if(maxSoFar<max-min)
      maxSoFar = max-min;
   std::cout << maxSoFar << std::endl; 
   return 0;
}

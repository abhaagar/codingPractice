#include<iostream>
#include<stdlib.h>
int main() {
   int T;
   std::cin >> T;
   while(T--) {
      int N;
      std::cin >> N;
      int *array = (int*) malloc(sizeof(int)*N);
      int *smallGreat= (int*) malloc(sizeof(int)*N);
      int max = -1000000,min = 100000;
      for(int i=0; i<N; ++i) {
         std::cin >> *(array+i);
         if(max<=*(array+i)) {
            max = *(array+i);
         }
         *(smallGreat+i) = max;
      }
      for(int i=N-1; i>=0; --i) {
         if(min>=*(array+i)) {
            min=*(array+i);
            if(*(smallGreat+i)!=*(array+i))
               *(smallGreat+i) = 0;
         } else {
            *(smallGreat+i) = 0;
         }
      } 
      int i=0;
      while(i<N) {
         if(*(smallGreat+i)!=0) {
            std::cout << *(smallGreat+i) << std::endl;
            return 0;
         }
         ++i;
      }
      std::cout << -1 << std::endl;

   }
   return 0;
}

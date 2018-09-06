#include<iostream>
#include<stdlib.h>
int main() {
   int N;
   std::cin >> N;
   int *array = (int*)malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i)
      std::cin >> array[i];
   for(int i=0; i<N; ++i) {
      array[(array[i]-1)%(N+1)] += (N+1); //*(array[i]);  
   }
   for(int i=0; i<N; ++i) 
      std::cout << array[i]/(N+1) << std::endl;
   return 0;
}

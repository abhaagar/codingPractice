#include<iostream>
#include<stdlib.h>

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
void sort012(int **nums,int N) {
   int end0 = -1, start2 = N;
   int current = 0;
   while(current<start2-1) {
      int currentElement = (*nums)[current];
      if(currentElement==1) {
         ++current;
      } else if(currentElement==0) {
         swap(*nums+end0+1,*nums+current);
         ++current;
      } else {
         swap(*nums+current,*nums+start2-1);
         --start2;
      }
      //std::cout << "progressed " << current << std::endl;
   }
}


int main() {
   int N;
   std::cin >> N;
   int *nums = (int*)malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i) 
      std::cin >> nums[i];
   sort012(&nums,N);
   for(int i=0; i<N; ++i) 
      std::cout << nums[i] << " ";
   std::cout << std::endl;
   return 0;
}

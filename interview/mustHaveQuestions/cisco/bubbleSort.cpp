#include<iostream>
#include<stdlib.h>

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubbleSort(int **nums,int start, int end) {
   for(int i=start; i<end; ++i) {
      if((*nums)[i]>(*nums)[i+1])
         swap(*nums+i,*nums+i+1);
   }
   if(start<end-1)
      bubbleSort(nums,start,end-1);

}

int main() {
   int N;
   std::cin >> N;
   int *nums = (int*)malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i) 
      std::cin >> nums[i];
   bubbleSort(&nums,0,N-1);
   for(int i=0; i<N; ++i) 
      std::cout << nums[i] << " ";
   std::cout << std::endl;
   return 0;
}

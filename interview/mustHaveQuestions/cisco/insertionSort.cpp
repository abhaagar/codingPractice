#include<iostream>
#include<stdlib.h>

void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
void insertionSort(int **nums,int start, int end) {
   int min = start;
   for(int j=start+1; j<=end; ++j) {
      if((*nums)[min]>(*nums)[j]) 
         min = j;
   }
   swap(*nums+start,*nums+min);
   if(start+1<end)
      insertionSort(nums,start+1,end);
}


int main() {
   int N;
   std::cin >> N;
   int *nums = (int*)malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i) 
      std::cin >> nums[i];
   insertionSort(&nums,0,N-1);
   for(int i=0; i<N; ++i) 
      std::cout << nums[i] << " ";
   std::cout << std::endl;
   return 0;
}

#include<iostream>
#include<stdlib.h>
void swap(int *a, int *b) {
   int  temp = *a;   
   *a = *b;
   *b = temp;
}
int quickKSort(int **nums, int start, int end, int k) {
   int startTemp = start, endTemp = end;
   int pivot = start;
   ++start;
   while(start<end) {
      while(start<end && (*nums)[start]<(*nums)[pivot])
        ++start;
      while(start<end && (*nums)[end]>(*nums)[pivot])
         --end;
      if(start<end && (*nums)[start]>(*nums)[pivot] && (*nums)[end]<(*nums)[pivot])
         swap(*nums+start,*nums+end);
   }
   if((*nums)[pivot]<(*nums)[start])
     --start;
   swap(*nums+pivot,*nums+start);
   if(k==start) {
     return (*nums)[start];
   } else if(k<start) {
      if(startTemp<start-1)
         quickKSort(nums,startTemp,start-1,k);
      else
         return(*nums)[startTemp];
   } else {
      if(end<endTemp)
        quickKSort(nums,end,endTemp,k);
      else
         return(*nums)[endTemp];
   }
}


int main() {
   int N, K;
   std::cin >> N >> K;
   int *nums = (int*)malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i)
      std::cin >> nums[i];
   std:: cout << quickKSort(&nums,0,N-1,K-1);
   //for(int i=0; i<N; ++i)
   //   std::cout << nums[i] << " ";
   std::cout << std::endl;
   return 0;
}

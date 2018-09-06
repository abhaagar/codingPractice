#include<iostream>
#include<stdlib.h>

void swap( int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void partition(int **array,int start, int end, int k) {
   int tempStart = start, tempEnd = end;
   int pivot = start;
   ++tempStart;
   while(tempStart<tempEnd) {
      while(tempStart<tempEnd && (*array)[tempStart]<(*array)[pivot])
         ++tempStart;
      while(tempStart<tempEnd && (*array)[tempEnd]>(*array)[pivot])
         --tempEnd;
      if((*array)[tempStart]>(*array)[pivot] && (*array)[tempEnd]<(*array)[pivot])
         swap((*array)+tempStart, (*array)+tempEnd);
   }
   if((*array)[tempStart]>(*array)[pivot])
      --tempStart;
   swap(*array+pivot,*array+tempStart);
   if(start<tempStart-1)
      partition(array,start,tempStart-1,k);
   if(tempEnd<end)
      partition(array,tempEnd,end,k);
}


int main() {
   int N,K;
   std::cin >> N >> K;
   int *nums = (int*) malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i)
      std::cin >> nums[i];
   partition(&nums,0,N-1,K);
   for(int i=0; i<N; ++i)
      std::cout << nums[i] << " ";
   std::cout << std::endl;
   return 0;
}

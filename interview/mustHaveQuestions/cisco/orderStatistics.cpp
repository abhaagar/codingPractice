#include<iostream>
#include<stdlib.h>

int N;
int quickSort(int **array, int start, int end, int k) {
   int pivot = start;
   std::cout << start << " " << end << " " << k << std::endl;
   std::cout << "pivot is " << (*array)[start] << std::endl;
   int saveStart = start, saveEnd = end;
   ++start;
   while(start<end) {
      if(start<end && (*array)[start]<(*array)[pivot])
         ++start; 

      if(start<end && (*array)[end]>(*array)[pivot])
         --end;

      if((*array)[start]>(*array)[pivot] && (*array)[end]<(*array)[pivot]) {
          int temp = (*array)[start];
          (*array)[start] = (*array)[end]; 
          (*array)[end] = temp;
      }
   }
   if((*array)[start]>(*array)[pivot])
     --start;
   int temp = (*array)[start];
   (*array)[start] = (*array)[pivot];
   (*array)[pivot] = temp;
   for(int i=0; i<N; ++i) {
      std::cout << (*array)[i] << " ";
   }
   std::cout << std::endl;
   if(k==start)
      return (*array)[start];
   else if(k<start)
      if(saveStart<=start-1)
        return quickSort(array,saveStart,start-1,k);
      else
        return (*array)[saveStart];
   else
      if(end<=saveEnd)
         return quickSort(array,end,saveEnd,k);
      else
         return (*array)[saveEnd];
}

int main() {
   int K;
   std::cin >> N >> K;
   int *nums = (int*) malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i) {
      std::cin >> nums[i];
   }
   std::cout << quickSort(&nums,0,N-1,K-1) << std::endl;

   return 0;
}

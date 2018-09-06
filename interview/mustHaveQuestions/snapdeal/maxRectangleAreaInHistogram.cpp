#include<iostream>
#include<stack>
#include<stdlib.h>
int main() {
   int N;
   std::cin >> N;
   int *array=(int*)malloc(sizeof(int)*N);
   for(int i=0; i<N; ++i) {
      std::cin >> array[i];
   }
   int *leftSmaller=(int*)malloc(sizeof(int)*N);
   int *rightSmaller=(int*)malloc(sizeof(int)*N);
   int i = 1;
   std::stack<int> s;
   s.push(0);
   while(i<N) {
      while(!s.empty() && array[i]<array[s.top()]) {
         rightSmaller[s.top()] = i-1;
         s.pop();
      }
      s.push(i);
      ++i;
   }
   while(!s.empty()) {
      rightSmaller[s.top()] = N-1;
      s.pop();
   }
   i = N-2;
   s.push(N-1);
   while(i>=0) {
      while(!s.empty() && array[i]<array[s.top()]) {
         leftSmaller[s.top()] = i+1;
         s.pop();
      }
      s.push(i);
      --i;
   }
   while(!s.empty()) {
      leftSmaller[s.top()] = 0;
      s.pop();
   }
   int max = 0;
   for(int i=0; i<N; ++i) {
      if(array[i]*(i-leftSmaller[i])+array[i]*(rightSmaller[i]-i)+array[i]>max)
         max = array[i]*(i-leftSmaller[i])+array[i]*(rightSmaller[i]-i)+array[i];
   }
   std::cout << max << std::endl;
   return 0;
}

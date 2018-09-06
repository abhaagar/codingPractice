#include<iostream>

int main() {
   int m,n,d;
   std::cin >> m >> n >> d;
   int *count = (int*)malloc(sizeof(int)*d);
   for(int i=0; i<d; ++i) {
      if(i<m && i<n) {
         count[i] = 0;
         continue;
      } else if(i==m) {
         count[i] = 1;
      } else if(i==n) {
         count[i] = 1;
      } else {
         count[i] = min(count[i-m],count[i-n])+1;
      }

   }
   return 0;
}

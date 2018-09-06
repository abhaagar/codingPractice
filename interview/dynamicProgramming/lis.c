#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

int main() {
   int arr[MAX_SIZE];
   int lis[MAX_SIZE];
   int N,i,j,length=0;
   scanf("%d",&N);
   for(i=0; i<N; ++i) {
      scanf("%d",arr+i);
   }
   for(i=0; i<N; ++i) {
      lis[i] = 1;
      for( j=i-1; j>=0; --j) {
         if(arr[j]<=arr[i] && lis[i]<=lis[j]) {
            lis[i] = lis[j]+1;
         }
      }
      if(lis[i]>length){
         length = lis[i];
      }
   }
   printf("%d\n",length);
   return 0;
}

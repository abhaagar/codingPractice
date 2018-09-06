#include<stdio.h>
#include<stdlib.h>

int main() {
   int N,sum,i=0;
   int start = 0,currentSum =0;
   int *arr;
   scanf("%d %d",&N,&sum);
   
   arr=(int*)malloc(sizeof(int)*N);
   for(;i<N;++i){
      int num;
      scanf("%d",&num);
      arr[i]=num;
   }
   currentSum = arr[0]; 
 
   for(i=1;i<N;++i) {
      if(arr[i]+currentSum==sum) {
         printf("%d %d",start,i);
         return 0;
      } else if(arr[i]+currentSum<sum) {
         currentSum += arr[i];
      } else {
         while(currentSum+arr[i]>sum && start<=i) {
           currentSum -= arr[start];
           ++start;
         }
         if(start>i) {
            currentSum = 0;
         } else if (currentSum+arr[i]==sum){
            printf("%d %d",start,i);
            return 0;
         } else {
           currentSum += arr[i];
         }
      }
   }
   return 0;
}

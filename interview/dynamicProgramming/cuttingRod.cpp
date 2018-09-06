#include<stdio.h>
#define MAX 100
int main() {
   int n=8;
   int cost[MAX]={1,5,8,9,10,17,17,20};
   int matrix[MAX];
   //scanf("%d",&n);
   //for(int i=0; i<n;++i)
   //   scanf("%d",cost+i);
   for(int i=0; i<=n; ++i){
      if(i==n)
         matrix[i] = 0;
      else
         matrix[i] = cost[i];
      for(int j=i-1; j>=0; --j) {
         if(matrix[i]<cost[j]+matrix[i-j-1])
            matrix[i]=cost[j]+matrix[i-j-1];
      }
   }
   printf("%d\n",matrix[n-1]);
   return 0;
}

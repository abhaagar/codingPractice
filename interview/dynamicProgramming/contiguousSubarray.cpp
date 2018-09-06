#include <stdio.h>
#define MAX 100

int main() {
   int arr[MAX];
   int len;
   scanf("%d",&len);
   for(int i=0; i<len; ++i) 
      scanf("%d",arr+i);
   int sum=0, lastPos,sumPos=0;
   for (int i=0;i<len;++i){
      sum += arr[i];
      if(sum>sumPos) { 
         sumPos = sum;
      }
      if(sum<0) {
        sum = 0;
      }
   }
   printf("%d\n",sumPos); 
   return 0;
}

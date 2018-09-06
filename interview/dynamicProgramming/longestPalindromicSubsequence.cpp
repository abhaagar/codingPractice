#include<stdio.h>
#include<cstring>
#define MAX 100
#define max(a,b) a>b?a:b

int main() {
   char str[] = "GEEKS FOR GEEKS";
   //char str[] = "BBABB";
   int length = sizeof(str)-1;
   int lenMatrix[MAX][MAX];
   memset(lenMatrix,0,sizeof(int)*MAX*MAX);
   for(int len=0;len<=length;++len) {
      for(int index=0;index<=length-len;++index) {
         if(len==0) {
           lenMatrix[len][index] = 0;
         } else if(len==1) {
           lenMatrix[len][index] = 1;
         } else if(str[index]==str[index+len-1]) {
           lenMatrix[len][index] = 2+lenMatrix[len-2][index+1];
         } else {
            lenMatrix[len][index] = max(lenMatrix[len-1][index],lenMatrix[len-1][index+1]);
         }

      }
   }
   printf("%d\n",lenMatrix[length][0]);
   return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000
#define MIN(a,b) a<b?a:b

int main() {
   int arr[MAX_SIZE+1][MAX_SIZE+1];
   char string1[MAX_SIZE],string2[MAX_SIZE];
   int length1=0, length2=0;
   scanf("%s %s",string1,string2);
   int i,j;
   for (i=0;i<=MAX_SIZE && string1[i]!='\0';++i,++length1) {
      arr[i][0] = i;
   }
   arr[i][0] = i;
   for (i=0;i<=MAX_SIZE && string2[i]!='\0';++i,++length2) {
      arr[0][i] = i;
   }
   arr[0][i] = i;
   for(i=1;i<=length1;++i) {
      for(j=1;j<=length2;++j) {
          if(string1[i-1]==string2[j-1]) {
             arr[i][j] = arr[i-1][j-1];
          } else {
             int replace = arr[i-1][j-1];
             int addition = arr[i][j-1];
             int deletion = arr[i-1][j];
             int cost = MIN(replace,MIN(addition,deletion));
             arr[i][j] = 1 + cost;
          }
      }
   }
   for(i=0; i<=length1; ++i){
      for(j=0; j<=length2; ++j){
         printf("%d ",arr[i][j]);
      }
      printf("\n");
   }
   printf("%d\n",arr[length1][length2]);
   return 0;
}

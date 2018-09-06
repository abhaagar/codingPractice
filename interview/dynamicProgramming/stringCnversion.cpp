#include<stdio.h>
#define MAX 100
//#define min(a,b) a>b?b:a
int min(int x,int y,int z) {
   return x>y?(y>z?z:y):(x>z?z:x);
}
int length(char str[]) {
   int i=0;
   while(str[i++]!='\0');
   return i-1;
}
int main() {
   char str1[MAX],str2[MAX];
   int cost[MAX][MAX];
   int insert,remove,replace;
   scanf("%d %d %d",&insert,&remove,&replace);
   scanf("%s %s",str1,str2);
   int m=length(str1),n=length(str2);
   printf("%d %d\n",m,n);
   for(int i=0;i<=m;++i) {
      for(int j=0;j<=n;++j) {
         if(i==0) {
            cost[i][j] = j;
         } else if(j==0) {
            cost[i][j] = i;
         } else if(str1[i-1]==str2[j-1]) {
            cost[i][j] = cost[i-1][j-1];
         } else {
            int replaceCost = replace+cost[i-1][j-1];
            int insertCost = insert+cost[i][j-1];
            int removalCost = remove+cost[i-1][j];
            cost[i][j] = min(insertCost,replaceCost,removalCost);
         }
      }
   }
   printf("%d\n",cost[m][n]);
   for(int i=0;i<=m;++i) {
      for(int j=0;j<=n;++j) {
         printf("%d ",cost[i][j]);
      }
      printf("\n");
   }
   return 0;
}

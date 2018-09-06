#include<iostream>
#include<stdlib.h>
#define INT_MAX 100000000
#define min(a,b) a>b?b:a
int main() {
   int N,C;
   std::cin >> N >> C;
   int *coins=(int*) malloc(sizeof(int)*C);
   for(int i=0; i<C; ++i)
      std::cin >> coins[i];
   int *change = (int*)malloc(sizeof(int)*(N+1));
   change[0] = 0;
   for(int i=1; i<=N; ++i) {
      change[i] = 0;
      for(int  j=0; j<C; ++j) {
         if(coins[j]<=i) {
            if(i-coins[j]==0)
               change[i] += 1;
            else if(change[i-coins[j]]!=0)
               change[i] += change[i-coins[j]];
         }
      }
   } 
   std::cout << change[N] << std::endl;
   return 0;
}

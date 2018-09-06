#include<iostream>
#define MAX 100
#define min(a,b) a>b?b:a
using namespace std;
int main() {
   int  matrix[MAX][MAX];
   int m,n;
   std::cin >> m >> n;
   for(int i=1;i<=m;++i) {
      for(int j=1;j<=n;++j) {
         std::cin >> matrix[i][j];
      }
   }
   for(int i=0;i<=m;++i) {
      matrix[i][0] = 0;
   }
   for(int j=0;j<=n;++j) {
      matrix[0][j] = 0;
   }
   for(int i=1;i<=m;++i) {
      for(int j=1;j<=n;++j) {
         if (matrix[i][j]==1) {
            matrix[i][j] = 
               min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i][j-1])+1;
         }
      }
   } 
   for(int i=1;i<=m;++i) {
      for(int j=1;j<=n;++j) {
         std::cout<< matrix[i][j]<<" ";
      }
      std::cout << std::endl;
   }
   return 0;
}

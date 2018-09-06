#include<iostream>

int main() {
   int N, M;
   std::cin >> N >> M;
   int matrix[1000][1000];
   for(int i=0; i<N; ++i) {
      for(int j=0; j<M; ++j) {
         std::cin >> matrix[i][j];
      }
   }
   return 0;
}

#include<queue>
#include<iostream>
//#include<pair>
using namespace std;

int dfs(int array, int size, int island, int x, int y) {
   queue<pair<int,int> > q;
   q.push(make_pair(x,y));
   int count = 0;
   while(q.empty()) {
      int n = q.size();
      for(int i=0; i<n; ++i) {
         pair<int,int> p(q.front());
         q.pop();
         if(p.first<0||p.first>=size || p.second<0||p.second>=size)
            continue;
         if(array[p.first][p.second]!=1)
            continue;
         ++count;
         array[p.first][p.second] = island;
         q.push(make_pair(p.first-1,p.second));
         q.push(make_pair(p.first+1,p.second));
         q.push(make_pair(p.first,p.second-1));
         q.push(make_pair(p.first,p.second+1));

      }
   }
   return count;

}

int main() {
   int matrix[][5] = {{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,1} };
   int size = 5;
   int island = 2;
   int maxIsland = 0;
   for(int i=0; i<size; ++i) {
      for(int j=0; j<size; ++j) {
         if(matrix[i][j]==1) {
            int islandCount(dfs(matrix,size,island,i,j));
            if(islandCount>maxIsland)
               maxIsland = islandCount;
            ++island;
         }
      }
   }
   cout << maxIsland << endl;
   return 0;
}

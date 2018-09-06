#include<iostream>
#include<queue>

using namespace std;
void traverse(priority_queue<int> q) {
    while(!q.empty()) {
       cout << q.top() << endl;
       q.pop();
    }
}
struct comp {
   bool operator()(const int &lhs,const int &rhs) {
      return lhs>=rhs;
   }
};


int main() {
   priority_queue<int,greater<int> > q;
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40);
   traverse(q);
   return 0;
}

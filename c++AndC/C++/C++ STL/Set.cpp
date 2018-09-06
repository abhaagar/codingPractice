// set by default maintains ascending order of elements
// no duplicate is kept for any element.
// O(logN) search, deletion of iterator does not invalidate
// all the iterators.

#include<set>
#include<vector>
#include<iostream>
struct comp {
   bool operator() (const int &lhs, const int &rhs) const {
      if(lhs%2==0 && rhs%2==0)
         return lhs<rhs;
      else if(lhs%2!=0 && rhs%2!=0)
         return lhs<rhs;
      else
         return lhs%2;
   }
};
using namespace std;
int main() {
   set<int,comp> evenSortSet;
   evenSortSet.insert(20);
   evenSortSet.insert(40);
   evenSortSet.insert(60);
   evenSortSet.insert(91);
   evenSortSet.insert(93);
   evenSortSet.insert(95);
   for(set<int,comp>::iterator it=evenSortSet.begin(); it!=evenSortSet.end();++it)
      evenSortSet.erase(it);
      //cout << *it << " ";
   return 0;
}

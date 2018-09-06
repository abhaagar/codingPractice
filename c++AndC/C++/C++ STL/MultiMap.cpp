#include<map>
#include<iostream>

using namespace std;

int main() {
   multimap<int,int> m;
   m.insert(make_pair(1,10));
   m.insert(make_pair(1,10));
   m.insert(make_pair(1,10));
   m.insert(make_pair(2,10));
   m.insert(make_pair(2,10));
   for(multimap<int,int>::iterator it=m.begin(); it!=m.end();++it)
      cout << it->first << " " << it->second << endl;
   m.erase(1);
   for(multimap<int,int>::iterator it=m.begin(); it!=m.end();++it)
      cout << it->first << " " << it->second << endl;
   return 0;
}

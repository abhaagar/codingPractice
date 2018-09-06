#include"dataStructure.cpp"
#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
   map<Coordinate,Mosquito> mosquitoMap;
   for(int i=0; i<4; ++i)  {
      for(int j=0; j<4; ++j) {
          char name[10];
          sprintf(name,"%d,%d",i,j);
          cout << "inserted pair " << i << j << std::endl;
          mosquitoMap.insert(make_pair(Coordinate(i,j),Mosquito(name)));
      }
   }
   for(map<Coordinate,Mosquito>::iterator it=mosquitoMap.begin();it!=mosquitoMap.end();++it)
      cout << it->first.x() << " " << it->first.y() << " " << it->second.name() << std::endl;
   return 0;
}

#include<iostream>
#include<map>

int main() {
   int N;
   std::cin >> N;
   std::map<int,int> stream;
   for(int i=0; i<N; ++i) {
      int num;
      std::cin >> num;
      stream.insert(std::make_pair(num,num));
      int median,size;
      std::map<int,int>::iterator it = stream.begin();
      if(size/2) {
         median = *(it+(size-1)/2);
      } else {
         int index = *(it+(size-1)/2);
         median = (*(it+index)+*(it+index+1))/2
      }
      std::cout << median << std:: endl;
   }

   return 0;
}

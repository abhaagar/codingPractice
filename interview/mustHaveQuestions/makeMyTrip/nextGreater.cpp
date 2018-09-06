#include<iostream>
#include<vector>
#include<algorithm>

int main() {
   int num;
   std::cin >> num;
   int unTraversedPart = num;
   int lastMax = unTraversedPart%10;
   std::vector<int> traversedPart;
   traversedPart.push_back(lastMax);
   unTraversedPart /= 10;
   while(unTraversedPart) {
      if(unTraversedPart%10<lastMax)
         break; 
      lastMax = unTraversedPart%10;
      traversedPart.push_back(lastMax);
      unTraversedPart /= 10;
   }
   if(unTraversedPart==0) {
      std::cout << "no such number" << std::endl;
      return 0;
   }
   int digitToSwap = unTraversedPart%10;
   unTraversedPart /= 10;
   std::vector<int>::iterator et = traversedPart.end();
   for(std::vector<int>::iterator it=traversedPart.begin(); it!=traversedPart.end(); ++it) {
      if(et==traversedPart.end() || (*it>digitToSwap) && (*it<*et) )
        et = it;
   }
   int temp;
   temp = *et;
   *et = digitToSwap;
   digitToSwap = temp;
   std::sort(traversedPart.begin(),traversedPart.end());
   unTraversedPart = 10*unTraversedPart+digitToSwap;
   for(std::vector<int>::iterator it=traversedPart.begin(); it!=traversedPart.end();++it)
      unTraversedPart = 10*unTraversedPart+*it;
   std::cout << unTraversedPart << std::endl;
   return 0;
}

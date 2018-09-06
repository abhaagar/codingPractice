#include<iostream>
#include<map>
int main() {
   int parasCount[3]={0,0,0}; 
   std::string paras;
   std::cin >> paras;
   for(auto & para : paras) {
      if(para=='(') {
         ++parasCount[0];
      } else if(para=='{') {
         ++parasCount[1];
      } else if(para=='[') {
         ++parasCount[2];
      } else if(para==')') {
         if(parasCount[0]<=0) 
            break;
         else 
            --parasCount[0];
      } else if(para=='}') {
         if(parasCount[1]<=0)
            break;
         else
            --parasCount[1];
      } else if(para==']') {
         if(parasCount[2]<=0)
            break;
         else
            --parasCount[2];
      }
   }
   if(parasCount[0]!=0 || parasCount[1]!=0 ||parasCount[2]!=0) 
      std::cout << "un balanced";
   else
      std::cout << "balanced";
   return 0;
}

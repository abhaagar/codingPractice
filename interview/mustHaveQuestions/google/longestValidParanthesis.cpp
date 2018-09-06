#include<stack>
#include<string>
#include<iostream>
int main() {
   std::stack<int> para;
   std::string paraStr;
   std::cin  >> paraStr;
   int max = 0;
   for(int i=0; i<paraStr.size(); ++i) {
      if(paraStr[i]=='(') {
         if(max!=0 && (para.empty()||para.top()!='(')) {
            if(!para.empty()) {
               max += para.top();
               para.pop();
            }
            para.push(max);
         } 
         para.push('(');
      } else {
         if(para.top()=='(') {
            para.pop();
            max += 2;
         } else if(para.top()!='('){
            max += para.top();
            para.pop();
            //paraStr.push(max);
            if(para.top()=='(') {
               para.pop();
               max += 2; 
               para.push(max);
            } else {
               para.push(max);
               para.push(')');
            }

         }

      }
     
   }
   return 0;
}

#include<iostream>
#include<string>

int main() {
   std::string sentence;
   std::cin >> sentence;
   int start = 0,end = sentence.length()-1;
   char c;
   while(start<end) {
      c = sentence[start];
      sentence[start] = sentence[end];
      sentence[end] = c;
      ++start;
      --end;
   }
   start = -1;
   for(int i=0; i<sentence.length(); ++i) {
      if(start==-1)
         start = i;
      if(sentence[i]=='.') {
         end = i-1;
         while(start<end) {
            c = sentence[start];
            sentence[start] = sentence[end];
            sentence[end] = c;
            ++start;
            --end;
         }
         start = -1;
      }

   }
   end = sentence.length()-1;
   while(start<end) {
      c = sentence[start];
      sentence[start] = sentence[end];
      sentence[end] = c;
      ++start;
      --end;
   }

   std::cout << sentence << std::endl;
   return 0;
}

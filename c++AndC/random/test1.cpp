#include<iostream>
#include<string>
using namespace std;

int main() {
   int count[26];
   for(int i=0; i<26; ++i)
      count[i] = 0;
   string s;
   cin >> s;  
   if(s.size()==0)
      return 0;
   int startIndex = 0; 
   count[s[startIndex]-'A'] += 1;
   for(int i=1; i<s.size();++i){
      count[s[i]-'A'] += 1;
      if(count[s[i]-'A']<3) {
         s[startIndex+1] = s[i];
         ++startIndex;
      }
   }
   if(startIndex!=(s.size()-1))
      s.erase(s.begin()+startIndex+1,s.end());
   cout << s <<endl;
   return 0;
}

#include <string>
#include <iostream>

using namespace std;
bool matchDonor(char g,string &q) {
    int count = 3;
    int size = q.size();
    while(size--) {
        if(g=='A' && (q[0]=='O' || q[0]=='A')) {
          count--;
       } else if(g=='B' && (q[0]=='O' || q[0]=='B')) {
          count--;
       } else if(g=='C' && (q[0]=='O' || q[0]=='B' || q[0]=='A' || q[0]=='C')) {
          count--;          
       } else if(g=='O' && (q[0]=='O')) {          
          count--;                     
        } else {
          q.append(string(1,q[0]));
        }
        q.erase(0,1);
        if(count==0)
           return true;
    }
    return false;
}

int main() {
    int T=0;
    std::cin>>T;
    while(T--) {
        string donor,patients;
        cin>> donor >> patients;
        int count = 0;
        for(int i=0; i<patients.size();++i) {
            if(matchDonor(patients[i],donor)) {
               ++count;
            }
            if(donor==string(""))
              break;
        }
        cout << count << std::endl;
    }
    return 0;
}

#ifndef _IPADDR_
#define _IPADDR_
#include <ostream>
#include "DataType.h"
#include <stdlib.h>
using namespace std;

class IpV4Address {
   // class to abstrace IpV4 address.
   public:
      IpV4Address(string ipAddres_);
      IpV4Address();
      IpV4Address(const IpV4Address &ip_);
      bool operator==(const IpV4Address &rhs) const;
      friend ostream &operator<<(ostream &out,const IpV4Address &ip_); 
      U8 octates(U8 index_) const;
   private:
      U8 _octates[4]; 
      // 1 Byte number for each octate of IPV4 address. 
};

IpV4Address::IpV4Address(const IpV4Address &ip_) {
   // copy constructor
   _octates[0] = ip_.octates(0);
   _octates[1] = ip_.octates(1);
   _octates[2] = ip_.octates(2);
   _octates[3] = ip_.octates(3);
}
ostream &operator<<(ostream &out,const IpV4Address &ip_) {
   out <<ip_.octates(0)<<"."<<ip_.octates(1)<<"."<<ip_.octates(2)<<"."<<ip_.octates(3)<<endl;
   return out;
}

U8 IpV4Address::octates(U8 index_) const{
   return _octates[index_];
}

IpV4Address::IpV4Address(string ipAddress_) {
   // parse string to fill the octates of the IpV4Address type.
   U8 first = 0;
   for(int i=0; i<=3; ++i) {
      U8 last = ipAddress_.find(first,'.');
      _octates[0] = atoi(ipAddress_.substr(first,last-1).c_str());
      first = last+1;
   }
}

bool IpV4Address::operator==(const IpV4Address &rhs_) const {
   return _octates[0]==rhs_.octates(0) &&
          _octates[1]==rhs_.octates(1) &&
          _octates[2]==rhs_.octates(2) &&
          _octates[3]==rhs_.octates(3);
}
#endif

#ifndef _RULE_
#define _RULE_
#include <ostream>
#include "IpV4Address.h"
using namespace std;
class Rule {
   // class to abstract routng table rules.
   // destinationIp :: mask :: gateway :: interface
   public:
     const IpV4Address &destinationIp() const;
     const IpV4Address &mask() const;
     const IpV4Address &gatewayIp() const; 
     const string &interface() const;
     bool isMatching(const IpV4Address &ip_);
     Rule(string destinationIp_,string mask_, string interface_,string gatewayIp_):
         _destinationIp(destinationIp_),_mask(mask_),
         _gatewayIp(gatewayIp_),_interface(interface_) {}
     bool operator==(const Rule &rule2_) const;
     friend ostream &operator<<( ostream &output, const Rule &rule_ );
   private:
      const IpV4Address _destinationIp;
      const IpV4Address _mask;
      const IpV4Address _gatewayIp;
      const string _interface;
};

ostream &operator<<( ostream &output, const Rule &rule_ ) {
   output << rule_.destinationIp() << " " << rule_.mask() << " "; 
   output << rule_.gatewayIp() << " " << rule_.interface();
   return output;
}
bool Rule::operator==(const Rule &rule_) const{
   return _destinationIp==rule_.destinationIp() &&
          _mask==rule_.mask() &&
          _gatewayIp==rule_.gatewayIp() &&
          _interface==rule_.interface();
}
const IpV4Address &Rule::destinationIp() const{
   return _destinationIp;
}
const IpV4Address &Rule::mask() const{
   return _mask;
}
const IpV4Address &Rule::gatewayIp() const{
   return _gatewayIp;
}
const string &Rule::interface() const{
   return _interface;
}
bool Rule::isMatching(const IpV4Address &ip_) {
    // a ipAddress matches the rule only when after  applying the mask, destinaition Ip
    // of the rule matches.
    return (ip_.octates(0)&_mask.octates(0))==_destinationIp.octates(0) &&
           (ip_.octates(1)&_mask.octates(1))==_destinationIp.octates(1) &&
           (ip_.octates(2)&_mask.octates(2))==_destinationIp.octates(2) &&
           (ip_.octates(3)&_mask.octates(3))==_destinationIp.octates(3);
} 

#endif


#ifndef _IFACE_
#define _IFACE_
#include "IpV4Address.h"
#include "Packet.h"
#include<string> 

class Interface {
   public:
      void up();
      void down();
      bool state() const;
      void ipAddressIs(IpV4Address ip_);
      const IpV4Address &ipAddress() const;
      void maskIs(IpV4Address mask_);
      const IpV4Address &mask() const;
      void routePacket(const Packet &packet_);
      string name() const;
      friend ostream &operator<<(ostream &out,const Interface &if_);
      //Interface() {}
      Interface(string name_="",bool state_=false,string ip_="",string mask_="");
   private:
      string _name;
      bool _state;
      IpV4Address _ipAddress; 
      IpV4Address _mask;
      void printRouting();
};

Interface::Interface(string name_,bool state_,string ip_,string mask_) {
   _name = name_;
   _state = state_;
   _ipAddress = IpV4Address(ip_); 
   _mask = IpV4Address(mask_);
} 
void Interface::routePacket(const Packet &packet_) {
   if(!_state) {
      cout << "Error: Interface is not up: "<<_name;
      return;
   }
   cout << "Info: Routed the packet "<<packet_<<endl;
}

ostream &operator<<(ostream &out,const Interface &if_) {
   out << if_.ipAddress() << " " << if_.mask() << " " << if_.state() << " " << if_.name();
   return out;
}

string Interface::name() const{
   return _name;
}
void Interface::up() {
   _state = true;
}
void Interface::down() {
   _state = false;
}
bool Interface::state() const{
   return _state;
}
void Interface::ipAddressIs(IpV4Address ipAddress_) {
    _ipAddress = ipAddress_;
}
const IpV4Address &Interface::ipAddress() const{
    return _ipAddress;
}
void Interface::maskIs(IpV4Address mask_) {
   _mask = mask_;
}
const IpV4Address &Interface::mask() const{
   return _mask;
}
#endif

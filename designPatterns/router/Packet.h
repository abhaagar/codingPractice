#ifndef _PACKET_
#define _PACKET_
#include <iostream>
#include "IpV4Address.h"

class Packet {
   // class to abstract network packet.
   // It only has destination  and source IPs.
   public:
     const IpV4Address & source() const{
        return _sourceIp;
     }
     const IpV4Address & destination() const{
        return _destinationIp;
     }
     Packet(IpV4Address source_, IpV4Address destination_):
        _sourceIp(source_),_destinationIp(destination_) {}
     friend ostream &operator<<(ostream &out, const Packet &pkt_);
   private:
     IpV4Address _sourceIp;
     IpV4Address _destinationIp;
};
ostream &operator<<(ostream &out, const Packet &pkt_) {
   cout << pkt_.source() << "<--> " <<pkt_.destination();
   return out;
}
#endif

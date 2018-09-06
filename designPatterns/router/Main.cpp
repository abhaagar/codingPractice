#include "Router.h"
#include <string>
#include <unistd.h>
int main() {
   Router r;
   string if0("eth0"),if1("eth1"),if2("wlan0");
   string destIp1("192.168.0.1"),destIp2("172.18.2.1"),destIp3("10.20.30.1");
   string mask("255.255.255.0");
   Interface eth0(if0,true,destIp1,mask);
   Interface eth1(if1,true,destIp2,mask);
   Interface wlan0(if2,true,destIp3,mask);
   r.addInterface(eth0);
   r.addInterface(eth1);
   r.addInterface(wlan0);
   r.setDefaultGateway("eth0");
   Rule rule1("192.168.0.0","255.255.255.0","eth0","");
   Rule rule2("172.18.2.0","255.255.255.0","eth1","");
   Rule rule3("10.20.30.0","255.255.255.0","wlan0","");

   r.addRule(rule1);
   r.addRule(rule2);
   r.addRule(rule3);

   while(true) {
      int randSubnet = random()%4;
      string sourceIp;
      string destinationIp;
      string ipPrefix;
      if(randSubnet==0) {
         ipPrefix += "192.168.0.";
      } else if(randSubnet==1) {
         ipPrefix += "172.18.2.";
      } else if(randSubnet==2) {
         ipPrefix += "10.20.30.";
      } else {
         ipPrefix += "192.170.0";
      } 
      int randHost = random()%255+1;
      destinationIp += to_string(randHost);
      randHost = random()%255+1;
      sourceIp += to_string(randHost);
      Packet p(sourceIp,destinationIp);
      r.routePacket(p);
      usleep(2000000);
   }
   return 0;
}

#include <iostream>
#include "RoutingTable.h"
#include "Interface.h"
#include "Packet.h"
class Router {
   public: 
      void routePacket(const Packet &packet_);
      void addInterface(Interface if_);
      void removeInterface(string name_);
      void listInterfaces();
      void addRule(Rule rule_);
      void removeRule(int num_);
      void listRules();
      void setDefaultGateway(const string &name_);
   private:
      RoutingTable _table;
      vector<Interface> _interfaces;
      Rule matchRule(string destinationIp_);
};

void Router::setDefaultGateway(const string &name_) {
   _table.setDefaultGateway(name_);
}
void Router::routePacket(const Packet &packet_) {
   string if_ = _table.matchedRuleInterface(packet_);
   for(int i=0; i<_interfaces.size(); ++i) {
      if(_interfaces[i].name()==if_) {
         _interfaces[i].routePacket(packet_); 
         return;
      }
   } 
   cout << "Info: No matching rule for packet with "<<packet_.destination();
}

void Router::addInterface(Interface if_) {
   for(int i=0; i<_interfaces.size();++i) {
      if(if_.name()==_interfaces[i].name()) {
         cout << "Error: Interface already Exists\n";
         return;
      }   
   }  
   _interfaces.push_back(if_);
}
void Router::removeInterface(string name_) {
   for(int i=0; i<_interfaces.size();++i) {
      if(name_==_interfaces[i].name()) {
         _interfaces.erase(_interfaces.begin()+i);
         return;
      }   
   }  
   cout << "Error: No such interface: " << name_ << endl;
} 

void Router::listInterfaces() {
   for(int i=0; i<_interfaces.size();++i) {
      cout << _interfaces[i] << endl;
   }
}
void Router::addRule(Rule rule_) {
   _table.addRule(rule_);
}

void Router::removeRule(int num_) {
   _table.removeRule(num_);
}
void Router::listRules() {
   _table.listRules();
}

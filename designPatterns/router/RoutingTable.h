#ifndef _ROUTE_TABLE_
#define _ROUTE_TABLE_
#include "Rule.h"
#include "Packet.h"
#include <vector>
class RoutingTable {
   // class to abstract Routing table of a router.
   public:
     void addRule(Rule rule_);
     void removeRule(const int num_);
     void listRules();
     void setDefaultGateway(const string &name_);
     string matchedRuleInterface(const Packet&);
   private:
      vector<Rule> _rules;
      string _defaultGateway;
};

string RoutingTable::matchedRuleInterface(const Packet &packet_) {
    // finds if a rule matches
    for(int i=0; i<_rules.size(); ++i) {
       if(_rules[i].isMatching(packet_.destination())) {
          return _rules[i].interface();
       }
    }
    return _defaultGateway;
    // if none of the rule matches that use default gateway.
}

void RoutingTable::setDefaultGateway(const string &name_) {
   // sets the default gateway of the router.
   for(int i=0; i<_rules.size(); ++i) 
      if(_rules[i].interface()==name_) {
         _defaultGateway = name_;
         return;
      }
   cout << "Error: Given interface does not exist\n";
}

void RoutingTable::addRule(Rule rule_) {
   for(int i=0; i<_rules.size(); ++i) {
      if(_rules[i]==rule_) {
        cout << "Error: Matching rule already exists\n";
        return;
      }
   }
}

void RoutingTable::removeRule(const int num_) {
   if(_rules.size()-1<num_)
      cout << "Error: Invalid rule number given\n";
   else {
      _rules.erase(_rules.begin()+num_);
      if(num_==0)
         cout << "Warning: Default gateway rule deleted\n";
   }
}

void RoutingTable::listRules() {
   for(int i=0; i<_rules.size();++i) {
      cout << _rules[i] << endl;
   }
}
#endif

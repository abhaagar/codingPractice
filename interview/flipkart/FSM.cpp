#include<string>
#include<unordered_map>
#include<assert.h>
#include<vector>
#include<iostream>
class State {
   public:
     void transitionIs(std::string input, std::string state_);
     State(std::string name_) : _name(name_) {}
     std::string transitionTo(std::string input_);
     void cleanUp(std::vector<std::string> &states_);
     void removeTransition(std::string toState_);
     std::string name();
     void display();
   private:
      std::string _name;
      std::unordered_map<std::string, std::string> _toStates;
};

void State::display() {
   std::cout << "Transition From State: " << _name << std::endl;
   std::unordered_map<std::string, std::string>::iterator it = _toStates.begin();
   for(; it!=_toStates.end();++it) {
      std::cout << "-" << it->first << "->" << it->second;
   }
}

void State::removeTransition(std::string name_) {
   for(std::unordered_map<std::string,std::string>::iterator it = _toStates.begin(); 
      it!=_toStates.end(); ++it) {
      if(it->second==name_) {
         _toStates.erase(it->first);
         return;
      }
   }
   std::cout << "Error : no transition to the state\n";
}

void State::cleanUp(std::vector<std::string> &states_) {
   std::unordered_map<std::string, std::string>::iterator it = _toStates.begin();
   for(; it!=_toStates.end(); ++it) {
      _toStates.erase(it->first);
      states_.push_back(it->second);
   }
}

std::string State::name() {
   return _name;
}

void State::transitionIs(std::string input_, std::string state_) {
   if(_toStates.find(input_)!=_toStates.end()) {
      std::cout << "Error: Already transition exists on the input\n";
      return;
   }
   _toStates[input_] = state_;
}

std::string State::transitionTo(std::string input_) {
    if(_toStates.find(input_)==_toStates.end()) {
       std::cout << "Error: No transition from the state for the input\n";
       return "";
    }
    return _toStates[input_];
}

class FSM {
   public:
      void stateIs(std::string name_); 
      void removeState(std::string name_);
      void transitionIs(std::string state1_, std::string input_, std::string state2_);
      void removeTransition(std::string state1_, std::string state2_);
      std::string currentState();
      void makeTransition(std::string input_);
      void finalStateIs(std::string state_);
      bool isInFinaleState();
      void startStateIs(std::string);
      std::string startState();
      void start();
      void usage();
      void display();
   private:
      std::string _currentState;
      std::string _startState;
      bool isState(std::string name_);
      bool isFinalState(std::string name_);
      std::unordered_map<std::string,State*> _states;
      std::unordered_map<std::string,State*> _finalStates;
};

void FSM::display() {
   std::unordered_map<std::string,State*>::iterator it = _states.begin();
   for(; it!=_states.end(); ++it) {
      it->second->display();
      std::cout << std::endl;
   }
}

void FSM::usage() {
   std::cout << "1: Add State\n";
   std::cout << "2: Add Transition\n";
   std::cout << "3: Add Start State\n";
   std::cout << "4: Add Final State\n";
   std::cout << "5: Make Transition\n";
   std::cout << "6: Delete State\n";
   std::cout << "7: Delete Transition\n";
   std::cout << "8: Display Current State\n";
   std::cout << "9: Check If Final State\n";
}

std::string getStringFromInput() {
    std::string input;
    std::cin >> input;
    return input;
}

void FSM::start() {
   char c;
   std::string to;
   std::string from;
   std::string input;
   while (true) {
      std::cin >> c;
      std::cout << "choice " << c << std::endl;
      if(c==0)
          return;
      switch(c) {
         case '0':
            usage();
            display();
            break;
         case '1':
            stateIs(getStringFromInput());
            break;
         case '2':
            from = getStringFromInput();
            input = getStringFromInput();
            to = getStringFromInput();
            transitionIs(from,input,to);
            break;
         case '3':
            startStateIs(getStringFromInput());
            break;
         case '4':
            finalStateIs(getStringFromInput());
            break;
         case '5':
            makeTransition(getStringFromInput());
            break;
         case '6':
            if(_startState==_currentState) {
              removeState(getStringFromInput());  
            } else {
               std::cout << "Error: FSM is not in start state\n";
            }
            break;
         case '7':
            if(_startState==_currentState) {
              removeTransition(getStringFromInput(),getStringFromInput());  
            } else {
               std::cout << "Error: FSM is not in start state\n";
            }
            break;
      }
   }
}
void FSM::startStateIs(std::string state_) {
   if(!isState(state_)) {
      std::cout << "Error: state does not exist\n";
   } else {
      _startState = state_;
      _currentState = state_;
   }
}
std::string FSM::startState() {
   if(!_startState.empty()) {
      return _startState;
   } else {
      std::cout << "Error: start state is not set\n";
   }
}

bool FSM::isInFinaleState() {
   return _finalStates.find(_currentState)==_finalStates.end(); 
}

void FSM::finalStateIs(std::string state_) {
   if(!isState(state_)) {
      std::cout << "Error: from state does not exist\n";
   } else { 
      _finalStates[state_] = _states[state_];
   }      
}

void FSM::makeTransition(std::string input_) {
   std::string state = _states[_currentState]->transitionTo(input_);
   assert(isState(state));
   _currentState = state; 
}

std::string FSM::currentState() {
   return _currentState;
}
bool FSM::isState(std::string name_) {
   return _states.find(name_)!=_states.end();
}
      
bool FSM::isFinalState(std::string name_) {
   return _finalStates.find(name_)!=_finalStates.end();
}
      
void FSM::stateIs(std::string name_) {
   if(isState(name_)) {
      std::cout << "Error: state already exists\n";
   } else {
      State * state = new State(name_); 
      _states[name_] = state;
   }
}

void FSM::removeState(std::string name_) {
   if(!isState(name_)) {
      std::cout << "Error: state does not exist\n";
   } else {
      std::vector<std::string> toStates;
      _states[name_]->cleanUp(toStates);
      _states.erase(name_);
      for(int i=0; i!=toStates.size();++i) {
         std::string name = toStates[i];
         _states[name]->removeTransition(name_);
      }
   }
}

void FSM::transitionIs(std::string state1_, std::string input_, std::string state2_) {
   if(!isState(state1_)) {
      std::cout << "Error: from state does not exist\n";
   } else if(!isState(state2_)) {
      std::cout << "Error: to state does not exist\n";
   } else {
     _states[state1_]->transitionIs(input_,state2_);
   }
}

void FSM::removeTransition(std::string state1_, std::string state2_) {
   if(!isState(state1_)) {
      std::cout << "Error: from state does not exist\n";
   } else if(!isState(state2_)) {
      std::cout << "Error: to state does not exist\n";
   } else {
      _states[state1_]->removeTransition(state2_);
   }
}

int main() {
   FSM fsm;
   fsm.start();
   //fsm.stateIs("A");
   //fsm.startStateIs("A");
   //fsm.stateIs("B");
   //fsm.stateIs("C");
   //fsm.finalStateIs("C");
   //fsm.transitionIs("A","a","B");
   //fsm.transitionIs("A","c","A");
   //fsm.transitionIs("B","c","C");
   //fsm.transitionIs("B","a","A");
   //fsm.transitionIs("C","c","C");
   //fsm.transitionIs("C","a","B");
   //fsm.makeTransition("c");
   //fsm.makeTransition("a");
   //fsm.makeTransition("c");
   //fsm.makeTransition("c");
   //fsm.makeTransition("a");
   //fsm.makeTransition("a");
   //std::cout << fsm.currentState() << std::endl;
   return 0;
}



#include<iostream>
#include<vector>

class Input {
   public:
      Input(std::string data): data(data){}
      Input(const Input &ip) {
         this->data = ip.getData();
      }
      std::string getData() const {
         return this->data;
      }
   private:
      std::string data;
};
class State;
class Transition {
   public:
      Transition(Input ip,State *to): ip(ip),to(to){}
      Input getInput() {
         return this->ip;
      }
      const State* getTransitionState() {
         return this->to;
      }
   private:
      Input ip;
      State *to;
};

class State {
   public:
     State(std::string label="",bool isStart=false,bool isEnd=false): 
       label(label),isStart(isStart),isEnd(isEnd) {}
     State(const State &s) {
        this->label = s.getLabel();
     }
     std::string transit(Input ip) {
        for(std::vector<Transition>::iterator it = this->transitions.begin(); it<this->transitions.end(); ++it) {
           if(it->getInput().getData()==ip.getData())
              return it->getTransitionState()->getLabel();
        }
        return std::string("");
     }
     std::string getLabel() const {
        return this->label;
     }
     void addTransition(Transition t) {
        this->transitions.push_back(t);
     }
   private:
     std::string label;
     bool isStart;
     bool isEnd;
     std::vector<Transition> transitions;
};

class StateMachine {
   public:
      void addState();
      void addState(std::string stateLabel, bool isStart, bool isEnd);
      void acceptInput();
      void addTransition();
      void addTransition(std::string start, std::string end,std::string inputLabel);
   private:
      std::vector<State> states;
      int currentStateIndex;
      Input *currentInput;
      void consumeInput();
};

void StateMachine::addTransition(std::string start, std::string end,std::string inputLabel) {
   std::vector<State>::iterator sit=this->states.end(), eit=this->states.end();
   for(std::vector<State>::iterator it = this->states.begin(); it<this->states.end(); ++it) {
      if(it->getLabel()==start) {
         sit = it;
      }
      if(it->getLabel()==end) {
         eit = it;
      }
      if(sit!=this->states.end()&&eit!=this->states.end()) {
         break;
     }
   }
   if(sit==this->states.end()||eit==this->states.end()) {
      std::cout << "Both the states not present\n";
      return;
   }
   Transition t(Input(inputLabel),&(*eit));
   sit->addTransition(t);
}

void StateMachine::addState(std::string stateLabel, bool isStart, bool isEnd) {
   //for(std::vector<State>::iterator it = this->states.begin(); it<this->states.end(); ++it) {
   for(auto & state :  states) {
      if(state.getLabel()==stateLabel) {
         std::cout << "a state with label "+stateLabel+" already present" << std::endl;
         return;
      }
   }
   State s(stateLabel,isStart,isEnd);
   this->states.push_back(s);
   if(isStart) {
      this->currentStateIndex = this->states.size()-1;
   }
}

void StateMachine::addState() {
   std::string stateLabel;
   std::cin >> stateLabel;
   //for(std::vector<State>::iterator it = this->states.begin(); it<this->states.end(); ++it) {
   for(auto & state :  states) {
      if(state.getLabel()==stateLabel) {
         std::cout << "a state with label "+stateLabel+" already present" << std::endl;
         return;
      }
   }
   char isStart,isEnd;
   std::cout << "Is a start state ? y/n" << std::endl;
   std::cin >> isStart;
   std::cout << "Is a end state ? y/n" << std::endl;
   std::cin >> isEnd;
   State s(stateLabel,isStart=='y',isEnd=='y');
   this->states.push_back(s);
   if(isStart=='y') {
      this->currentStateIndex = this->states.size()-1;
   }
}
void StateMachine::acceptInput() {
   std::string inputLabel;
   std::cin >> inputLabel;
   std::string nextStateLabel = this->states[this->currentStateIndex].transit(Input(inputLabel));
   std::vector<State>::iterator it = this->states.begin();
   for(; it<states.end(); ++it) {
      if(it->getLabel()==nextStateLabel) {
         this->currentStateIndex = it-this->states.begin();
         std::cout << "current state is "+nextStateLabel<<std::endl;
         return;
      }
   }
   std::cout << "no transition for the input form currentState" << std::endl;
}


int main() {
   StateMachine sm;
   sm.addState();
   sm.addState();
   sm.addTransition();
   sm.addTransition();
   sm.addTransition();
   sm.addTransition();
   while(1) {
      sm.acceptInput();
   }
   return 0;
}

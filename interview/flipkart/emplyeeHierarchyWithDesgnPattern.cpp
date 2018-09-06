#include<iostream>
#include<vector>
using namespace std;
class IdCounter {
    public:
       static IdCounter *idc;
       int _id;
    protected:
       IdCounter() {
          _id = 0;
       }
    public:
       int next() {
          return ++_id;
       }
       int id() {
          return _id;
       }
       static IdCounter *instance() {
          if(!idc) {
             idc = new IdCounter;
          }
          return idc;
       } 
};

IdCounter * IdCounter::idc = 0;
class Employee {
   public:
      virtual float rating() = 0;
      virtual float salary() = 0;
      string name();
      int id();
      Employee(string);
   private:
      string _name;
      int _id;
   protected:
      float _rating;
      float _salary;
};
Employee::Employee(string name_) {
   _name = name_;
   IdCounter::instance()->next();
   _id = IdCounter::instance()->id();
}
string Employee::name() {
   return _name;
}
int Employee::id() {
   return _id;
}

class Engineer : public Employee {
   public:
      void ratingIs(float);
      void salaryIs(float);
      void managerIs(Engineer*);
      virtual float rating();
      virtual float salary();
      Engineer* manager();
      Engineer(string);
   private:
      Engineer *_manager;
};
Engineer::Engineer(string name_): Employee(name_) {
}
float Engineer::rating() {
   return _rating; 
}
float Engineer::salary() {
   return _salary;
}
void Engineer::ratingIs(float rating_) {
   _rating = rating_;
}
void Engineer::salaryIs(float salary_) {
   _salary = salary_;
}
void Engineer::managerIs(Engineer *manager_){
   _manager = manager_;
}
Engineer * Engineer::manager() {
   return _manager;
}

class Manager : public Employee {
   public:
      void addEmployee(Employee *);
      virtual float rating();
      virtual float salary();
      Manager(string);
   private:
      vector<Employee*> _employees;
};

Manager::Manager(string name_):Employee(name_) {
}

float Manager::rating() {
   float rating = 0;
   for(int i=0;i<_employees.size();++i){
      rating += _employees[i]->rating();
   }
   return rating/_employees.size();
}
float Manager::salary() {
   float salary = 0;
   for(int i=0;i<_employees.size();++i){
      salary += _employees[i]->salary();
   }
   return salary/_employees.size();
}
void Manager::addEmployee(Employee *employee_) {
   if(employee_->id()==id()) {
      std::cout << "Error: a manager can't be his/her own employee" <<std::endl;
      return;
   }
   for(int i=0; i<_employees.size();++i){
      if(_employees[i]->id()==employee_->id()) {
         std::cout << "Warning: Already added " << employee_->name();
         std::cout << " to mamanger " << _employees[i]->name() << std::endl;
         return;
      }
   }
   _employees.push_back(employee_);
}

class CEO : public Employee{
    virtual float rating() {}
    virtual float salary() {}
    protected:
       CEO(string name_) : Employee(name_) {
       }
    public:
       static CEO* instance() {
          if(!ceo) {
             ceo = new CEO("CEO");
          }
          return ceo;
       }
    private:
       static CEO* ceo;
};
CEO* CEO::ceo = 0;
float rating(Employee*emp) {
   return emp->rating();
}

float salary(Employee *emp) {
   return emp->salary();
}
int main() {
   Engineer emp1("E1");
   Engineer emp2("E2");
   Engineer emp3("E3");
   Engineer emp4("E4");
   Manager man1("M1");
   Manager man2("M2");
   CEO *emp = CEO::instance();
   //EngineerFactory * empFact = new EngineerFactory; 
   //Engineer * emp1 = empFact->createEngineer("E1");
   //Engineer * emp2 = empFact->createEngineer("E2");
   //Engineer * emp3 = empFact->createEngineer("E3");
   //Engineer * emp4 = empFact->createEngineer("E4");
   //Manager * manager1 = empFact->createManager("M1");
   //Manager * manager2 = empFact->createManager("M2");
   //manager1->addEngineer(emp1);
   //std::unordered_map<string,Engineer*> employees;
   //std::unordered_map<string,Engineer*> managers;
   //vector<Engineer*> employees;
   //vector<Manager*> managers;
   //Engineer *ceo;
   //char choice;
   //string id;
   //Engineer *empl_;
   //while(true) {
   //   usage();
   //   std::cin >> choice;
   //   switch(choice) {
   //      case '1':
   //         std::cin >> id;
   //         if(employees.find(id)==employees.end()) {
   //            empl_ = createEngineer(employees); 
   //            employees[empl_.id()] = empl_;
   //         } else {
   //            std::cout << "Error: Engineer with input id already exists\n";
   //         }
   //      case '2':
   //         std::cin >> id;
   //         if(employees.find(id)!=employees.end()) {
   //             if(managers.find(empl_.id())!=managers.end()) {
   //                std::cout << "Error: Manager already exists\n";
   //             } else {
   //                empl_ = createEngineer(); 
   //                employees[empl_.id()] = empl_;
   //                managers[empl_.id()] = empl_;
   //             }
   //         } else {
   //            std::cout << "Error: Engineer with input id already exists\n";
   //         }
   //      case '3':
   //         if(ceo) {
   //            std::cout << "CEO already exists\n";
   //         } else { 
   //            empl_ = createEngineer(); 
   //            employees[empl_.id()] = empl_;
   //            ceo = empl_;
   //         } 
   //      case '4':
   //         std::cin >> managerId >> employeeId; 
   //         if(managers.find(managerId)!=managers.end() && employees.find(employeeId)!=employees.end()) {
   //            employees[employeeId].managerIs(managers[managerId]);
   //            managers[managerId].addEngineer(employees[employeeId]);
   //         } else {
   //            std::cout << "Error: either manager or employee does not exist\n"
   //         } 
   //      case '5':
 
   //   }
   //}
   return 0;
}

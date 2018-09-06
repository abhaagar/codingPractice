#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Employee {
   private:
      string _name;
   public:
      Employee(string name_) {
         _name = name_;
      }
      string name() {
         return _name;
      }
      void virtual work() = 0; 
      float virtual salary() = 0;
};

class Developer : public Employee {
   private:
      float _salary;
   public:
      Developer(string name_,float salary_) : Employee(name_),_salary(salary_) {}
      void work() {
         cout << "Developer " << name() << " Worked\n";
      }
      float salary() {
         return _salary;
      }
};

class Manager : public Employee {
   private:
      vector<Employee *> _team; 
   public:
      Manager(string name_) : Employee(name_) {}
      void add(Employee * emp_) {
          _team.push_back(emp_);
      } 
      void work() {
         cout << "Manager " << name() << " Distributed Work\n"; 
         for(vector<Employee*>::iterator it = _team.begin(); it!=_team.end(); ++it) {
            (*it)->work();
         }
      }
      float salary() {
         float salary_ = 0.0;
         for(vector<Employee*>::iterator it = _team.begin(); it!=_team.end(); ++it) {
            salary_ += (*it)->salary()+10000;
         }
         return salary_;
      }
};

int main() {
   Developer d1("developer1",10000);
   Developer d2("developer2",15000);
   Manager m1("manager1");
   m1.add(&d1);
   m1.add(&d2);
   Manager m2("manager2");
   m2.add(&m1);
   cout << m2.salary() << "\n";
   m2.work();
   return 0;
}

// Problem Statement:
// Employee hierarchy in an Organization is classic example of modeling Composite design pattern.
// Following are the details that are to be modeled:
// 
// (1)- There are two type of employees; Manager, and Developer.
// (2)- A Manager manages a team that can comprise managers, and developer.
// (3)- A Developer has fixed salary at given point of time and get work from the manager.
// (4)- The salary of a manager is the sum of salary of all the team members + 10K.
// (5)- We need to model work distribution, and salary of employees of the organization


using std::vector;
using std::string;
using std::cout;

class Employee {
   private:
      string _name;
   public:
      Employee(string name_) {
         _name = name_;
      }
      string name() const {
         return _name;
      }
      void virtual work() const = 0; 
      float virtual salary() const = 0;
};
// Common Interface to interact with Manager, and Developer
class Developer : public Employee {
   private:
      float _salary;
   public:
      Developer(string name_,float salary_) : Employee(name_),_salary(salary_) {}
      void work() const {
         std::cout << "Developer " << name() << " Worked\n";
         // A developer works own.
      }
      float salary() const {
         return _salary;
      }
};

class Manager : public Employee {
   private:
      vector<Employee*> _team; 
   public:
      Manager(string name_) : Employee(name_) {}
      void add(Employee * emp_) {
          _team.push_back(emp_);
      } 
      void work() const {
         std::cout << "Manager " << name() << " Distributed Work\n";
           for(const auto & emp : _team) {
              emp->work();
         }
         // A manager distributes work in team members.
      }
      float salary() const {
         float salary_ = 0.0;
         for(const auto & emp : _team) {
            salary_ += emp->salary() + 15000;
         }
         return salary_;
         // Salary of a manager is derived from team members.
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
   std::cout << m2.salary() << "\n";
   m2.work();
   return 0;
}

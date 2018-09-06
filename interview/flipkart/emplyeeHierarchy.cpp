class Employee {
   public:
      void nameIs(string);  
      void idIs(string);
      void ratingIs(float);
      void salaryIs(float);
      string name();  
      string id();
      float rating();
      float salary();
      void addManager(Employee *);
   private:
      string _name;
      string _id;
      float _rating;
      float _salary;
      Employee * _manager;
};
void Employee::nameIs(string name_) {
   _name = name_;
}
void Employee::idIs(string id_) {
   _id = id_;
}
void Employee::ratingIs(float rating_) {
   _rating = rating_;
}
void Employee::salarayIs(float salary_) {
   _salary = salary_;
}
string Employee::name() {
   return _name;
}
string Employee::id() {
   return _id;
}
float Employee::rating() {
   return _rating;
}
float Employee::salaray() {
   return _salary;
}
void managerIs(Employee *manager_){
   _manager = manager_;
}
Employee * manager() {
   return _manager;
}

class Manager : public Employee {
   public:
      void addEmployee(Employee *);
   private:
      vector<Employee*> employees_;
}

void Manager::addEmployee(Employee *employee_) {
   if(employee_->id()==_id) {
      std::cout << "Error: a manager can't be his/her own employee" <<std::endl;
      return;
   }
   for(int i=0; i<_employees.size();++i){
      if(_employees[i]->id()==employee_->id()) {
         std::cout << "Warning: Already added " << employee_->name() << " to mamanger " << _employees[i]->name() << std::endl;
         return;
      }
   }
   _employees.push_back(employee_);
}

Employee * createEmployee() {
   string name_;
   float rating_, salary_;
   std::cin >> name_ >> id_ >> rating_ >> salary_;
   Employee *newEmpl_ = Employee(name_,id_,rating_,salary_);
   return newEmpl_;
}

int main() {
   std::unordered_map<string,Employee*> employees;
   std::unordered_map<string,Employee*> managers;
   vector<Employee*> employees;
   vector<Manager*> managers;
   Employee *ceo;
   char choice;
   string id;
   Employee *empl_;
   while(true) {
      usage();
      std::cin >> choice;
      switch(choice) {
         case '1':
            std::cin >> id;
            if(employees.find(id)==employees.end()) {
               empl_ = createEmployee(employees); 
               employees[empl_.id()] = empl_;
            } else {
               std::cout << "Error: Employee with input id already exists\n";
            }
         case '2':
            std::cin >> id;
            if(employees.find(id)!=employees.end()) {
                if(managers.find(empl_.id())!=managers.end()) {
                   std::cout << "Error: Manager already exists\n";
                } else {
                   empl_ = createEmployee(); 
                   employees[empl_.id()] = empl_;
                   managers[empl_.id()] = empl_;
                }
            } else {
               std::cout << "Error: Employee with input id already exists\n";
            }
         case '3':
            if(ceo) {
               std::cout << "CEO already exists\n";
            } else { 
               empl_ = createEmployee(); 
               employees[empl_.id()] = empl_;
               ceo = empl_;
            } 
         case '4':
            std::cin >> managerId >> employeeId; 
            if(managers.find(managerId)!=managers.end() && employees.find(employeeId)!=employees.end()) {
               employees[employeeId].managerIs(managers[managerId]);
               managers[managerId].addEmployee(employees[employeeId]);
            } else {
               std::cout << "Error: either manager or employee does not exist\n"
            } 
         case '5':
 
      }
   }
   return 0;
}

#include<iostream>
using namespace std;
template <typename T> 
class SmartPtr
{
   T *ptr;  // Actual pointer
   int ref;
public:
   // Constructor: Refer http://www.geeksforgeeks.org/g-fact-93/
   // for use of explicit keyword 
   explicit SmartPtr(T *p = NULL) { 
      std::cout << "constructor" <<std::endl;
      ptr = p;
     
   } 
 
   // Destructor
   ~SmartPtr() { 
      std::cout << "destructor" <<std::endl;
      delete(ptr);
   }  
 
   // Overloading dereferencing operator
   T &operator *() {  return *ptr; }
};

void f() {

    SmartPtr<int> ptr1(new int());
    SmartPtr<char> ptr2(new char());
    *ptr1 = 20;
    *ptr2 = 'a';
    std::cout << *ptr1 << " " << *ptr2 << std::endl;
 
    // We don't need to call delete ptr: when the object 
    // ptr goes out of scope, destructor for it is automatically
    // called and destructor does delete ptr.

}  

int main()
{
    f(); 
    return 0;
}

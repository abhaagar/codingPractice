#include<iostream>
using namespace std;
class Expression {
   public:
      virtual float value() = 0;
};

class Singleton : public Expression {
      float _value;
   public:
      float value() {
         return _value;
      }
      Singleton(float value_) {
         _value = value_;
      }
};


class Composite : public Expression {
       Expression *_left;
       Expression *_right;
       char _operator;
    public:
       float value() {
           if(_operator=='*') {
              return _left->value()*_right->value(); 
           } else if(_operator=='-') {
              return _left->value()-_right->value(); 
           } else if(_operator=='+') {
              return _left->value()+_right->value(); 
           } else if(_operator=='/') {
              return _left->value()/_right->value(); 
           }  
       }
       void leftIs(Expression *left_) {
          _left = left_;
       }
       void rightIs(Expression *right_) {
          _right = right_;
       }
       void operatorIs(char operator_) {
          _operator = operator_;
       }
};

int main() {
   Singleton s1(2);
   Singleton s2(23);
   Composite *c1 = new Composite;
   c1->leftIs(&s1);
   c1->rightIs(&s2);
   c1->operatorIs('+');
   Composite *c2 = new Composite;
   c2->leftIs(c1);
   c2->rightIs(&s1);
   c2->operatorIs('*');
   cout << c2->value() << "\n";
   return 0;
}

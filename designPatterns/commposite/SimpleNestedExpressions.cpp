// Problem Statement:
// Simple Nested expression with operators ‘X’, ‘+’, ‘-‘.
// Following are the details that are to be modeled:
// 
// (1)- Simple expression comprises of two numbers as operand and
//      an operator ‘+’, ‘/’, ‘-‘, and ‘x’. Example is “24+45”, “50/2”.
// (2)- Nested expression can contains at least one simple expression as operand and 
//      operator ‘+’, ‘/’, ‘-‘, and ‘x’. Example is “(2+8)x3”, “(8-3)/(4-3)”.

class Expression {
   public:
      virtual float value() const = 0;
};

class Singleton : public Expression {
      float _value;
   public:
      float value() const {
         return _value;
      }
      Singleton(float value_) const {
         _value = value_;
      }
};


class Composite : public Expression {
       Expression *_left;
       Expression *_right;
       char _operator;
    public:
       float value() const {
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

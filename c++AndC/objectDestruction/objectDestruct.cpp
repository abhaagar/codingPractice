

class A{

   public:
      int a;
      A() {
        
      }
      ~A() {

      }
};

int Z(int a){
   A a1;
   if(a==3){
      return 9;
   }
   A a2;
   return 0;
}

int main() {
   return Z(3);
}

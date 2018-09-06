int functionF() {
   int variableA = 3;
   int variableB = 4;
   char variableC[]="f() function";
   return variableA+variableB;
}

int functionG() {
   int variableA = 3;
   int variableB = 4;
   char variableC[]="g() function";
   return variableA+variableB;
}

int main() {
   functionF()+functionG();   
   return 0;
}

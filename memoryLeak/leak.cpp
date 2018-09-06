#include<stdio.h>
#include<stdlib.h>
void createLeak() {
   int *p = (int*) malloc(sizeof(int)*100);
}  

int main() {

   createLeak();
   return 0;
}

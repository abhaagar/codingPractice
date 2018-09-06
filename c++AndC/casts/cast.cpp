int main() {
   int a = 9;
   int *p1 = (&a);
   int *p2 = dynamic_cast<int*>(&a);
   return 0; //*p1+*p2;
}

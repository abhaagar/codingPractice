#include<iostream>
#include <bitset>
using namespace std;

int gcd(int a, int b) {
  if(a%b==0)
     return b;
  return gcd(b,a%b);
}
void print(int *arr, int size) {
   for(int i=0; i<size; ++i) {
      cout << arr[i];
   }
   cout << endl;
}
int main() {
   int arr[10] = {0,1,2,3,4,5,6,7,8,9};
   bitset<1> direction(1);
   int rotationBy(4);
   int size(sizeof(arr)/sizeof(int));
   print(arr,size);
   for(int i=0; i<gcd(rotationBy,size); ++i) {
      int j=i,temp=arr[i];
      while(true) {
         int k = j+rotationBy; 
         if(k>=size)
            k -= size;
         if(k==i)
            break;

         arr[j] = arr[k];
         j = k;
      }
      arr[j] = temp;
   }
   print(arr,size);
   return 0;
}

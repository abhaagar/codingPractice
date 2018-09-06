#include<iostream>
using namespace std;

int main() {
   int arr[10] = {1,3,5,7,9,11,19,27,33}; 
   int start = 0, end = sizeof(arr)/sizeof(int)-1;
   int num = 9;
   while(start<=end) {
      // if ever start==end then either mid(=start) will have the 
      // required element or in next step start>end and condition
      // will become false to exit from while loop.
      int mid = (start+end)/2;
      if(arr[mid]==num) {
         cout << mid << endl;
         break;
      } else if(arr[mid]>num) {
         end = mid - 1;
      } else  {
         start = mid + 1;
      }
   }
   return 0;
}

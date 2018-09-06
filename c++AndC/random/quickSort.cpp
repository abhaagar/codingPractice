void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

void quickSort(int *arr, int size) {
   if(size<2)
      return;
   int left = 1, right = size;
   int pivotIndex = 0;
   
   while(left<right) {
      if(arr[left]<=arr[pivotIndex])
         ++left;
      if(arr[right]>=arr[pivotIndex])
         --right;
      if(arr[left]>arr[pivotIndex] && arr[right]<arr[pivotIndex])
         swap(arr[left++],arr[right--]);
   }
   if(arr[pivotIndex]>arr[right])
      swap(arr[pivotIndex],arr[right]);
   quickSort(arr,right);
   //quickSort(arr+right+1,size-right);
}

int main() {
   int arr[10] = {10,9,8,7,6,5,4,3,2,1};
   quickSort(arr,10);
   return 0;
}

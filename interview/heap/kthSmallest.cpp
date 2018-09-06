#include <vector>
#include <iostream>

void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

int parent(int i) {
   return (i-1)/2;
}

int left(int i) {
   return i*2+1;
}

int right(int i) {
   return i*2+2;
}

void maxHeapify(std::vector<int> &heap, int index) {
   int leftIndex = left(index);
   int rightIndex = right(index);
   int largestIndex = index;
   if(leftIndex<heap.size() && heap[largestIndex]<heap[leftIndex])
      largestIndex = leftIndex;
   if(rightIndex<heap.size() && heap[largestIndex]<heap[rightIndex])
      largestIndex = rightIndex;
   if(largestIndex!=index) {
      swap(heap[index],heap[largestIndex]);
      maxHeapify(heap,largestIndex);
   }
}

void insert(std::vector<int> &heap, int element) {
   heap.push_back(element);
   if(heap.size()==1)
      return;
   int i = heap.size()-1;
   while(i>0) {
      if(heap[i]>heap[parent(i)]) {
         swap(heap[i],heap[parent(i)]);
         i = parent(i); 
      } else {
        break;
      }
   }
}

int extractMax(std::vector<int> &heap) {
   int root = heap[0];
   heap[0] = heap[heap.size()-1];
   heap.pop_back();
   maxHeapify(heap,0);
}

int main() {
   //int arr[9] = {1,2,3,4,5,6,7,8,9};
   int arr[9] = {9,8,7,6,5,4,3,2,1};
   std::vector<int> heap;
   int k = 4;
   for(int i=0; i<k; ++i)
      insert(heap,arr[i]);
   for(int i=k; i<9; ++i) {
      if(arr[i]<heap[0]) {
         insert(heap,arr[i]);
         extractMax(heap);
      }
   }
   std::cout << heap[0] << std::endl;
   return 0;
}

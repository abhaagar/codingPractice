#include <iostream>
#include <vector>
#define INVALID_INT -1000000
void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}
int parent(int i) {
   return (i-1)/2;
}

int left(int i) {
   return 2*i+1;
}

intright(int i) {
   return 2*i+2;
}


void minHeapify(std::vector<int> &heap,int rootIndex) {
   int root = heap[rootIndex];
   int leftIndex = rootIndex*2+1;
   int rightIndex = rootIndex*2+2;
   int smallestIndex = rootIndex;
   if(leftIndex<heap.size() && heap[smallestIndex]>heap[leftIndex])
      smallestIndex = leftIndex;
   if(rightIndex<heap.size() && heap[smallestIndex]>heap[rightIndex])
      smallestIndex = rightIndex;
   if(smallestIndex!=rootIndex) {
      int temp = heap[rootIndex];
      heap[rootIndex] = heap[smallestIndex];
      heap[smallestIndex] = temp;
      minHeapify(heap,smallestIndex);
   }
}

void insert(std::vector<int> &heap,int element) {
   std::cout << "Inserting " << element << std::endl;
   heap.push_back(element);
   if(heap.size()==1)
      return;
   int i = heap.size()-1;
   while(true) {
      if(i>0 && heap[i]<heap[parent(i)]) {
         int temp = heap[i];
         heap[i] = heap[parent(i)];
         heap[parent(i)] = temp;
         i = parent(i);
      } else {
        break;
      }
   }
}
void extractMin(std::vector<int> &heap){
   std::cout << "Extracting " << heap[0] << std::endl;
   heap[0] = heap[heap.size()-1];
   heap.pop_back();
   minHeapify(heap,0);
}
int main() {
   //int arr[9] = {1,2,3,4,5,6,7,8,9};
   int arr[9] = {9,8,7,6,5,4,3,2,1};
   int k = 4;
   std::vector<int> heap;
   for(int i=0; i<k; ++i) {
      insert(heap,arr[i]);
   }
   //std::cout << std::endl;
   for(int i=k; i<9;++i) {
      if(arr[i]>heap[0]) {
         insert(heap,arr[i]);
         extractMin(heap);
      }
      std::cout << "Min element is " << heap[0] << std::endl;
   }
   for(int i=0; i<heap.size(); ++i) 
      std::cout << heap[i] << " ";
   std::cout << std::endl;
   //std::cout << heap[heap.size()-1] << std::endl;
   return 0;
}

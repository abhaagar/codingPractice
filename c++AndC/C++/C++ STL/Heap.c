#include<iostream>
#include<vector>

struct HeapNode {
   int val;
   struct Node * left;
   struct Node * right;
};


void insert(std::vector<int> &heap,int val) {
   int i = heap.size();
   heap.push_back(val);
   while(i && heap[i]>heap[i/2]){
      int temp = heap[i];
      heap[i] = heap[i/2];
      heap[i/2] = temp;
      i = i/2;
  }
}

void swap(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}

int extractMax(std::vector<int> &heap) {
   int max = heap[0];
   heap[0] = heap[heap.size()-1];
   heap.erase(heap.end()-1);
   int i=0;
   while(true) {
      int left = -100000;
      int right = -100000;
      if(2*i+1<heap.size())
         left = heap[2*i+1];
      if(2*i+2<heap.size())
         right = heap[2*i+2];
      if(left>heap[i] && right>heap[i]) {
         if(left>right) {
            swap(heap[i],heap[2*i+1]);
            i = i*2+1; 
         } else {
            swap(heap[i],heap[2*i+2]);
            i = i*2+2; 
         }
      } else if(left>heap[i]) {
         swap(heap[i],heap[2*i+1]);
         i = i*2+1; 
      } else if(right>heap[i]) {
         swap(heap[i],heap[2*i+2]);
         i = i*2+2; 
      } else  {
         break;
      }
   }
   return max; 
}
int main() {
   int arr[9] = {1,2,3,4,5,6,7,8,9};
   std::vector<int> v;
   for(int i=0; i<9; ++i){
      insert(v,arr[i]);
   }
   for(int i=0; i<9; ++i)
      std::cout << v[i] << " ";
   std::cout << std::endl;
   std::cout << extractMax(v) << std::endl;
   for(int i=0; i<8; ++i)
      std::cout << v[i] << " ";
   std::cout << std::endl;
   return 0;
}


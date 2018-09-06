#include <assert.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>
template <class T>
struct Block {
   T *data;
   int tag;
   Block *next;
   Block *prev;
};
struct Tag{
   int tag;
   Tag *next;
   Tag *prev;
};

template<class T>
T *fetchFromMemory(int address) {
   T *page = (T*)malloc(sizeof(T));
   return page;
}

template <class T>
class LRUCache {
   public:
      T get(int );
      void put(int, T *);
      LRUCache(int,int);
   private:
      int _size;
      int _totalSize;
      int _associativity;
      std::unordered_map<int, Block<T>*> _cacheLines;
      std::vector<Tag*> _accessOrderList;
      int _hit;
      int _miss;
      void updateAccess(int);
      void evictPage(int ,int); 
      
};

template<class T>
LRUCache<T>::LRUCache(int totalSize_, int associativity_) {
   _totalSize = totalSize_;
   _associativity = associativity_;
   _size = _totalSize/_associativity;
   _hit = 0;
   _miss = 0;
   for(int i=0; i<_size;++i) {
      Block<T> * block = (Block<T> *)malloc(sizeof(Block<T>));
      block->data = (T*)malloc(sizeof(T));
      block->next = NULL;
      _cacheLines.insert(std::make_pair(i,block));
      Tag *tHead = (Tag*)malloc(sizeof(Tag));
      tHead->next = NULL;
      tHead->prev = NULL;
      _accessOrderList.push_back(tHead);
   } 
}

template<class T>
void LRUCache<T>::evictPage(int index, int tag) {
   Block<T> * block = _cacheLines[index];
   while(block->next && block->next->tag!=tag)
      block = block->next;
   assert(block->next);
   // this function call means, the page must be present.
   block = block->next;
   Block<T> *evictBlock = block;
   block->prev->next = block->next;
   if(block->next)
     block->next->prev = block->prev;
   free(evictBlock);
}

template<class T>
void LRUCache<T>::updateAccess(int address_) {
   int index = address_%_size;
   int tag = address_/_size;
   Tag *tempTag = _accessOrderList[index];
   int count=0;
   while(count<_associativity && tempTag->next) {
      ++count;
      if(tempTag->next->tag==tag) 
         break;
      tempTag = tempTag->next;
   }
   if(tempTag->next) {
      // cache hit, update the order of this tag by bringing it to front.
      tempTag = tempTag->next;
      Tag* frontTag = tempTag;
      tempTag->prev->next = tempTag->next;
      if(tempTag->next) {
         tempTag->next->prev = tempTag->prev; 
         _accessOrderList[index]->next->prev = frontTag;
      }
      frontTag->next = _accessOrderList[index]->next;
      _accessOrderList[index]->next = frontTag;
      frontTag->prev = _accessOrderList[index];
      return;
   }
   // cache miss.
   if(count==_associativity) {
     //set is also full so we need to evict the last.
     Tag * evictTag = tempTag->prev->next;
     free(evictTag);
     tempTag->prev->next = NULL;
     evictPage(index,tag);
   }
   Tag *newTag = (Tag*)malloc(sizeof(Tag));
   newTag->tag = tag;
   newTag->next = NULL;
   if(_accessOrderList[index]->next) {
      _accessOrderList[index]->next->prev = newTag;
      newTag->next = _accessOrderList[index]->next;
      _accessOrderList[index]->next = newTag;
      newTag->prev = _accessOrderList[index];
   } else {
      _accessOrderList[index]->next = newTag;
      newTag->prev = _accessOrderList[index];
   }
}

template<class T>
T LRUCache<T>::get(int address_) {
   // return the data at address.  
   int index = address_%_size;
   int tag = address_/_size;
   Block<T> *temp = _cacheLines[index];
   while(temp) {
      if(temp->tag==tag) 
         // found the tag of the addess.
         break;
      temp = temp->next;
   } 
   if(temp) {
      // cache hit, update the accress order. 
      ++_hit;
      updateAccess(address_);
      return *(temp->data);
   }
   ++_miss;
   std::cout << "Info : cache miss " << address_;
   T *data = fetchFromMemory<T>(address_);
   // fetch data from memory. 
   put(address_,data); 
   // put the data fetched from memory in cache.
   updateAccess(address_);
   // update the access.
   return *(data);
}

template<class T>
void LRUCache<T>::put(int address_, T *data_) {
   int index = address_%_size;
   int tag = address_/_size;
   Block<T> *newBlock = (Block<T>*)malloc(sizeof(Block<T>));
   // create new block with data.
   newBlock->tag = tag;
   newBlock->data = data_;
   if(!_cacheLines[index]->next) {
      _cacheLines[index]->next = newBlock;
      newBlock->prev = _cacheLines[index];
   }  else {
      _cacheLines[index]->next->prev = newBlock;
      newBlock->next = _cacheLines[index]->next;
      _cacheLines[index]->next = newBlock;
      newBlock->prev = _cacheLines[index];
   }
   updateAccess(address_);
   // add the block at head
}
int main() {
   int data1 = 39;
   int data2 = 40;
   LRUCache<int> cache(30,3);
   cache.put(11,&data1);
   cache.put(21,&data2);
   std::cout << cache.get(11) << std::endl;
   std::cout << cache.get(21) << std::endl;

   return 0;
}

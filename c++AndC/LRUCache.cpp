
#include<iostream>
#include<unordered_map>

using namespace std;
struct CacheEntry {
   int val;
   CacheEntry* left;
   CacheEntry* right;
};


class LRUCache {
   private:
      unordered_map<int,CacheEntry*> cache;
      CacheEntry* accessStart, *accessEnd;
      void updateAccess(int key);
      void insertAccess(int key);
      int size;
      static CacheEntry* allocateCacheEntry(int key, int val) {
	  CacheEntry * temp = new CacheEntry;
	  temp->val = val;
	  temp->left = NULL;
	  temp->right = NULL;
	  return temp;
      }	      
      static void deAllocateCacheEntry(CacheEntry* entry) {
          delete entry;
      }	      
   public:
      LRUCache(int size);
      void save(int key,int val);
      int search(int key);
};

LRUCache::LRUCache(int size) {
   this->size = size;
}	

void LRUCache::updateAccess(int key) {
   CacheEntry* currentEntry = cache[key]; 
   if(currentEntry==accessStart) {
      cout << "Referenced Least Recently Used Key: " <<  key << endl;
      return;
   }
   if(currentEntry==accessEnd) {
      cout << "Referenced Last Used Key: " <<  key << endl;
      currentEntry->left->right = NULL;
      currentEntry->right = accessStart;
      accessStart->left = currentEntry;
      accessStart = currentEntry;
      accessStart->left = NULL;
      return;
   }	   
   currentEntry->left->right = currentEntry->right;
   currentEntry->right->left = currentEntry->left;
   currentEntry->right = accessStart;
   accessStart->left = currentEntry;
   accessStart = currentEntry;
   accessStart->left = NULL;
}	

int LRUCache::search(int key) {
   if(!cache.count(key)) {
      cout << "key not found: " << key << endl;
      return -1;
   }

   updateAccess(key);
   return cache[key]->val;
}	

void LRUCache::save(int key,int val) {
   if(cache.count(key)) {
      cout << "key already found: " << key << endl;
      return;
   }
   CacheEntry* newEntry = LRUCache::allocateCacheEntry(key,val);  
   cache[key] = newEntry;
   if(size>=cache.size()) {

   }
      
}	


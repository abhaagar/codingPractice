#include<assert.h>
#include<iostream>

#define SIZE 100
#define INVALID -12345
using namespace std;
class HashNode {
   public:	
      int key;
      int val;
      HashNode *next;
      HashNode(int key_,int val_): key(key_), val(val_),next(0) {}	      
};	


class HashTable {
   private:
	HashNode **table;
	int hash(const int key);
   public:
	HashTable();
        ~HashTable();
	int search(const int key);
        void insert(const int k, const int val);
};	

HashTable::HashTable() {
   table = new HashNode*[SIZE]();
}	

int HashTable::hash(const int key) {
   return key%SIZE;
}	
HashTable::~HashTable() {
   delete [] table;
}	

int HashTable::search(const int key) {
   const int hash_ = hash(key);
   assert(hash_<SIZE);
   HashNode * temp = table[hash_];
   while(temp&&temp->key!=key)
      temp = temp->next;	   
   return temp?temp->val:INVALID;
}

void HashTable::insert(int key, int val) {
   const int hash_ = hash(key);
   assert(hash_<SIZE);
   HashNode* temp = table[hash_];
   if(!temp) {
      table[hash_] = new HashNode(key,val);
      return;
   }
   while(temp->next&&temp->key!=key) 
      temp = temp->next;
   if(temp->key==key) {
      // replacing or storing same value at key `key`.
      temp->val = val;
      return;
   }
   temp->next = new HashNode(key,val); 
   // inserted `val` for `key`.
}	

int main() {
   HashTable ht;
   for(int i=0; i<10000; ++i)
      ht.insert(i,i);
   for(int i=0; i<10000; ++i)
      assert(ht.search(i)==i);
   return 0;
}	

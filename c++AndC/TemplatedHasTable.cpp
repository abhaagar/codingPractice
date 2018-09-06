#include<assert.h>
#include<iostream>

#define SIZE 100
#define INVALID -12345
using namespace std;

class Node {
   public:
      int val;
      Node(int val_) {
         val = val_;
      }	       
      int valIs() {
         return val;
      }	      
};	

template <typename T>
class HashNode {
   public:	
      int key;
      T val;
      HashNode *next;
      HashNode(int key_,T val_): key(key_), val(val_),next(0) {}	      
};	


template <typename T>
class HashTable {
   private:
	HashNode<T> **table;
	int hash(const int key);
   public:
	HashTable();
        ~HashTable();
	T search(const int key);
        void insert(const int k,T val);
};	

template <typename T>
HashTable<T>::HashTable() {
   table = new HashNode<T>*[SIZE]();
}	

template <typename T>
int HashTable<T>::hash(const int key) {
   return key%SIZE;
}	

template <typename T>
HashTable<T>::~HashTable() {
   delete [] table;
}	

template <typename T>
T HashTable<T>::search(const int key) {
   const int hash_ = hash(key);
   assert(hash_<SIZE);
   HashNode<T> * temp = table[hash_];
   while(temp&&temp->key!=key)
      temp = temp->next;	   
   return temp?temp->val:INVALID;
}

template <typename T>
void HashTable<T>::insert(int key, T val) {
   const int hash_ = hash(key);
   assert(hash_<SIZE);
   HashNode<T>* temp = table[hash_];
   if(!temp) {
      table[hash_] = new HashNode<T>(key,val);
      return;
   }
   while(temp->next&&temp->key!=key) 
      temp = temp->next;
   if(temp->key==key) {
      // replacing or storing same value at key `key`.
      temp->val = val;
      return;
   }
   temp->next = new HashNode<T>(key,val); 
   // inserted `val` for `key`.
}	

int main() {
   HashTable<Node> ht;
   for(int i=0; i<10000; ++i) {
      Node n(i);
      ht.insert(i, n);
   }   
   for(int i=0; i<10000; ++i)
      assert(ht.search(i).valIs()==i);
   return 0;
}	

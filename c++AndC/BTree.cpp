
#include<iostream>
#include<assert>
#define ORDER 5
#define INVALID_KEY -12345

using namespace std;

class BTreeNode {
   private:
      BTreeNode* parent;	   
      int keys[ORDER];
      BTreeNode *children[ORDER+1];
      int currentNumberOfKeys;
   public:	
      BTreeNode();
      static BTreeNode* createNode();
      int search(int key);
      void insert(int val);
      bool isFull();
};
bool BTreeNode::isNotFull() {
   return currentNumberOfKeys<ORDER;
}	
bool BTreeNode::isReadyForSplit() {
   return currentNumberOfKey==ORDER;
}
BTreeNode::BTreeNode() {
   for(int i=0; i<ORDER; ++i){
      keys[i] = INVALID_KEY;
   }	  
   for(int i=0; i<ORDER+1; ++i){
      children[i] = NULL;
   }	   
   currentNumberOfKeys = 0;
   parent = NULL; 
}

void BTreeNode::copyFrom(BTreeNode* node, int from, int to) {
   for(int i=from; i<to; ++i)
      node->keys[i] = keys[i];
}	

BTreeNode* BTreeNode::getParent() {
   return parent;
}	
void BTreeNode::setParent(BTreeNode* node) {
   parent = node;
}	
BTreeNode* BTreeNode::insert(int key) {
   assert(isNotFull());
   int index = search(val);
   if(keys[index]==key)
      return;
   if(keys[index]<key) {
      ++index;
   }
   if(!children[index]) {
      // leaf node so insert in the node by swapping the
      // successor keys to right.
      int swapIndex = currentNumberOfKeys;
      while(swapIndex>index){
         keys[swapIndex] = keys[swapIndex-1];
         --swapIndex;
      }
      keys[swapIndex] = key;
      return NULL;
   } else {
      return children[index];
   }	   
}

int BTreeNode::search(int key) {
   int left = 0, right = currentNumberOfKeys-1;
   while(left<right) {
      int middle = (left+right)/2;
      if(keys[middle]==key)
         return middle;  
      if(keys[middle]<key)
         left = middle+1;	      
      else
         right = middle-1;	      
   }	   
   return left;
}

class BTree {
   private:
      BTreeNode* root;
   public:
      BTree();
      bool search(int val);
      void insert(int val);
      void splitNode(AVLNode* node);
};	

Btree::BTree() {
   root = NULL;
}

AVLNode* BTree::search(int val) {
    AVLNode* temp = root;
    while(temp) {
       int index = temp->search(val);
       if(temp->keys[index]==val)
          return temp;
       if(temp->keys[index]<val)
	  index = index+1;
       if(temp->children[index+1])
          temp = temp->children[index+1];
       else
          return temp;
    }
    return temp;
}	

void BTree::splitNode(AVLNode* node) {
   AVLNode* leftChild = AVLNode::createNode();
   AVLNode* rightChild = AVLNode::createNode();
   AVLNode* parent = AVLNode::createNode();
}

void BTree::insert(int val) {
   if(!root)
      root = new BTreeNode;
   BTreeNode * temp = root;   
   while(temp) {
      if(!temp->isFull()) {
         temp = temp->insert(val);
      }	else {
         // temp is the node where key will be added
	 // after splitting.
	 BTreeNode* left = BTreeNode::createNode();
	 BTreeNode* right = BTreeNode::createNode();
	 temp->copyFrom(left,0,ORDER/2);
	 temp->copyFrom(right,ORDER/2,ORDER);
	 left->setParent(temp);
	 right->setParent(temp);
         if(temp->getParent()) {
            temp->getParent()->insert(val);
         } else {
           // root is getting split.
	   root = BTreeNode::createNode();
	   root->insert(val);
         }		 
      } 
   }
   // temp will be NULL only when key was inserted into 
   // last BTreeNode successfully. 
}

BTree::BTree() {
   root = NULL;
}	

int main() {
   Btree btree;
   return 0;
}

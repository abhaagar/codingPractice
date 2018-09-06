#include<iostream>
#include<stack>
using namespace std;

struct Node {
   int val;
   Node* left;
   Node* right;
};	

Node* allocateNode(int val) {
  Node* temp = new Node;
  temp->val = val;
  temp->left = temp->right = NULL;
  return temp;
}	

class Iterator {
   public:
      stack<const Node*> iterator;
      Iterator(const Node*);
      virtual const Node* next() = 0;   
};	
Iterator::Iterator(const Node* root) {
   iterator.push(root);
}	

class InOrderIT : public Iterator {
   public:
      const Node* next();   
      InOrderIT(const Node* n): Iterator(n) {
         while(iterator.top()->left)
            iterator.push(iterator.top()->left);		 
      }	      
};	

const Node* InOrderIT::next() {
   if(iterator.empty())
      return NULL;
   const Node* node = iterator.top();	
   const Node* temp = node;
   iterator.pop();
   if(temp->right) {
     iterator.push(temp->right);
     while(iterator.top()->left)
        iterator.push(iterator.top()->left);	     
   }	   
   return node;
}	

class PreOrderIT : public Iterator {
   public:
      const Node* next();   
      PreOrderIT(const Node* n): Iterator(n) {}
};	
const Node* PreOrderIT::next() {
   if(iterator.empty())
      return NULL;
   const Node* node = iterator.top();	
   iterator.pop();
   if(node->right)
      iterator.push(node->right);
   if(node->left)
      iterator.push(node->left);
   return node;
}	

int main() {
   Node* root = allocateNode(1); 
   root->left = allocateNode(2);
   root->left->left = allocateNode(3);
   root->left->right = allocateNode(4);
   root->right = allocateNode(5);
   root->right->left = allocateNode(6);
   root->right->right = allocateNode(7);
   root->left->left->left = allocateNode(8);
   root->left->left->right = allocateNode(9);
   Iterator* it = new PreOrderIT(root);
   const Node* node = NULL;
   while((node=it->next())!=NULL) {
      std::cout << node->val << " -> ";
   }
   cout << "NULL\n"; 
   it = new InOrderIT(root);
   while((node=it->next())!=NULL) {
      std::cout << node->val << " -> ";
   }
   return 0;
}	

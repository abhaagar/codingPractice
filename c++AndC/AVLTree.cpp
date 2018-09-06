#include<stdlib.h>
#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
class AVLNode {
   public:
      int val;
      AVLNode *left;
      AVLNode *right;
      AVLNode *parent;
      static AVLNode* createNode(int val) {
         AVLNode* temp = new AVLNode;
	 temp->parent = temp->left = temp->right = NULL;
	 temp->val = val;
	 return temp;
      }
      static AVLNode* destructNode(AVLNode*node){
         delete node;
      }
};

class AVLTree {
   private:
      AVLNode * root;
      static int height(AVLNode *root);
      static AVLNode* inorderSuccessor(AVLNode* root);
      static AVLNode* inorderPredecessor(AVLNode* root);
      void leftSubtreeLeftChildRotate(
         AVLNode* root, AVLNode* child, AVLNode* grandChild); 
      void leftSubtreeRightChildRotate(
         AVLNode* root, AVLNode* child, AVLNode* grandChild); 
      void rightSubtreeLeftChildRotate(
         AVLNode* root, AVLNode* child, AVLNode* grandChild); 
      void rightSubtreeRightChildRotate(
         AVLNode* root, AVLNode* child, AVLNode* grandChild); 
      static bool isLeftChild(AVLNode* node) {
         return !!node && !!node->parent && node->parent->left==node;
      }
      static bool isRightChild(AVLNode* node) {
         return !!node && !!node->parent && node->parent->right==node;
      }
   public:
      AVLNode* rootOfTree() {
         return root;
      }	
      void insert(int val);
      bool search(int val);
      void remove(int val);
      void static inorder(AVLNode*root) {
	  if(!root)
	     return;
	  inorder(root->left);
	  cout << root->val << " ";
	  inorder(root->right);

      }	 
};


void AVLTree::leftSubtreeLeftChildRotate(
   AVLNode* root, AVLNode* child, AVLNode* grandChild) {
   if(!root||!child||!grandChild)
      return;
   //cout << "   Left Subtree Left Child Rotation " << root->val << " " << child->val << " " << grandChild->val << endl;
   child->parent = root->parent;
   if(root->parent)
      root->parent->left = child;
   root->parent = child;
   child->right = root;
   root->left = NULL;
   if(this->root==root)
      this->root = child;
}

void AVLTree::rightSubtreeRightChildRotate(
   AVLNode* root, AVLNode* child, AVLNode* grandChild) {
   if(!root||!child||!grandChild)
      return;
   //cout << "   Right Subtree Right Child Rotation " << root->val << " " << child->val << " " << grandChild->val << endl;
   child->parent = root->parent;
   if(root->parent)
      root->parent->right = child;
   root->parent = child;
   child->left = root;
   root->right = NULL;
   if(this->root==root)
      this->root = child;
}

void AVLTree::leftSubtreeRightChildRotate(
   AVLNode* root, AVLNode* child, AVLNode* grandChild) {
   if(!root||!child||!grandChild)
      return;
   //cout << "   Left Subtree Right Child Rotation " << root->val << " " << child->val << " " << grandChild->val << endl;
   grandChild->parent = root;
   root->left = grandChild;
   grandChild->left = child;
   child->parent = grandChild;
   child->right = NULL;
   leftSubtreeLeftChildRotate(root,grandChild,child);
}

void AVLTree::rightSubtreeLeftChildRotate(
   AVLNode* root, AVLNode* child, AVLNode* grandChild) {
   if(!root||!child||!grandChild)
      return;
   //cout << "   Right Subtree Left Child Rotation " << root->val << " " << child->val << " " << grandChild->val << endl;
   grandChild->parent = root;
   root->right = grandChild;
   grandChild->right = child;
   child->parent = grandChild;
   child->left = NULL;
   rightSubtreeRightChildRotate(root,grandChild,child);
}

//AVLTree::AVLTree() {
//   root = NULL;
//}
bool AVLTree::search(int val) {
   AVLNode * temp = root;
   while(temp) {
      if(temp->val==val)
         return true;
      if(temp->val<val)
	 // required value should be in right subtree.
	 temp = temp->right;
      else
	 // required value should be in left subtree.
	 temp = temp->left;
   }
   return false;
}

int AVLTree::height(AVLNode *root) {
   if(!root)
      return 0;
   //cout << " getting height of root " << root->val << endl;
   int leftSubTreeHeight = height(root->left);
   int rightSubTreeHeight = height(root->right);
   //cout << " left subtree height of root " << root->val << " is " << leftSubTreeHeight << endl;
   //cout << " right subtree height of root " << root->val << " is " << rightSubTreeHeight << endl;
   int height = (max(leftSubTreeHeight,rightSubTreeHeight))+1;
   //cout << "height of root " << root->val << " is " << height << endl;
   return height;
}


AVLNode* AVLTree::inorderSuccessor(AVLNode* root) {
   if(!root)
      return NULL;
   if(root->right) {
      while(root->left)
         root = root->left;
      return root;
   } else {
      while(root->parent && root->parent->left==root)
	 root = root->parent;
      if(root->parent)
	 return root;
   }
   return NULL;
}	

AVLNode* AVLTree::inorderPredecessor(AVLNode* root) {
   if(!root)
      return NULL;
   if(root->left) {
      while(root->right)
         root = root->right;
      return root;
   } else {
      while(root->parent && root->parent->right==root)
	 root = root->parent;
      if(root->parent)
	 return root;
   }
   return NULL;
}	

void AVLTree::remove(int val) {
   AVLNode *node = root;
   while(node) {
      if(node->val==val)
	 break; 
      if(node->val>val)
	 node = node->left;
      else
	 node = node->right;
   }
   if(!node)
      return;
   if(!node->left && !node->right) {
      if(AVLTree::isLeftChild(node)) 
	 node->parent->left = NULL;
      else if(AVLTree::isRightChild(node))
	 node->parent->right = NULL;
      AVLNode::destructNode(node);
      return;
   } else if(node->left && !node->right) {
      if(AVLTree::isLeftChild(node)) {
         node->parent->left = node->left;
         node->left->parent = node->parent; 
      } else if(AVLTree::isRightChild(node)) {
         node->parent->right = node->left;
         node->left->parent = node->parent; 
      } 	      
      AVLNode::destructNode(node);
   } else if(!node->left && node->right) {
      if(AVLTree::isLeftChild(node)) {
         node->parent->left = node->right;
         node->right->parent = node->parent; 
      } else if(AVLTree::isRightChild(node)) {
         node->parent->right = node->right;
         node->right->parent = node->parent; 
      } 	      
      AVLNode::destructNode(node);
   } else {


   }	   
}

void AVLTree::insert(int val) {
   //cout << "Inserting "<<val<<endl;
   if(!root) {
      root = AVLNode::createNode(val); 
      return;
   }

   AVLNode* temp = root,*parent = NULL;
   while(temp) {
      if(temp->val==val)
	  return;
      parent = temp;
      if(temp->val>val)
	 temp = temp->left;
      else
	 temp = temp->right;
   }
   AVLNode *node = AVLNode::createNode(val);
   node->parent = parent;
   if(parent->val>val)
      parent->left = node;
   else	   
      parent->right = node;
   AVLNode* parentParent = parent->parent;
   if(!parentParent)
      return;
   //cout << "ParentParent is " << parentParent->val << endl;
   if(abs(height(parentParent->left)-height(parentParent->right))>1) {
      if(parentParent->left==parent && parent->left==node) {
         leftSubtreeLeftChildRotate(parentParent,parent,node);
      } else if(parentParent->left==parent && parent->right==node) {
         leftSubtreeRightChildRotate(parentParent,parent,node);
      } else if(parentParent->right==parent && parent->right==node) {
         rightSubtreeRightChildRotate(parentParent,parent,node);
      } else if(parentParent->right==parent && parent->left==node) {
         rightSubtreeLeftChildRotate(parentParent,parent,node);
      }
   }
}

int main() {
   AVLTree* tree = new AVLTree;

   tree->insert(2);
   tree->insert(5);
   tree->insert(1);
   tree->insert(3);
   tree->insert(8);
   tree->insert(6);
   tree->insert(9);
   tree->insert(7);
   tree->insert(4);

   AVLTree::inorder(tree->rootOfTree());

   return 0;
}

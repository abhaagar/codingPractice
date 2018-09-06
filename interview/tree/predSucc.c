#include"binaryTree.h"
#include<stdbool.h>

struct BinaryTreeNode*
findPred(struct BinaryTreeNode* node, int key, struct BinaryTreeNode* ancestor) {
   struct BinaryTreeNode* pred = ancestor;
   if(node==NULL)
      return ancestor;
   if(node->num==key) {
      if(node->left) {
         node = node->left;
         while(node->right) 
            node = node->right;
         pred = node;
      }
   }  else {
     if(node->num<key) {
        ancestor = node;
        node = node->right;
     } else {
        node = node->left;
     }
     pred = findPred(node,key,ancestor);
   }
   return pred;
}


struct BinaryTreeNode*
findSucc(struct BinaryTreeNode* node, int key, struct BinaryTreeNode* ancestor) {
   struct BinaryTreeNode* succ = ancestor;
   if(node->num==key) {
      if(node->right) {
         node = node->right;
         while(node->left) 
            node = node->left;
         succ = node;
      }
   }  else {
     if(node->num>key) {
        ancestor = node;
        node = node->left;
     } else {
        node = node->right;
     }
     succ = findSucc(node,key,ancestor);
   }
   return succ;
}


int main() {
   struct BinaryTreeNode* root = createSubTree(4);
   int key;
   scanf("%d",&key);
   struct BinaryTreeNode* pred = findPred(root,key,NULL);
   struct BinaryTreeNode* succ = findSucc(root,key,NULL);
   printf("predecessor: %d\n",pred->num);
   printf("succeessor: %d\n",succ->num);
   return 0;
}

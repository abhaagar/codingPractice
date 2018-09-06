#ifndef _binaryTree_h
#define _binaryTree_h
#include<stdio.h>
#include<stdlib.h>

struct BinaryTreeNode {
   int num;
   struct BinaryTreeNode* left;
   struct BinaryTreeNode* right;
};
int count = 0;
struct BinaryTreeNode *
createBinaryTreeNode(int num){
   struct BinaryTreeNode * node = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
   node->num = num;
   node->left = NULL;
   node->right = NULL;
   return node;
}

struct BinaryTreeNode*
createSubTree(int level,int num) {
   if(level==0) 
      return NULL;
   printf("%d level:%d\n",++count,4-level);
   struct BinaryTreeNode * root = createBinaryTreeNode(count,num);
   root->left = createSubTree(level-1,num/2);
   root->right = createSubTree(level-1,num+num/2);
   return root;   
}
#endif

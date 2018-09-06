#include"binaryTree.h"
#include<stdbool.h>

int
kLevelSum(struct BinaryTreeNode* node,int currentLevel,int K) {
   if(!node)
      return 0;
   if(currentLevel==K) {
     return node->num;
   } else if(currentLevel<K) {
     return kLevelSum(node->left,1+currentLevel,K) +
            kLevelSum(node->right,1+currentLevel,K);
   } else {
     return 0;
   }
}

int main() {
   struct BinaryTreeNode* root = createSubTree(4); 
   printf("\n%d\n",kLevelSum(root,0,4));
   return 0;
}

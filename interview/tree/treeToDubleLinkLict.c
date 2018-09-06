#include<binaryTree.h>
#include<stdbool.h>

int count = 1;
int nodeCount = 0;

bool
parseAsDoubleLinkList(struct BinaryTreeNode*node) {
   while(node) {
     if(node->right){
        if(node->right->left!=node)
           return false;
        //printf("%d ->",node->num);
     }
     printf("%u ->",node);
     node = node->right;
   }
   return true;
}

struct BinaryTreeNode*
inorderTraverseAndConvert(struct BinaryTreeNode* node) {
   struct BinaryTreeNode* pred = NULL;
   struct BinaryTreeNode* succ = NULL;
   if(node->left) {
      pred = inorderTraverseAndConvert(node->left);
      while(pred->right) {
         pred = pred->right;
      }
      node->left=pred; 
      pred->right=node;
      //printf("%d ->",pred->num);
      printf("%u ->",pred);
   }
   //printf("%d ->",node->num);
   printf("%u ->",node);
   if(node->right) {
      succ = inorderTraverseAndConvert(node->right);
      while(succ->left) {
         succ = succ->left;
      }
      node->right = succ;
      succ->left = node;
      //printf("%d ->",succ->num);
      printf("%u ->",succ);
   }
   return node;
}

struct BinaryTreeNode *
convertToLinkList(struct BinaryTreeNode* root) {
   root = inorderTraverseAndConvert(root);
   while(root->left) {
      root = root->left;
   }
   return root;
}

int main() {
   struct BinaryTreeNode * root = createBinaryTreeNode(10);
   root->left = createSubTree(2);
   root->right = createSubTree(1);
   root = convertToLinkList(root);
   printf("\n%d\n",nodeCount);
   
   if(parseAsDoubleLinkList(root)) {
      printf("tree is successfully converted to double link list\n");
   } else {
      printf("conversion from tree to double link list is unsuccessful\n");
   }
   return 0;
}

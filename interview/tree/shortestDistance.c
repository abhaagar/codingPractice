#include"binaryTree.h"
#include<stdbool.h>
int main() {
   //struct BinaryTreeNode* root = createSubTree(4); 
   int num1, num2;
   int count1=0, count2=0;
   scanf("%d %d",&num1,&num2);
   while(true) {
     if(num2>num1) {
        num2 = num2/2;
        ++count2;
     } else if(num1>num2) {
        num1 = num1/2;
        ++count1;
     } else {
       break;
     }
   }
   printf("%d\n",count1+count2);
   return 0;
}

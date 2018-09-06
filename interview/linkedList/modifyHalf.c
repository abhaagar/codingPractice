#include<stdio.h>
#include<stdlib.h>

struct Node {
   int num;
   struct Node *next;
};
struct Node *
modifyFirstHalf(struct Node* node,int total,int curr) {
   struct Node* pair = NULL;
   if(curr!=0) {
      pair = modifyFirstHalf(node->next,total,--curr);
   } else {
     if(total%2) {
        node = node->next;
     }
     return node;
   }
   node->num = -pair->num+node->num;
   return pair->next;

}

int main() {
   int testCase;
   scanf("%d",&testCase);
   while(testCase--) {
      struct Node *head = NULL;
      int N,i,count=0;
      scanf("%d",&N);
      struct Node* temp=NULL;
      for(i=0; i<N; ++i) {
         int num;
         if(!temp) {
            temp = (struct Node*)malloc(sizeof(struct Node));
            head = temp;
            temp->next = NULL;
         } else {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->next = head;
            head = temp;
         }

         scanf("%d",&num);
         head->num = num;
         printf("%d -> ",num);
         ++count;
      }
      printf("\n");
      modifyFirstHalf(head,count,count/2);
      while(head){
         printf("%d -> ",head->num);
         head = head->next; 
      }
   }
   return 0;
}

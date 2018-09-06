#include<stdio.h>
#include<stdlib.h>


struct Node {
   int num;
   struct Node* next;
};

int main() {
   struct Node *head = NULL;
   int N,i;
   scanf("%d",&N);
   struct Node* temp=NULL;
   for(i=0; i<N; ++i) {
      int num;
      if(!temp) {
         temp = (struct Node*)malloc(sizeof(struct Node));
         head = temp;
      } else {
         temp->next = (struct Node*)malloc(sizeof(struct Node));
         temp = temp->next;
      }
      temp->next = NULL;
      scanf("%d",&num);
      temp->num = num;
      printf("%d -> ",num);
   }
   if(head==NULL) {
      printf("0\n")
      return;
   }
   struct Node * step = head, doubleStep = head->next;
   int count = 1;
   while(step!=doubleStep && doubleStep!=NULL) {
      step = step->next;
      doubleStep = doubleStep->next;
      if(doubleStep) {
         doubleStep = doubleStep->next;
      }
      ++count;
   }
   if(step==doubleStep) {
      printf("%d\n",count);
   } else {
      printf("0\n")
   }
   return 0;
}

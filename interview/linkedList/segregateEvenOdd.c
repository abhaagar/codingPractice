#include<stdio.h>
#include<stdlib.h>

struct Node {
   int num;
   struct Node *next;
};

int main() {
   int testCase;
   scanf("%d",&testCase);
   while(testCase--) {
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
      printf("\n");
      temp = head->next;
      struct Node* prev = head;
      while(temp) {
         if(temp->num%2==0) {
           prev->next = temp->next;
           temp->next = head;
           head = temp;
           temp = prev->next;
         } else {
           prev = temp;
           temp = temp->next;
         }
      }
      while(head) {
         printf("%d -> ",head->num); 
         head = head->next;
      }
   }
   return 0;
}

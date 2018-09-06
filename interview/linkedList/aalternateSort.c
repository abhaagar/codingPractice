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
      struct Node *first = NULL;
      struct Node *firstTemp = NULL;
      struct Node *second = NULL;
      struct Node *secondTemp = NULL;
     
      while(head) {
         if(!first) {
           first = head;
           firstTemp = head;
           head = head->next;
         } else {
           firstTemp->next = head;
           firstTemp = firstTemp->next;
           head = head->next;
           firstTemp->next = NULL;
         }

         if(head) {
            if(!second) {
               second =  head;
               secondTemp =  head;
               head = head->next;
            } else {
               secondTemp->next =  head;
               secondTemp = secondTemp->next;
               head = head->next;
               secondTemp->next = NULL;
            }

         }
      }
      secondTemp = NULL;
      struct Node * headTemp = NULL;
      while(first && second) {
         if(first->num<second->num) {
            firstTemp = first;
            first = first->next;
         } else if(second->num<first->num) {
            secondTemp = second;
            second = second->next;
         } else {
           firstTemp = first;
           secondTemp = second;
           first = first->next;
           second = second->next;
         }
         if(!head) {
           if(firstTemp && secondTemp) {
              head = firstTemp;
              headTemp = firstTemp;
              headTemp->next = secondTemp;
              headTemp = headTemp->next;
              headTemp->next = NULL;
           } else {
              firstTemp = firstTemp?firstTemp:secondTemp;
              head = firstTemp;
              headTemp = firstTemp;
              headTemp->next = NULL;
           }
         } else {
            if(firstTemp) {
               headTemp->next = firstTemp;
               headTemp = headTemp->next;
            }
            if(secondTemp) {
               headTemp->next = secondTemp;
               headTemp = headTemp->next;
            }
            headTemp->next = NULL;
         }
         firstTemp = NULL;
         secondTemp = NULL;
      }
      secondTemp = NULL;
      if(first) {
         headTemp->next = first;
      } else {
         headTemp->next = second;
      }
      while(head) {
         printf("%d -> ",head->num);
         head = head->next;
      }
   }
   return 0;
}

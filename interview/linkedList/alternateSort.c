#include "list.h"
void
createList(struct Node ** headTemp) {

}

int main() {
   int N,i;
   scanf("%d",&N);
   struct Node * head = (struct Node*)malloc(sizeof(struct Node));
   struct Node * temp = head;
   for(i=0; i<N; ++i) {
     temp->next = (struct Node*)malloc(sizeof(struct Node));
     temp = temp->next;
     temp->next = NULL;
     scanf("%d",&(*temp).num);
   }
   head = head->next;
   //while(head) {
   //   printf("%d -> ",head->num);
   //   head =head->next;
   //}
    
   struct Node * first = NULL,*second = NULL; 
   struct Node * firstTemp = NULL;
   firstTemp = first = (struct Node*)malloc(sizeof(struct Node));
   //secondTemp = second = (struct Node*)malloc(sizeof(struct Node));
   while(head) {
      firstTemp->next = head;
      firstTemp = firstTemp->next;
      head = head->next;
      firstTemp->next = NULL;
      if(head) {
        temp = head;
        head = head->next;
        temp->next = second;
        second = temp;
      }
   }
   first = first->next;
   temp = head = (struct Node*)malloc(sizeof(struct Node));
   while(first && second) {
      if(first->num<second->num) {
         temp->next = first;
         first = first->next;
      } else if(second->num<first->num) {
         temp->next = second;
         second = second->next;
      } else {
         temp->next = first;
         first = first->next;
         temp = temp->next;
         temp->next = second;
         second = second->next;
      }
      temp = temp->next;
      temp->next = NULL;
   }
   if(first) {
     temp->next = first;
   } else {
     temp->next = second;
   }
   head =  head->next;
   print(head);
   return 0;
}

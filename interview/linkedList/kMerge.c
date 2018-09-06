#include "list.h"

struct Node*
mergeTwoLists(struct Node *list1,struct Node *list2);

int main() {
   int K,i=0;
   scanf("%d",&K);
   struct Node *lists[K];
   int num[K];
   for(i=0;i<K;++i) {
      scanf("%d",&num[i]); 
   }
   for(i=0;i<K;++i) {
      int j=0;
      struct Node* temp = createNode(0),*dummy = NULL;
      lists[i] = temp;
      for(;j<num[i];++j) {
         int n;
         scanf("%d",&n);
         temp->next = createNode(n);   
         temp = temp->next;
      }
      dummy = lists[i];
      lists[i] = lists[i]->next;
      free(dummy);
   }
   struct Node* merged = lists[0];
   for(i=1;i<K;++i) {
      merged = mergeTwoLists(merged,lists[i]);
   }
   print(merged);
   return 0;
}
struct Node*
mergeTwoLists(struct Node *list1,struct Node *list2) {
   struct Node* head = createNode(0), *temp = head;
   while(list1&&list2) {
      if(list1->num<list2->num) {
         temp->next = list1;
         list1 = list1->next;
      } else if(list2->num<list1->num) {
         temp->next = list2;
         list2 = list2->next;
      } else {
         temp->next = list1;
         list1 = list1->next;
         temp = temp->next;
         temp->next = list2;
         list2 = list2->next;
      }
      temp = temp->next;
      temp->next = NULL;
   } 
   if(list1) {
     temp->next = list1;
   } else {
     temp->next = list2;
   }
   list1 = head;
   head = head->next;
   free(list1);
   return head;
}

#ifndef _list_h
#define _list_h
#include<stdio.h>
#include<stdlib.h>
struct Node {
   int num;
   struct Node * next;
};

void
print(struct Node * head) {
   while(head) {
      printf("%d -> ",head->num);
      head = head->next;
   }
}
struct Node*
createNode(int num) {
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
   temp->num = num;
   temp->next = NULL;
   return temp;
}

struct PolyNode {
   int coef;
   int pow;
   struct PolyNode * next;
};
#endif

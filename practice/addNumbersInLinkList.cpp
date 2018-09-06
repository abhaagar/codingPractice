#include<iostream>

using namespace std;

struct Node {
   int data;
   Node *next;
};

void print(Node *node){
   while(node) {
      cout << node->data << " ";
      node = node->next;
   }
}

Node * createLinkListFromArray(int array[], int len) {
   Node * head = NULL, *temp = NULL;
   //for (int i=0; i<sizeof(array)/sizeof(int); ++i) {
   for (int i=0; i<len; ++i) {
      if(!head) {
         head = new Node;
         head->next = NULL;
         head->data = array[i];
         temp  = head;
      } else {
         temp->next = new Node;
         temp = temp->next;
         temp->data = array[i];
         temp->next = NULL;
      }
   }
   print(head);
   cout << endl;
   return head;
}

int lengthOfList (Node * list) {
   int len = 0;
   while(list) {
      len++;
      list = list->next;
   }
   return len;
}


Node* addReverseLinkList(Node *first, Node* second, bool start) {
   int addition = 0;
   if (start) {
      int len1 = lengthOfList(first); 
      int len2 = lengthOfList(second);
      if(len1<len2) {
         for(int i=0; i<len2-len1; ++i) {
            addition = 10*addition + second->data;         
            second = second->next;
         }
      } else if(len1>len2) {
         for(int i=0; i<len1-len2; ++i) {
            addition = 10*addition + first->data;         
            first = first->next;
         }
      }
   }
   if(first==NULL && second==NULL) {
      return NULL;
   }
   int digit1 = first->data;
   int digit2 = second->data;
   Node * currHead = NULL;
   currHead = addReverseLinkList(first->next, second->next,false);
   int carry = 0;
   if(currHead) {
      carry = currHead->data/10;
      currHead->data = (currHead->data)%10;
   }

   Node *newHead  = NULL;
   newHead = new Node;
   newHead->next = currHead;
   newHead->data = digit1+digit2+carry;


   if(start) {
      newHead->data = (digit1+digit2+carry)%10;
      carry = (digit1+digit2+carry)/10;
      currHead = newHead;          
      addition += carry;
      if(addition) {
         while(addition) {
            newHead = new Node;
            newHead->next = currHead;
            newHead->data = addition%10;
            addition = addition/10;
            currHead = newHead;          
         }
      }
   }
   return newHead;
}


int main() {
   Node *first=NULL, *second=NULL, *temp = NULL;
   int  numArray1[] = {3,4,2,8,7};
   int numArray2[] = {9,5,2};
   first = createLinkListFromArray(numArray1,5);   
   second = createLinkListFromArray(numArray2,3);   

   Node * temp1 = addReverseLinkList(first,second,true);
   print(temp1);
   cout <<  endl;
   return 0;
}

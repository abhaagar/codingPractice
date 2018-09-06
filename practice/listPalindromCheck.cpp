#include<iostream>
#include<stack>

struct Node{
   int data;
   Node *next;
};

using namespace std;
Node * createPalindromLinkList(int a){

}
Node * createPalindromLinkList(){
   int num=12344321;
   Node *head=NULL, *temp=NULL;
   while(num!=0) {
      if(!head) {
         head = new Node;
         temp = head;
      } else {
         temp->next = new Node;
         temp = temp->next;
      }
      temp->data = num%10;
      temp->next = NULL;
      num = num/10;
   }
   return head;
}

int main() {
   Node *head = createPalindromLinkList();
   stack<int> firstHalf;
   Node *slow=head, *fast=head->next->next;
   firstHalf.push(slow->data);
   while(true) {
      if(fast->next) {
         fast = fast->next;
         slow = slow->next;
         firstHalf.push(slow->data);
      } else {
         slow = slow->next;
         slow = slow->next;
         break;
      }
      if(fast->next) {
         fast = fast->next;
      } else {
         slow = slow->next;
         break;
      }
   }
   while(slow) {
     int data = firstHalf.top();
     if(data!=slow->data) {
        cout << "Not palindrome" << endl;
        return 1;
     }
     firstHalf.pop();
     slow = slow->next;
   }
   cout << "Palindrome" << endl;
   return 0;
}

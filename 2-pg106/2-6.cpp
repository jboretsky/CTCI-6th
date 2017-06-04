#include "ll.h"

bool isPalindrome( Node* head ) {
   Node* newHead = NULL;
   Node* p = head;
   while( p != NULL ) {
      Node* newNode = new Node();
      newNode->val = p->val;
      newNode->next = newHead;
      newHead = newNode;
      p = p->next;
   }

   p = head;
   while( p != NULL ) {
      if( p->val != newHead->val ) return false;
      p = p->next;
      newHead = newHead->next;
   }
   return true;
}

int main() {
   SinglyLinkedList* list = new SinglyLinkedList();

   list->printList();
   cout << isPalindrome( list->head ) << endl;
   list->printList();

   return 0;
}

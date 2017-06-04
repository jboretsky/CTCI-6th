#include "ll.h"

Node* partitionList( Node* head, int val ) {
   Node* p = head;
   Node* newHead = NULL;
   bool headCorrect = false;
   while( p != NULL ) {
      if( p->val < val ) {
         Node* tmp = p->next;
         p->next = newHead;
         newHead = p;
         p = tmp;
      } else {
         if( headCorrect == false ) {
            head = p;
            headCorrect = true;
         }
         p = p->next;
      }
   }

   // case where nothing was smaller than that element
   if( newHead == NULL ) return head;

   p = newHead;
   while( p->next != NULL ) {
      p = p->next;
   }
   p->next = head;
   return newHead;
}

int main() {
   SinglyLinkedList* list = new SinglyLinkedList();

   list->addNode(5);
   list->addNode(10);
   list->addNode(20);
   list->addNode(1);
   list->addNode(30);
   list->addNode(40);

   list->printList();
   list->head = partitionList( list->head, 1 );
   list->printList();

   return 0;
}

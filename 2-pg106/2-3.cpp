#include <iostream>
#include <unordered_set>
#include "ll.h"

void deleteNode( Node* toDelete ) {
   Node* tmp = toDelete->next;
   toDelete->val = toDelete->next->val;
   toDelete->next = toDelete->next->next;
   free(tmp);
}

int main() {
   SinglyLinkedList* list = new SinglyLinkedList();

   list->addNode(1);
   list->addNode(5);
   list->addNode(10);
   list->addNode(20);
   list->addNode(30);
   list->addNode(40);

   Node* fast = list->head;
   Node* slow = list->head;
   while( fast != NULL ) {
      fast = fast->next->next;
      slow = slow->next;
   }

   list->printList();
   deleteNode( slow );
   list->printList();

   return 0;
}

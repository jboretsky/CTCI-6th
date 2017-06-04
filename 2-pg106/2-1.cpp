#include <unordered_set>
#include "ll.h"

void removeDups( Node* head ) {
   unordered_set<int> intSet;
   Node* p = head;
   if( head == NULL ) {
      return;
   }
   intSet.emplace(p->val);

   while( p->next != NULL ) {
      if( intSet.find(p->next->val) == intSet.end() ) {
         intSet.emplace(p->next->val);
         p = p->next;
      } else {
         Node* tmp = p->next;
         p->next = p->next->next;
         free(tmp);
      }
   }
   return;
}

int main() {
   SinglyLinkedList* list = new SinglyLinkedList();

   list->addNode(10);
   list->addNode(20);
   list->addNode(30);
   list->addNode(5);
   list->addNode(20);
   list->addNode(50);
   list->addNode(5);
   list->addNode(30);
   list->addNode(5);
   list->addNode(5);
   list->addNode(5);
   list->addNode(5);
   list->addNode(5);
   list->addNode(5);
   list->addNode(5);
   list->addNode(50);

   list->printList();
   removeDups( list->head );
   list->printList();

   return 0;
}

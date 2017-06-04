#include "ll.h"

int findKthFromLast( Node* head, int k ) {
   int size = 0;
   Node* p = head;
   while( p != NULL ) {
      p = p->next;
      ++size;
   }

   if( k > size ) return -1;
   p = head;
   for( int i = size-k-1; i > 0; --i ) {
      p = p->next;
   }
   return p->val;
}

int main() {
   SinglyLinkedList* list = new SinglyLinkedList();

   list->addNode(1);
   list->addNode(5);
   list->addNode(10);
   list->addNode(20);
   list->addNode(30);
   list->addNode(40);

   list->printList();
   int k = 5;
   int val = findKthFromLast(list->head, k);
   cout << k << "th from last element is: " << val << endl;

   return 0;
}

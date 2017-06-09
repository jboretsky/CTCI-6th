#include<ctime>
#include<cstdlib>
#include "ll.h"

// IDEA: if they do intersect, then the length of the intersecting area
// must be at least smaller than the shorter one.
bool doIntersect( Node* head, Node* head2 ) {
   int len1 = 0;
   int len2 = 0;
   Node* p = head;
   Node* q = head2;
   while(p->next != NULL) {
      p = p->next;
      ++len1;
   }
   while(q->next != NULL) {
      q = q->next;
      ++len2;
   }

   if(len1 > len2) {
      p = head;
      q = head2;
   } else {
      p = head2;
      q = head;
   }

   int i = 0;
   while(i < abs(len1-len2)) {
      p = p->next;
      ++i;
   }

   while(p != NULL && q != NULL) {
      if(p == q) return true;
      p = p->next;
      q = q->next;
   }
   return false;
}

void makeIntersect( Node* head, Node* head2 ) {
   Node* p = head;
   Node* q = head2;

   while(p->next != NULL) {
      p = p->next;
   }
   while(q->next != NULL) {
      q = q->next;
   }

   Node* newNode = new Node();
   newNode->val = 4;
   p->next = newNode;
   q->next = newNode;
   p = p->next;
   for( int i = 0; i < 2; ++i ) {
      p->next = new Node();
      p->next->val = i+5;
      p = p->next;
   }
}

int main() {
   SinglyLinkedList* list = new SinglyLinkedList();
   SinglyLinkedList* list2 = new SinglyLinkedList();

   list->addNode(1);
   list->addNode(2);
   list->addNode(3);

   list2->addNode(1);


   srand(time(0));
   int intersect = rand() % 2;

   if(intersect) makeIntersect(list->head, list2->head);

   cout << "List1: ";
   list->printList();
   cout << "List2: ";
   list2->printList();
   cout << "Intersecting?: " << intersect << endl <<
   "Result: " << doIntersect( list->head, list2->head ) << endl;

   return 0;
}

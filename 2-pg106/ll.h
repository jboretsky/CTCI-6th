using namespace std;

struct Node {
   Node* next;
   int val;
};

class SinglyLinkedList {
   public:
      Node* head;
      void addNode( int );
      void printList();
};

void SinglyLinkedList::addNode(int val) {
   Node* newNode = new Node();
   newNode->val = val;
   if( head == NULL ) {
      head = newNode;
      return;
   }

   Node* p = head;
   while(p->next != NULL) {
      p = p->next;
   }
   p->next = newNode;
}

void SinglyLinkedList::printList() {
   Node* p = head;
   while( p != NULL ) {
      cout << p->val;
      if( p->next != NULL ) cout << " -> ";
      p = p->next;
   }
   cout << endl;
}

/**~*~*~*
CIS 22C
Project: Queue of strings (Destructor)

Written by: Pratyush Shanbhag
IDE: VSCode
*~*/
#include <iostream>
#include <string>
using namespace std;

class Queue_str
{
private:
   // Structure for the stack nodes
   struct QueueNode {
       string value;        // Value in the node
       QueueNode *next;     // Pointer to next node
   };

   QueueNode *front;          // Pointer to the first node
   QueueNode *rear;           // Pointer to the last node
   int length;                // Number of nodes in the queue

public:
   Queue_str(){ front = rear = NULL; length = 0; }    //Constructor
   ~Queue_str();                                    // Destructor

   // Queue operations
   // bool isEmpty();
   bool push(string);
   // string pop();
   // string peek();
   // string peekRear();
   // int getLength();
};

/**~*~*~*
  Member function push: inserts the argument into the queue
*~**/
bool  Queue_str::push(string item)
{
   QueueNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new QueueNode;
   if (!newNode)
       return false;
   newNode->value = item;
   newNode->next = NULL;
   
   // Update links and counter
   if (!front) // front is NULL: empty queue
       front = newNode;
   else
       rear->next = newNode;
       
   rear = newNode;
   length++;

   return true;
}


/**~*~*~*
   Destructor
*~**/
Queue_str::~Queue_str()
{
   QueueNode *currNode = front;
   QueueNode *tempNode;
   
   while(currNode != NULL) {
      cout << currNode->value << " - deleted!" << endl;
      tempNode = currNode->next;
      delete currNode;
      currNode = tempNode;
   }
   
   length = 0;
   
   cout << "Empty queue!" << endl;
}

int main() {
   Queue_str que;
   string item;

   cin >> item;
   while (item != "#" ) {
      que.push(item);
      cin >> item;
   }
   
   return 0;
}
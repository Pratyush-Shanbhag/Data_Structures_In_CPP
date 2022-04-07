/**~*~*~*
CIS 22C
Project: Stack of integers 

Written by: Pratyush Shanbhag
IDE: VSCode
*~*/
#include <iostream>
using namespace std;

class Stack_int
{
private:
   // Structure for the stack nodes
   struct StackNode {
       int value;           // Value in the node
       StackNode *next;     // Pointer to next node
   };

   StackNode *top;          // Pointer to the stack top
   int length;

public:
   Stack_int(){ top = NULL; length = 0; }    //Constructor
   //~Stack_int();                            // Destructor

   // Stack operations
   bool isEmpty() {/* Write your code here */ }
   bool push(int);
   // int pop();
   int peek() {/* Write your code here */ }
   int getLength() {/* Write your code here */ }
};

/**~*~*~*
  Member function push: pushes the argument onto the stack.
*~**/
bool Stack_int::push(int item)
{
   StackNode *newNode; // Pointer to a new node

   // Allocate a new node and store num there.
   newNode = new StackNode;
   if (!newNode)
      return false;
   newNode->value = item;

   // Update links and counter
   newNode->next = top;
   top = newNode;
   length++;

   return true;
}


int main() {

   Stack_int s;
   int item;

     
   return 0;
}
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
        bool isEmpty() { return length == 0; }
        bool push(int);
        // int pop();
        int peek() {
            if(length == 0)
                return -1;
            return top->value; 
        }
        int getLength() { return length; }
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

   cin >> item;
   while(item > 0) {
      s.push(item);
      cin >> item;
   }
   
   cout << s.getLength() << endl;
   item = s.peek();
   if(item == -1)
      cout << "Empty Stack!" << endl;
   else
      cout << item << endl;
   cout << s.getLength() << endl;
     
   return 0;
}
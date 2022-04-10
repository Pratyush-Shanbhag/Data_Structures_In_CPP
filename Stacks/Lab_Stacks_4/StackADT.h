/**~*~*~*~*
   Stack template
*~*/

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class Stack
{
    private:
        // Structure for the stack nodes
        struct StackNode
        {
        T value;          // Value in the node
        StackNode *next;  // Pointer to next node
        };

        StackNode *top;     // Pointer to the stack top
        int length;

    public:
        // Constructor
        Stack() { top = NULL; length = 0; }
        // Destructor
        ~Stack();
      
        // Stack operations:
        // push()
        bool push(T);
        // pop()
        T pop();
        // peek()
        T peek() { return top->value; }
        // isEmpty()
        bool isEmpty() { return length == 0; }
        // getLength()
        int getLength() { return length; }
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Stack<T>::push(T item) {
    StackNode *newNode;
    newNode = new StackNode;
    if (!newNode)
        return false;
    newNode->value = item;
    
    newNode->next = top;
    top = newNode;
    length++;
    
    return true;
}




/**~*~*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume stack is not empty.
*~**/
template <class T>
T Stack<T>::pop() {
    T item = top->value;
    top = top->next;
    length--;
    return item;
}




/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/
template <class T>
Stack<T>::~Stack() {
    StackNode *currNode = top;
    StackNode *tempNode;
    
    while(currNode != NULL) {
        tempNode = currNode->next;
        delete currNode;
        currNode = tempNode;
    }
}

#endif
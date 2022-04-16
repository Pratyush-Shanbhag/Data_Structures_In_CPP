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
        Stack() { top = NULL; length = 0; }
        ~Stack();
      
        // Stack operations:
        bool push(T);
        T pop();
        T peek() { return top->value; }
        bool isEmpty() { return length == 0; }
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
    StackNode* tempNode = top;
    T item = top->value;
    top = top->next;
    delete top;
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
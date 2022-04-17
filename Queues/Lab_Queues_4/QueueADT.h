/**~*~*~*~*
   Queue template
*~*/

#ifndef QUEUE_ADT
#define QUEUE_ADT

template <class T>
class Queue
{
    private:
        // Structure for the stack nodes
        struct QueueNode
        {
            T value;          // Value in the node
            QueueNode *next;  // Pointer to next node
        };

        QueueNode *front;          // Pointer to the first node
        QueueNode *rear;           // Pointer to the last node
        int length;                // Number of nodes in the queue

    public:
        Queue() { front = rear = NULL; length = 0; }
        ~Queue();
      
        // Stack operations:
        bool push(T);
        T pop();
        T peek() { return top->value; }
        T peekRear() { return rear->value; }
        bool isEmpty() { return length == 0; }
        int getLength() { return length; }
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Queue<T>::push(T item) {
    QueueNode *newNode;
    newNode = new QueueNode;
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
T Queue<T>::pop() {
    QueueNode* tempNode = top;
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
Queue<T>::~Queue() {
    QueueNode *currNode = top;
    QueueNode *tempNode;
    
    while(currNode != NULL) {
        tempNode = currNode->next;
        delete currNode;
        currNode = tempNode;
    }
}

#endif
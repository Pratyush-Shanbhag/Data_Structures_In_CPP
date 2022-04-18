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
        T peek() { return front->value; }
        T peekRear() { return rear->value; }
        bool isEmpty() { return length == 0; }
        int getLength() { return length; }

        T getItem(int);
};

/**~*~*~*~*
  Member function push inserts the argument onto
  the stack.
*~**/
template <class T>
bool Queue<T>::push(T item) {
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

/**~*~*~*~*
  Member function pop deletes the value at the top
  of the stack and returns it.
  Assume queue is not empty.
*~**/
template <class T>
T Queue<T>::pop() {
    QueueNode* tempNode = front;
    T item = front->value;
    front = front->next;
    delete tempNode;
    length--;
    return item;
}


/**~*~*~*~*
  Destructor:
  Traverses the list deleting each node (without calling pop)
*~**/
template <class T>
Queue<T>::~Queue() {
    QueueNode *currNode = front;
    QueueNode *tempNode;
    
    while(currNode != NULL) {
        tempNode = currNode->next;
        delete currNode;
        currNode = tempNode;
    }

    length = 0;        
}

/**~*~*~*~*
  This function returns the value of the
  node that is at a certain specified index
  in the queue. This index is passed in as an
  int parameter
*~**/
template <class T>
T Queue<T>::getItem(int index) {
    QueueNode *currNode = front;
    int num = 0;

    while(num < index) {
        currNode = currNode->next;
        num++;
    }

    return currNode->value;     
}

#endif
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

        QueueNode *top;     // Pointer to the stack top
        int length;

    public:
        Queue() { top = NULL; length = 0; }
        ~Queue();
      
        // Stack operations:
        bool push(T);
        T pop();
        T peek() {}
        bool isEmpty() {}
        int getLength() {}
};

#endif
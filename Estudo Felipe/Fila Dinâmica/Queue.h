#ifndef QUEUE_H
#define QUEUE_H
typedef int QueueEntry;

class Queue{
    public:
        Queue();
        ~Queue();
        bool full();
        bool empty();
        void append(QueueEntry x);
        void serve(QueueEntry &x);
        int size();
        void clear();
        void getFront(QueueEntry &x);
        void getRear(QueueEntry &x);

    private:
        struct QueueNode;
        typedef QueueNode* QueuePointer;
        struct QueueNode{
            QueueEntry entry;
            QueuePointer nextNode;
        };
        QueuePointer head;
        QueuePointer tail;

};


#endif
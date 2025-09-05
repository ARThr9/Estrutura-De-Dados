#ifndef QUEUE_H
#define QUEUE_H

typedef int QueueEntry;

class Queue{
      public:
      Queue();
      ~Queue();
      bool empty();
      bool full(); // na fila dinâmica não tem muita importância
      void append(QueueEntry x); // acrescenta um novo elemento no final da fila
      void serve(QueueEntry &x); // remove o elemento do início da fila
      int size();
      void getFront(QueueEntry &x); // passa uma cópia do primeiro elemento
      void getRear(QueueEntry &x); // passa uma cópia do último elemento
      void clear();

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
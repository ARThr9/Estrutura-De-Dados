#ifndef QUEUE_H
#define QUEUE_H
typedef int QueueEntry;
class Queue{
   public:
   Queue();
   ~Queue();
   bool empty();
   bool full();
   void append(QueueEntry x);
   void serve(QueueEntry &x);
   int size();
   void clear();
   void getFront(QueueEntry &x);
   void getRear(QueueEntry &x);
   private:
      static const int MaxQueue = 100;
      int entry[MaxQueue+1];
      int count;
      int head;
      int tail;

};

#endif
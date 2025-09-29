#ifndef STACK_H
#define STACK_H
typedef char StackEntry;

class Stack{
   public:
      Stack();
      ~Stack();
      int size();
      void clear();
      bool empty();
      bool full();
      void push(StackEntry x);
      void pop(StackEntry &x);
      void getTop(StackEntry &x);

   private:
      static const int MaxEntry = 100;
      StackEntry entry[MaxEntry + 1];
      int top = 1;
};
#endif
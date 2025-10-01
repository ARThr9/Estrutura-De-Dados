// ESTÁTICA

#ifndef STACK_H
#define STACK_H
typedef char StackEntry;

class Stack{
    public:
        Stack();
        ~Stack();
        bool empty();
        bool full();
        int size();
        void push(StackEntry x);
        void pop(StackEntry &x);
        void getTop(StackEntry &x);
        void clear();


    private:
        static const int MaxEntry = 100;
        StackEntry entry[MaxEntry + 1];
        int top;
};


#endif
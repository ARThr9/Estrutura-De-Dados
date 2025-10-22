#ifndef STACK_H
#define STACK_H
typedef char StackEntry;

class Stack{
    public:
        Stack();
        ~Stack();
        bool full();
        bool empty();
        void push(StackEntry x);
        void pop(StackEntry &x);
        void clear();
        void getTop(StackEntry &x);
        int size();

    private:
        struct StackNode;
        typedef StackNode* StackPointer;
        StackPointer top;
        struct StackNode{
            StackEntry entry;
            StackPointer nextNode;
        };
        int count;
};


#endif
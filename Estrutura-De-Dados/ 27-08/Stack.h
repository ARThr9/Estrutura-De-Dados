#ifndef STACK_H
#define STACK_H
typedef char StackEntry;
class Stack{
    public:
        Stack(); // construtor
        ~Stack(); // destrutor
        bool full();
        bool empty();
        void push(StackEntry x); // passado por cópia
        void pop(StackEntry &x); // passado por referencia 
        void clear();
        int size();
        void getTop(StackEntry &x);

    private:
        struct StackNode;
        typedef StackNode* StackPointer;
        StackPointer top;
        struct StackNode { // definição da struct protegida
          StackEntry entry;
          StackPointer nextNode;  
        };
        int count;
};


#endif
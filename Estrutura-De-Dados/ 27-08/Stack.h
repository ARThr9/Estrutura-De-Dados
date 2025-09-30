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
        struct StackNode; // declaração do nó da pilha
        typedef StackNode* StackPointer; // definição do ponteiro para o nó
        StackPointer top; // ponteiro para o topo da pilha
        struct StackNode { // definição da struct protegida
          StackEntry entry; // valor do nó, campo de dados
          StackPointer nextNode; // ponteiro para o próximo nó
        };
        int count;
};


#endif

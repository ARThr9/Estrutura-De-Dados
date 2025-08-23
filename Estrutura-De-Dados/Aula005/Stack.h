#ifndef STACK_H
#define STACK_H
typedef char StackEntry;

class Stack{
    public:
        Stack();
        ~Stack();
        bool empty(); // retorna true se estiver vazia e false se tiver algo dentro
        bool full(); // retorna true se estiver cheia e false se estiver algum espaço livre
        void push(StackEntry x); // adiciona um novo elemento na pilha, caso ela não esteja cheia
        void pop(StackEntry &x); // remove um elemento do topo caso a pilha não esteja vazia e armazena uma cópia em x 
        int size(); // retorna a quantidade de elementos atualmente armazenados na estrutura
        void clear(); // descarta todos os elementos da estrutura tornando-a vazia
        void getTop(StackEntry &x); // armazena uma cópia do topo em x, caso exista, a estrutura permanece inalterada
        


    private:
        static const int MaxEntry = 100;
        StackEntry entry[MaxEntry + 1];
        int top;
};

#endif
#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
   count = 0;
   top = NULL;
}

Stack::~Stack(){
   clear();
}

bool Stack::empty(){
   return top == NULL;
}

bool Stack::full(){
   return false; // deixar como false sempre para testar a pilha
}

void Stack::push(StackEntry x){
   StackPointer p = new StackNode;
   if(p == NULL){
      cout<< "Sem espaço na memória! Saindo..." << endl;
      abort();
   }
   p->entry = x; // -> acesso via referência a um campo de uma struct
   p->nextNode = top;
   top = p;
   count++;
}

void Stack::pop(StackEntry &x){
   if(empty()){
      cout << "Não há elementos para remover! Saindo..." << endl;
      abort();
   }
   StackPointer p; // ponteiro auxiliar 
   x = top->entry; // devolve o valor para x
   p = top; // salva endereço do topo para não perde-lo
   top = top->nextNode; 
   delete p;
}
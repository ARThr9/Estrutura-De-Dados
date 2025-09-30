#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
   top = 0;
}

Stack::~Stack(){
   cout << "Pilha destruída";
}

bool Stack::empty(){
   return top == 0;
}

bool Stack::full(){
   return top == MaxEntry;
}

int Stack::size(){
   return top;
}

void Stack::clear(){
   top = 0;
}

void Stack::pop(StackEntry &x){
   if (empty()) abort();
   x = entry[top]; // x recebe o valor do topo
   top--; // decrementa o topo; tem que vir depois
}

void Stack::push(StackEntry x){
   if (full()) abort();
   top++; // incrementa o topo tem que vir primeiro porque o topo começa em 0
   entry[top] = x; // insere o elemento no topo
}

void Stack::getTop(StackEntry &x){
   if (empty()) abort();
   x = entry[top]; // x recebe o valor do topo
}

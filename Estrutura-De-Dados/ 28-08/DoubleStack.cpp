#include "DoubleStack.h"
#include <iostream>
using namespace std;

DoubleStack::DoubleStack(){
   top1 = -1; // começa em -1 pq é o começo da pilha
   top2 = MaxEntry; // começa em MaxEntry pq é o tamanho da pilha inteira
}

DoubleStack::~DoubleStack(){
   cout << "DoubleStack desalocada!" << endl;
}

bool DoubleStack::full(){
   return top2 - top1 == 1; // se a diferença entre eles for de 1 unidade significa que a pilha está cheia
}

bool DoubleStack::stack1_empty(){
   return top1 == -1; // -1 é o início da pilha, se for igual a -1 significa que está vazia
}

bool DoubleStack::stack2_empty(){
   return top2 == MaxEntry; // MaxEntry é o tamanho total da pilha/final da pilha, se for igual a MaxEntry sifnifica que está vazia;
}

void DoubleStack::stack1_clear(){
   top1 = -1;
}

void DoubleStack::stack2_clear(){
   top2 = MaxEntry;
}

int DoubleStack::stack1_size(){ // já foi questão de prova
   return top1 + 1;
}

int DoubleStack::stack2_size(){ // já foi questão de prova
   return MaxEntry - top2; // tamanho total - o top2 (posição do topo) = tamanho da pilha 2
}

void DoubleStack::stack1_push(StackEntry x){
   if(full()){
      cout << "Não há espaço para novo elemento! Saindo..." << endl;
      abort();
   }
   top1++;
   entry[top1] = x;
}

void DoubleStack::stack2_push(StackEntry x){
   if(full()){ // primeiro verifica se a pilha está cheia
      cout << "Não há espaço para novo elemento! Saindo..." << endl;
      abort();
   }
   top2--; // decrementa o top2 pq a pilha 2 começa do final para o começo
   entry[top2] = x; // insere o elemento na posição do top2
}

void DoubleStack::stack1_pop(StackEntry &x){
   if(stack1_empty()){
      cout << "Pilha 1 vazia! Saindo..." << endl;
      abort();
   }
   x = entry[top1]; // retorna o elemento do topo
   top1--; // decrementa o top1 para remover o elemento
}

void DoubleStack::stack2_pop(StackEntry &x){
   if(stack2_empty()){
      cout << "Pilha 2 vazia! Saindo..." << endl;
      abort();
   }
   x = entry[top2]; // retorna o elemento do topo
   top2++; // incrementa o top2 para remover o elemento
}

void DoubleStack::stack1_getTop(StackEntry &x){
   if(stack1_empty()){
      cout << "Pilha 1 vazia! Saindo..." << endl;
      abort();
   }
   x = entry[top1]; // retorna o elemento do topo
}

void DoubleStack::stack2_getTop(StackEntry &x){
   if(stack2_empty()){
      cout << "Pilha 2 vazia! Saindo..." << endl;
      abort();
   }
   x = entry[top2]; // retorna o elemento do topo
}
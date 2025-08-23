#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    top = 0;
}

Stack::~Stack(){
    cout << "Pilha destruída!" << endl;
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
    if (empty()) {
        cout << "Pilha vazia! Saindo..." << endl;
        abort();
    }
    x = entry[top];
    top--;
}

void Stack::push(StackEntry x){
    if(full()){
        cout << "Pilha cheia! Saindo..." << endl;
        abort();
    }
    top++;
    entry[top] = x;
}

void Stack::getTop(StackEntry &x){
    if(empty()){
        cout << "Pilha vazia! Sem topo. Saindo..." << endl;
        abort();
    }
    x = entry[top]; // retorna true, caso o método retorne um valor bool
}

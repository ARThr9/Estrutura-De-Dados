#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    top = 0;
}

Stack::~Stack(){
    cout << "Pilha destruída";
}

void Stack::clear(){
    top = 0;
}

bool Stack::full(){
    return top == MaxEntry;
}

bool Stack::empty(){
    return top == 0;
}

int Stack::size(){
    return top;
}

void Stack::push(StackEntry x){
    if(full()) abort();
    top++;
    entry[top] = x;
}

void Stack::pop(StackEntry &x){
    if(empty()) abort();
    x = entry[top];
    top--;
}

void Stack::getTop(StackEntry &x){
    if(empty()) abort(); // pilha vazia, aborta
    x = entry[top];
}
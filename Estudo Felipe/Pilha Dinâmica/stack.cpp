#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    top = NULL;
    count = 0;
}

Stack::~Stack(){
    clear();
}

bool Stack::full(){
    return false;
}

bool Stack::empty(){
    return top == NULL;
}

void Stack::pop(StackEntry &x){
    if(empty()) abort();
    StackPointer p;
    x = top->entry;
    p = top;
    top = top->nextNode;
    delete p;
    count--;
}

void Stack::push(StackEntry x){
    if(full()) abort();
    StackPointer p;
    p->entry = x;
    p->nextNode = top;
    top = p;
    count++;
}

int Stack::size(){
    return count;
}

void Stack::getTop(StackEntry &x){
    if(empty()) abort();
    x = top->entry; // passa o valor do campo de dados de top para x;
}

void Stack::clear(){
    StackPointer p;
    while(top != NULL){
        p = top;
        top = top->nextNode;
        delete p;
    }
    count = 0;
}
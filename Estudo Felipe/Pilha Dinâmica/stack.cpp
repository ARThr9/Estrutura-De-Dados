#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
   count = 0;
   top = NULL;
}

Stack::~Stack(){
   clear();
}

int Stack::size(){
   return count;
}

bool Stack::full(){
   return false;
}

bool Stack::empty(){
   return top == NULL;
}

void Stack::push(StackEntry x){
   StackPointer p = new StackNode;
   if (p == NULL) abort();
   p->entry = x;
   p->nextNode = top;
   top = p;
   count++;
}

void Stack::pop(StackEntry &x){
   if (empty()) abort();
   StackPointer p;
   x = top->entry;
   p = top;
   top = top->nextNode;
   delete p;
   count--;
}
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
   head = tail = NULL;
}

Queue::~Queue(){
   clear();
}

bool Queue::empty(){
   return head == NULL;
}

bool Queue::full(){
   return false;
}

void Queue::append(QueueEntry x ){
   QueuePointer p;
   p = new QueueNode;
   if(p == NULL){
      cout << "Sem memória suficiente! Saindo..." << endl;
      abort();
   }
   p->entry = x;
   if(empty()){
      head = p;
   } else{
      tail->nextNode = p;
   }
   tail = p;
   p->nextNode = NULL;
}
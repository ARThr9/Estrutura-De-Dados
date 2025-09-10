#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
   count = 0;
   head = 1; // Para facilitar a implementação 
   tail = MaxQueue;
}

Queue::~Queue(){
   cout << "Estrutura destruida" << endl;
}

bool Queue::empty(){
   return count == 0;
}

bool Queue::full(){
   return count == MaxQueue;
}

void Queue::clear(){
   count = 0;
   head = 1; 
   tail = MaxQueue;
}

int Queue::size(){
   return count;
}

void Queue::append(QueueEntry x){
   if (full()){
      cout << "Fila cheia" << endl;
      abort();
   }
   count++;
   tail = (tail % MaxQueue) + 1;
   entry[tail] = x;
}

void Queue::serve(QueueEntry &x){
   if (empty()){
      cout << "Fila vazia." << endl;
      abort();
   }
   x = entry[head];
   count--;
   head = (head % MaxQueue) + 1;
}

void Queue::getFront(QueueEntry &x){
   if(empty()){
      cout << "Fila vazia" << endl;
      abort();
   }
   x = entry[head];
}

void Queue::getRear(QueueEntry &x){
   if(empty()){
      cout << "Fila vazia" << endl;
      abort();
   }
   x = entry[tail];
}


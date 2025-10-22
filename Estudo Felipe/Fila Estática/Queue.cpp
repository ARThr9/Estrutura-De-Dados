#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    count = 0;
    head = 1;
    tail = MaxQueue;
}

Queue::~Queue(){
    cout << "Fila destruída";
}

bool Queue::full(){
    return count == MaxQueue;
}

bool Queue::empty(){
    return count == 0;
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
    if(full()) abort();
    count++;
    tail = (tail % MaxQueue) + 1; // como o tail começa em MaxQueue, o resto da divisão tail % MaxQueue = 0, + 1 para adicionar na próxima posição;
    entry[tail] = x;
}

void Queue::serve(QueueEntry &x){
    if(empty()) abort();
    x = entry[head];
    count--;
    head = (head % MaxQueue) + 1; // como head começa em 1, o resto da divisão head % MaxQueue = 1, + 1 para acançar para a próxima posição;
}

void Queue::getFront(QueueEntry &x){
    if(empty()) abort();
    x = entry[head];
}

void Queue::getRear(QueueEntry &x){
    if(empty()) abort();
    x = entry[tail];
}
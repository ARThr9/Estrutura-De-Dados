#include "Queue.h"
#include <iostream>
using namespace std;

int count = 0;
Queue::Queue(){
    head = NULL;
    tail = NULL;
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

void Queue::append(QueueEntry x){
    if(full()) abort();
    QueuePointer p;
    p = new QueueNode; // aloca um novo nó para o novo elemento
    if(p == NULL) abort();

    p->entry = x;

    if(empty()){
        head = p;
    }

    else{
        tail->nextNode = p;
    }

    tail = p;
    p->nextNode = NULL;
    count++;
}

void Queue::serve(QueueEntry &x){
    if(empty()) abort();
    QueuePointer p = head; // ponteiro auxiliar armazena o head;
    x = head->entry; // armazena o valor que será removido de head no x;
    head = head->nextNode; // head passa a ser o próximo valor;
    delete p;

    if(head == NULL) tail == NULL;
    count--;
}

void Queue::clear(){
    QueuePointer p;
    while(head != NULL){
        p = head;
        head = head->nextNode;
        delete p;
    }
    tail = NULL;
    count = 0;
}

int Queue::size(){
    int s = 0;
    QueuePointer p = head;
    while(p != NULL){
        s++;
        p = p->nextNode;
    }
    return s;
}

void Queue::getFront(QueueEntry &x){
    if(empty()) abort();
    x = head->entry; // x recebe o valor do campo de dados do head, que é o começo/frente da fila
}

void Queue::getRear(QueueEntry &x){
    if(empty()) abort();
    x = tail->entry;
}
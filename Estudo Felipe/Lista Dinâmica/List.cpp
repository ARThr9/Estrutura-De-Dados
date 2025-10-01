#include "List.h"
#include <iostream>
using namespace std;

List::List(){
    count = 0;
    head = NULL;
}

List::~List(){
    clear();
}

bool List::full(){
    return false;
}

bool List::empty(){
    return head == NULL;
}

void List::clear(){
    head = NULL;
    count = 0;
}

void List::setPosition(int p, ListPointer &current){
    current = head; // aqui o p assume o valor 1;
    for(int i = 2; i <= p; i++){
        current = current->nextNode; 
    }
}

void List::insert(int p, ListEntry x){
    if(p < 1 || p > count + 1) abort();
    ListPointer newNode = new ListNode;
    if(newNode == NULL) abort();

    newNode->entry = x;
    if(p == 1){
        newNode->nextNode = head;
        head = newNode;
    }
    else{
        ListPointer current;
        setPosition(p - 1, current); // current aponta para o nó anterior a p
        newNode->nextNode = current->nextNode; // o nextNode do novo nó aponta para o nextNode do nó anterior, current
        current->nextNode = newNode; // o nextNode do current passa a apontar para o novo nó
    }
    count++;

}

void List::remove(int p, ListEntry &x){
    if(empty()) abort();
    if(p < 1 || p > count) abort();
    ListPointer node;
    if(p == 1){
        node = head;
        head = head->nextNode;
    }
    else{
        ListPointer current;
        setPosition(p - 1, current);
        node = current->nextNode;
        current->nextNode = node->nextNode;
    }
    x = node->entry;
    delete node;
    count--;
}
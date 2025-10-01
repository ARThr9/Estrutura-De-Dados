#include "List.h"
#include <iostream>
using namespace std;

List::List(){
    count = 0;
}

List::~List(){
    cout << "Lista destruída";
}

bool List::empty(){
    return count == 0;
}

bool List::full(){
    return count = MaxList;
}

int List::size(){
    return count;
}

void List::clear(){
    count = 0;
}

void List::insert(int p, ListEntry x){
    if(full()) abort();
    if(p > count + 1 || p < 1) abort();

    for (int i = count; i >= p; i--){ // desloca elementos para direita, abrindo espaço na posição p;
        entry[i + 1] = entry[i];
    }
    entry[p] = x; // insere o novo elemento na posição p;
    count++;
}

void List::remove(int p, ListEntry &x){
    if(empty()) abort();
    if(p > count + 1 || p < 1) abort();
    x = entry[p]; // retorna o elemento que está sendo removido, armazenando em x;
    for (int i = p; i < count; i++){
        entry[i] = entry[i + 1]; // desloca elementos para esquerda, fechando o espaço que estava na posição p;
    }
    count--;
}

void List::retrieve(int p, ListEntry &x){ // retorna o elemento que está na posição p;
    if(empty()) abort();
    
    if(p > count + 1 || p < 1) abort(); // verificação para ver se a posição p é válida;

    x = entry[p]; // retorna o elemento que está na posição p, armazenando em x;
}

void List::replace(int p, ListEntry x){ // substitui o elemento que está na posição p, pelo elemento x;
    if(empty()) abort();
    if(p > count + 1 || p < 1) abort();
    entry[p] = x; // substitui o elemento que está na posição p, pelo elemento x;
}
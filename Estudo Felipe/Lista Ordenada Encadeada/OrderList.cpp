#include "OrderList.h"
#include <iostream>
using namespace std;

OrderList::OrderList(){
    count = 0;
    sentinel = new ListNode; // alocar dinamicamente um nó para a sentinela
    if(sentinel == NULL) abort(); // não tem espaço pra sentinela
    head = sentinel;
}

OrderList::~OrderList(){
    clear();
    delete sentinel; // como é o destrutor, deve desalocar a sentinela;
}

bool OrderList::full(){
    return false;
}

bool OrderList::empty(){
    return head == sentinel;
}

void OrderList::insert(ListEntry x){
    ListPointer p, q;
    sentinel->entry = x;

    p = head;
    while(p->entry < x){
        p = p->nextNode;
    }
    q = new ListNode;
    if(q == NULL) abort();
    
    if(p != sentinel){
        *q = *p; // copia o conteúdo do nó apontado por p para o nó apontado por q
        p->entry = x; // atualiza o valor do nó apontado por p
        p->nextNode = q; // atualiza o ponteiro nextNode do nó apontado por p
    }
    else{
        p->nextNode = sentinel;
        sentinel = q;
    }
    count++;
}

bool OrderList::remove(ListEntry x){
    ListPointer p, q;
    q = head;
    p = NULL;
    sentinel->entry = x;
    while(q->entry < x){
        p = q; // salvo o valor de q antes de ir para o próximo nó
        q = q->nextNode;
    }
    if(q->entry != x || q == sentinel){
        return false; // retorna falso pq o valor não tá na lista
    }
    if(q == head){
        head = head->nextNode;
    }

    p->nextNode = q->nextNode;
    delete q;
    count--;

}

int OrderList::search(ListEntry x){
    ListPointer q = head;
    int posicao = 1;
    sentinel->entry = x;
    while(q->entry < x){
        q = q->nextNode;
        posicao++;
    }
    if(q->entry!= x || q == sentinel){
        return 0; // elemnto não encontrado
    }
    else{
        return posicao;
    }
}

void OrderList::clear(){
    ListPointer q = head;
    while(head != sentinel){
        q = head;
        head = head->nextNode;
        delete q;
    }
    count = 0;
}
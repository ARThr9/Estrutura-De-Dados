#include "OrderList.h"
#include <iostream>
using namespace std;

OrderList::OrderList(){
   count = 0;
   sentinel = new ListNode; // aloca dinamicamente um novo nó para sentinel
   if(sentinel == NULL){
      cout << "Não há espaço disponível. Saindo..." << endl;
      abort();
   }
   head = sentinel;
}

OrderList::~OrderList(){
   clear(); // descarta todos os elementos
   delete sentinel;
}

bool OrderList::full(){
   return false;
}

bool OrderList::empty(){
   return head == sentinel; // se head aponta pra sentinel quer dizer que está vazia
}

void OrderList::insert(ListEntry x){
   ListPointer p, q;

   sentinel->entry = x;

   p = head;
   while(p->entry < x){
      p = p->nextNode;
   }
   q = new ListNode; // aloca dinamicamente um novo nó
   if (q == NULL){
      cout << "Não há espaço disponível. Saindo..." << endl;
      abort();
   }
   if (p == sentinel){
      p->nextNode = q;
      sentinel = q;
   }
   else{
      *q = *p;
      p->entry = x;
      p->nextNode = q;
   }
    
   count++;
}

bool OrderList::remove(ListEntry x){ // pode ser void ou bool
   ListPointer p, q;
   q = head;
   p = NULL;
   sentinel->entry = x;

   while(q->entry < x){
      p = q;
      q = q->nextNode;
   }

   if(q->entry != x || q == sentinel){
      return false;
   }

   if (q == head){
      head = head->nextNode;
   }

   p->nextNode = q->nextNode;
   delete q;
   count--;
   return true;
}

int OrderList::search(ListEntry x){
   // retorna o índice em que a primeira ocorrência do elemento x foi encontrada
   // retorna 0 caso não seja encontrado
   ListPointer q = head;
   int posicao = 1;

   sentinel->entry = x;
   while(q->entry < x){
      q = q->nextNode;
      posicao++;
   }

   if(q->entry != x || q == sentinel){
      return 0;
   }
   else{
      return posicao;
   }
}

void OrderList::clear(){
   ListPointer q = head;

   while(head != sentinel){ // apaga todos os nós exceto a sentinela
      q = head;
      head = head->nextNode;
      delete q;
   }
}
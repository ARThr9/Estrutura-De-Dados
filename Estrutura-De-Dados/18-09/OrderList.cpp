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
   q = new ListNode;
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
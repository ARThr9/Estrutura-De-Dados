#include "ListaDuplamenteEncadeada.h"
#include <iostream>
using namespace std;

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada(){
   head = new ListNode; // aloca dinamicamente um novo nó para head;;
   count = 0;
   if(head == NULL){
      cout << "Não tem espaço disponível. Saindo..." << endl;
      abort();
   }
   head->nextNode = head;
   head->prevNode = head;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada(){
   clear();
   delete head;
}

bool ListaDuplamenteEncadeada::empty(){
   return count == 0;
}

bool ListaDuplamenteEncadeada::full(){
   return false;
}

void ListaDuplamenteEncadeada::insert(ListEntry x){
   ListPointer p, q;
   p = head->nextNode;
   q = new ListNode;
   head->entry = x; // sentinela temporária
   if(q == NULL){
      cout << "Não tem espaço disponível. Saindo..." << endl;
      abort();
   }
   while(p != head && p->entry < x){
      p = p->nextNode;
   }
   q->entry = x;
   q->nextNode = p;
   q->prevNode = p->prevNode;
   p->prevNode->nextNode = q;
   p->prevNode = q;
   count++;
}

// Escreva um método breakList do TAD lista duplamente encadeada circular com 
// sentinela, que recebe uma posição de uma célula Q da lista e devolve uma lista 
// duplamente encadeada circular com os elementos a partir de Q
// assinatura do método: bool breakList(int q, ListaDuplamenteEncadeada &newList)

bool ListaDuplamenteEncadeada::breakList(int q, ListaDuplamenteEncadeada &newList){
   if (q == 0 || q >= count || this->empty()){
      return false;
   }
   if (!newList.empty()) return false;

   ListPointer pQ = head->nextNode; // nó Q é onde ocorrerá a divisão da Lista
   for (int i = 0; i < q; i++){
      pQ = pQ->nextNode;
   }
   ListPointer ultimo_na_lista1 = pQ->prevNode; // último nó da lista original
   ListPointer ultimo_na_lista2 = this->head->prevNode; // último nó da nova lista

   ultimo_na_lista1->nextNode = this->head;
   this->head->prevNode = ultimo_na_lista1;

   newList.head->nextNode = pQ;
   pQ->prevNode = newList.head;
   ultimo_na_lista2->nextNode = newList.head;
   newList.head->prevNode = ultimo_na_lista2;

   newList.count = this->count - q;
   this->count = q;
   return true;
}

bool ListaDuplamenteEncadeada::remove(ListEntry x){
   ListPointer p;
   p = head->nextNode;
   head->entry = x; // sentinela temporária
   while(p != head && p->entry < x){
      p = p->nextNode;
   }
   if(p != head && p->entry == x){
      p->prevNode->nextNode = p->nextNode;
      p->nextNode->prevNode = p->prevNode;
      delete p;
      count--;
      return true;
   }
   return false;
}

void ListaDuplamenteEncadeada::clear(){
   ListPointer p, q; // p percorre a lista e q guarda o próximo nó para liberar p
   p = head->nextNode; // inicia em head->nextNode, pois head não deve ser apagado
   while(p != head){ // enquanto não chegar em head
      q = p->nextNode; // guarda o próximo nó
      delete p; // libera o nó p
      p = q; // avança p
   }
   head->nextNode = head; // lista fica vazia
   head->prevNode = head;
   count = 0;
}

int ListaDuplamenteEncadeada::search(ListEntry x){
   ListPointer p;
   int pos = 0;
   p = head->nextNode;
   head->entry = x; // sentinela temporária
   while(p != head && p->entry < x){
      p = p->nextNode;
      pos++;
   }
   if (p != head && p->entry == x){
      return pos;
   }
   return -1;
}
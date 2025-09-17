#include "List.h"
#include <iostream>
using namespace std;

List::List(){
   head = NULL;
   count = 0;
}

List::~List(){
   clear();
}

void List::clear(){
   head = NULL;
   count = 0;
}

bool List::full(){
   return false;
}

bool List::empty(){
   head == NULL;
}

int List::size(){
   return count;
}

void List::setPosition(int p, ListPointer &current){
   // a verificação de posição válida na lista, será feita no método que chama o setPosition
   // portanto, aqui, assumimos que p é uma posição válida
   current = head; // isso já é p = 1;
   for (int i = 2; i <= p; i++){
      current = current->nextNode;
   }
}

void List::insert(int p, ListEntry x){
   if(p < 1 || p > count + 1){
      cout << "Posição inválida. Saindo..." << endl;
      abort();
   }
   ListPointer newNode = new ListNode;
   if (newNode == NULL){
      cout << "Não há espaço para novo elemento. Saindo..." << endl;
      abort();
   }
   newNode->entry = x;
   if (p == 1){
      newNode->nextNode = head;
      head = newNode;
   }
   else{
      ListPointer current;
      setPosition(p-1, current);
      newNode->nextNode = current->nextNode; // faz apontar para onde o current estava apontando
      current->nextNode = newNode; // current nextNode passa a apontar para o elemento que o newNode estava apontando
   }
   count ++;
}

void List::remove(int p, ListEntry &x){
   if (empty()){
      cout << "Não há nenhum elemnto para remover. Saindo..." << endl;
      abort();
   }
   if(p < 1 || p > count){
      cout << "Posição inválida. Saindo..." << endl;
      abort();
   }
   ListPointer node;
   if(p == 1){
      node = head;
      head = head->nextNode;
   }
   else{
      ListPointer current;
      setPosition(p-1, current);
      node = current->nextNode;
      current->nextNode = node->nextNode;
      
   }
   x = node->entry;
   delete node;
   count--;

}
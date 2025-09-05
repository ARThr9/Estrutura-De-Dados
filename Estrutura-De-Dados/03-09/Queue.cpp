#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
   head = tail = NULL;
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

void Queue::append(QueueEntry x ){
   QueuePointer p;            // ponteiro auxiliar para novo nó
   p = new QueueNode;         // aloca dinamicamente um novo nó
   if(p == NULL){             // verifica se a alocação foi bem sucedida
      cout << "Sem memória suficiente! Saindo..." << endl;
      abort();
   }
   p->entry = x;              // atribui o valor ao novo nó
   if(empty()){               // verifica se a fila está vazia
      head = p;               // se estiver, o novo nó é o pimeiro da fila
   } else{
      tail->nextNode = p;     // se não estiver, o próximo do último nó aponta para o novo nó
   }
   tail = p;                  // o novo nó é o último da fila
   p->nextNode = NULL;        // o próximo do novo nó aponta para NULL
}

void Queue::clear(){
   QueuePointer p; // ponteiro auxiliar para percorrer a fila
   while(head != NULL){ // enquanto a fila não estiver vazia
      p = head; // ponteiro auxiliar recebe o primeiro nó
      head = head->nextNode; // o segundo nó passa a ser o primeiro
      delete p; // libera a memória desalocando o ponteiro
   }
   tail = NULL; // o tail também aponta para NULL
}

void Queue::serve(QueueEntry &x){
   if(empty()){
      cout << "Fila vazia! Saindo..." << endl;
      abort();
   }
   QueuePointer p = head;        // ponteiro auxiliar para o nó que será removido
   x = head->entry;              // atribui o valor do primeiro nó para a variável x
   head = head->nextNode;        // o segundo nó passa a ser o primeiro
   delete p;                     // libera a memória desalocando o ponteiro
   if(head == NULL) tail = NULL; // se a fila ficou vazia, o tail também aponta para NULL
}

int Queue::size(){
   int s = 0;                    // contador de elementos
   QueuePointer p = head;        // ponteiro auxiliar para percorrer a fila
   while(p != NULL){             // percorre a fila até o final
      s++;                       // incrementa o contador
      p = p->nextNode;           // avança o ponteiro para o próximo nó
   }
   return s;                     // retorna o tamanho da fila
}

void Queue::getFront(QueueEntry &x){
   if(empty()){
      cout << "Fila vazia! Saindo..." << endl;
      abort();
   }
   x = head->entry; // atribui o valor do primeiro nó para a variável x
}

void Queue::getRear(QueueEntry &x){
   if(empty()){
      cout << "Fila vazia! Saindo..." << endl;
      abort();
   }
   x = tail->entry; // atribui o valor do último nó para a variável x
}
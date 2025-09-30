#include <iostream>
#include "list.h"
using namespace std;

List::List(){
   count = 0;
}

List::~List(){
   cout << "Lista destruida!" << endl; // basicamente inútil
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
   if (full()) abort(); // verifica se a lista tá cheia

   if (p > count+1 || p < 1){ // verifica se a posição p é um índice válido
      cout << "Posição inválida. Saindo..." << endl;
      abort();
   }

   for (int i = count; i >= p; i--){ // abrir espaço para o novo elemento, começa do final e vai até p
      entry[i+1] = entry[i]; // desloca os elementos para a direita
   }
   
   entry[p] = x;
   count++;
}

void List::remove(int p, ListEntry &x){
   if (empty()) abort(); // verifica se a lista está vazia
   if (p > count + 1 || p < 1){
      cout << "Posição inválida. Saindo..." << endl;
   }
   x = entry[p];
   for (int i = p; i <= count; i++){
      entry[i] = entry[i+1];
   }

   count--;

}
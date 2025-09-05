#include "Queue.h"
#include <iostream>
using namespace std;

int main(){
   Queue q1;
   q1.append(3);
   if(q1.full()){
      // faça algo
      // houve uma alocação de memória no espaço que você verificou com o full()
   }
}
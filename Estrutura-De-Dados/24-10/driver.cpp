#include <iostream>
#include "BST.h"
using namespace std;

int main(){
   BinarySearchTree b;

   for(int i = 0; i < 10; i++)
      b.insert(rand() % 101);

   int op = 1;

   while(op != 0){
      cout << "Informe a opção: " << endl;
      cout << "1 - Print" << endl;
      cout << "2 - Insert" << endl;
      cin >> op;

      switch (op){
         case 1:
            b.print();
            break;
         case 2:
            int value;
            cout << "Informe o valor a ser inserido: ";
            cin >> value;
            b.insert(value);
            break;
      }
   }
      
   return 0;
}
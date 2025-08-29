#include "Stack.h"
#include <iostream>
using namespace std;

int main(){

    string expr;
    cout << "Informe a expressão matemática: ";
    getline(cin, expr);

    Stack pilha;
    char temp; // para desempilhar
    for(int i = 0; i < expr.length(); i++){
        if(expr[i] == '('){
            pilha.push(expr[i]);
        }
        else if(expr[i] == ')'){
            pilha.pop(temp); // manda uma cópia para a variável auxiliar
        }
    }
    if(pilha.empty()) {
        cout << "Expressão válida!" << endl;
    }
    else if(!pilha.empty()){
        cout << "Expressão Inválida!" << endl;
    }

    return 0;
}
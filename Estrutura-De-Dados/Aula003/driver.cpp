//arquivo de implementação da aplicação
#include "ThinkingCap.h"
#include <iostream>
using namespace std;

int main(){
    ThinkingCap estudo, festa;
    //estudo.leftString = "Ola"; > Erro pois 
    //leftString é um campo privado (inacessível à main())
    if(estudo.slots("Olaaaaa", "Tchau")){
        char op = 'l';

        cout << "Escolha o botao (r/l): ";
        cin >> op;
        if(op == 'r') estudo.pressRight();
        if(op == 'l') estudo.pressLeft();
    }else
        cout << "Falhou!"<<endl;

    return 0;
}
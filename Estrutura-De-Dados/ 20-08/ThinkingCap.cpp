//Arquivo de implementação dos métodos
#include "ThinkingCap.h"
#include <iostream>
using namespace std;

bool ThinkingCap::slots(string newLeft, string newRight){
    //guarda as duas strings passadas pelos parâmetros
    //nos campos de dados
    if(newLeft.length() < 5 || newRight.length() < 5){
        cout << "String muito curta! Informe novo valor!"<<endl;
        return false;
    }
    leftString = newLeft;
    rightString = newRight;
    return true;
}

void ThinkingCap::pressLeft(){
    //quando acionado, imprime o conteúdo do campo
    //de dados leftString na tela
    cout << leftString << endl;
}

void ThinkingCap::pressRight(){
    //quando acionado, imprime o conteúdoo do campo
    //de dados rightString na tela
    cout << rightString << endl;
}
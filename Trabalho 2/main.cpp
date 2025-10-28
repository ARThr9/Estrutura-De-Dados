// Trabalho 2 - Estrutura de Dados
// Alunos: Arthur Bis Rodrigues (2295221), Gabriel Foresti ( ), Murilo Garibaldi (2297370), Richard Fernandes (2296253)

#include "BT.h"
using namespace std;

int main(){
    BinaryTree arvore;
    arvore.BuildFileTree("exemplo2.tree");
    arvore.imprimirSaida();

    return 0;
}
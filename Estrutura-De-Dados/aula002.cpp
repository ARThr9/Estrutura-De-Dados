// Revisão: ponteiros, alocação dinamica, structs
#include <iostream>
#include <string>
using namespace std;

struct funcionario {
    int id;
    int idade;
    double salario;
};

typedef struct funcionario funcionario; // opcional, mas é bom utilizar

int main() {
    // funcionario func1, func2; // referecia direta 
    // func1.id = 1;
    // func1.idade = 33;
    // func1.salario = 1000.00;
    
    // func2 = func1;
    // func1.salario = func1.salario * 1.1; 

    int n;
    cout << "Informe a quantidade de funcionários da sua empresa: ";
    cin >> n;

    funcionario *p;
    p = new funcionario[n]; // alocação dinâmica de memória para n funcionários
    // se não houver espaço na heap, o new retorna NULL, ou seja, a alocação falhou
    if (p == nullptr) abort(); // verifica se a alocação foi bem sucedida

    for (int i = 0; i < n; i++) {
        p[i].id = 100 + i; 
        
    }

    delete[] p; // desaloca a memória alocada para p

    funcionario *q;
    q = new funcionario;
    q -> id = 200; // notação muito comum para acessar membros de structs através de ponteiros

    delete q; // desaloca a memória alocada para q

    return 0;
}
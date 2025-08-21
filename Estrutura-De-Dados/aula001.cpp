// Relembrando

#include <iostream>
using namespace std;

// sub-algoritmo
// função: retorna um único valor
float divisao(float x, float y) {
    return x / y;
}

// procedimento: não retorna valor



int main() {

    float x, y;
    cout << "Informe o primeiro valor: ";
    cin >> x;

    cout << "Informe o segundo valor: ";
    cin >> y;
    float resultado = divisao(x, y);
    cout << "O resultado da divisão desses números é: " << resultado << endl;

    const int tam = 10;
    int vet1[tam];
    // 1- vetores são estruturas contíguas e homogêneas
    // 2- vetores são sempre passados como referência para os sub-algoritmos
    // 3- ve1 é um ponteiro para o primeiro elemento do vetor vet1[0]
    // 4- o vetor é endereçado a partir da posição 0 até n-1 (0...9)
    return 0;
}
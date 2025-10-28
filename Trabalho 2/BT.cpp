// Trabalho 2 - Estrutura de Dados
// Alunos: Arthur Bis Rodrigues (2295221), Gabriel Foresti ( ), Murilo Garibaldi (2297370), Richard Fernandes (2296253)

#include "BT.h"
using namespace std;

// Construtor e Destrutor

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    clear();
}

// Verifica se a árvore está vazia

bool BinaryTree::empty() {
    return root == NULL;
}

// Libera toda a memória da árvore

void BinaryTree::clear() {
    clear(root);
    root = NULL;
}

// Libera recursivamente os nós

void BinaryTree::clear(TreePointer &t) {
    if (t != NULL) {
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
        t = NULL;
    }
}

// Busca recursivamente por um nó com a chave 'chaveBusca'.
BinaryTree::TreePointer BinaryTree::buscar(TreePointer &t, TreeEntry chaveBusca) {
    if (t == NULL) return NULL;
    if (t->entry == chaveBusca) return t;

    TreePointer esq = buscar(t->leftNode, chaveBusca);
    if (esq != NULL) return esq;

    return buscar(t->rightNode, chaveBusca);
}

void BinaryTree::BuildFileTree(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << fileName << endl;
        return;
    }

    string chavePai, chaveEsq, chaveDir;
    while (file >> chavePai >> chaveEsq >> chaveDir) {
        // Fim da entrada
        if (chavePai == "X" && chaveEsq == "X" && chaveDir == "X") break;
            
        // Caso a árvore ainda esteja vazia (primeira linha)
        if (root == NULL) {
            root = new TreeNode(chavePai);
            if (chaveEsq != "X")
                root->leftNode = new TreeNode(chaveEsq);
                     
            if (chaveDir != "X")
                root->rightNode = new TreeNode(chaveDir);
        } else {
            // Busca o nó pai
            TreePointer pai =  buscar(root, chavePai);
            if (pai != NULL) {
                if (chaveEsq != "X" && pai->leftNode == NULL)
                    pai->leftNode = new TreeNode(chaveEsq);
                if (chaveDir != "X" && pai->rightNode == NULL)
                    pai->rightNode = new TreeNode(chaveDir);
            }
        }
    }

    file.close();
}

// Conta o número total de nós

int BinaryTree::contarNos(TreePointer &t) {
    if (t == NULL) return 0;
    return 1 + contarNos(t->leftNode) + contarNos(t->rightNode);
}

// Conta o número total de folhas
int BinaryTree::contarFolhas(TreePointer &t) {
    if (t == NULL) return 0;
    if (t->leftNode == NULL && t->rightNode == NULL)
        return 1;
    return contarFolhas(t->leftNode) + contarFolhas(t->rightNode);
}

// Impressão recursiva formatada (pré-ordem)
void BinaryTree:: preOrdem(TreePointer &t) {
    if (t == NULL) return;

    int filhos = 0;
    string tipoFilhos = "";

    if (t->leftNode != NULL) {
        filhos++;
        tipoFilhos += "E";
    }
    if (t->rightNode != NULL) {
        filhos++;
        tipoFilhos += "D";
    }
    if (filhos == 0)
        tipoFilhos = "F";

    cout << t->entry << " " << filhos << " " << tipoFilhos << endl;

     preOrdem(t->leftNode);
     preOrdem(t->rightNode);
}

// Função principal para imprimir a saída

void BinaryTree::imprimirSaida() {
     preOrdem(root);
    cout << contarNos(root) << " " << contarFolhas(root) << endl;
}

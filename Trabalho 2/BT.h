// Trabalho 2 - Estrutura de Dados
// Alunos: Arthur Bis Rodrigues (2295221), Gabriel Foresti ( ), Murilo Garibaldi ( ), Richard Fernandes ( )

#ifndef BT_H
#define BT_H
#include <string>  
#include <fstream> 
#include <iostream>

// O PDF especifica que as chaves são strings (ex: "A1", "S1")
typedef std::string TreeEntry;

class BinaryTree{
    public:
        // Construtor. Inicializa a árvore como vazia.
        BinaryTree();

        // Destrutor. Libera toda a memória alocada.
        ~BinaryTree();

        // Verifica se a árvore está vazia.
        bool empty();

        // Libera toda a memória da árvore.
        void clear();

        // Função pública principal para construir a árvore a partir do arquivo.
        void BuildFileTree(std::string fileName);

        // Função pública principal para imprimir a saída formatada.
        void imprimirSaida();

    
    private:
        struct TreeNode; // Declaração da struct do nó
        typedef TreeNode* TreePointer; // "Apelido" para o ponteiro do nó

        struct TreeNode{
            TreeEntry entry; // O dado (chave, ex: "A1")
            TreePointer leftNode; // Ponteiro para o filho esquerdo
            TreePointer rightNode; // Ponteiro para o filho direito

            // Construtor do TreeNode para facilitar a alocação dinâmica.
            TreeNode(TreeEntry valor) {
                entry = valor;
                leftNode = NULL;
                rightNode = NULL;
            }
        };
        
        TreePointer root; // O único dado que a classe armazena

        // --- Funções Auxiliares Recursivas ---

        // Busca recursivamente por um nó com a chave 'chaveBusca'.
        TreePointer search(TreePointer &t, TreeEntry chaveBusca);

        // Imprime recursivamente os dados em pré-ordem no formato do trabalho.
        void preOrdem(TreePointer &t);

        // Conta o número total de nós na árvore recursivamente.
        int contarNos(TreePointer &t);

        // Conta o número total de folhas (nós sem filhos) recursivamente.
        int contarFolhas(TreePointer &t);

        // Libera a memória da árvore recursivamente (em pós-ordem).
        void clear(TreePointer &t);
};

#endif
#include <string>
#ifndef BST_H
#define BST_H

typedef char TreeEntry;

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool empty();
        bool full();
        void print();
        void clear();

        int nodes(); //Número de nós
        int leaves(); //Número de folhas
        int height(); //Altura da árvore
        void preOrdem(); // processa raíz antes de processar esquerda e direita
        
        void emOrdem();  //processa raíz entre esquerda e direita
        void posOrdem(); //processa raíz depois de processar esquerda e direita
        
        void insert(TreeEntry x);
        
    private:
        struct TreeNode;
        typedef TreeNode* TreePointer;

        struct TreeNode{
            TreeEntry entry;
            TreePointer leftNode, rightNode;
        };
        
        TreePointer root;

        void print(TreePointer &t, int s);
        int nodes(TreePointer &t);
        int leaves(TreePointer &t);
        int height(TreePointer &t);
        void preOrdem(TreePointer &t);
        void emOrdem(TreePointer &t);
        void posOrdem(TreePointer &t);
        void clear(TreePointer &t);
};

#endif
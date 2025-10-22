#include <string>
#ifndef BT_H
#define BT_H

typedef char TreeEntry;

class BinaryTree{
    public:
        BinaryTree();
        ~BinaryTree();
        bool empty();
        bool full();
        void print();
        int nodes(); //Número de nós
        int leaves(); //Número de folhas
        int height(); //Altura da árvore
        void preOrdem(); // processa raíz antes de processar esquerda e direita
        /*
        void emOrdem();  //processa raíz entre esquerda e direita
        void posOrdem(); //processa raíz depois de processar esquerda e direita
        */
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
};

#endif
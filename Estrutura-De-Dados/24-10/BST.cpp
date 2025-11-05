#include "BST.h"
#include <iostream>
#include <iomanip>
using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    clear();
}

void BinarySearchTree::clear(){
    clear(root);
    root = NULL;
}

void BinarySearchTree::clear(TreePointer &t){ 
    // em pós ordem, se não perde a referência da raíz e precisa usar ponteiro auxiliar
    if(t != NULL){
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
    }
}

bool BinarySearchTree::empty(){
    return root == NULL;
}

bool BinarySearchTree::full(){
    return false; //não é possível garantir neste momento > estrutura dinâmica!
}

void BinarySearchTree::print(){
    print(root, 0);
}

void BinarySearchTree::print(TreePointer &t, int s){
    int i;
    if(t != NULL){
        print(t->rightNode, s+3); //escreve subarvore direita
        
        for(i = 1; i <= s; i++){
            cout << " ";
        }

        cout << setw(6) << t->entry <<endl;//escreve raiz
        print(t->leftNode, s+3);//escreve subarvore esquerda
    }
}

int BinarySearchTree::nodes(){
    return nodes(root);
}

int BinarySearchTree::nodes(TreePointer &t) {
    if(t == NULL) return 0;

    return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}

int BinarySearchTree::leaves(){
    return leaves(root);
}

int BinarySearchTree::leaves(TreePointer &t){
    if(t == NULL) return 0;
    if(t->leftNode == NULL && t->rightNode == NULL) return 1;

    return leaves(t->leftNode) + leaves(t->rightNode);

}

int BinarySearchTree::height(){
    return height(root);
}

int BinarySearchTree::height(TreePointer &t){
    if(t ==  NULL) return -1;
    int L, R;
    L = height(t->leftNode);
    R = height(t->rightNode);
    if(L > R) return L + 1; else return R + 1;
}

void BinarySearchTree::preOrdem(){
    preOrdem(root);
}

void BinarySearchTree::preOrdem(TreePointer &t){
    if(t == NULL) return;
    cout << t->entry << " ";
    preOrdem(t->leftNode);
    preOrdem(t->rightNode);
    
}

void BinarySearchTree::emOrdem(){
    emOrdem(root);
}

void BinarySearchTree::emOrdem(TreePointer &t){
    if (t == NULL) return;
    emOrdem(t->leftNode);
    cout << t->entry << " ";
    emOrdem(t->rightNode);

}

void BinarySearchTree::insert(TreeEntry x){
    TreePointer p, q , r;
    // Iniciar ponteiros
    p = NULL;
    q = root;

    // laço de posicionamento dos ponteiros
    while(q != NULL){
        p = q;
        if(x < q->entry) q = q->leftNode;
        if(x > q->entry) q = q->rightNode;
    }
    // alocação dinâmica e inicialização do novo nó
    r = new TreeNode;
    if(r == NULL) abort();
    r->entry = x;
    r->leftNode = r->rightNode = NULL;

    // Encadeamento do nó
    if(p == NULL) root = r; // nesse caso daria pra usar root == NULL
    if(p != NULL){
        if(x < p->entry) p->leftNode = r;
        if(x > p->entry) p->rightNode = r;
    }
}

TreeEntry BinarySearchTree::minimum(){
    if(root == NULL){
        cout << "Árvore vazia!" << endl;
        abort(); // INT_MIN também pode ser usado
    }
    return minimum(root);
}

TreeEntry BinarySearchTree::minimum(TreePointer &t){
    while(t->leftNode != NULL)
        t = t->leftNode;
    
    return t->entry;
}

TreeEntry BinarySearchTree::maximum(){
    if(root == NULL){
        cout << "Árvore vazia!" << endl;
        abort(); // INT_MIN também pode ser usado
    }
    return maximum(root);
}

TreeEntry BinarySearchTree::maximum(TreePointer &t){
    while(t->rightNode != NULL)
        t = t->rightNode;
    
    return t->entry;
}

bool BinarySearchTree::search(TreeEntry x){
    return iSearch(x);
}

// Se for fazer de maneira recursiva:
bool BinarySearchTree::iSearch(TreeEntry x){
    TreePointer t = root;
    while(t->entry != x && t != NULL){
        if(x < t->entry)
            t = t->leftNode;
        
        else // if(x >= t->entry)
            t = t->rightNode;
    }
    return t != NULL;
}

bool BinarySearchTree::remove(TreeEntry x){
    return remove(x, root);
}

bool BinarySearchTree::remove(TreeEntry x, TreePointer &p){
    // Casos de Remoção:
    // A } quando o nó x tem no máximo uma das subárvores 
    // B } quando o nó x tem no máximo uma das subárvores 
    // C } quando o nó x tem as duas subárvores
    // -> C1 / C2 (XOR) C1: Sucessor C2: Predecessor/Antecessor

    if(p == NULL) return false; // árvore vazia ou nó não encontrado

    // x < p->entry tentar a remoção na subárvore esquerda
    if(x < p->entry) return remove(x, p->leftNode);
    // x > p->entry tentar a remoção na subárvore direita
    if(x > p->entry) return remove(x, p->rightNode);

    else{
        // elemento econtrado. prosseguir com a remoção
        TreePointer q;
        q = p;
        if(q->leftNode == NULL)         // Caso A
            p = q->rightNode;
        else{ 
            if(q->rightNode == NULL)    //Caso B
                p = q->leftNode;
            else{                       //Caso C
                removeMin(q, q->rightNode);
            }
        }
        delete q;
        return true;
    }
}

void BinarySearchTree::removeMin(TreePointer &q, TreePointer &r){
    if(r->leftNode != NULL)
        removeMin(q, r->leftNode);
    else{
        q->entry = r->entry;
        q = r;
        r = r->rightNode;
    }
}
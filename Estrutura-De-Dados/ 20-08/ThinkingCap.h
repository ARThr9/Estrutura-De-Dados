//Arquivo de definição
//Arquivo de interface
#include <string>
using namespace std;

#ifndef THINKINGCAP_H
#define THINKINGCAP_H
class ThinkingCap{
    //Aqui definimos os atributos (campos de dados)
    //E os métodos (ações/funções) da classe Thinking Cap
    public://permite com que qualquer usuário faça uso
        bool slots(string newLeft, string newRight);
        void pressLeft();
        void pressRight();
    private://restringe modificações de usuários externos ao objeto
        string leftString;
        string rightString;
};
#endif




// class ThinkingCapAdvanced{
//     //exemplo de declaração de outras classes no mesmo arquivo

// };
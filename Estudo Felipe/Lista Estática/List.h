#ifndef LIST_H
#define LIST_H
typedef int ListEntry;

class List{
    public:
        List();
        ~List();
        bool empty();
        bool full();
        void insert(int p, ListEntry x); // p é a posição onde o elemento x será inserido
        void remove(int p, ListEntry &x); // p é a posição do elemento a ser removido
        void clear();
        int size();
        void retrieve(int p, ListEntry &x); // p é a posição do elemento a ser recuperado
        void replace(int p, ListEntry x); // p é a posição do elemento a ser substituído

    private:
        static const int MaxList = 100;
        ListEntry entry[MaxList + 1];
        int count;

};


#endif
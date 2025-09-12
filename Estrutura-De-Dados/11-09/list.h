#ifndef LIST_H
#define LIST_H
typedef int ListEntry;
class List{
   public:
      List();
      ~List(); // desnecessário na lista estática
      bool full();
      bool empty();
      void insert(int p, ListEntry x);
      void remove(int p, ListEntry &x);
      int size();
      void clear();
      void retrieve(int p, ListEntry &x); // recupera um elemento da lista na posição desejada
      void replace(int p, ListEntry x); // substitui um elemento da lista

   private:
      static const int MaxList = 100;
      ListEntry entry[MaxList + 1];
      int count;

};


#endif
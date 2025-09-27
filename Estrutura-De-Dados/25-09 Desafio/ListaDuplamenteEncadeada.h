// Lista Duplamente Encadeada Circular
#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

typedef int ListEntry;
class ListaDuplamenteEncadeada{
   public:
      ListaDuplamenteEncadeada();
      ~ListaDuplamenteEncadeada();
      bool empty();
      bool full();
      void insert(ListEntry x);
      bool remove(ListEntry x); // informa por cópia e usa bool para informar se removeu ou não, retornando true ou false
      void clear();
      int search(ListEntry x);
      bool breakList(int q, ListaDuplamenteEncadeada &newList);
   private:
      struct ListNode;
      typedef ListNode* ListPointer;
      struct ListNode{
         ListEntry entry;
         ListPointer nextNode;
         ListPointer prevNode;
      };
      int count;
      ListPointer head;
};
#endif
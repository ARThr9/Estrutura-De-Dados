#ifndef ORDERLIST_H
#define ORDERLIST_H

typedef int ListEntry;
class OrderList{
   public:
      OrderList();
      ~OrderList();
      bool empty();
      bool full();
      void insert(ListEntry x);
      bool remove(ListEntry x); // informa por cópia
      void clear();
      int search(ListEntry x);

   private:
      struct ListNode;
      typedef ListNode* ListPointer;
      struct ListNode{
         ListEntry entry;
         ListPointer nextNode;
      };
      int count;
      ListPointer head, sentinel; // sentinel é o nó que será empre o último elemento. Sentinel tem que ficar disponível o tempo todo

};

#endif
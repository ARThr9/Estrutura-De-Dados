#ifndef ORDERLIST_H
#define ORDERLIST_H
typedef int ListEntry;

class OrderList{
    public:
        OrderList();
        ~OrderList();
        bool full();
        bool empty();
        void clear();
        void insert(ListEntry x);
        bool remove(ListEntry x); // esse é passado por cópia e não por referência como nos outros
        int search(ListEntry x);

    private:
        struct ListNode;
        typedef ListNode* ListPointer;
        struct ListNode{
            ListEntry entry;
            ListPointer nextNode;
        };
        int count;
        ListPointer head, sentinel;

};


#endif
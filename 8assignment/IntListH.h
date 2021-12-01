#ifndef INTLIST_H
#define INTLIST_H

class IntList
{
private:
    struct ListNode
    {
        int value;
        struct ListNode* next;
    };

    ListNode* head;

public:
    IntList();
    IntList(const IntList&);
    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    void displayList();
    int sumlist();
    ~IntList();
};
#endif // INTLIST_H

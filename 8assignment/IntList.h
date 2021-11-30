#ifndef IntList_h
#define IntList_h

class Intlist
{
  private:
    struct listNode
    {
      double value;
      struct listNode *next;
    };

    listNode *head;

  public:
    Intlist();
    Intlist(Intlist&);

    void appendNode(double a);
    void insertNode(double a);
    void deleteNode(double a);
    void displayList();
    double sumList();

    ~Intlist();


};
#endif

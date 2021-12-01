#ifndef IntList_h
#define IntList_h

//the name of the class.
class Intlist
{
  private:
    
    //the actualy structure that powers the whole thing.
    struct listNode
    {
      int value;
      struct listNode *next;
    };
    
    //the thing that holds everything.
    listNode *head;

  public:
    
    //the two constructors that i used
    Intlist();
    Intlist(Intlist&);
    
    //destructor 
    ~Intlist();

    //member functions that do stuff
    void appendNode(int a);
    void insertNode(int a);
    void deleteNode(int a);
    void displayList() const;
    int sumList();

    


};
#endif

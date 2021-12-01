#include "IntList.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    IntList list;

    list.appendNode(2);
    list.appendNode(4);
    list.appendNode(6);
    list.appendNode(8);
    list.displayList();
    cout << endl;

    list.insertNode(5);
    list.displayList();
    cout << endl;

    list.deleteNode(5);
    list.displayList();
    cout << endl;

    cout << list.sumlist() << endl;

    IntList list2(list);
    list2.displayList();

}

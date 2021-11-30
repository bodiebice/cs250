#include <iostream>
#include <iomanip>
#include "IntList.h"
using namespace std;

int main()
{
  Intlist test1;
  double test;

  test1.appendNode(4);
  test1.appendNode(5);
  test1.displayList();

  Intlist test2(test1);

  test2.insertNode(1);
  test2.displayList();
  test = test2.sumList();
  cout<<test<<endl;
  test = 0;
  test2.deleteNode(5);
  test = test2.sumList();
  cout<<test<<endl;
  //test2.~Intlist();
  //test1.~Intlist();

  return 0;
}
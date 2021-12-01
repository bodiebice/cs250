#include <iostream>
#include "IntList.h"
using namespace std;

//basic constructor, makes the head initialized to nothing
Intlist::Intlist()
{
  head = NULL;
}
//constructor that copies over a totally seperate Intlist object into the new object.
Intlist::Intlist(Intlist& a)
{
  head = a.head;
}
//this appends nodes, or it takes a value and puts it into a new node at the end of the linked list of nodes
void Intlist::appendNode(int a)
{
  listNode *newNode = NULL;
  listNode *nodePtr = NULL;

  newNode = new listNode;
  newNode->value = a;
  newNode->next = NULL;

  if (!head)
  {
    head = newNode;
  }
  else
  {
    nodePtr=head;
    while(nodePtr->next)
      nodePtr=nodePtr->next;
    
    nodePtr->next = newNode;
  } 
}
// this will insert a node (when the linked list is sorted) numerically in order.
void Intlist::insertNode(int a)
{
  listNode *newNode = NULL;
  listNode *nodePtr = NULL;
  listNode *previousNode = NULL;

  newNode = new listNode;
  newNode->value = a;

  if (!head)
  {
    head = newNode;
    newNode->next = NULL;
  }
  else
  {
    nodePtr = head;
    previousNode = NULL;
    while (nodePtr != NULL && nodePtr->value < a)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    if (previousNode == NULL)
    {
      head = newNode;
      newNode->next = nodePtr;
    }
    else
    {
      previousNode->next = newNode;
      newNode->next = nodePtr;
    }
  }
}
//this will search a list and delete a node specified by the double a that is put into
void Intlist::deleteNode(int a)
{
  listNode *nodePtr = NULL;
  listNode *previousNode = NULL;

  if(!head)
    return;

  if (head->value == a)
  {
    nodePtr = head->next;
    delete head;
    head = nodePtr;
  }
  else
  {
    nodePtr = head;
    
    while (nodePtr != NULL && nodePtr->value != a)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }

    if (nodePtr)
    {
      previousNode->next = nodePtr->next;
      delete nodePtr;
    }
  }
}

void Intlist::displayList() const
{
  listNode *nodePtr = NULL;
  nodePtr = head;
  cout<<"Here are the values in this linked list"<<endl;
  while (nodePtr)
  {
    cout<<nodePtr->value<<endl;
    nodePtr = nodePtr->next;
  }
}

int Intlist::sumList()
{
  listNode *nodePtr = NULL;
  nodePtr = head;
  int sum = 0;

  while(nodePtr)
  {
    sum = sum+nodePtr->value;
    nodePtr = nodePtr->next;
  }
  return sum;
}

Intlist::~Intlist()
{
  listNode *nodePtr = NULL;
  listNode *nextNode = NULL;

  nodePtr = head;

  while (nodePtr != NULL)
  {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
}


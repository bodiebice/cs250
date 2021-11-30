#include <iostream>
#include <iomanip>
#include "IntList.h"
using namespace std;

Intlist::Intlist()
{
  head = nullptr;
}

Intlist::Intlist(Intlist& a)
{
  listNode *nodePtra;
  listNode *newNode;
  listNode *nodePtr;

  nodePtra = a.head;
  double ab;
  while (nodePtra != nullptr)
  {
    nodePtra = nodePtra->next;
    newNode = nodePtra;
  
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
}

void Intlist::appendNode(double a)
{
  listNode *newNode;
  listNode *nodePtr;

  newNode = new listNode;
  newNode->value = a;

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

void Intlist::insertNode(double a)
{
  listNode *newNode;
  listNode *nodePtr;
  listNode *previousNode = nullptr;

  newNode = new listNode;
  newNode->value = a;

  if (!head)
  {
    head = newNode;
    newNode->next = nullptr;
  }
  else
  {
    nodePtr = head;
    previousNode = nullptr;
    while (nodePtr != nullptr && nodePtr->value < a)
    {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    if (previousNode == nullptr)
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

void Intlist::deleteNode(double a)
{
  listNode *nodePtr;
  listNode *previousNode;

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
    
    while (nodePtr != nullptr && nodePtr->value != a)
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

void Intlist::displayList()
{
  listNode *nodePtr;
  nodePtr = head;
  cout<<"Here are the values in this linked list"<<endl;
  while (nodePtr)
  {
    cout<<nodePtr->value<<endl;
    nodePtr = nodePtr->next;
  }
}

double Intlist::sumList()
{
  listNode *nodePtr;
  nodePtr = head;
  double sum;

  while(nodePtr)
  {
    sum = sum+nodePtr->value;
    nodePtr = nodePtr->next;
  }
  return sum;
}

Intlist::~Intlist()
{
  listNode *nodePtr;
  listNode *nextNode;

  nodePtr = head;

  while (nodePtr != nullptr)
  {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
}


#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
  public:
    LinkedList();
    LinkedList(int*, int);
    ~LinkedList();

    void insertPosition(int, int);
    bool deletePosition(int);

    int get(int);
    int search(int);
    void printList();
    
  private:
    Node *head;
};

#endif

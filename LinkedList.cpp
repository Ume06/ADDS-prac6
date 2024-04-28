#include <iostream>
#include "LinkedList.h"
#include "Node.h"
LinkedList::LinkedList() {
  head = nullptr;
}
LinkedList::LinkedList(int* array, int len) {
  Node* temp = new Node(array[len-1]);

  for (int i = len - 2; i >= 0; i--) {
    temp = new Node(array[i], temp);
  }

  head = temp;
}
 LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
      Node* victim = temp;
      temp = temp->getLink();
      delete victim;
    }
    delete head;
}

void LinkedList::printList() {
  Node* temp = head;
  std::cout << "[";
  while (temp != nullptr) {
    std::cout << temp->getVal();
    temp = temp->getLink();
    if (temp != nullptr) {
      std::cout << " ";
    }
  }
  std::cout << "]" << std::endl;
}

void LinkedList::insertPosition(int pos, int newNum) {
  Node* temp = head;
  while (pos > 2 && temp != nullptr) { // -2 because indexing starts at 1
    temp = temp->getLink();
    pos--;
  }
  temp->setLink(new Node(newNum, temp->getLink()));
}

bool LinkedList::deletePosition(int pos) {
  Node* temp = head;
  while (pos > 2 && temp != nullptr) {
    temp = temp->getLink();
    pos--;
  }
  if (temp == nullptr)
    return false;
  temp->setLink(temp->getLink()->getLink());
}
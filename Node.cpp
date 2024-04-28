#include "Node.h"
#include <iostream>

Node::Node() {
  data = 0;
  link = nullptr;
}

Node::Node(int d) {
  data = d;
  link = nullptr;
}

Node::Node(int d, Node *n) {
  data = d;
  link = n;
}

void Node::setLink(Node *n) {
  link = n;
}

void Node::setVal(int d) {
  data = d;
}

Node *Node::getLink() {
  return link;
}

int Node::getVal() {
  return data;
}

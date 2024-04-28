#include "Node.h"

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
#ifndef NODE_H
#define NODE_H

class Node {
  public:
    Node();
    Node(int);
    Node(int, Node*);
  private:
    int data;
    Node* link;
};

#endif
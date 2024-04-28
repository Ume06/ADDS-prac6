#ifndef NODE_H
#define NODE_H

class Node {
  public:
    Node();
    Node(int);
    Node(int, Node*);

    void setVal(int);
    void setLink(Node*);

    int getVal();
    Node* getLink();
    
  private:
    int data;
    Node* link;
};

#endif
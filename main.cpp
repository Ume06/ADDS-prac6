#include "LinkedList.H"

int main() {

  int x[5] = {1, 2, 3, 4, 5};
  LinkedList list(x, 5);
  list.printList();
  list.insertPosition(3, 0);
  list.printList();
  bool z = list.deletePosition(3);
  if (z) list.printList();
  bool y = list.deletePosition(7);
  if (y) list.printList();
}
#include "LinkedList.H"
#include <iostream>
int main() {

  int x[5] = {1, 2, 3, 4, 7};
  LinkedList list(x, 5);
  list.printList();
  std::cout << list.get(6) << std::endl;
  std::cout << list.search(9) << std::endl;
}
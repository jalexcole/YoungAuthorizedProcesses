#include "LinkedList.hpp"


T LinkedList::get(int index) {
  if (index < size()) {

  }
}

int LinkedList::size() {
  int size = 0;

  if (head != nullptr) {
    size++;
    Node* currentNode = &head
    if (currentNode.hasNext()) {
      size++
      currentNode = currentNode.next();
    }

    return size();
  } else return size;
}
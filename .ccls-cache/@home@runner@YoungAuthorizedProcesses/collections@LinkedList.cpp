#include "LinkedList.hpp"

template <typename T>
T LinkedList<T>::get(int index) {
  if (index < size()) {

  }
}

template <typename T>
int LinkedList<T>::size() {
  int size = 0;

  if (head != nullptr) {
    size++;
    Node<T>* currentNode = head;
    if (currentNode->hasNext()) {
      size++;
      currentNode = currentNode->next();
    }

    return size;
  } else return size;
}
#pragma once

#include "IComparable.hpp"


template<typename T: public IComparable<T>>
class OrderedLinkedList {
  public:
    Node<T> head;

    OrderedLinkedList();
    ~OrderedLinkedList(); 
    int size();
    T[] toArray();
  private:
    void order();
};

template<typename T>
inline T[] OrderedLinkedList::toArray() {
  T listArray[size()];

  listArray[0] = head.element;

  Node<T>* node = head.next();
  for (int i = 1; i < size(); i++) {
    listArray[i] = node->element

    if (node->hasNext) {
      node = node->next
    } else {
      return listArray;
    }
  }

  return listArray;
}

template<typename T: public IComparable>
inline void OrderedLinkedList<T>::order() {
  bool sorted = false;

  Node<T>* node1;
  Node<T>* node2;
  while (!sorted) {
    for (int i = 0; i < size(); i++) {

    }
  }
}

template<typename T: public IComparable>
class Node {
  public:
    T element;
    Node<T>* nextNode;

    Node() {
      nextNode = nullptr;
    }

    Node (T t) {
      element = t;
      nextNode = nullptr;
    }

    ~Node() {
      
    }

    Node<T> next();
    bool hasNext();
};

template<typename T>
inline bool Node<T>::hasNext() {
  return nextNode != nullptr;
}

template<typename T>
Node<T> Node<T>::next() {
  return nextNode;
}

template <typename T>
int OrderedLinkedList<T>::size() {
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
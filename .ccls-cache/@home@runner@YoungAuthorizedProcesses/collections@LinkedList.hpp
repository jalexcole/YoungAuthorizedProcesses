#pragma once

#include "Node.hpp"

template<typename T>
class LinkedList {
  Node<T> head;

  public:
    LinkedList() {
      head = nullptr;
    }
    ~LinkedList();

    T get(int index);
    bool insert(T item, int index);
    int size();
    bool remove(T item);
};

template <typename T>
T& LinkedList<T>::get(int index) {
  if (index < size()) {
    Node* node = &head;
    if (head != nullptr) {

    }
  }
}

template <typename T>
bool LinkedList<T>::insert(T item, int index) {
  newNode = new Node(item);
  Node* current = &head;
  Node* previous = nullptr;

  while (current != nullptr && &item > index->&item) {
    previous = current;
    current = current->next();
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


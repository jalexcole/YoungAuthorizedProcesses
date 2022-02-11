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




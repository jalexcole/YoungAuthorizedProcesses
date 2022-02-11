#pragma once

#include "Node.hpp"

template<typename T>
class LinkedList {
  Node<T> head;

  public:
    LinkedList() {
      Node<T>* head = nullptr;
    }
    ~LinkedList();

    T get(int index);
    bool insert(T item);
    int size();
    bool remove(T item);
};

// template <typename T>
// T& LinkedList<T>::get(int index) {
//   if (index < size()) {
//     Node* node = &head;
//     if (head != nullptr) {

//     }
//   }

//   return head.&T;
// }

template <typename T>
bool LinkedList<T>::insert(T item) {
  Node<T>* newNode = new Node<T>(item);
  Node<T>* current = head;
  Node<T>* previous = nullptr;


  bool inserted = false; 
  while (current != nullptr && current > newNode) {
    previous = current;
    current = current->next();
  }
  
  return inserted;
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

template<typename T>
LinkedList<T>::~LinkedList() {
  
}


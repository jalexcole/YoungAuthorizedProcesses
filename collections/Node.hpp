#pragma once

template<typename T>
class Node {
  public:
    T element;
    Node<T>* nextNode;

    Node() {
      nextNode = nullptr;
    }

    Node(T t) {
      element = t;
      nextNode = nullptr;
    }

    Node<T>* next();
    bool hasNext();
};

template<typename T>
inline bool Node<T>::hasNext() {
  return nextNode != nullptr;
}

template<typename T>
Node<T>* Node<T>::next() {
  return nextNode;
}
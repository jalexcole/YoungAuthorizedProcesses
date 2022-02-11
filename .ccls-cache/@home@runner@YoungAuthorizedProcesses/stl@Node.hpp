#pragma once

template<typename T>
class Node {
  public:
    T element;
    Node<T>* nextNode;

    Node() {
      nextNode = nullptr;
    }

    Node (T t) {
      element = t;
      next = nullptr;
    }

    Node<T> next();
    bool hasNext();
};

inline bool Node::hasNext() {
  return nextNode != nullptr;
}

inline Node<T> Node::next() {
  return nextNode;
}
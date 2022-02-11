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

    ~Node() {
      if (hasNext()) {
        
      }
    }

    Node<T>* next();
    bool hasNext();

    void set(T data);
};

template<typename T>
inline bool Node<T>::hasNext() {
  return nextNode != nullptr;
}

template<typename T>
inline Node<T>* Node<T>::next() {
  return nextNode;
}

template<typename T>
inline void Node<T>::set(T data) {
  Node<T>::element = data;
}
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
      next = nullptr
    }

    Node<T> next();
    bool hasNext();
};

template<typename E>
class IComparable {
  virtual int conpareTo(E e) = 0;
};

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

inline bool Node::hasNext() {
  return nextNode != nullptr;
}

inline Node<T> Node::next() {
  return nextNode;
}

inline T LinkedList::get(int index) {
  if (index < size()) {

  }
}

inline int LinkedList::size() {
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

template<typename T, class IComparable<T>>
class OrderedLinkedList {

};
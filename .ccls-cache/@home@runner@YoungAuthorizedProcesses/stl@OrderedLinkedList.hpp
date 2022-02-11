#pragma once



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
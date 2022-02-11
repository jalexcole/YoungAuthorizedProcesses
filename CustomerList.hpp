#pragma once
#include <list>

#include "Store.h"

class CustomerList {
  std::list<Store*> stores;
  
  public:
    CustomerList();
    ~CustomerList();

    bool addStore(Store* store);
    Store* removeStore(int ID);
    Store* getStore(int ID);
    bool updateStore(int ID, char* name, char* address, char* city, char* street, char* zip);
    void printStoresInfo();
};

template<class T>
class Node {
  private:
    T element;
    Node* next;

  public:
    Node(T);
    ~Node();
    T getElement();
    bool hasNext();

};

class OrderedLinkedList {
  private:
    Node<Store*> head;
};





#pragma once


#include "Store.h"

template<class T>
class Node {
  private:
    T element;
    Node* next;

  public:
    Node();
    Node(T);
    ~Node();
    T getElement();
    bool setElement(T element);
    bool hasNext();
    bool deleteNext();
    Node* getNext();
    void setNext(Node<T>*);
    bool isEmpty();
};

class CustomerList {
  // std::vector<Store*> stores;
  
  Node<Store*>* stores;

  public:
    CustomerList();
    ~CustomerList();

    bool addStore(Store* store);
    Store* removeStore(int ID);
    Store* getStore(int ID);
    bool updateStore(int ID, char* name, char* address, char* city, char* street, char* zip);
    void printStoresInfo();
};







#pragma once
#include <list>

#include "Store.h"
#include "collections/LinkedList.hpp"
class CustomerList {
  std::list<Store>* stores;
  LinkedList<Store>* storeList;
  public:
    CustomerList();
    ~CustomerList();

    bool addStore(Store* store);
    Store* removeStore(int ID);
    Store* getStore(int ID);
    bool updateStore(int ID, char* name, char* address, char* city, char* street, char* zip);
    void printStoresInfo();
};
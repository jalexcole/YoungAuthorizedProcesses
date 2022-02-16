#pragma once


#include "Store.h"

/**
* @brief Create a node for holding an element in a list of elements.
* @author Alex Cole
* @param None type.
* 
*/


class CustomerList {
  // std::vector<Store*> stores;
  private:
    Store* m_pHead; // Head of store list

  public:
    CustomerList();
    ~CustomerList();

    bool addStore(Store* store);
    Store* removeStore(int ID);
    Store* getStore(int ID);
    bool updateStore(int ID, char* name, char* address, char* city, char* street, char* zip);
    void printStoresInfo();
};







#include <iostream>

#include "EmployeeRecord.hpp"
#include "Store.h"
// #include "CustomerList.hpp"

#include <vector>




Store* getmyLast(Store* store) {
  
  if (store == nullptr) {
    return nullptr;
  } else if (store->m_pNext == nullptr) {
    return store;
  }

  while (store->m_pNext != nullptr) {
    store = store->m_pNext;
  }
  return store;
}

int main() {
  std::cout << "Hello World!\n";

  std::vector<Store*> stores;
  // Store* store = new Store();
  for (int i = 0; i < 10; i++) {
    Store* store = new Store();
    store->setStoreID(i);

    stores.push_back(store);
  } 
  Store* head = stores[0];

  for (int i = 0; i < stores.size(); i++) {
     stores[i]->printStoreInfo();
  }

  Store* temp = head;

  for (int i = 1; i < stores.size(); i++) {
    temp->m_pNext = stores[i];
    temp = temp->m_pNext;
  }

  Store* lastStore = getmyLast(head);
  lastStore->printStoreInfo();
}



#include <iostream>
#include <memory>
#include "EmployeeRecord.hpp"
#include "Store.h"
#include "CustomerList.hpp"
#include "EmployeeDatabase.hpp"
#include <vector>
#include <string>
#include <list>

void testEmployeeRecord(void);
void testSotreList(void);
void testEmployeeDatabase(void);
void testStore(void);
void testCustomerList();

Store* getmyLast(Store* store) {
  std::cout << "Getting tail of store list" << std::endl;
  if (store == nullptr) {
    std::cout << "store is a nullptr" << std::endl;
    return nullptr;
  } else if (store->m_pNext == nullptr) {
    std::cout << "Store is a single unit" << std::endl;
    store->printStoreInfo();
    return store;
  } else {
    std::cout << "Entering Recursion" << std::endl;
    return getmyLast(store->m_pNext);
  }

  while (store->m_pNext != nullptr) {
    store = store->m_pNext;
  }
  return store;
}

void testSotreList() {
  std::vector<Store *> stores;
  // Store* store = new Store();
  for (int i = 0; i < 10; i++) {
    Store *store = new Store();
    store->setStoreID(i);

    stores.push_back(store);
  }
  Store *head = stores[0];

  for (int i = 0;  i < (int) stores.size(); i++) {
    stores[i]->printStoreInfo();
  }

  Store *temp = head;

  for (int i = 1; i < (int) stores.size(); i++) {
    temp->m_pNext = stores[i];
    temp = temp->m_pNext;
  }

  Store *lastStore = getmyLast(head);
  lastStore->printStoreInfo();

  for (int i = stores.size(); i > 0; --i) {
    delete stores[i];
  }
}


int main() {
  std::cout << "Hello World!\n";
  // std::cout << "Testing CustomerList" << std::endl;
  // testSotreList();
  // testCustomerList();
  // std::cout << "CustomerList testing complete" << std::endl;

  std::cout << "Testing EmployeeDatabase" << std::endl;
  testEmployeeDatabase();
  
  return 0;
}

void testCustomerList() {
  std::cout << "Constructing Test CustomerList" << std::endl;
  unique_ptr<CustomerList> customerList(new CustomerList);
  std::list<Store*> stores;

  for (int i = 0; i < 10; i++) {
    Store* store = new Store();
    store->setStoreID(i);
    stores.push_back(store);
  }

  while (!stores.empty()) {
    customerList->addStore(stores.front());
    stores.pop_front();
  }
  
  // delete customerList;
}

void testEmployeeDatabase(void) {
  std::cout << "Running Test For Employee DataBase" << std::endl;
  std::string dataFile = "Program3Data.txt";
  unique_ptr<EmployeeDatabase> employeeDatabase(new EmployeeDatabase());
  employeeDatabase->buildDatabase(dataFile.c_str());
  employeeDatabase->printEmployeeDatabase();
  employeeDatabase->getEmployee(0)->printRecord();
  
}

#include "CustomerListTest.hpp"

#include "stdio.h"

void CustomerListTest::before() {
  customerList = new CustomerList();
  store = new Store();
  store->setStoreID(0);
}

void CustomerListTest::addStore() {
  try {
    customerList->addStore(store);
  } catch (const std::exception& e) {
    printf("Failed: CustomerListTest::addStore()\n");
    // printf(e.what());
  }
}

void CustomerListTest::getStore() {
  Store* testStore;
  try {
    testStore = customerList->getStore(0);
  } catch (const std::exception& e) {
    printf("Failed: CustomerListTest::getStore()\n");
    // printf(e.what());
  }
  testStore = nullptr;
}

void CustomerListTest::updateStore() {
  try {
    customerList->updateStore(0, "name", "address", "city", "street", "0000");
  } catch (const std::exception& e) {
    printf("Failed: CustomerListTest::updateStore()\n");
    printf(e.what());
  }
}

void CustomerListTest::removeStore() {
  try {
    customerList->removeStore(0);
  } catch (const std::exception& e) {
    printf("Failed: CustomerListTest::removeStore()\n");
    printf(e.what());
  }
}

void CustomerListTest::after() {
  delete customerList;
  delete store;
}
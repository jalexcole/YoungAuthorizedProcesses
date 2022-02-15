#pragma once

#include "../CustomerList.hpp"

class CustomerListTest {
  CustomerList* customerList;
  Store* store;

  public:
    void before();
    void after();
    void addStore();
    void getStore();
    void updateStore();
    void removeStore();
    
    CustomerListTest() {
      before();
    }
    ~CustomerListTest() {
      after();
    }
};
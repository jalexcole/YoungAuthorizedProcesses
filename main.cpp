#include <iostream>

#include "EmployeeRecord.hpp"
#include "Store.h"
#include "CustomerList.hpp"

#include "test/CustomerListTest.hpp"

void runCustorerListTest(void);

int main() {
  std::cout << "Hello World!\n";

  // EmployeeRecord* employee = new EmployeeRecord();
}

void runCustorerListTest() {
  CustomerListTest* customerListTest = new CustomerListTest();
  customerListTest->addStore();
  customerListTest->getStore();
  customerListTest->updateStore();
  customerListTest->removeStore();
  delete customerListTest;
}
#pragma once
#include <list>

#include "Store.h"
#include "collections/LinkedList.hpp"
class CustomerList {
  std::list<Store> stores;
  LinkedList<Store> storeList;
  public:
    CustomerList();
    ~CustomerList();
};
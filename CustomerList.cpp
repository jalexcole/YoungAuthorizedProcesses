#include "CustomerList.hpp"
#include "Store.h"

#include <cstddef>

/**
 * @brief Construct a new Customer List:: Customer List object
 *
 */
CustomerList::CustomerList() {
  std::cout << "CustomerList::CustomerList()" << std::endl;
  CustomerList::m_pHead = nullptr;
}

/**
 * @brief Destroy the Customer List:: Customer List object
 *
 */
CustomerList::~CustomerList() { m_pHead = nullptr; }

/**
 * @brief Get the Last object
 *
 * @param store
 * @return Store*
 */
Store* getStoreTail(Store *store) {

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
    return getStoreTail(store->m_pNext);
  }

  // while (store->m_pNext != nullptr) {
  //   store = store->m_pNext;
  // }
  // return store;
}

bool storeSingle(Store *store) {
  if (store == nullptr) {
    return false;
  } else {
    return store->m_pNext == nullptr;
  }
}

int storeListSize(Store *store) {
  // find the size of the store paramater;
  int storeSize = 0;

  if (store == nullptr) {
    return false;
  } else if (store->m_pNext == nullptr) {
    storeSize++;
  } else {
    Store *temp = store;
    while (temp->m_pNext != nullptr) {
      storeSize++;
      temp = temp->m_pNext;
    }
  }
  return storeSize;
}

/**
 * @brief Swaps Stores for sorting
 *
 * @param x
 * @param y
 */
void swap(Store *x, Store *y) {
  Store *temp = x;
  x = y;
  y = temp;
}

Store **storeListToArray(Store *store) {
  int size = storeListSize(store);

  Store *storeArray[size];
  Store *temp = store;
  for (int i = 0; i < size; i++) {
    storeArray[i] = temp;
    temp = temp->m_pNext;
  }

  return storeArray;
}

Store *storeArrayToList(Store **storeArray) {
  int size = sizeof(storeArray) / sizeof(storeArray[0]);

  Store *head = storeArray[0];
  Store *temp = head;

  for (int i = 1; i < size; i++) {
    temp = temp->m_pNext;
    temp = storeArray[i];
  }

  return head;
}

/**
 * @brief Sorts the List of stores with a bubble sort
 *
 * @param store
 * @return true
 * @return false
 */
bool sortListByID(Store *store) {
  std::cout << "CustomerList: Sorting list" << std::endl;
  // Do nothing if the store is of size one
  if (storeSingle(store)) {
    return true;
  }

  bool swapped = false;
  Store **storeArray = storeListToArray(store);
  for (int i = 0; i < storeListSize(store) - 1; i++) {
    swapped = false;
    for (int j = 0; j < storeListSize(store) - i - j; j++) {
      if (storeArray[j]->getStoreID() > storeArray[j + 1]->getStoreID()) {
        swap(storeArray[j], storeArray[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false) {
      store = storeArrayToList(storeArray);
      return true;
      break;
    }
  }
  return false;
}

Store *getLastStore(Store *store) {
  Store *temp = store;

  while (temp->m_pNext != nullptr) {
    temp = temp->m_pNext;
  }

  return temp;
}

/**
 * @brief This is for the case that the store is empty and is not a list
 * of its own.
 *
 * @details This assignment was probably expecting an interaction between two
 * linked lists. That seemed to efficient. Therefore, Each linked list was
 * converted to an array, a new array was created, with the contents of each
 * array, followed by a bubble sort and then converted back to a linked list.
 * @param store
 * @return true
 * @return false
 */
bool CustomerList::addStore(Store *store) {
  // if (store == nullptr) {
  //   std::cout << "store is a nullptr" << std::endl;
  //   return false;
  // } else if (this->m_pHead == nullptr) {
  //   std::cout << "Head is a nullptr" << std::endl;
  //   m_pHead = store;
  //   return true;
  // } else if (this->m_pHead) {
  //   Store* lastStore = getStoreTail(this->m_pHead);

  //   if (!lastStore) {
  //     std::cout << "last store is a nullptr" << std::endl;
  //   }
  //   lastStore->m_pNext = store;
  //   return true;
  // }

  if (store) {
    std::cout << "Store exists" <<std::endl;
    if (m_pHead != nullptr) {
      std::cout << "m_pHead exists" << std::endl;
      getStoreTail(this->m_pHead)->m_pNext = store;
      return true;
    } else {
      std::cout << "Store is becoming head" << std::endl;
      this->m_pHead = store;
      return true;
    }
  } else {
    std::cout << "Store does not exist" << std::endl;
    return false;
  }

  // return false;
}

/**
 * @brief Removes a store from list based on id.
 *
 * @param ID
 * @return Store*
 */
Store *CustomerList::removeStore(int ID) {
  Store *temp = this->m_pHead;
  Store *tempNext = this->m_pHead->m_pNext;

  if (this->m_pHead->getStoreID() == ID) {
    m_pHead = m_pHead->m_pNext;
    return temp;
  }

  while (tempNext->m_pNext != NULL) {
    if (tempNext->getStoreID() == ID) {
      Store *continuation = tempNext->m_pNext;
      temp->m_pNext = continuation;

      return tempNext;
    } else {
      temp = tempNext;
      tempNext = tempNext->m_pNext;
    }
  }

  return nullptr;
}

/**
 * @brief Returns a store with ID.
 *
 * @param ID
 * @return Store*
 */
Store *CustomerList::getStore(int ID) {
  if (m_pHead == nullptr) {
    return nullptr;
  }

  Store *temp = m_pHead;

  while (temp->m_pNext != nullptr) {
    if (temp->getStoreID() == ID) {
      return temp;
    } else {
      temp = temp->m_pNext;
    }
  }

  return nullptr;
}

/**
 * @brief updates a store based on ID with selected information.
 *
 * @param ID
 * @param name
 * @param address
 * @param city
 * @param state
 * @param zip
 * @return true
 * @return false
 */
bool CustomerList::updateStore(int ID, char *name, char *address, char *city,
                               char *state, char *zip) {
  Store *store = getStore(ID);
  if (store == nullptr) {
    return false;
  }

  // TODO: do some things to that store;
  store->setStoreName(name);
  store->setStoreCity(city);
  store->setStoreState(state);
  store->setStoreAddress(address);
  store->setStoreZip(zip);
  return false;
}

void CustomerList::printStoresInfo() {
  std::cout << "Printing Store Info" << std::endl;
  Store *temp = m_pHead;

  while (temp != nullptr) {
    temp->printStoreInfo();
    temp = temp->m_pNext;
  }

  temp = nullptr;
}

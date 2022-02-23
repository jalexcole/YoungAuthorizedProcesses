#include "CustomerList.hpp"
#include "Store.h"

#include <cstddef>

/**
 * @brief Construct a new Customer List:: Customer List object
 *
 */
CustomerList::CustomerList() { 
  std::cout << "CustomerList::CustomerList()" << std::endl;
  m_pHead = nullptr; }

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
Store *getLast(Store *store) {

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


bool storeSingle(Store* store) {
  if (store == nullptr) {
    return false;
  } else {
    return store->m_pNext == nullptr;
  }
}

int storeListSize(Store* store) {
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
void swap(Store* x, Store* y) {
    Store* temp = x;
    x = y;
    y = temp;
  }

Store** storeListToArray(Store* store) {
  int size = storeListSize(store);

  Store* storeArray[size];
  Store* temp = store;
  for (int i = 0; i < size; i++) {
    storeArray[i] = temp;
    temp = temp->m_pNext;
  }

  return storeArray;
}

Store* storeArrayToList(Store** storeArray) {
  int size = sizeof(storeArray) / sizeof(storeArray[0]);

  Store* head = storeArray[0];
  Store* temp = head;

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
bool sortListByID(Store* store) {
  std::cout << "CustomerList: Sorting list" << std::endl;
  // Do nothing if the store is of size one
  if (storeSingle(store)) {
    return true;
  }


  bool swapped = false;
  Store** storeArray = storeListToArray(store);
  for (int i = 0; i < storeListSize(store) - 1; i++) {
    swapped = false;
    for (int j = 0; j < storeListSize(store) - i - j; j++) {
      if (storeArray[j]->getStoreID() > storeArray[j+1]->getStoreID()) {
        swap(storeArray[j], storeArray[j+1]);
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

Store* getLastStore(Store* store) {
  Store* temp = store;

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
  std::cout << "Adding store to the customer List" << std::endl;
  store->printStoreInfo();

  // If Store is single add store to current list;
  if (m_pHead == nullptr) {
    std::cout << "Adding store as head of the list" << std::endl;

    m_pHead = store;

    // if (!storeSingle(m_pHead)) {
    //   sortListByID(m_pHead);
    // }
    return true;
  }

  if (storeSingle(store)) {
    std::cout << "Store is single" << std::endl;
    getLastStore(m_pHead)->printStoreInfo();
    getLastStore(m_pHead)->m_pNext = store;

    sortListByID(m_pHead);
    return true;
  } 

  getLast(m_pHead)->m_pNext = store;
  return true;

  // int storeSize = storeListSize(store);

  // Store *storeArray[storeSize];

  // {
  //   Store *temp = store;
  //   for (int i = 0; i < storeSize; i++) {
  //     storeArray[i] = temp;
  //     temp = temp->m_pNext;
  //   }
  // }
  // // Convert this to an array;

  // int thisSize = 0;

  // if (this->m_pHead == NULL) {
  //   m_pHead = store;
  //   return true;
  // } else if (this->m_pHead->m_pNext == NULL) {
  //   thisSize++;
  // } else {
  //   Store *temp = this->m_pHead;
  //   while (temp->m_pNext != NULL) {
  //     thisSize++;
  //     temp = temp->m_pNext;
  //   }
  // }
  // Store *thisArray[thisSize];
  // {
  //   Store *temp = this->m_pHead;
  //   for (int i = 0; i < thisSize; i++) {
  //     thisArray[i] = temp;
  //     temp = temp->m_pNext;
  //   }
  // }

  // Store *outputArray[thisSize + storeSize];

  // for (int i = 0; i < thisSize; i++) {
  //   outputArray[i] = thisArray[i];
  // }

  // for (int i = 0; i < storeSize; i++) {
  //   outputArray[i + thisSize] = storeArray[i];
  // }

  // // Sort array with bubble sort;

  // int n = thisSize + storeSize;
  // bool swapped = false;

  // for (int i = 0; i < n - 1; i++) {
  //   swapped = false;
  //   for (int j = 0; j < n - i - 1; j++) {
  //     if (outputArray[j]->getStoreID() > outputArray[j + 1]->getStoreID()) {
  //       // swap elements
  //       Store *one = outputArray[j];
  //       Store *two = outputArray[j + 1];

  //       outputArray[j] = two;
  //       outputArray[j + 1] = one;

  //       swapped = true;
  //     }
  //   }
  //   if (swapped == false) {
  //     break;
  //   }
  // }

  // Store *newStoreList = outputArray[0];

  // Store *temp = newStoreList;
  // for (int i = 1; i < thisSize + storeSize; i++) {
  //   temp->m_pNext = outputArray[i];
  //   temp = temp->m_pNext;
  // }

  // this->m_pHead = newStoreList;
  // return true;
  // // Case List is empyt

  // if (m_pHead == nullptr) {
  //   m_pHead = store;
  //   return true;

  //   // Case if list is single
  // } else if (m_pHead->m_pNext == nullptr) {
  //   if (store->getStoreID() > m_pHead->getStoreID()) {
  //     m_pHead->m_pNext = store;

  //     return true;
  //   } else {
  //     store->m_pNext = m_pHead;
  //     m_pHead = store;

  //     return true;
  //   }
  // } else {
  //   // If there are multiple elements in the list
  //   Store *temp = m_pHead;
  //   Store *tempNext = m_pHead->m_pNext;

  //   // If the store needs to be listed at the front;
  //   if (store->getStoreID() < temp->getStoreID()) {
  //     store->m_pNext = temp;
  //     m_pHead = store;
  //   }
  //   // If not inserting at the start of the list;
  //   while (tempNext != nullptr) {
  //     if (tempNext->getStoreID() < store->getStoreID()) {
  //       temp = tempNext;
  //       tempNext = tempNext->m_pNext;
  //     } else {
  //       // perform insertion
  //       store->m_pNext = tempNext;
  //       temp->m_pNext = store;
  //       return true;
  //     }
  //   }
  //   // if it is being added at the end of the list
  //   tempNext->m_pNext = store;
  //   return true;
  // }
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

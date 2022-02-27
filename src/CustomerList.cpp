#include "CustomerList.hpp"
#include "Store.h"

#include <cstddef>

#include <memory>
#include <list>

/**
 * Construct a new Customer List:: Customer List object
 *
 */
CustomerList::CustomerList() {
  CustomerList::m_pHead = nullptr;
}

/**
 * Destroy the Customer List:: Customer List object
 * 
 */
CustomerList::~CustomerList() {
  Store* temp = m_pHead;

  while (m_pHead) {
    while(temp->m_pNext) {
      temp = temp->m_pNext;
    }
    delete temp;
    temp = m_pHead;
  }
}

/**
 * @brief Get the Last object
 *
 * @param store
 * @return Store*
 */
Store *getLastStore(Store *store) {
  Store *temp = store;

  while (temp->m_pNext) {
    temp = temp->m_pNext;
  }

  return temp;
}



Store *sort(Store *store) {
  Store *temp = store;
  
  int size = 0;

  Store* index = store;
  while(index->m_pNext) {
    size++;
    index = index->m_pNext;
  }
  
  Store** stores = (Store**) malloc(size * sizeof(Store*));
  
  for (int i = 0; i < size; i++) {
    stores[i] = temp;
    temp = temp->m_pNext;
  }

  for (int i = 0; i < size; i++) {
    stores[i]->m_pNext = nullptr;
  }

  bool sorted = false;
  // bool swapped;

  while (!sorted) {
    bool swapped = false;
    for (int i = 0; i < size; i++) {
      if (i + 1 != size) {
        if (stores[i]->getStoreID() > stores[i+1]->getStoreID()) {
          Store* x = stores[i];
          Store* y = stores[i+1];
          stores[i] = y;
          stores[i+1] = x;
          swapped = true;
        }
      }
    }
    if (!swapped) {
      sorted = true;
    }

  }
  Store* sortedHead = stores[0];
  Store* tempSorted = sortedHead;
  for (int i = 1; i < size; i++) {
    tempSorted->m_pNext = stores[i];
    tempSorted = tempSorted->m_pNext;
  }
  free(stores);
  return sortedHead;
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
  if (store != nullptr) {
    if (m_pHead) {
      getLastStore(m_pHead)->m_pNext = store;
      m_pHead = sort(m_pHead);
      // this->printStoresInfo();
      return true;
    } else {
      this->m_pHead = store;
      return true;
    }
  } else {
    return false;
  }
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
  if (!m_pHead) {
    return nullptr;
  }

  Store *temp = m_pHead;

  while (temp->m_pNext) {
    if (temp->getStoreID() == ID) {
      return temp;
    } else {
      temp = temp->m_pNext;
    }
  }
  return nullptr;
}

/**
 * Updates a store based on ID with selected information.
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
bool CustomerList::updateStore(int ID, char *name, char *address, char *city, char *state, char *zip) {
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
  Store *temp = m_pHead;

  while (temp->m_pNext) {
    temp->printStoreInfo();
    temp = temp->m_pNext;
  }
}

#include "CustomerList.hpp"
#include "Store.h"


CustomerList::CustomerList(void) {
  m_pHead = NULL;
}

CustomerList::~CustomerList() {
  delete m_pHead;
}

bool CustomerList::addStore(Store* store){
  /**
  * @brief This is for the case that the store is empty and is not a list
  *        of its own. A sec
  *
  */
  // Case List is empyt

  
  if (m_pHead == nullptr) {
    m_pHead = store;
    return true;

    // Case if list is single
  } else  if (m_pHead->m_pNext == nullptr) {
    if (store->getStoreID() > m_pHead->getStoreID()) {
      m_pHead->m_pNext = store;

      return true;
    } else {
      store->m_pNext = m_pHead;
      m_pHead = store;

      return true;
    }
  } else {
    // If there are multiple elements in the list
    Store* temp = m_pHead;
    Store* tempNext = m_pHead->m_pNext;

    // If the store needs to be listed at the front;
    if (store->getStoreID() < temp->getStoreID()) {
      store->m_pNext = temp;
      m_pHead = store;
    }
    // If not inserting at the start of the list;
    while(tempNext != nullptr) {
      if(tempNext->getStoreID() < store->getStoreID()) {
        temp = tempNext;
        tempNext = tempNext->m_pNext;
      } else {
        // perform insertion
        store->m_pNext = tempNext;
        temp->m_pNext = store;
        return true;
      }
    }
    // if it is being added at the end of the list
    tempNext->m_pNext = store;
    return true;
  }
  return false;
}

Store* CustomerList::removeStore(int ID) {
  

  return nullptr;
}

Store* CustomerList::getStore(int ID) {
  
  
  return nullptr;
}

bool CustomerList::updateStore(int ID, char* name, char* address, char* city, char* street, char* zip) {
 
 return false;
}

void CustomerList::printStoresInfo() {
  Store* temp = m_pHead;

  while (temp != nullptr) {
    temp->printStoreInfo();
    temp = temp->m_pNext;
  }

  temp = nullptr;

}



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

  // find the size of the store paramater;
  int storeSize = 0;

  if (store == nullptr) {
    // TODO: Flag do nothing
  } else if (store->m_pNext == nullptr) {
    storeSize++;
  } else {
    Store* temp = store;
    while (temp->m_pNext != nullptr) {
      storeSize++;
      temp = temp->m_pNext;
    }
  }

  Store* storeArray[storeSize];

  {
    Store* temp = store;
    for (int i= 0; i < storeSize; i++) {
      storeArray[i] = temp;
      temp = temp->m_pNext;
    }
  }
  // Convert this to an array;

  int thisSize = 0;

  if (this->m_pHead == NULL) {
    // TODO: Flag do nothing
  } else if (this->m_pHead->m_pNext == NULL) {
    thisSize++;
  } else {
    Store* temp = this->m_pHead;
    while (temp->m_pNext != NULL) {
      thisSize++;
      temp = temp->m_pNext;
    }
  }
  Store* thisArray[thisSize];
  { 
    Store* temp = this->m_pHead;
    for (int i = 0; i < thisSize; i++) {
      thisArray[i] = temp;
      temp = temp->m_pNext;
    }
  }

  

  Store* outputArray[thisSize + storeSize];

  for (int i = 0; i < thisSize; i++) {
    outputArray[i] = thisArray[i];
  }

  for (int i = 0; i < storeSize; i++) {
    outputArray[i + thisSize] = storeArray[i];
  }

  // Sort array with bubble sort;

  int n = thisSize + storeSize;
  bool swapped = false;

  for (int i = 0; i < n -1; i++) {
    swapped = false;
    for (int j = 0; j < n-i-1; j++) {
      if (outputArray[j]->getStoreID() > outputArray[j+1]->getStoreID()) {
        // swap elements
        Store* one = outputArray[j];
        Store* two = outputArray[j+1];

        outputArray[j] = two;
        outputArray[j+1] = one;

        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
  
  Store* newStoreList = outputArray[0];

  Store* temp = newStoreList;
  for (int i = 1; i < thisSize + storeSize; i++) {
    temp->m_pNext = outputArray[i];
    temp = temp->m_pNext;
  }

  this->m_pHead = newStoreList;
  return true;
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
  Store* temp = this->m_pHead;
  Store* tempNext = this->m_pHead->m_pNext;


  if (this->m_pHead->getStoreID() == ID) {
    m_pHead = m_pHead->m_pNext;
    return temp;
  }

  while (tempNext->m_pNext != NULL) {
    if (tempNext->getStoreID() == ID) {
      Store* continuation = tempNext->m_pNext;
      temp->m_pNext = continuation;
      
      return tempNext; 
    } else {
      temp = tempNext;
      tempNext = tempNext->m_pNext;
    }
  }

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



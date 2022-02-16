#include "CustomerList.hpp"
#include "Store.h"


CustomerList::CustomerList(void) {
  stores = new Node<Store*>();
}

CustomerList::~CustomerList() {
  
}

bool CustomerList::addStore(Store* store){
  if (stores->isEmpty()) {
    stores->setElement(store);
    return true;
  }

  int id = store->getStoreID();

  bool found = false;
  Node<Store*>* currentNode = stores;
  while (!found) {
    if (currentNode->getElement()->getStoreID() > id) {
      currentNode = stores->getNext();
    } else {
      found = true;
      Node<Store*>* newStoreNode= new Node<Store*>(store);


      // perform insertion
      if (currentNode->hasNext()) {
        newStoreNode->setNext(currentNode->getNext());
        currentNode->setNext(newStoreNode);
        return true;
      } else {
        currentNode->setNext(newStoreNode);
        return true;
      }
      
    }
  }
  return false;
}

Store* CustomerList::removeStore(int ID) {
  Node<Store*>* currentNode = stores;
  // Check if the head has the store id;
  if (stores->getElement()->getStoreID() == ID) {
    if (stores->hasNext()) {
      stores = stores->getNext();
      return currentNode->getElement();
    }
  }


  while(currentNode->hasNext()) {
    if (currentNode->getNext()->getElement()->getStoreID() == ID) {
      Store* returnable = currentNode->getNext()->getElement();

      if (currentNode->getNext()->hasNext()) {
        currentNode->setNext(currentNode->getNext()->getNext());
      } else {
        currentNode->setNext(nullptr);
      }
      return returnable;
    }
  }

  return nullptr;
}

Store* CustomerList::getStore(int ID) {
  Node<Store*>* currentNode = stores;
  
  if (stores == nullptr) {
    return nullptr;
  }

  while(currentNode->hasNext()) {
    if (currentNode->getElement()->getStoreID() == ID) {
      return currentNode->getElement();
    } else {
      currentNode = currentNode->getNext();
    }
  }
  return nullptr;
}

bool CustomerList::updateStore(int ID, char* name, char* address, char* city, char* street, char* zip) {
  Store* store = getStore(ID);

  if (store != nullptr) {
    store->setStoreName(name);
    store->setStoreAddress(address);
    store->setStoreCity(city);
    store->setStoreZip(zip);
    return true;
  }


  return false;
}

void CustomerList::printStoresInfo() {
  Node<Store*>* currentNode = stores;

  if (stores == nullptr) {
    while (currentNode->hasNext()) {
      currentNode->getElement()->printStoreInfo();
      currentNode = currentNode->getNext();
    }
  }

}



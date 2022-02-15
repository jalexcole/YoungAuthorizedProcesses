#pragma once

#include "EmployeeRecordBT.hpp"

class EmployeeDatabase {
  EmployeeRecordBT m_pRoot;
  public:
    EmployeeDatabase();
    ~EmployeeDatabase();

    bool addEmployee(EmployeeRecordBT* empoyee);
    EmployeeRecordBT* getEmployee(int ID);
    EmployeeRecordBT* removeEmployee(int ID);
    void printEmployeeDatabase();
    bool buildDatabase(char* dataFile);

  private:
    void printEmployeeRecords(EmployeeRecordBT* rt);

    void destoroTree(EmployeeRecordBT* recordTree);
};

template <class T>
typedef struct BTNode {
  T element;
  Node<T>* left;
  Node<T>* right;
  Node<T>* parent;
};

template <class T>
void _addNode(Node<T>* currentNode, Node<T> &newNode) {
  
}



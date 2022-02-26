#pragma once

#include <fstream>
#include <iostream>
#include "EmployeeRecord.hpp"

/**
 * @brief A database of employee records.
 * @details A binary tree with simple search methods that are implemented for
 * access
 * 
 */
class EmployeeDatabase {
  EmployeeRecord m_pRoot;
  // CustomerList* theList;
  ifstream inFile;

  bool getNextLine(char* line, int lineLen);

  public:
    EmployeeDatabase();
    ~EmployeeDatabase();

    bool addEmployee(EmployeeRecord* empoyee);
    EmployeeRecord* getEmployee(int ID);
    EmployeeRecord* removeEmployee(int ID);
    void printEmployeeDatabase();
    bool buildDatabase(const char* dataFile);

  private:
    void printEmployeeRecords(EmployeeRecord* rt);
    void destroyTree(EmployeeRecord* recordTree);
};





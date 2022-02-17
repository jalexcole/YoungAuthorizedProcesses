#pragma once

#include <fstream>
#include <iostream>
#include "EmployeeRecord.hpp"

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
    bool buildDatabase(char* dataFile);

  private:
    void printEmployeeRecords(EmployeeRecord* rt);

    void destoroTree(EmployeeRecord* recordTree);
};





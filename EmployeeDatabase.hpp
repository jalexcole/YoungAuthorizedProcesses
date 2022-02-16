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





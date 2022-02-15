#pragma once

#include "EmployeeRecord.hpp"

class EmployeeRecordBT: public EmployeeRecord {
  public:
    EmployeeRecordBT* m_pLeft;
    EmployeeRecordBT* m_pRight;

    EmployeeRecordBT() {
     
    }
    ~EmployeeRecordBT() {
      delete m_pLeft;
      delete m_pRight;
    }

    void removeCustomerList();
    void destroyCustomerList();
};
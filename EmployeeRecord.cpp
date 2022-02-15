#include <cstring>
#include <iostream>

#include "EmployeeRecord.hpp"

EmployeeRecord::EmployeeRecord(void) {
    m_iEmployeeID = 0;
    strncpy(m_sFirstName, "", sizeof(m_sFirstName));
    strncpy(m_sLastName, "", sizeof(m_sLastName)); 
    m_iDeptID = 0;
    m_dSalary = 0.0;
    m_pCustomerList = new CustomerList();
}

EmployeeRecord::EmployeeRecord(int _ID, char* _lname, char* _fname, int _dept, double _salary) {

    m_iEmployeeID = _ID;
    strncpy(m_sFirstName, _fname, sizeof(m_sFirstName));
    strncpy(m_sLastName, _lname, sizeof(m_sLastName)); 
    m_iDeptID = _dept;
    m_dSalary = _salary;
}

EmployeeRecord::~EmployeeRecord() {
  delete m_pCustomerList;
}

int EmployeeRecord::getID() {
    return  m_iEmployeeID;
}

void EmployeeRecord::setID(int _id) {
    m_iEmployeeID = _id;
}

void EmployeeRecord::setName(char* _fname, char* _lname) {
    strncpy(m_sFirstName, _fname, sizeof(m_sFirstName));
    strncpy(m_sLastName, _lname, sizeof(m_sLastName)); 
}

void EmployeeRecord::getName(char* _fname, char* _lname) {
    strncpy(_fname, m_sFirstName, sizeof(_fname));
    strncpy(_lname, m_sLastName, sizeof(_lname));
}

int EmployeeRecord::getDept() {
    return m_iDeptID;
}

void EmployeeRecord::setDept(int _departmentID) {
    m_iDeptID = _departmentID;
}

double EmployeeRecord::getSalary() {
    return m_dSalary;
}

void EmployeeRecord::setSalary(double _salary) {
    m_dSalary = _salary;
}



void EmployeeRecord::printRecord() {
    std::cout << "EmployeeRecord: " << std::endl;
    std::cout << "Employee Record ID: " << m_iEmployeeID << std::endl;
    std::cout << "Employee Name: " << m_sLastName << ", " << m_sFirstName << std::endl;
    std::cout << "Employee Department ID: " << m_iDeptID << std::endl;
    std::cout << "Employee Salary" << m_dSalary << std::endl;
}

// Part 2

CustomerList* EmployeeRecord::getCustomerList() {
  return m_pCustomerList;
}
#include <iostream>

#include "EmployeeRecord.hpp"

/** 
 * @brief A constructor for the employee record class
 */
EmployeeRecord::EmployeeRecord(void) {
    m_iEmployeeID = 0;
    strcpy(m_sFirstName, "");
    strcpy(m_sLastName, ""); 
    m_iDeptID = 0;
    m_dSalary = 0.0;
    // m_pCustomerList = new CustomerList();
}

/**
 * @brief Construct a new Employee Record:: Employee Record object
 * @details Construct a new Employee Record with parameters.
 * @param _ID  int
 * @param _lname cstring 
 * @param _fname cstring
 * @param _dept  int
 * @param _salary  double
 */
EmployeeRecord::EmployeeRecord(int _ID, char* _lname, char* _fname, int _dept, double _salary) {

    m_iEmployeeID = _ID;
    strcpy(m_sFirstName, _fname);
    strcpy(m_sLastName, _lname); 
    m_iDeptID = _dept;
    m_dSalary = _salary;
}

/**
 * @brief Destroy the Employee Record:: Employee Record object
 * 
 */
EmployeeRecord::~EmployeeRecord() {
//   delete m_pCustomerList;
}

/**
 * @brief Returns the id of the employee.
 * 
 * @return int 
 */
int EmployeeRecord::getID() {
    return  m_iEmployeeID;
}

/**
 * @brief sets the id of the employee.
 * 
 * @param _id 
 */
void EmployeeRecord::setID(int _id) {
    m_iEmployeeID = _id;
}

/**
 * @brief Sets the name of the employee.
 * 
 * @param _fname 
 * @param _lname 
 */
void EmployeeRecord::setName(char* _fname, char* _lname) {
    strncpy(m_sFirstName, _fname, sizeof(m_sFirstName));
    strncpy(m_sLastName, _lname, sizeof(m_sLastName)); 
}

/**
 * @brief Gets the names of the employee as cstrings
 * 
 * @param _fname 
 * @param _lname 
 */
void EmployeeRecord::getName(char* _fname, char* _lname) {
    strcpy(_fname, m_sFirstName);
    strcpy(_lname, m_sLastName);
}

/**
 * @brief 
 * 
 * @return int 
 */
int EmployeeRecord::getDept() {
    return m_iDeptID;
}

/**
 * @brief 
 * 
 * @param _departmentID 
 */
void EmployeeRecord::setDept(int _departmentID) {
    m_iDeptID = _departmentID;
}

/**
 * @brief 
 * 
 * @return double 
 */
double EmployeeRecord::getSalary() {
    return m_dSalary;
}

/**
 * @brief 
 * 
 * @param _salary 
 */
void EmployeeRecord::setSalary(double _salary) {
    m_dSalary = _salary;
}


/**
 * @brief prints the record of employee
 * 
 */
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
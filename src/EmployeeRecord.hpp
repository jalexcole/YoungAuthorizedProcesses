#pragma once

#include "CustomerList.hpp"

class EmployeeRecord {
private:
    int m_iEmployeeID;
    char m_sLastName[32];
    char m_sFirstName[32];
    int m_iDeptID;
    double m_dSalary;

    // Part 2
    CustomerList* m_pCustomerList;

public:
    EmployeeRecord();
    EmployeeRecord(int ID, char *fname, char *IName, int dept, double sal);
    ~EmployeeRecord();

    EmployeeRecord* m_pLeft;
    EmployeeRecord* m_pRight;

    int getID();
    void setID(int);
    void getName(char *fName, char *IName);
    void setName(char *fName, char *IName);
    int getDept();
    void setDept(int d);
    double getSalary();
    void setSalary(double sal);

    void printRecord();

    // Part 2
    CustomerList* getCustomerList();

    // Part 3
    void removeCustomerList(void);
    void destroyCustomerList(void); // deletes 
};
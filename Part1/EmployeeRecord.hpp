#pragma once

class EmployeeRecord {
private:
    int m_iEmployeeID;
    char m_sLastName[32];
    char m_sFirstName[32];
    int m_iDeptID;
    double m_dSalary;

    

public:
    EmployeeRecord();
    EmployeeRecord(int ID, char *fname, char *IName, int dept, double sal);
    ~EmployeeRecord();

    int getID();
    void setID(int);
    void getName(char *fName, char *IName);
    void setName(char *fName, char *IName);
    void getDept(int &d);
    void setDept(int d);
    void getSalary(double &sal);
    void setSalary(double sal);

    void printRecord();

    
};
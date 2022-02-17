#include "EmployeeDatabase.hpp"
#include "string.h"
#include <cstdio>
#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>


#include "CustomerList.hpp"

enum employeeInfo{
  ID = 0,
  FIRST_NAME = 1,
  LAST_NAME = 2,
  DEPARTMENT = 3,
  SALARY = 4,
  STOP = 5
};

enum StoreReadState {
  
};

enum ReadStatus {
  Employee = 1,
  CustomerList = 2,
  Comment = 0
};


EmployeeDatabase::EmployeeDatabase() {

}

EmployeeDatabase::~EmployeeDatabase() {

}

bool single(EmployeeRecord* employee) {
  if (employee->m_pLeft == nullptr && employee->m_pRight == nullptr) {
    return true;
  } else {
    return false;
  }
}

std::list<EmployeeRecord*>* employeeToList(EmployeeRecord* employee) {
  std::list<EmployeeRecord*>* list = new std::list<EmployeeRecord*>();
  EmployeeRecord* root = employee;

  std::list<EmployeeRecord*>* temp = new std::list<EmployeeRecord*>();
  std::list<EmployeeRecord*>* tempNext = new std::list<EmployeeRecord*>();

  temp->push_back(root);
  while (temp->size() != 0) {
    while (temp->size() != 0) {
      list->push_back(temp->front());
      if (temp->front()->m_pRight != nullptr) {
        tempNext->push_back(temp->front()->m_pRight);
      }

      if (temp->front()->m_pLeft != nullptr) {
        tempNext->push_back(temp->front()->m_pLeft);
      }

      temp->pop_front();
    }
    delete temp;
    temp = tempNext;
    tempNext = new std::list<EmployeeRecord*>();
  }
  if (temp != nullptr) {
    delete temp;
  }
  
  if (tempNext != nullptr) {
    delete tempNext;
  }

  return list;
}

bool EmployeeDatabase::addEmployee(EmployeeRecord* employee) {
  // Determine if the employeee is a single employee
  

  if (single(employee)) {
    // add to tree;
  } else {
    // parse into list and then add back into tree;
    std::list<EmployeeRecord*>* employees = employeeToList(employee);

    


  }
  return false;
}

EmployeeRecord* EmployeeDatabase::getEmployee(int ID) {
  return nullptr;
}

EmployeeRecord* EmployeeDatabase::removeEmployee(int ID) {


  return nullptr;
}

void EmployeeDatabase::printEmployeeRecords(EmployeeRecord* record) {

}

//-----------------------------------------------------
// Build the database
//-----------------------------------------------------
bool EmployeeDatabase::buildDatabase(char *dataFile) {
	bool OK = true;
	int numEmp, id, dept, numStores, sID;
	double sal;
	EmployeeRecord *empRec;
	class CustomerList* theList;
	Store *theStore;
	char inStr[128];
	char fName[32];
	char lName[32];
	char sName[64];
	char sAddr[64];
	char sSt[32];
	char sCity[32];
	char sZip[12];
	

	inFile.open(dataFile, ifstream::in); 
  if(!inFile.is_open()) {
    // inFile.is_open() returns false if the file could not be found or
    //    if for some other reason the open failed.
    cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
		cout << "Press Enter to continue...";
		getc(stdin);
    return false;
  }

	// Get number of employees
	getNextLine(inStr, 128);
	numEmp = atoi(inStr);
	for(int i=0; i<numEmp; i++) {
		// Instantiate an EmployeeRecord
		empRec = new EmployeeRecord();
		// Read and set the ID
		getNextLine(inStr, 127);
		id = atoi(inStr);
		empRec->setID(id);
		// Read and set the name
		getNextLine(fName, 31);
		getNextLine(lName, 31);
		empRec->setName(fName, lName);
		// Read and set the Department ID
		getNextLine(inStr, 127);
		dept = atoi(inStr);
		empRec->setDept(dept);
		// Read and set the Salary
		getNextLine(inStr, 127);
		sal = atof(inStr);
		empRec->setSalary(sal);
		// Get the customer list
		theList = empRec->getCustomerList();
		// Get the number of stores
		getNextLine(inStr, 127);
		numStores = atoi(inStr);
		for(int j=0; j<numStores; j++) {
			// Read the store ID
			getNextLine(inStr, 127);
			sID = atoi(inStr);
			// Read the store name
			getNextLine(sName, 63);
			// Read the store address
			getNextLine(sAddr, 63);
			// Read the store city
			getNextLine(sCity, 31);
			// Read the store state
			getNextLine(sSt, 31);
			// Read the store zip
			getNextLine(sZip, 11);
			// Create a new Store object
			theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
			theList->addStore(theStore);
		}
		cout.flush();
		addEmployee(empRec);
	}
	inFile.close();
	return true;	// Successfully built the database
}

//--------------------------------------------
// GetNextLine() 
// Read a line from a data file.
// Author: Rick Coleman
// Used by permission
//--------------------------------------------
bool EmployeeDatabase::getNextLine(char *line, int lineLen)
{
    int    done = false;
    while(!done)
    {
        inFile.getline(line, 128);
        
        if(inFile.good())    // If a line was successfully read
        {
            if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else return true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return false;
        }
    } // end while
    return false;
}
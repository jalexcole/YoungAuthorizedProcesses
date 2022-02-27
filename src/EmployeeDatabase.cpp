#include "EmployeeDatabase.hpp"

#include <fstream>
#include <iostream>
#include <list>

#include "CustomerList.hpp"
#include "EmployeeRecord.hpp"

/**
 * @brief Construct a new Employee Database:: Employee Database object
 *
 */
EmployeeDatabase::EmployeeDatabase() {}

/**
 * @brief Destroy the Employee Database:: Employee Database object
 *
 */
EmployeeDatabase::~EmployeeDatabase() {}

/**
 * @brief Checks if the employee is not a binary tree;
 *
 * @param employee
 * @return true
 * @return false
 */
bool single(EmployeeRecord *employee) {
  return employee->m_pLeft == nullptr && employee->m_pRight == nullptr;
}

/**
 * @brief Converts and EmployeeRecord binary tree to a list to iterator through
 *
 * @param employee
 * @return std::list<EmployeeRecord*>*
 */
std::list<EmployeeRecord *> *employeeToList(EmployeeRecord *employee) {
  std::list<EmployeeRecord *> *list = new std::list<EmployeeRecord *>();
  EmployeeRecord *root = employee;

  std::list<EmployeeRecord *> *temp = new std::list<EmployeeRecord *>();
  std::list<EmployeeRecord *> *tempNext = new std::list<EmployeeRecord *>();

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
    tempNext = new std::list<EmployeeRecord *>();
  }

  // release resources
  if (temp != nullptr) {
    delete temp;
  }

  if (tempNext != nullptr) {
    delete tempNext;
  }

  return list;
}

/**
 * @brief inserts the target EmployeeRecord into the source tree
 *
 * @description Recursivly goes though each node on a binary tree for
 * comparison.
 * @param source
 * @param target  Assumes a single employee.
 * @return true
 * @return false
 */
bool insertEmployee(EmployeeRecord *source, EmployeeRecord *target) {
  if (source == nullptr || target == nullptr) {
    return false;
  }

  if (source->getID() < target->getID()) {
    // add left;
    if (source->m_pLeft != nullptr) {
      insertEmployee(source->m_pLeft, target);
    } else {
      source->m_pLeft = target;
      return true;
    }
  } else {
    if (source->m_pRight != nullptr) {
      insertEmployee(source->m_pRight, target);
    } else {
      source->m_pRight = target;
      return true;
    }
  }
  return false;
}

/**
 * @brief Adds an employee or Employee Record tree to the Employee Record Tree.
 *
 * @param employee  Can be a single employee or a tree of employees.
 * @return true
 * @return false
 */
bool EmployeeDatabase::addEmployee(EmployeeRecord *employee) {
  // Determine if the employeee is a single employee

  if (single(employee)) {
    // add to tree;
    return insertEmployee(&m_pRoot, employee);

  } else {
    // parse into list and then add back into tree;
    std::list<EmployeeRecord *> *employees = employeeToList(employee);

    while (!employees->empty()) {
      // traverse tree to add each employee;
      EmployeeRecord *employeefromList = employees->front();

      employeefromList->m_pLeft = nullptr;
      employeefromList->m_pRight = nullptr;

      insertEmployee(&m_pRoot, employeefromList);

      employees->pop_front();
    }
    delete employees;
  }
  return false;
}

/**
 * @brief Finds an employee Record by from a given Tree by id.
 *
 * @param employee
 * @param id
 * @return EmployeeRecord*
 */
EmployeeRecord *findEmployeeById(EmployeeRecord *employee, int id) {
  if (employee->getID() == id) {
    return employee;
  } else if (employee->getID() < id) {
    if (employee->m_pLeft == nullptr) {
      return nullptr;
    }
    return findEmployeeById(employee->m_pLeft, id);
  } else {
    if (employee->m_pRight == nullptr) {
      return nullptr;
    }
    return findEmployeeById(employee->m_pRight, id);
  }
}

/**
 * @brief Gets the Employee with the given id.
 *
 * @param ID
 * @return EmployeeRecord*
 */
EmployeeRecord *EmployeeDatabase::getEmployee(int ID) {
  return findEmployeeById(&m_pRoot, ID);
}

/**
 * @brief Removes an Employee from the database.
 *
 * @param ID
 * @return EmployeeRecord*
 */
EmployeeRecord *EmployeeDatabase::removeEmployee(int ID) {
  // find the employee
  EmployeeRecord *employee = findEmployeeById(&m_pRoot, ID);
  if (employee == nullptr) {
    return nullptr;
  }
  // index childeren of employee
  EmployeeRecord *left = employee->m_pLeft;
  EmployeeRecord *right = employee->m_pRight;

  // find parent node of employee;
  EmployeeRecord *parent = &m_pRoot;

  bool found = false;

  while (!found) {
    if (parent->m_pLeft == employee) {
      found = true;
      break;
    } else if (parent->m_pRight == employee) {
      found = true;
      break;
    }

    if (parent->getID() > ID) {
      parent = parent->m_pLeft;
    } else {
      parent = parent->m_pRight;
    }
  }

  if (parent->m_pRight == employee) {
    parent->m_pRight = nullptr;
    if (left != nullptr) {
      addEmployee(left);
    }
    if (right != nullptr) {
      addEmployee(right);
    }
  }
  return employee;
}

void EmployeeDatabase::printEmployeeDatabase() {
  std::list<EmployeeRecord *> *employeeDatabase = employeeToList(&m_pRoot);

  while (!employeeDatabase->empty()) {
    employeeDatabase->front()->printRecord();
    employeeDatabase->pop_front();
  }
}

/**
 * @brief Prints out an employee record tree.
 *
 * @param record
 */
void EmployeeDatabase::printEmployeeRecords(EmployeeRecord *record) {

  // Allacate employees
  std::list<EmployeeRecord *> *employees = employeeToList(record);

  while (!employees->empty()) {
    EmployeeRecord *employeeFromList = employees->front();
    employeeFromList->printRecord();
    employeeFromList->getCustomerList()->printStoresInfo();
    employees->pop_front();
  }

  delete employees; // deallicate employees
}

//-----------------------------------------------------
// Build the database
//-----------------------------------------------------
bool EmployeeDatabase::buildDatabase(const char *dataFile) {
  bool OK = true;
  int numEmp, id, dept, numStores, sID;
  double sal;
  EmployeeRecord *empRec;
  class CustomerList *theList;
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
  if (!inFile.is_open()) {
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
  for (int i = 0; i < numEmp; i++) {
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
    for (int j = 0; j < numStores; j++) {
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
      
      theStore->printStoreInfo();
      theList->addStore(theStore);
    }
    cout.flush();
    std::cout << "Adding Employee to Employee database" << std::endl;
    addEmployee(empRec);
  }
  inFile.close();
  return true; // Successfully built the database
}

//--------------------------------------------
// GetNextLine()
// Read a line from a data file.
// Author: Rick Coleman
// Used by permission
//--------------------------------------------
bool EmployeeDatabase::getNextLine(char *line, int lineLen) {
  int done = false;
  while (!done) {
    inFile.getline(line, 128);

    if (inFile.good()) // If a line was successfully read
    {
      if (strlen(line) == 0) // Skip any blank lines
        continue;
      else if (line[0] == '#') // Skip any comment lines
        continue;
      else
        return true; // Got a valid data line so return with this line
    } else {
      strcpy(line, "");
      return false;
    }
  } // end while
  return false;
}

void EmployeeDatabase::destroyTree(EmployeeRecord* rt) {
  std::list<EmployeeRecord*>* list = employeeToList(rt);
  while (!list->empty()) {
    EmployeeRecord* record = list->front();
    list->pop_front();
    delete record;
  }
  delete list;
}
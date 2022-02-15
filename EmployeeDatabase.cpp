#define _GNU_SOURCE

#include "EmployeeDatabase.hpp"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>


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

typedef struct EmployeeList {
  EmployeeRecord* employee;
  EmployeeList* next;
};

bool _isEmpty(EmployeeList* list) {
  return list->employee == NULL;
}

bool _hasNext(EmployeeList* list) {
  return list->next != NULL;
}

bool _deleteEmployeeList(EmployeeList* list) {
  while (_hasNext(list->next)) {
    _deleteEmployeeList(list->next);
  }
  free(list->next);
  free(list);

}

bool _addEmployee(EmployeeList* list, EmployeeRecord* _employee) {
  if (_isEmpty(list)) {
    list->employee = _employee;
    return true;
  } else {
    if (_hasNext(list)) {
      EmployeeList* parent = list;
      EmployeeList* placeholder = list->next;

      while (_hasNext(list)) {
        if (placeholder->employee > _employee) {
          // continue
          parent = placeholder;
          placeholder = placeholder->next;
        } else {
          EmployeeList* employeeList = (EmployeeList*) malloc(sizeof(EmployeeList));
          employeeList->employee = _employee;
          employeeList->next = placeholder->next;
          parent->next = employeeList;

          return true;
        }
      }
    }
  }
  return false;
}

EmployeeRecord* _getEmployeeRecord(EmployeeList* employeeList, int id) {
  if (_isEmpty(employeeList)) {
    return NULL;
  } else (_hasNext(employeeList)) {
    if (employeeList->next->employee->getID() == id) {
      return employeeList->next->employee;
    } else {
      _getEmployeeRecord(employeeList->next, id);
    }
  } else if (employeeList->employee->getID() == id) {
    return employeeList->employee;
  }

  return NULL;
}



EmployeeDatabase::EmployeeDatabase() {

}

EmployeeDatabase::~EmployeeDatabase() {

}

bool EmployeeDatabase::addEmployee(EmployeeRecordBT* employee) {


  return false;
}

EmployeeRecordBT* EmployeeDatabase::getEmployee(int ID) {
  return nullptr;
}

EmployeeRecordBT* EmployeeDatabase::removeEmployee(int ID) {


  return nullptr;
}

void EmployeeDatabase::printEmployeeRecords(EmployeeRecordBT* record) {

}

bool EmployeeDatabase::buildDatabase(char* dataFile) {
  FILE* file_ptr;
  char* line = NULL;
  size_t length = 0;
  ssize_t read;

  file_ptr = fopen(dataFile, "r");

  if (file_ptr == NULL) {
    return false;
  }

  std::list<EmployeeRecord*> employees;

  EmployeeRecord* employee = new EmployeeRecord();

  ReadStatus readState = Employee;
  while ((read = getline(&line, &length, file_ptr)) != -1) {
    
    if (line[0] == '#' && strstr(line, "Employee")) {
      readState = Employee;
    } else if (line[0] == '#') {
      readState = Comment;
    }
    // do parsing logic here. 
  }

  fclose(file_ptr);
  return true;
}


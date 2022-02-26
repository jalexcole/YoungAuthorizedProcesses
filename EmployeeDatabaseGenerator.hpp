#pragma once

#include "EmployeeDatabase.hpp"
#include "EmployeeRecord.hpp"
#include "CustomerList.hpp"
#include "Store.h"

class EmployeeDatabaseGenerator {
    private:
    int* x;
    public:
        EmployeeDatabaseGenerator(){
            x = new int;
        }
        ~EmployeeDatabaseGenerator() {
            delete x;
        }
};
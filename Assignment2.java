


// Assignment 2
public class Assignment2 {
  public static void main(String[] args) {

  }
}

class EmployeeRecord {
  int m_iEmployeeID;
  char[] m_sLastName = new char[32];
  char[] m_sFirstName = new char[32];
  int m_iDeptID;
  double m_dSalary;

  EmployeeRecord() {
    m_iDeptID = 0;
    
  }
}

class EmployeeRecordLL extends EmployeeRecord {
  EmployeeRecordLL m_pNext;
  private CustomerList m_pCustomerList;

  EmployeeRecordLL() {

  }

  EmployeeRecordLL(CustomerList customerList) {

  }

  int getDept() {

  }

  int getSalary() {

  }
}

class EmployeeRecordBT extends EmployeeRecord {
  EmployeeRecordBT m_pLeft;
  EmployeeRecordBT m_pRight;

  void removeCurstomerList() {

  }

  void destroyCustomerList() {

  }
}

class CustomerList {
  boolean addStore(Store s) {

  }

  Store removeStore(int ID) {

  }

  Store getStore(int ID) {

  }

  boolean update(int ID, char[] name, char[] address, char[] city, char[] zip) {

  }

  void printStoreInfor() {

  }
}

class EmployeeDatabase {
  boolean addEmployee(EmployeeRecordBT employeeRecord) {

  }

  EmployeeRecordBT getEmployee(int ID) {

  }

  EmployeeRecordBT removeEmployee(int ID) {

  }

  void printEmployeeRecords() {

  }

  bool buildDatabase(char[] dataFile) {

  }

  private void printEmployeeRecords(EmployeeRecordBT employeeRecord) {

  }

  private void destroyTree(EmployeeRecordBT employeeRecord) {

  }
}

class Store {
  Store m_pNext;
}


/// Design, develop, and execute a program in C++ based on the following requirements: An EMPLOYEE class is to contain the following data members and member functions: Data members: Employee_Number (an integer), Employee_Name (a string of characters), Basic_Salary (an integer) , All_Allowances(an integer), IT (an integer), Net_Salary (an integer). Member functions: to read the data of an employee, to calculate Net_Salary and to print the values of all the data members. (All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the gross salary (= basicSalary All_Allowance); Net_Salary = Basic_Salary + All_Allowances - IT)

#include <iostream>

using namespace std;

class Employee {

private:
    int EmployeeNumber, BasicSalary, AllAllowances, IncomeTax, GrossSalary, NetSalary;
    char EmployeeName[20];

public:
    void readData();
    void calcNetSalary();
    void printData();

};

void Employee :: readData() {
    cout << "Enter Employee Number: ";
    cin >> EmployeeNumber;

    cout << "Enter Employee Name: ";
    cin >> EmployeeName;

    cout << "Enter Basic Salary: ";
    cin >> BasicSalary;
}

void Employee :: calcNetSalary() {
    AllAllowances = (123 * BasicSalary) / 100;
    GrossSalary = BasicSalary + AllAllowances;
    IncomeTax = (30 * GrossSalary) / 100;
    NetSalary = GrossSalary - IncomeTax;
}

void Employee :: printData() {
    cout << "Employee Number: " << EmployeeNumber << endl
         << "Employee Name: " << EmployeeName << endl
         << "Basic Salary: " << BasicSalary << endl
         << "Net Salary: " << NetSalary;
}

int main()
{
    int numOfEmployees;

    cout << "Enter number of employees: ";
    cin >> numOfEmployees;

    Employee obj[numOfEmployees];

    cout << "Enter details of " << numOfEmployees << " employees:" << endl;
    for (int i = 0; i < numOfEmployees; i++) {
        obj[i].readData();
        obj[i].calcNetSalary();
    }

    for (int i = 0; i < numOfEmployees; i++) {
        cout << "Employee #" << i+1 << " Details:" << endl;
        obj[i].printData();
        cout << endl;
    }

    return 0;
}

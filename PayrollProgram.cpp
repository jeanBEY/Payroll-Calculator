#include "PayrollProgram.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

PayrollProgram::PayrollProgram() {
    cout << "***************************" << endl;
    cout << "*                         *" << endl;
    cout << "*     PAYROLL PROGRAM     *" << endl;
    cout << "*                         *" << endl;
    cout << "***************************" << endl << endl;
    cout << "Welcome!" << endl << endl;

}

PayrollProgram::~PayrollProgram() {
    cout << "***************************" << endl;
    cout << "*                         *" << endl;
    cout << "*         GOODBYE         *" << endl;
    cout << "*                         *" << endl;
    cout << "***************************" << endl;

}

void PayrollProgram::menu() {

    int choice;

    cout << "***************************" << endl;
    cout << "*           MENU          *" << endl;
    cout << "***************************" << endl << endl;
    cout << "1.) HIRE EMPLOYEE" << endl;
    cout << "2.) PROCESS PAYROLL" << endl;
    cout << "3.) QUIT" << endl << endl;
    cout << "Enter 1 to hire an employee, 2 to process payroll, or, 3 to quit.. " << endl << endl;

    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    if (choice == 1){
        hireEmployee();
    }
    else if (choice == 2){
        cout << endl << "Let's process payroll! " << endl << endl;
    }
    else if (choice == 3) {
        cout << endl << "Quitting the program! " << endl << endl;
        quit();
    }
    else{
        cout << endl << "Invalid entry!  Try again..." << endl << endl;
        menu();
    }
}

//Hire one employee at a time.  The employee will be valid for the duration of the program.
void PayrollProgram::hireEmployee() {

    //New employee attributes
    string Name;
    string Address;
    string City;
    string State;
    long int ZipCode;
    string EmploymentStatus;
    string Type;
    double HourlyRate;
    double StatePercentage;
    double FederalPercentage;

    //Only asked the first time the employer hires their first employee
    if(askedForBudgetedNumOfEmployees == false){
        cout << endl << "How many employees in total do you plan on employing?" << endl << endl;
        cin >> budgetedNumOfEmployees;
        cin.ignore();
        askedForBudgetedNumOfEmployees = true;
        activeEmployeeArray = new Employee * [(budgetedNumOfEmployees * 2)];        //initialize array of Employee pointers to be double the 
                                                                                    //anticipated employees the employer expects to employ
    }

    //Hire an employee
    cout << endl << "Let's hire an employee!" << endl << endl;
    cout << endl << "Please enter the following information..." << endl;
    cout << endl << "Name: " << endl;
    cin >> Name;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Address: " << endl;
    cin >> Address;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "City: " << endl;
    cin >> City;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "State: " << endl;
    cin >> State;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Zip Code: " << endl;
    cin >> ZipCode;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Employment Status (Full Time or Part Time): " << endl;
    cin >> EmploymentStatus;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Type (Salary or Hourly): " << endl;
    cin >> Type;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Hourly Rate: " << endl;
    cin >> HourlyRate;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Federal Withholding (1 for Single or 2 for Married): " << endl;
    int SingleOrMarriedFed;
    cin >> SingleOrMarriedFed;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
    if(SingleOrMarriedFed == 1){
        FederalPercentage = .07;
    }
    else if(SingleOrMarriedFed == 2){
        FederalPercentage = .04;
    }

    cout << endl << "State Withholding (1 for Single or 2 for Married): " << endl;
    int SingleOrMarriedState;
    cin >> SingleOrMarriedState;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
    if(SingleOrMarriedState == 1){
        StatePercentage = .07;
    }
    else if(SingleOrMarriedState == 2){
        StatePercentage = .04;
    }

    Employee * employeePointer;                           
    employeePointer = new Employee(Name, Address, City, State, ZipCode, 
    EmploymentStatus, Type, HourlyRate, StatePercentage, FederalPercentage);
    activeEmployeeArray[activeEmployeeCount] = employeePointer;                 //assign new Employee pointer to current empty index
    activeEmployeeCount+=1;                                                     //incrememnt active employee count to include new hire just added


}

int PayrollProgram::quit() {
    delete [] activeEmployeeArray;      //delete dynamically allocated array when program quits
    activeEmployeeArray = 0;            //no longer is pointing to memory
    return 0;
}

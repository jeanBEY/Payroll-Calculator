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

//Getters
int PayrollProgram::getActiveEmployeeCount(){
    return activeEmployeeCount;
}

int PayrollProgram::getBudgetedNumOfEmployees(){
    return budgetedNumOfEmployees;
}

bool PayrollProgram::getAskedForBudgetedNumOfEmployees(){
    return askedForBudgetedNumOfEmployees;
}

//Setters
void PayrollProgram::setActiveEmployeeCount(int ActiveEmployeeCount){
    activeEmployeeCount = ActiveEmployeeCount;
}
void PayrollProgram::setBudgetedNumOfEmployees(int BudgetedNumOfEmployees){
    budgetedNumOfEmployees = BudgetedNumOfEmployees;
}
void PayrollProgram::setAskedForBudgetedNumOfEmployees(bool AskedForBudgetedNumOfEmployees){
    askedForBudgetedNumOfEmployees = AskedForBudgetedNumOfEmployees;
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
        setAskedForBudgetedNumOfEmployees(true);
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

    //Dynamically allocate Employee object & store address in temporary Employee pointer
    Employee * employeePointer;                           
    employeePointer = new Employee(Name, Address, City, State, ZipCode, 
    EmploymentStatus, Type, HourlyRate, StatePercentage, FederalPercentage);

    //Check if there is space in the array before adding the new Employee pointer
    if(activeEmployeeCount< (budgetedNumOfEmployees*2)){

        //ADD NEW HIRE TO ARRAY

        //assign address in temporary Employee pointer to current empty index
        activeEmployeeArray[activeEmployeeCount] = employeePointer; 

        //Display employee information that you just hired
        cout << "Great!  You've hired the following employee: " << endl;
        activeEmployeeArray[activeEmployeeCount]->displayEmployeeInformation();

        //incrememnt active employee count to include new hire just added
        activeEmployeeCount+=1;                 

    }
    else if (activeEmployeeCount >= (budgetedNumOfEmployees*2)){
        //Create temp array
        Employee ** tempEmployeeArray = new Employee * [(budgetedNumOfEmployees * 2)];                                 

        //Copy active employee array elements > temp array
        for(int i = 0; i < (budgetedNumOfEmployees *2); i++){
            tempEmployeeArray[i] = activeEmployeeArray[i];
        }

        //Delete active employee array elements (freed the array that the pointer variable is pointing to)
        delete [] activeEmployeeArray;
        activeEmployeeArray = 0;        //set to null or 0 because that deallocated memory could be used by another progra,

        //Updating budgeted number of employees & create larger dynamically allocated array
        int tempBudgetedNumOfEmployees = budgetedNumOfEmployees;
        budgetedNumOfEmployees = activeEmployeeCount;  
        activeEmployeeArray = new Employee * [(budgetedNumOfEmployees * 2)];

        //Copy temp array > new larger active employee array
        for(int i = 0; i < (tempBudgetedNumOfEmployees *2); i++){
            activeEmployeeArray[i] = tempEmployeeArray[i];
        }

        //ADD NEW HIRE TO ARRAY

        //assign address in temporary Employee pointer to current empty index
        activeEmployeeArray[activeEmployeeCount] = employeePointer; 

        //Display employee information that you just hired
        cout << "Great!  You've hired the following employee: " << endl;
        activeEmployeeArray[activeEmployeeCount]->displayEmployeeInformation();

        //incrememnt active employee count to include new hire just added
        activeEmployeeCount+=1;     
    }                                    

}

int PayrollProgram::quit() {
    delete [] activeEmployeeArray;      //delete dynamically allocated array when program quits
    activeEmployeeArray = 0;            //no longer is pointing to memory
    return 0;
}

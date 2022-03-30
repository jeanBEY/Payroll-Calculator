#ifndef PayrollProgram_hpp
#define PayrollProgram_hpp
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Employee.h"
#include "Paycheck.h"
#include "Payroll.h"
#include "Teacher.h"
using namespace std;


class PayrollProgram{

    private: 
        int activeEmployeeCount = 0;                    //program starts with zero active employees
        Employee ** activeEmployeeArray;                //dynamic array of type Employee * (or Employee pointer), 
                                                        //created at run time based on user input

        int budgetedNumOfEmployees;                     //number of employees the employer anticipates it will employ, 
                                                        //used for dynamically allocating activeEmployeeArray at run time
        bool askedForBudgetedNumOfEmployees = false;

    public:

        //Constrctor
        PayrollProgram();

        //Destructor
        ~PayrollProgram();

        //Display menu selections & switch statement
        void menu();

        //Hire employees
        void hireEmployee();

        //Sort activeEmployeeArray in alpha order (based on last name), to be done at the start of each processPayroll() call - INCOMPLETE
        void mergeSortActiveEmployeeArray(Employee **, int , int );

        //Helper function for mergeSortActiveEmployeeArray(), merges two subarrays - INCOMPLETE
        void merge(Employee **, int const, int const, int const);

        //Process a payroll - INCOMPLETE (NEED TO CREATE LINKED LIST OF Paycheck objects)
        void processPayroll();

        //Print each object in activeEmployeeArray - INCOMPLETE
        void printEmployeeList();

        //Reset to an empty payroll - INCOMPLETE
        void resetPayroll();

        //Delete payroll - INCOMPLETE
        void deletePayroll();

        //Exit program
        int quit();

        //Getters
        int getActiveEmployeeCount();
        int getBudgetedNumOfEmployees();
        bool getAskedForBudgetedNumOfEmployees();

        //Setters
        void setActiveEmployeeCount(int);
        void setBudgetedNumOfEmployees(int);
        void setAskedForBudgetedNumOfEmployees(bool);

};

#endif
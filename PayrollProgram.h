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
        int activeEmployeeCount;                        //program starts with zero active employees
        Employee ** activeEmployeeArray;                //dynamic array of type Employee * (or Employee pointer), 
                                                        //created at run time based on user input

        int budgetedNumOfEmployees;                     //number of employees the employer anticipates it will employ, 
                                                        //used for dynamically allocating activeEmployeeArray at run time
        bool askedForBudgetedNumOfEmployees;

        int payrollCount;
        Payroll ** payrollHistoryArray;                 //dynamic array of type Payroll * (or Payroll pointer),
                                                        //created at run time based on user input

        int payrollFrequency;                           //holds number of payrolls expected to process per calendar year

        bool askedForPayrollFrequency;          

    public:

        //Constrctor
        PayrollProgram();

        //Destructor
        ~PayrollProgram();

        //Display menu selections & switch statement
        void menu();

        //Hire employees
        void hireEmployee();

        //Sort activeEmployeeArray in alpha order (based on last name), to be done at the start of each processPayroll() call
        void mergeSortActiveEmployeeArray(Employee **, int , int );

        //Helper function for mergeSortActiveEmployeeArray(), merges two subarrays
        void merge(Employee **, int const, int const, int const);

        //Process a payroll - INCOMPLETE (NEED TO CREATE LINKED LIST OF Paycheck objects)
        void processPayroll();
        
        //Add employee to payroll
        void addEmployeeToPayroll(Payroll *);

        //Edit the payroll (if checks exist)
        void editPayroll(Payroll *);

        //Print each object in activeEmployeeArray
        void printEmployeeList();

        void displayEditPayrollChoices();

        //Exit program
        int quit();

        //Getters
        int getActiveEmployeeCount();
        int getBudgetedNumOfEmployees();
        bool getAskedForBudgetedNumOfEmployees();
        int getPayrollCount();
        int getPayrollFrequency();
        bool getAskedForPayrollFrequency();

        //Setters
        void setActiveEmployeeCount(int);
        void setBudgetedNumOfEmployees(int);
        void setAskedForBudgetedNumOfEmployees(bool);
        void setPayrollCount(int);
        void setPayrollFrequency(int);
        void setAskedForPayrollFrequency(bool);

};

#endif
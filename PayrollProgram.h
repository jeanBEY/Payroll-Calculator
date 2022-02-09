#ifndef PayrollProgram_hpp
#define PayrollProgram_hpp
#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "Paycheck.h"
#include "Payroll.h"
#include "Teacher.h"
using namespace std;


class PayrollProgram{

    private: 
        int activeEmployeeCount;
        Employee ** activeEmployeeArray;       //dynamic array of type Employee * (or Employee pointer), 
                                               //created at run time based on user input

    public:

        //Constrctor
        PayrollProgram();

        //Destructor
        ~PayrollProgram();

        //Display menu selections & switch statement
        void menu();

        //Hire employees
        void hireEmployee();

        //Process a payroll
        void processPayroll();

        //Reset to an empty payroll - INCOMPLETE
        void resetPayroll();

        //Delete payroll - INCOMPLETE
        void deletePayroll();

        //Exit program
        int quit();

};

#endif
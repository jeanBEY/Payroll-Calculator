#include "PayrollProgram.h"
#include <iostream>
#include <iomanip>
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

    cout << "***************************" << endl;
    cout << "*           MENU          *" << endl;
    cout << "***************************" << endl << endl;
    cout << "1.) HIRE EMPLOYEE" << endl;
    cout << "2.) PROCESS PAYROLL" << endl;
    cout << "3.) QUIT" << endl << endl;
    cout << "Enter 1 to hire an employee, 2 to process payroll, or, 3 to quit.. " << endl << endl;


    int choice;
    cin >> choice;

    if (choice == 1){
        cout << endl << "Let's hire an employee! " << endl << endl;
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

int PayrollProgram::quit() {
    return 0;
}

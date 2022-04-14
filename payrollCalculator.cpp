#include <iostream>
#include <iomanip>
#include <string>
#include "Paycheck.h"
#include "Employee.h"
#include "Teacher.h"
#include "Payroll.h"
#include "PayrollProgram.h"
using namespace std;

int main()
{

/**
//default constructor
Employee * employee1 = new Employee;

//constructor
Employee * employee2 = new Employee("Phom", "Alex", "1224 Egar St", "San Diego", "CA", 92118, "Full Time", "Salary", 
50.00, .05, .075);

//constructor
Employee * employee3 = new Employee("Beato","Jeanvally", "1224 Egar St", "San Diego", "CA", 92118, "Full Time", "Salary", 
50.00, .10, .15);

//constructor
Teacher * employee4 = new Teacher("Alevally", "1224 Egar St", "San Diego", "CA", 92118, "Full Time", "Salary", 
50.00, .10, .15, true);


//cout << "hourly rate is: " << employee1.getHourlyRate() << endl;
Paycheck px1 = Paycheck(100, 0, 0, 0, 0, true, employee1);
px1.displayCheck();

Paycheck px2 = Paycheck(100, 0, 0, 0, 0, true, employee2);
px2.displayCheck();

Paycheck px3 = Paycheck(50, 2, 4, 0, 0, true, employee3);
px3.displayCheck();

Paycheck px4 = Paycheck(50, 2, 4, 0, 0, true, employee4);
px4.displayCheck();
cout << "Certificated: " << employee4->getCertificated() << endl;

Payroll payroll = Payroll(6, 15, 2022, 1, 1, 2022, 
1, 15, 2022);
payroll.displayPayrollCheckDate();
payroll.displayPayrollPayperiod();
cout << "Quarter: " << payroll.getQuarter() << endl << endl;

cout << "My name is " << employee3->getName() << " and ";
employee3->showSummerSchedule();
cout << endl << endl;

cout << "My name is " << employee4->getName() << " and ";
employee4->showSummerSchedule();
cout << endl << endl;
**/

PayrollProgram test;
test.menu();

}
#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

int main()
{

//function that calculates gross, net, taxes after deductions are entered; which will 
//also add any additional payments if any & pay it correctly
//function that handles additional payments; how should they be paid out?  

//CLASSES
//employee - information such as withholding, member of ARetirement or BRetirement, taxable for social security/exempt, 
//YTD values, termination status, hourly/salary
//check stub - check date, quarter, year, gross, deductions, taxes, net, direct deposit/live/manual check
//payroll - check stubs for all employees receiving a check

cout << "hello world" << endl;
Employee employee1;
cout << "hourly rate is: " << employee1.getHourlyRate() << endl;

}
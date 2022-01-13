#include <iostream>
#include <iomanip>
#include "Paycheck.h"
using namespace std;

int main()
{

//default constructor
Employee * employee1 = new Employee;

//constructor
Employee * employee2 = new Employee("Alex", "1224 Egar St", "San Diego", "CA", 92118, "Full Time", "Salary", 
50.00, .05, .075);

//constructor
Employee * employee3 = new Employee("Jeanvally", "1224 Egar St", "San Diego", "CA", 92118, "Full Time", "Salary", 
50.00, .10, .15);

//cout << "hourly rate is: " << employee1.getHourlyRate() << endl;
Paycheck px1 = Paycheck(100, 0, 0, 0, 0, true, employee1);
px1.displayCheck();

Paycheck px2 = Paycheck(100, 0, 0, 0, 0, true, employee2);
px2.displayCheck();

Paycheck px3 = Paycheck(50, 2, 4, 0, 0, true, employee3);
px3.displayCheck();

}
#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "Paycheck.h"
using namespace std;

int main()
{

Employee employee1;
cout << "hourly rate is: " << employee1.getHourlyRate() << endl;
Paycheck px1 = Paycheck(100, 0, 0, 0, 0, true);
cout << "Paycheck #1: " << endl;
cout << "gross: " << px1.getGrossAmount() << endl;
cout << "net: " << px1.getNetPay() << endl;
cout << "pretaxHealth: " << px1.getPreTaxHealthDeduction() << endl;
cout << "postaxHealth: " << px1.getPostTaxHealthDeduction() << endl;


}
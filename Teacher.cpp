#include "Teacher.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Teacher contructor only needs to implement setting Teacher attributes.  Employee constructor can be utilized for inherited attributes.
Teacher::Teacher(string LastName, string FirstName, string Address, string City, string State, long int ZipCode, string EmploymentStatus, string Type, 
double HourlyRate, double StatePercentage, double FederalPercentage, bool Certificated)
    :Employee(LastName, FirstName, Address, City, State, ZipCode, EmploymentStatus, Type, HourlyRate, StatePercentage, FederalPercentage)
{
    certificated = Certificated;
} 

void Teacher::setCertificated(bool Certificated){
    certificated = Certificated;
}

bool Teacher::getCertificated(){
    return certificated;
}

void Teacher::showSummerSchedule(){
    cout << "I have summer break off!" << endl;
}
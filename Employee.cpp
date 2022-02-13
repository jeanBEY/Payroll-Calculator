#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

Employee::Employee() {
    name = "";
    address =""; 
    city="";
    state="";
    zipcode=0;
    employmentStatus="";
    type="";
    hourlyRate=0;
    federalPercentage = 0;
    statePercentage = 0;
}

Employee::Employee(string Name, string Address, string City, string State, long int ZipCode, string EmploymentStatus, string Type, 
double HourlyRate, double StatePercentage, double FederalPercentage) {
    setName(Name);
    setAddress(Address); 
    setCity(City);
    setState(State);
    setZipCode(ZipCode);
    setEmploymentStatus(EmploymentStatus);
    setType(Type);
    setHourlyRate(HourlyRate);
    setStatePercentage(StatePercentage);
    setFederalPercentage(FederalPercentage);
}

void Employee::setName(string Name){
    name = Name;
}

string Employee::getName(){
    return name;
}

void Employee::setAddress(string Address){
    address = Address;
}

string Employee::getAddress(){
    return address;
}

void Employee::setCity(string City){
    city = City;
}

string Employee::getCity(){
    return city;
}

void Employee::setState(string State){
    state = State;
}

string Employee::getState(){
    return state;
}

void Employee::setZipCode(long int ZipCode){
    zipcode = ZipCode;
}

long int Employee::getZipCode(){
    return zipcode;
}

void Employee::setEmploymentStatus(string EmploymentStatus){
    employmentStatus = EmploymentStatus;
}

string Employee::getEmploymentStatus(){
    return employmentStatus;
}

void Employee::setType(string Type){
    type = Type;
}

string Employee::getType(){
    return type;
}

void Employee::setHourlyRate(double HourlyRate){
    hourlyRate = HourlyRate;
}

double Employee::getHourlyRate(){
    return hourlyRate;
}

void Employee::setStatePercentage(double StatePercentage){
    statePercentage = StatePercentage;
}

double Employee::getStatePercentage(){
    return statePercentage;
}

void Employee::setFederalPercentage(double FederalPercentage){
    federalPercentage = FederalPercentage;
}

double Employee::getFederalPercentage(){
    return federalPercentage;
}

//Virtual function
void Employee::showSummerSchedule(){
    cout << "I have to work this summer." << endl;
}

void Employee::displayEmployeeInformation(){
    cout << endl << "Name:                  " << name <<endl;
    cout << "Address:               " << address <<endl; 
    cout << "City:                  " << city <<endl;
    cout << "State:                 " << state <<endl;
    cout << "Zip Code:              " << zipcode <<endl;
    cout << "Employment Status:     " << employmentStatus <<endl;
    cout << "Type:                  " << type <<endl;
    cout << "Hourly Rate:           " << hourlyRate <<endl;
    cout << "Federal Percentage:    " << federalPercentage <<endl;
    cout << "State Percentage:      " << statePercentage <<endl << endl;

}

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
}

Employee::Employee(string Name, string Address, string City, string State, long int ZipCode, string EmploymentStatus, string Type, double HourlyRate) {
    setName(Name);
    setAddress(Address); 
    setCity(City);
    setState(State);
    setZipCode(ZipCode);
    setEmploymentStatus(EmploymentStatus);
    setType(Type);
    setHourlyRate(HourlyRate);
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


//employee - information such as withholding, member of ARetirement or BRetirement, taxable for social security/exempt, 
//YTD values, termination status, hourly/salary
#ifndef Employee_hpp
#define Employee_hpp
#include <iostream>
#include <iomanip>
using namespace std;

class Employee{
    protected: 
        string lastName;
        string firstName;
        string address; 
        string city;
        string state;
        long int zipcode;
        string employmentStatus;  //Full Time or Part Time
        string type;              //Salary or Hourly
        double hourlyRate;
        double statePercentage;   //Will need to incorporate W4 later, for now employee will have set percentage
        double federalPercentage; //Will need to incorporate W4 later, for now employee will have set percentage

    public:

        //Constrctors
        Employee();
        Employee(string, string, string, string, string, long int, string, string, double, double, double);

        //Setters
        void setLastName(string);
        void setFirstName(string);
        void setAddress(string);
        void setCity(string);
        void setState(string);
        void setZipCode(long int);
        void setEmploymentStatus(string);
        void setType(string);
        void setHourlyRate(double);
        void setStatePercentage(double);
        void setFederalPercentage(double);

        //Getters
        string getLastName();
        string getFirstName();
        string getAddress();
        string getCity();
        string getState();
        long int getZipCode();
        string getEmploymentStatus();
        string getType();
        double getHourlyRate();
        double getStatePercentage();
        double getFederalPercentage();

        //Virtual function
        virtual void showSummerSchedule();

        //Display Employee information
        void displayEmployeeInformation();

};

#endif
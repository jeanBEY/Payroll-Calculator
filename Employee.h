#include <iostream>
#include <iomanip>
using namespace std;

class Employee{
    protected: 
        string name;
        string address; 
        string city;
        string state;
        long int zipcode;
        string employmentStatus;
        string type;
        double hourlyRate;

    public:

        //Constrctors
        Employee();
        Employee(string, string, string, string, long int, string, string, double);

        //Setters
        void setName(string);
        void setAddress(string);
        void setCity(string);
        void setState(string);
        void setZipCode(long int);
        void setEmploymentStatus(string);
        void setType(string);
        void setHourlyRate(double);

        //Getters
        string getName();
        string getAddress();
        string getCity();
        string getState();
        long int getZipCode();
        string getEmploymentStatus();
        string getType();
        double getHourlyRate();
};
#include <iostream>
#include <iomanip>
using namespace std;

//Base/Parent/Super Class will have all the same information that any emlpoyee will have
class Employee{
    private: 
        string name;
        string address; 
        string city;
        string state;
        long int zipcode;
        string employmentStatus;
        string type;
        double hourlyRate;

        //Maybe inheritance for salary employees reportable to CalSTRS/CalPERS, hourly employees reportable to CalSTRS/CalPERS
        /**        
        bool overtimeExempt;
        bool socialSecurityExempt;
        bool medicareExempt;
        int salaryPerPayPeriod;
        int numPayPeriods;
        int annualSalaryProrated;
        int numPayPeriods100FTE;
        int annualSalary100FTE;
        **/

    public:
        Employee();
        Employee(string, string, string, string, long int, string, string, double);
        void setName(string);
        string getName();
        void setAddress(string);
        string getAddress();
        void setCity(string);
        string getCity();
        void setState(string);
        string getState();
        void setZipCode(long int);
        long int getZipCode();
        void setEmploymentStatus(string);
        string getEmploymentStatus();
        void setType(string);
        string getType();
        void setHourlyRate(double);
        double getHourlyRate();
};
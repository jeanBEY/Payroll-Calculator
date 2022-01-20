#ifndef Teacher_hpp
#define Teacher_hpp
#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

//Derived Class or Child Class or Sub Class
//"public Employee" so any dervived classes have access to methods
class Teacher: public Employee{
    private: 
        bool certificated;
        
    public:
        //Constrctor
        Teacher(string, string, string, string, long int, string, string, double, double, double, bool);

        //Setter
        void setCertificated(bool);

        //Getter
        bool getCertificated();

        //Virtual function (polymorphism, most derived implementation will be invoked)
        void showSummerSchedule();
};

#endif
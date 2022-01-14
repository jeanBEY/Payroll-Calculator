#ifndef Paycheck_hpp
#define Paycheck_hpp
#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

//Base Class or Parent Class or Super Class
class Paycheck{

    //protected so any derived class has access to the attributes of base class
    protected: 
        
        double grossAmount;
        double preTaxHealthDeduction;
        double postTaxHealthDeduction;
        double retirementDeduction401k;
        double retirementDeductionRoth401k;
        double federalTax;
        double stateTax;
        double stateDisabilityInsuranceTax;
        double stateUnemploymentInsuranceTax;
        double medicareTax;
        double socialSecurityTax;
        double netPay;
        bool directDeposit;
        Employee* employeePointer;

    public:

        //Constrctors
        Paycheck();
        Paycheck(double, double, double, double, double, bool, Employee*);

        //Destructor
        ~Paycheck();

        //Setters
        void setGrossAmount(double);
        void setPreTaxHealthDeduction(double);
        void setPostTaxHealthDeduction(double);
        void setRetirementDeduction401k(double);
        void setRetirementDeductionRoth401k(double);
        void setFederalTax(double);
        void setStateTax(double);
        void setStateDisabilityInsuranceTax(double);
        void setStateUnemploymentInsuranceTax(double);
        void setMedicareTax(double);
        void setSocialSecurityTax(double);
        void setNetPay(double);
        void setDirectDeposit(bool);

        //Getters
        double getGrossAmount();
        double getPreTaxHealthDeduction();
        double getPostTaxHealthDeduction();
        double getRetirementDeduction401k();
        double getRetirementDeductionRoth401k();
        double getFederalTax();
        double getStateTax();
        double getStateDisabilityInsuranceTax();
        double getStateUnemploymentInsuranceTax();
        double getMedicareTax();
        double getSocialSecurityTax();
        double getNetPay();
        bool getDirectDeposit();

        //Calculate check to get net pay & taxes
        void calculateCheck(Employee *);

        //Display check preview
        void displayCheck();

};

#endif
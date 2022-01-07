#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Paycheck{
    private: 
        
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

};
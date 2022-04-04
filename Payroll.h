#ifndef Payroll_hpp
#define Payroll_hpp
#include "Paycheck.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Payroll{

    private: 
       int year;
       int month;
       int day;
       int quarter;

       int payperiodStartYear;
       int payperiodStartMonth;
       int payperiodStartDay;

       int payperiodEndYear;
       int payperiodEndMonth;
       int payperiodEndDay;

       double payrollGrossAmount;
       double payrollPreTaxHealthDeduction;
       double payrollPostTaxHealthDeduction;
       double payrollRetirementDeduction401k;
       double payrollRetirementDeductionRoth401k;
       double payrollFederalTax;
       double payrollStateTax;
       double payrollStateDisabilityInsuranceTax;
       double payrollStateUnemploymentInsuranceTax;
       double payrollMedicareTax;
       double payrollSocialSecurityTax;
       double payrollNetPay;

       int payrollNumberOfPaychecks;
       int payrollNumberOfEmployees;

       struct paycheckNode
       {
           Paycheck * paycheckPointer;
           paycheckNode *next;
           paycheckNode *previous;
        };
        
        paycheckNode *head;    //head pointer
        paycheckNode *tail;    //tail pointer

    public:

        //Constrctors
        Payroll(int, int, int, int, int, int, int, int, int);

        //Destructor

        //Setters
        void setYear(int);
        void setMonth(int);
        void setDay(int);
        void setQuarter(int);

        void setPayperiodStartYear(int);
        void setPayperiodStartMonth(int);
        void setPayperiodStartDay(int);

        void setPayperiodEndYear(int);
        void setPayperiodEndMonth(int);
        void setPayperiodEndDay(int);

        void setPayrollGrossAmount(double);
        void setPayrollPreTaxHealthDeduction(double);
        void setPayrollPostTaxHealthDeduction(double);
        void setPayrollRetirementDeduction401k(double);
        void setPayrollRetirementDeductionRoth401k(double);
        void setPayrollFederalTax(double);
        void setPayrollStateTax(double);
        void setPayrollStateDisabilityInsuranceTax(double);
        void setPayrollStateUnemploymentInsuranceTax(double);
        void setPayrollMedicareTax(double);
        void setPayrollSocialSecurityTax(double);
        void setPayrollNetPay(double);
        
        void setPayrollNumberOfPaychecks(int);
        void setPayrollNumberOfEmployees(int);

       //Getters
       int getYear();
       int getMonth();
       int getDay();
       int getQuarter();
       
       int getPayperiodStartYear();
       int getPayperiodStartMonth();
       int getPayperiodStartDay();
       
       int getPayperiodEndYear();
       int getPayperiodEndMonth();
       int getPayperiodEndDay();
       
       double getPayrollGrossAmount();
       double getPayrollPreTaxHealthDeduction();
       double getPayrollPostTaxHealthDeduction();
       double getPayrollRetirementDeduction401k();
       double getPayrollRetirementDeductionRoth401k();
       double getPayrollFederalTax();
       double getPayrollStateTax();
       double getPayrollStateDisabilityInsuranceTax();
       double getPayrollStateUnemploymentInsuranceTax();
       double getPayrollMedicareTax();
       double getPayrollSocialSecurityTax();
       double getPayrollNetPay();
       
       int getPayrollNumberOfPaychecks();
       int getPayrollNumberOfEmployees();

       //Display payroll check date
       void displayPayrollCheckDate();

       //Display payroll pay period
       void displayPayrollPayperiod();

};

#endif
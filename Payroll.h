#ifndef Payroll_hpp
#define Payroll_hpp
#include "Paycheck.h"
#include "Employee.h"
#include <string>
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
           paycheckNode * next;
           paycheckNode * previous;
           paycheckNode();
        };
        
        paycheckNode * head;    //head pointer
        paycheckNode * tail;    //tail pointer
        paycheckNode * iterator; //current pointer

        bool payrollHasProcessed;

    public:

        //Constrctors
        Payroll(int, int, int, int, int, int, int, int, int);

        //Destructor
        ~Payroll();
        
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

       //Add Paycheck node to linked list
       void addPaycheckNodeToEnd(double, double, double, double, double, bool, Employee*);

       //Preview payroll
       void previewPayroll(paycheckNode *);

       //Delete Paycheck node from linked list
       void deletePaycheckNode(paycheckNode *, paycheckNode *);

       //Process payroll
       void processThePayroll();

       //Increment payroll number of checks by 1
       void incrementPayrollNumberOfChecks();

       //Traversing linked list
       paycheckNode * nextPaycheckNode(paycheckNode *);
       paycheckNode * previousPaycheckNode(paycheckNode *);

       //Return first node in linked list
       paycheckNode * getHeadPaycheckNode();

       //Return last node in linked list
       paycheckNode * getTailPaycheckNode();

       //set the iterator
       void setIterator(paycheckNode *);

       paycheckNode * getIterator();
};

#endif
#include "Payroll.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructors
Payroll::Payroll(int Month, int Day, int Year, int PayperiodStartMonth, int PayperiodStartDay, int PayperiodStartYear, 
int PayperiodEndMonth, int PayperiodEndDay, int PayperiodEndYear)  //pass in check date, pay period start, pay period end (month, day, year)
{
    //initialize linked list of paycheck nodes to null
    head = NULL;
    tail = NULL;
    iterator = NULL;

    //initializing starting values
    payrollHasProcessed = false;
    payrollNumberOfPaychecks = 0;
    payrollNumberOfEmployees = 0;

    setMonth(Month);
    setDay(Day);
    setYear(Year);

    //quarter is determined base on what month in the calendar year the check date falls in
    if(month == 1 || month == 2 || month == 3){
        quarter = 1;
    }
    if(month == 4 || month == 5 || month == 6){
        quarter = 2;
    }
    if(month == 7 || month == 8 || month == 9){     //can't use 08 or 09 or else it will be seen as an octal digit
        quarter = 3;
    }
    if(month == 10 || month == 11 || month == 12){
        quarter = 4;
    }

    setPayperiodStartMonth(PayperiodStartMonth);
    setPayperiodStartDay(PayperiodStartDay);
    setPayperiodStartYear(PayperiodStartYear);
 
    setPayperiodEndMonth(PayperiodEndMonth);
    setPayperiodEndDay(PayperiodEndDay);
    setPayperiodEndYear(PayperiodEndYear);

    setPayrollNumberOfEmployees(0);
    setPayrollNumberOfPaychecks(0);

    cout << "-----------------------------------" << endl;
    cout << "Great!  Let's begin the payroll..." << endl;
    cout << "-----------------------------------" << endl;
    displayPayrollCheckDate();
    displayPayrollPayperiod();
    cout << "-----------------------------------" << endl;
}

//Destructor
Payroll::~Payroll(){
    paycheckNode *temp = head;        //Begin at head of list, and traverse through deallocating
    while(temp != NULL)
    {
        paycheckNode *trash = temp;   //Assign first node to trash
        temp = temp->next;            //Assign second node to temp
        delete trash;                 //Delete first node
        if(temp == NULL)              //So we don't access NULL pointers
        {
            break;
        }
    }
}

//Setters
void Payroll::setYear(int Year){
    year = Year;
}
void Payroll::setMonth(int Month){
    month = Month;
}
void Payroll::setDay(int Day){
    day = Day;
}
void Payroll::setQuarter(int Quarter){
    quarter = Quarter;
}

void Payroll::setPayperiodStartYear(int PayperiodStartYear){
    payperiodStartYear = PayperiodStartYear;
}
void Payroll::setPayperiodStartMonth(int PayperiodStartMonth){
    payperiodStartMonth = PayperiodStartMonth;
}
void Payroll::setPayperiodStartDay(int PayperiodStartDay){
    payperiodStartDay = PayperiodStartDay;
}

void Payroll::setPayperiodEndYear(int PayperiodEndYear){
    payperiodEndYear = PayperiodEndYear;
}
void Payroll::setPayperiodEndMonth(int PayperiodEndMonth){
    payperiodEndMonth = PayperiodEndMonth;
}
void Payroll::setPayperiodEndDay(int PayperiodEndDay){
    payperiodEndDay = PayperiodEndDay;
}

void Payroll::setPayrollGrossAmount(double PayrollGrossAmount){
    payrollGrossAmount = PayrollGrossAmount;
}
void Payroll::setPayrollPreTaxHealthDeduction(double PayrollPreTaxHealthDeduction){
    payrollPreTaxHealthDeduction = PayrollPreTaxHealthDeduction;
}
void Payroll::setPayrollPostTaxHealthDeduction(double PayrollPostTaxHealthDeduction){
    payrollPostTaxHealthDeduction = PayrollPostTaxHealthDeduction;
}
void Payroll::setPayrollRetirementDeduction401k(double PayrollRetirementDeduction401k){
    payrollRetirementDeduction401k = PayrollRetirementDeduction401k;
}
void Payroll::setPayrollRetirementDeductionRoth401k(double PayrollRetirementDeductionRoth401k){
    payrollRetirementDeductionRoth401k = PayrollRetirementDeductionRoth401k;
}
void Payroll::setPayrollFederalTax(double PayrollFederalTax){
    payrollFederalTax = PayrollFederalTax;
}    
void Payroll::setPayrollStateTax(double PayrollStateTax){
    payrollStateTax = PayrollStateTax;
}
void Payroll::setPayrollStateDisabilityInsuranceTax(double PayrollStateDisabilityInsuranceTax){
    payrollStateDisabilityInsuranceTax = PayrollStateDisabilityInsuranceTax;
}
void Payroll::setPayrollStateUnemploymentInsuranceTax(double PayrollStateUnemploymentInsuranceTax){
    payrollStateUnemploymentInsuranceTax = PayrollStateUnemploymentInsuranceTax;
}
void Payroll::setPayrollMedicareTax(double PayrollMedicareTax){
    payrollMedicareTax = PayrollMedicareTax;
}
void Payroll::setPayrollSocialSecurityTax(double PayrollSocialSecurityTax){
    payrollSocialSecurityTax = PayrollSocialSecurityTax;
}
void Payroll::setPayrollNetPay(double PayrollNetPay){
    payrollNetPay = PayrollNetPay;
}

void Payroll::setPayrollNumberOfPaychecks(int PayrollNumberOfPaychecks){
    payrollNumberOfPaychecks = PayrollNumberOfPaychecks;
}
void Payroll::setPayrollNumberOfEmployees(int PayrollNumberOfEmployees){
    payrollNumberOfEmployees = PayrollNumberOfEmployees;
}

//Getters
int Payroll::getYear(){
    return year;
}
int Payroll::getMonth(){
    return month;
}
int Payroll::getDay(){
    return day;
}
int Payroll::getQuarter(){
    return quarter;
}

int Payroll::getPayperiodStartYear(){
    return payperiodStartYear;
}
int Payroll::getPayperiodStartMonth(){
    return payperiodStartMonth;
}
int Payroll::getPayperiodStartDay(){
    return payperiodStartDay;
}

int Payroll::getPayperiodEndYear(){
    return payperiodEndYear;
}
int Payroll::getPayperiodEndMonth(){
    return payperiodEndMonth;
}
int Payroll::getPayperiodEndDay(){
    return payperiodEndDay;
}

double Payroll::getPayrollGrossAmount(){
    return payrollGrossAmount;
}
double Payroll::getPayrollPreTaxHealthDeduction(){
    return payrollPreTaxHealthDeduction;
}
double Payroll::getPayrollPostTaxHealthDeduction(){
    return payrollPostTaxHealthDeduction;
}
double Payroll::getPayrollRetirementDeduction401k(){
    return payrollRetirementDeduction401k;
}
double Payroll::getPayrollRetirementDeductionRoth401k(){
    return payrollRetirementDeductionRoth401k;
}
double Payroll::getPayrollFederalTax(){
    return payrollFederalTax ;
}
double Payroll::getPayrollStateTax(){
    return payrollStateTax;
}
double Payroll::getPayrollStateDisabilityInsuranceTax(){
    return payrollStateDisabilityInsuranceTax;
}
double Payroll::getPayrollStateUnemploymentInsuranceTax(){
    return payrollStateUnemploymentInsuranceTax;
}
double Payroll::getPayrollMedicareTax(){
    return payrollMedicareTax;
}
double Payroll::getPayrollSocialSecurityTax(){
    return payrollSocialSecurityTax;
}
double Payroll::getPayrollNetPay(){
    return payrollNetPay;
}

int Payroll::getPayrollNumberOfPaychecks(){
    return payrollNumberOfPaychecks;
}
int Payroll::getPayrollNumberOfEmployees(){
    return payrollNumberOfEmployees;
}

//Display payroll check date
void Payroll::displayPayrollCheckDate()
{   
    cout << "Check Date: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}

//Display payroll pay period
void Payroll::displayPayrollPayperiod()
{
    cout << "Pay Period: " << getPayperiodStartMonth() << "/" << getPayperiodStartDay() << "/" << getPayperiodStartYear() << 
    " - " << getPayperiodEndMonth() << "/" << getPayperiodEndDay() << "/" << getPayperiodEndYear() << endl;
}

//Add Paycheck node to linked list
void Payroll::addPaycheckNodeToEnd(double GrossAmount, double PreTaxHealthDeduction, double PostTaxHealthDeduction, 
double RetirementDeduction401k, double RetirementDeductionRoth401k, bool DirectDeposit, Employee * EmployeePointer){

    //Create Paycheck pointer
    Paycheck * newPaycheckPointer = new Paycheck(GrossAmount, PreTaxHealthDeduction, PostTaxHealthDeduction, 
RetirementDeduction401k, RetirementDeductionRoth401k, DirectDeposit, EmployeePointer);

    //If there are no nodes that exist
    if(head == NULL){

        //Create first node
        paycheckNode * node = new paycheckNode();
        node->paycheckPointer = newPaycheckPointer;

        node->next = NULL;
        node->previous = NULL;

   
        //Both head & tail are pointing to the same single node
        head = node;
        tail = node;


        payrollNumberOfPaychecks++;
    }
    else{    


        //Otherwise, create subsequent node
        paycheckNode * node = new paycheckNode();
        node->paycheckPointer = newPaycheckPointer;
        node->next = NULL;
        node->previous = tail;
        tail->next = node;
        tail = node;

        payrollNumberOfPaychecks++;
    }
}

//Preview payroll checks
void Payroll::previewPayroll(paycheckNode * head){
    paycheckNode * traverser = head;
    while (traverser != NULL){
        traverser->paycheckPointer->displayCheck();
        traverser = traverser->next;
    }
}

//Delete Paycheck node
void Payroll::deletePaycheckNode(paycheckNode * head, paycheckNode * nodeToDelete){

    //Took from source
    //https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/

    //base case
    if(head == NULL || nodeToDelete == NULL){
        return;
    }

    //if node to be deleted is head node
    if(head == nodeToDelete){
        head = nodeToDelete->next;
    }

    //change next only if node to be deleted is not the last node
    if(nodeToDelete != NULL){
        nodeToDelete->next->previous = nodeToDelete->previous;
    }

    //change previous only if node to be deleted is not the first node
    if(nodeToDelete->previous != NULL){
        nodeToDelete->previous->next = nodeToDelete->next;
    }

    //delete the node by freeing memory
    delete nodeToDelete;
    nodeToDelete = 0;
    return;
}

//Process the payroll
void Payroll::processThePayroll(){

    payrollHasProcessed = true;
}

void Payroll::incrementPayrollNumberOfChecks(){

    //increase by 1
    payrollNumberOfPaychecks++;
}

//Struct needs to be preceeded by classname:: if we are returning a struct
Payroll::paycheckNode* Payroll::nextPaycheckNode(paycheckNode * currentNode){
    return currentNode->next;
}

//Struct needs to be preceeded by classname:: if we are returning a struct
Payroll::paycheckNode* Payroll::previousPaycheckNode(paycheckNode * currentNode){
    return currentNode->previous;
}

//Struct needs to be preceeded by classname:: if we are returning a struct
Payroll::paycheckNode* Payroll::getHeadPaycheckNode(){
    return head;
}

//Struct needs to be preceeded by classname:: if we are returning a struct
Payroll::paycheckNode* Payroll::getTailPaycheckNode(){
    return tail;
}

Payroll::paycheckNode::paycheckNode(){

    //EMPTY IN ORDER TO CREATE NODES

}

void Payroll::setIterator(paycheckNode * currentNode){
    iterator = currentNode;
}

Payroll::paycheckNode* Payroll::getIterator(){
    return iterator;
}
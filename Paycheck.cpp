#include "Paycheck.h"
#include <iostream>
#include <iomanip>
using namespace std;

Paycheck::Paycheck() {
    grossAmount=0;
    preTaxHealthDeduction=0;
    postTaxHealthDeduction=0;
    retirementDeduction401k=0;
    retirementDeductionRoth401k=0;
    stateTax=0;
    stateDisabilityInsuranceTax=0;
    stateUnemploymentInsuranceTax=0;
    medicareTax=0;
    socialSecurityTax=0;
    netPay=0;
    directDeposit = false;
    employeePointer=0;
}

Paycheck::Paycheck(double grossAmount, double preTaxHealthDeduction, double postTaxHealthDeduction, 
double retirementDeduction401k, double retirementDeductionRoth401k, bool directDeposit, Employee * EmployeePointer) {
    setGrossAmount(grossAmount);
    setPreTaxHealthDeduction(preTaxHealthDeduction);
    setPostTaxHealthDeduction(postTaxHealthDeduction);
    setRetirementDeduction401k(retirementDeduction401k);
    setRetirementDeductionRoth401k(retirementDeductionRoth401k);
    setDirectDeposit(directDeposit);
    stateTax=0;
    stateDisabilityInsuranceTax=0;
    stateUnemploymentInsuranceTax=0;
    medicareTax=0;
    socialSecurityTax=0;
    netPay=0;
    employeePointer = EmployeePointer;
    calculateCheck(employeePointer);
} 

//Destructor
Paycheck::~Paycheck(){
    delete employeePointer;
}

void Paycheck::setGrossAmount(double GrossAmount){
    grossAmount = GrossAmount;
}

double Paycheck::getGrossAmount(){
    return grossAmount;
}

void Paycheck::setPreTaxHealthDeduction(double PreTaxHealthDeduction){
    preTaxHealthDeduction = PreTaxHealthDeduction;
}

double Paycheck::getPreTaxHealthDeduction(){
    return preTaxHealthDeduction;
}

void Paycheck::setPostTaxHealthDeduction(double PostTaxHealthDeduction){
    postTaxHealthDeduction = PostTaxHealthDeduction;
}

double Paycheck::getPostTaxHealthDeduction(){
    return postTaxHealthDeduction;
}

void Paycheck::setRetirementDeduction401k(double RetirementDeduction401k){
    retirementDeduction401k = RetirementDeduction401k;
}

double Paycheck::getRetirementDeduction401k(){
    return retirementDeduction401k;
}

void Paycheck::setRetirementDeductionRoth401k(double RetirementDeductionRoth401k){
    retirementDeductionRoth401k = RetirementDeductionRoth401k;
}

double Paycheck::getRetirementDeductionRoth401k(){
    return retirementDeductionRoth401k;
}

void Paycheck::setFederalTax(double FederalTax){
    federalTax = FederalTax;
}

double Paycheck::getFederalTax(){
    return federalTax;
}

void Paycheck::setStateTax(double StateTax){
    stateTax = StateTax;
}

double Paycheck::getStateTax(){
    return stateTax;
}

void Paycheck::setStateDisabilityInsuranceTax(double StateDisabilityInsuranceTax){
    stateDisabilityInsuranceTax = StateDisabilityInsuranceTax;
}

double Paycheck::getStateDisabilityInsuranceTax(){
    return stateDisabilityInsuranceTax;
}

void Paycheck::setStateUnemploymentInsuranceTax(double StateUnemploymentInsuranceTax){
    stateUnemploymentInsuranceTax = StateUnemploymentInsuranceTax;
}

double Paycheck::getStateUnemploymentInsuranceTax(){
    return stateUnemploymentInsuranceTax;
}

void Paycheck::setMedicareTax(double MedicareTax){
    medicareTax = MedicareTax;
}

double Paycheck::getMedicareTax(){
    return medicareTax;
}

void Paycheck::setSocialSecurityTax(double SocialSecurityTax){
    socialSecurityTax = SocialSecurityTax;
}

double Paycheck::getSocialSecurityTax(){
    return socialSecurityTax;
}

void Paycheck::setNetPay(double NetPay){
    netPay = NetPay;
}

double Paycheck::getNetPay(){
    return netPay;
}

void Paycheck::setDirectDeposit(bool DirectDeposit){
    directDeposit = DirectDeposit;
}

bool Paycheck::getDirectDeposit(){
    return directDeposit;
}

void Paycheck::calculateCheck(Employee * EmployeePointer){
    
    //federal = federal withholding * gross - pretaxhealth & 401k
    federalTax = EmployeePointer->getFederalPercentage() * (grossAmount - preTaxHealthDeduction - retirementDeduction401k);

    //state = state withholding * gross - pretax & 401k
    stateTax = EmployeePointer->getStatePercentage() * (grossAmount - preTaxHealthDeduction - retirementDeduction401k);

    //medicare = gross - pretax * 1.45%
    medicareTax = (grossAmount - preTaxHealthDeduction) * .0145;

    //social security = gross - pretax * 6.2%
    socialSecurityTax = (grossAmount - preTaxHealthDeduction) * .062;

    //SDI = gross - pretax * 1.1%
    stateDisabilityInsuranceTax = (grossAmount - preTaxHealthDeduction) * .011;

    //SUI = gross - pretax * .05%
    stateUnemploymentInsuranceTax = (grossAmount - preTaxHealthDeduction) * .005;

    //net pay = gross - deductions (pre & post) - taxes
    netPay = grossAmount - preTaxHealthDeduction - retirementDeduction401k - postTaxHealthDeduction - 
        retirementDeductionRoth401k - federalTax - stateTax - medicareTax - socialSecurityTax - stateDisabilityInsuranceTax - stateUnemploymentInsuranceTax;
}

void Paycheck::displayCheck(){
    cout << "********************************" << endl;
    cout << "*                              *" << endl;
    cout << "*        Check Preview         *" << endl;
    cout << "*                              *" << endl;
    cout << "********************************" << endl << endl;
    cout << "NAME:            " << employeePointer->getName() << endl << endl;  
    cout << "EARNINGS" << endl;
    cout << "Gross:           " << setprecision(2) << fixed << getGrossAmount() << endl << endl;
    cout << "DEDUCTIONS" << endl;
    cout << "Pre-Tax Health:  " << getPreTaxHealthDeduction() << endl;
    cout << "Post-Tax Health: " << getPostTaxHealthDeduction() << endl;
    cout << "401k:            " << getRetirementDeduction401k() << endl;
    cout << "Roth 401k:       " << getRetirementDeductionRoth401k() << endl << endl;
    cout << "TAXES" << endl;
    cout << "Federal:         " << getFederalTax() << endl;
    cout << "State:           " << getStateTax() << endl;
    cout << "Medicare:        " << getMedicareTax() << endl;
    cout << "Social Security: " << getSocialSecurityTax() << endl;
    cout << "SDI:             " << getStateDisabilityInsuranceTax() << endl;
    cout << "SUI:             " << getStateUnemploymentInsuranceTax() << endl << endl;
    cout << "NET PAY:         " << getNetPay() << endl << endl;
}


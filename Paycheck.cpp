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
}

Paycheck::Paycheck(double grossAmount, double preTaxHealthDeduction, double postTaxHealthDeduction, 
double retirementDeduction401k, double retirementDeductionRoth401k, bool directDeposit) {
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
    
    //WORK ON NEXT - NEED TO ADD FUNCTIONALITY HERE TO CALCULATE NET PAY & TAXES
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
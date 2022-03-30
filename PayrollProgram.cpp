#include "PayrollProgram.h"
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <limits>
using namespace std;

PayrollProgram::PayrollProgram() {
    cout << "***************************" << endl;
    cout << "*                         *" << endl;
    cout << "*     PAYROLL PROGRAM     *" << endl;
    cout << "*                         *" << endl;
    cout << "***************************" << endl << endl;
    cout << "Welcome!" << endl << endl;

}

PayrollProgram::~PayrollProgram() {
    cout << "***************************" << endl;
    cout << "*                         *" << endl;
    cout << "*         GOODBYE         *" << endl;
    cout << "*                         *" << endl;
    cout << "***************************" << endl;

}

//Getters
int PayrollProgram::getActiveEmployeeCount(){
    return activeEmployeeCount;
}

int PayrollProgram::getBudgetedNumOfEmployees(){
    return budgetedNumOfEmployees;
}

bool PayrollProgram::getAskedForBudgetedNumOfEmployees(){
    return askedForBudgetedNumOfEmployees;
}

//Setters
void PayrollProgram::setActiveEmployeeCount(int ActiveEmployeeCount){
    activeEmployeeCount = ActiveEmployeeCount;
}
void PayrollProgram::setBudgetedNumOfEmployees(int BudgetedNumOfEmployees){
    budgetedNumOfEmployees = BudgetedNumOfEmployees;
}
void PayrollProgram::setAskedForBudgetedNumOfEmployees(bool AskedForBudgetedNumOfEmployees){
    askedForBudgetedNumOfEmployees = AskedForBudgetedNumOfEmployees;
}


void PayrollProgram::menu() {

    int choice;

    cout << "***************************" << endl;
    cout << "*           MENU          *" << endl;
    cout << "***************************" << endl << endl;
    cout << "1.) HIRE EMPLOYEE" << endl;
    cout << "2.) PROCESS PAYROLL" << endl;
    cout << "3.) QUIT" << endl << endl;
    cout << "Enter 1 to hire an employee, 2 to process payroll, or, 3 to quit.. " << endl << endl;

    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    if (choice == 1){
        hireEmployee();
    }
    else if (choice == 2){
        cout << endl << "Let's process payroll! " << endl << endl;
        processPayroll();
    }
    else if (choice == 3) {
        cout << endl << "Quitting the program! " << endl << endl;
        quit();
    }
    else{
        cout << endl << "Invalid entry!  Try again..." << endl << endl;
        menu();
    }
    
}

//Hire one employee at a time.  The employee will be valid for the duration of the program.
void PayrollProgram::hireEmployee() {

    //New employee attributes
    string LastName;
    string FirstName;
    string Address;
    string City;
    string State;
    long int ZipCode;
    string EmploymentStatus;
    string Type;
    double HourlyRate = 0;
    double StatePercentage = 0;
    double FederalPercentage = 0;

    //Only asked the first time the employer hires their first employee
    if(askedForBudgetedNumOfEmployees == false){
        cout << endl << "How many employees in total do you plan on employing?" << endl << endl;
        cin >> budgetedNumOfEmployees;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
        setAskedForBudgetedNumOfEmployees(true);
        activeEmployeeArray = new Employee * [(budgetedNumOfEmployees * 2)];        //initialize array of Employee pointers to be double the 
                                                                                    //anticipated employees the employer expects to employ
    }

    //Hire an employee
    cout << endl << "Let's hire an employee!" << endl << endl;
    cout << endl << "Please enter the following information..." << endl;
    cout << endl << "Last Name: " << endl;
    //cin.ignore();
    getline(cin, LastName);
    //cin >> LastName;
    //cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "First Name: " << endl;
    //cin.ignore();
    getline(cin, FirstName);
    //cin >> FirstName;
    //cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Address: " << endl;
    //cin.ignore();
    getline(cin, Address);
    //cin >> Address;
    //cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "City: " << endl;
    //cin.ignore();
    getline(cin, City);
    //cin >> City;
    //cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "State: " << endl;
    //cin.ignore();
    getline(cin, State);
    //cin >> State;
    //cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Zip Code: " << endl;
    //cin.ignore();
    //getline(cin, ZipCode, '\n');
    cin >> ZipCode;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Employment Status (1 for Full Time or 2 for Part Time): " << endl;
    int fulltimeOrParttime;
    //cin.ignore();
    //getline(cin, EmploymentStatus);
    cin >> fulltimeOrParttime;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
    if(fulltimeOrParttime == 1){
        EmploymentStatus = "Full Time";
    }
    else if(fulltimeOrParttime == 2){
        EmploymentStatus = "Part Time";
    }

    cout << endl << "Type (1 for Salary or 2 for Hourly): " << endl;
    int salaryOrHourly;
    //cin.ignore();
    //getline(cin, Type);
    cin >> salaryOrHourly;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
    if(salaryOrHourly == 1){
        Type = "Salary";
    }
    else if(salaryOrHourly == 2){
        Type = "Hourly";
    }

    cout << endl << "Hourly Rate: " << endl;
    //cin.ignore();
    //getline(cin, HourlyRate, '\n');
    cin >> HourlyRate;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)

    cout << endl << "Federal Withholding (1 for Single or 2 for Married): " << endl;
    int SingleOrMarriedFed;
    //cin.ignore();
    //getline(cin, SingleOrMarriedFed, '\n');
    cin >> SingleOrMarriedFed;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
    if(SingleOrMarriedFed == 1){
        FederalPercentage = .07;
    }
    else if(SingleOrMarriedFed == 2){
        FederalPercentage = .04;
    }

    cout << endl << "State Withholding (1 for Single or 2 for Married): " << endl;
    int SingleOrMarriedState;
    //cin.ignore();
    //getline(cin, SingleOrMarriedState, '\n');
    cin >> SingleOrMarriedState;
    //cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            //clears the buffer until new line character is hit (which is also cleared)
    if(SingleOrMarriedState == 1){
        StatePercentage = .07;
    }
    else if(SingleOrMarriedState == 2){
        StatePercentage = .04;
    }

    //Dynamically allocate Employee object & store address in temporary Employee pointer
    Employee * employeePointer = new Employee (LastName, FirstName, Address, City, State, ZipCode, 
    EmploymentStatus, Type, HourlyRate, StatePercentage, FederalPercentage);

    //Check if there is space in the array before adding the new Employee pointer
    if(activeEmployeeCount< (budgetedNumOfEmployees*2)){

        //ADD NEW HIRE TO ARRAY

        //assign address in temporary Employee pointer to current empty index
        activeEmployeeArray[activeEmployeeCount] = employeePointer; 

        //Display employee information that you just hired
        cout << endl << endl << "Great!  You've hired the following employee: " << endl;                  
        activeEmployeeArray[activeEmployeeCount]->displayEmployeeInformation();

        //incrememnt active employee count to include new hire just added
        activeEmployeeCount++;       

        //printing employee list
        cout << endl << "Printing Employee List..." << endl;
        printEmployeeList();          

        //display menu 
        menu(); 

    }
    else if (activeEmployeeCount >= (budgetedNumOfEmployees*2)){
        //Create temp array
        Employee ** tempEmployeeArray = new Employee * [(budgetedNumOfEmployees * 2)];                                 

        //Copy active employee array elements > temp array
        for(int i = 0; i < (budgetedNumOfEmployees *2); i++){
            tempEmployeeArray[i] = activeEmployeeArray[i];
        }

        //Delete active employee array elements (freed the array that the pointer variable is pointing to)
        delete [] activeEmployeeArray;
        activeEmployeeArray = 0;        //set to null or 0 because that deallocated memory could be used by another program

        //Updating budgeted number of employees & create larger dynamically allocated array
        budgetedNumOfEmployees = activeEmployeeCount;  
        activeEmployeeArray = new Employee * [(budgetedNumOfEmployees * 2)];

        //Copy temp array > new larger active employee array
        for(int i = 0; i < (activeEmployeeCount); i++){
            activeEmployeeArray[i] = tempEmployeeArray[i];
        }

        //Delete temp employee array
        delete [] tempEmployeeArray;
        tempEmployeeArray = 0;          //set to null or 0 because that deallocated memory could be used by another program

        //ADD NEW HIRE TO ARRAY

        //assign address in temporary Employee pointer to current empty index
        activeEmployeeArray[activeEmployeeCount] = employeePointer; 

        //Display employee information that you just hired
        cout << endl << endl << "Great!  You've hired the following employee: " << endl;
        activeEmployeeArray[activeEmployeeCount]->displayEmployeeInformation();

        //incrememnt active employee count to include new hire just added
        activeEmployeeCount++;     

        //printing employee list
        cout << endl << "Printing Employee List..." << endl;
        printEmployeeList();

        //display menu 
        menu(); 

    }                                    

}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
//https://www.geeksforgeeks.org/merge-sort/ 
void PayrollProgram::merge(Employee ** activeEmployeeArray, int const left, int const mid, int const right) {

    //https://www.asciitable.com/

    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
  
    // Create temp arrays
    Employee **leftArray = new Employee *[subArrayOne];
    Employee **rightArray = new Employee *[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = activeEmployeeArray[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = activeEmployeeArray[mid + 1 + j];
  
    int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {

        //************************************************************************************
        //Taken directly from link below
        //https://stackoverflow.com/questions/43268672/sorting-a-string-array-alphabetically-c
        string lastNameLeft, lastNameRight;
        lastNameLeft = leftArray[indexOfSubArrayOne]->getLastName();
        lastNameRight = rightArray[indexOfSubArrayTwo]->getLastName();

        cout << endl << "Comparing " << lastNameLeft << " vs " << lastNameRight << endl;

        // Find which name is shorter using .length()
        int shorterNameLength;
        if(lastNameLeft.length() <= lastNameRight.length()){
            shorterNameLength = lastNameLeft.length();
        }
        else {
            shorterNameLength = lastNameRight.length();
        }

        bool leftLessThanOrEqualToRight = true;
        bool continueChecking = true;

        cout << "Check Point 1" << endl;

        // Loop through this next part for all characters in each name for comparison
        for (int i = 0; i < shorterNameLength; i++)
        {   cout << "Check Point A" << endl;    
            if((i < shorterNameLength) && (leftLessThanOrEqualToRight == true) && (continueChecking == true))
            {
                cout << "Check Point B: " << lastNameLeft[i] << " " << lastNameRight[i] << endl;
                // Compare ascii values as I showed above.
                // If one is larger than the other, swap them.    
                if (lastNameLeft[i] > lastNameRight[i]) {
                    leftLessThanOrEqualToRight = false;
                    continueChecking = false;
                    cout << "Check Point F, right is greater" << endl;
                }        
                else if (lastNameLeft[i] < lastNameRight[i]) 
                {
                    continueChecking = false;
                }
                else if (lastNameLeft[i] == lastNameRight[i]) 
                {
                    cout << "Check Point C" << endl;
                    //if on last index of shortest name & left name is longer, left name is not <= right, therefore the right element will be added
                    if(i == (shorterNameLength-1))
                    {   cout << "Check Point D" << endl;
                        if(lastNameLeft.length() > lastNameRight.length())
                        {   cout << "Check Point E" << endl;
                            leftLessThanOrEqualToRight = false;
                        }
                    }
                    //if not on last index of shortest name, do nothing, break out of if statement, continue to next index
                
                }
            }
        }
        //end of snippet from link https://stackoverflow.com/questions/43268672/sorting-a-string-array-alphabetically-c
        //************************************************************************************

        cout << "Check Point 2" << endl;

        if (leftLessThanOrEqualToRight == true) {
            activeEmployeeArray[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            cout << "Check Point 3" << endl;
        }
        else {
            activeEmployeeArray[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            cout << "Check Point 4" << endl;
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        activeEmployeeArray[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        activeEmployeeArray[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    cout << "Check Point 5" << endl;

    delete [] leftArray;        
    leftArray = 0;              //set to null or 0 because that deallocated memory could be used by another program
    delete [] rightArray;       
    rightArray = 0;             //set to null or 0 because that deallocated memory could be used by another program
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
//https://www.geeksforgeeks.org/merge-sort/
void PayrollProgram::mergeSortActiveEmployeeArray(Employee ** activeEmployeeArray, int begin, int end) {

        if (begin >= end)
            return; // Returns recursively
    
        int mid = begin + (end - begin) / 2;

        cout << endl << "inside mergesort (" << begin << " , " << end << " ) " << endl;
        cout << "mid: " << mid << endl;

        mergeSortActiveEmployeeArray(activeEmployeeArray, begin, mid);
        mergeSortActiveEmployeeArray(activeEmployeeArray, mid + 1, end);
        merge(activeEmployeeArray, begin, mid, end);
}

void PayrollProgram::processPayroll(){

    cout << endl << "Inside processPayroll() prior to the mergesort" << endl;
    mergeSortActiveEmployeeArray(activeEmployeeArray, 0, activeEmployeeCount-1);
    cout << endl << "Inside processPayroll() AFTER to the mergesort" << endl;
    
    //printing employee list
    cout << endl << "STARTING PAYROLL - Printing Employee List..." << endl;
    printEmployeeList();  

    menu();

}

void PayrollProgram::printEmployeeList(){

    for(int i = 0; i < activeEmployeeCount; i++){
        activeEmployeeArray[i]->displayEmployeeInformation();
    }
    
}

int PayrollProgram::quit() {

    delete [] activeEmployeeArray;      //delete dynamically allocated array when program quits

    activeEmployeeArray = 0;            //no longer is pointing to memory

    return 0;
}

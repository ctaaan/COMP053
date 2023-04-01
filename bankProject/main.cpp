//CAITLIN TAN
//did not comment on things that were self explanatory (names that explained the purpose)
#include "bankaccount.h"
#include "savingsubaccount.h"
#include "checkingsubaccount.h"
#include "subaccount.h"
#include "bank.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char bankMenu(string name) {
    char selection; 
    cout << endl;
    cout << "Eligible services for " << name  << ":" << endl;
    cout << "   A -- Number of Bank-Accounts" << endl;
    cout << "   S -- Number of Saving-Accounts" << endl;
    cout << "   H -- Number of Checking-Accounts" << endl;
    cout << "   O -- Open Bank-Account" << endl;
    cout << "   C -- Close Bank-Account" << endl;
    cout << "   M -- Modify Bank-Account" << endl;
    cout << "   D -- Detailed Bank-Accouns" << endl;
    cout << "   B -- Brief Bank-Accounts Info Sorted Based on Aggregated Balances" << endl;
    cout << "   X -- Exit" << endl;
    cout << "Please enter your selection: "; //printed menu
    cin >> selection; //reads user input
    return tolower(selection); //returns lower case user input
}

char bankAccMenu(int accNum) {
    char selection; 
    cout << "\nEligible services for Bank-Account BNK" << accNum << ":"  << endl;
    cout << "   S -- Open Saving Sub-Account" << endl;
    cout << "   C -- Open Checking Sub-Account" << endl;
    cout << "   M -- Modify a Sub-Account" << endl;
    cout << "   E -- Close a Sub-Account" << endl;
    cout << "   D -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts" << endl;
    cout << "   B -- Brief Bank Account Info" << endl;
    cout << "   X -- Exit" << endl;
    cout << "Please enter your selection: "; //printed menu
    cin >> selection; //reads user input
    return tolower(selection); //returns lower case user input
}

char subAccMenu(int accNum) {
    char selection; 
    if (accNum > 2000) {
        cout << "\nEligible services for sub-Account CHK" << accNum << ":"  << endl;
        cout << "   D -- Deposit" << endl;
        cout << "   W -- Withdraw" << endl;
        cout << "   C -- Max Capacity" << endl;
        cout << "   L -- Lock Sub-Account" << endl;
        cout << "   U -- Unlock Sub-Account" << endl;
        cout << "   X -- Exit" << endl;
        cout << "Please enter your selection: "; //printed menu
        cin >> selection; //reads user input
        return tolower(selection); //returns lower case user input
    
    }
    else {
        cout << "\nEligible services for sub-Account SAV" << accNum << endl;
        cout << "   D -- Deposit" << endl;
        cout << "   W -- Withdraw" << endl;
        cout << "   X -- Exit" << endl;
        cout << "Please enter your selection" << endl; //printed menu
        cin >> selection; //reads user input
        return tolower(selection); //returns lower case user input
    }
}

int main() {

    bool AGAIN = true;
    string name; 
    string address; 
    string working; 
    cout << "Enter the name of the bank: "; 
    getline(cin, name); //reads user input
    cout << "Enter the address of the bank: ";
    getline(cin, address); //reads user input
    cout << "Enter the working hours: ";
    getline(cin, working); //reads user input

    Bank bank = Bank(name, address, working); //creates new Bank "bank" with name, address, and hours inputted

    do
    {
        char choice = bankMenu(name); //variable for user choice set to what character the bankMenu function returns
        
        switch (choice)
        {
        case 'a': cout << "\nThe number of Bank-Accounts is " << bank.numberOfBankAccounts() << endl; // display total number of bank accounts
            break;

        case 's': cout << "\nThe number of Saving-Accounts is " << bank.numberOfSavingAccounts() << endl; // display total number of saving accounts
            break;

        case 'h': cout << "\nThe number of Checking-Accounts is " << bank.numberOfCheckingAccounts() << endl; // display total number of checking accounts
            break;

        case 'o': { //opens bank account
            string fn; 
            string ln; 
            string ssn; 
            cin.ignore(); //buffer
            cout << "\nEnter the first name of the account holder: ";
            getline(cin, fn); //reads user input
            cout << "Enter the last name of the account holder: ";
            getline(cin, ln); //reads user input
            cout << "Enter the SSN of the account holder: ";
            getline(cin, ssn); //reads user input
            BankAccount acc = bank.openBankAccount(fn, ln, ssn); //creates new BankAccount "acc" with name and ssn inputted
            cout << "A new bank account BNK" << acc.getId() << " was sucessfully created." << endl;


        }
                break;
        case 'c': { // close a bank account
            string id; 
            cin.ignore(); //buffer
            cout << "\nEnter the id of the account you want to close: ";
            getline(cin, id); //reads user input
            int intId = stoi(id.substr(3, 6)); //   take only the ID - leave the prefix
            bank.closeBankAccount(intId); //closes account
            cout << "Bank Account BNK" << intId << " closed" << endl;

        }
                break;
        case 'm': { // modify a bank account
            string id; 
            string lo;
            getline(cin, lo);
            cout << "\nEnter the id of the account you want to modify: ";
 
            getline(cin, id); //reads user input
            string k = id.substr(3, 7); // id num
            int intId = stoi(id.substr(3, 7)); //take only the ID
            BankAccount& acc = bank.getBankAccount(intId); //gets account info based off ID


            bool again2 = true;
            do {
                char choice2 = bankAccMenu(intId); //variable for user choice set to what character the bankAccMenu function returns

                switch (choice2) {

                case 's': { // create saving account
                    string balance; 
                    cout << "\nEnter the initial balance: ";
                    cin.ignore(); //buffer
                    getline(cin, balance); //reads user input
                    SavingSubAccount& save = acc.openSaving(stoi(balance)); //opens saving acc with balance entered
                    cout << "A new Saving Sub-Account SAV" << save.getId() << " was sucessfully created." << endl;

                }
                        break;
                case 'c': { // create checking account
                    string balance; 
                    string cap; 
                    char state;
                    cin.ignore(); //buffer
                    cout << "\nEnter the initial balance: ";
                    getline(cin, balance); //reads user input
                    cout << "Enter the desired maximum capacity: ";
                    getline(cin, cap); //reads user input
                    cout << "Define initial state: (L - Locked, Otherwise - Unlocked): ";
                    cin >> state; //reads user input
                    bool lck = true; //sets as locked
                    if (state != 'L') {
                        lck = false; //changes to unlocked if input is not L
                    }
                    CheckingSubAccount& check = acc.openChecking(stoi(cap), lck, stoi(balance)); //create checking account
                    cout << "A new Checking Sub-Account CHK" << check.getId() << " was sucessfully created." <<endl;

                }
                        break;
                case 'm': {

                    string idSub;
                    cout << "\nEnter the sub-account number to modify:";
                    cin.ignore(); //buffer
                    getline(cin, idSub); //reads user input
                    int intIdSub = stoi(idSub.substr(3, 6)); // gets only ID num

                    bool again3 = true;

                    do {


                        if (intIdSub > 2000) { //checking account
                            char choice3 = subAccMenu(intIdSub); //variable for user choice set to what character the subAccMenu function returns
                            switch (choice3) {
                            case 'd': { //deposit
                                string dep;
                                cin.ignore(); //buffer
                                cout << "\nEnter the amount to deposit: ";
                                getline(cin, dep); //reads user input
                                acc.getCheckAcc(intIdSub).deposit(stoi(dep)); //deposits

                            }
                                    break;
                            case 'w': { //withdraw
                                string wit;
                                cin.ignore(); //buffer
                                cout << "\nEnter the amount to withdraw: ";
                                getline(cin, wit); //reads user input
                                acc.getCheckAcc(intIdSub).withdraw(stoi(wit)); //withdraws


                            }
                                    break;
                            case 'c': { // max capacity

                                int max = acc.getCheckAcc(intIdSub).getMaxCap(); //sets max
                                cout << "\nThe max capacity is: " << max << endl;;


                            }
                                    break;
                            case 'l': { // lock account

                                acc.getCheckAcc(intIdSub).lock(); //locks
                                cout << "\nThe sub-account CHK: " << intIdSub << " is locked now!" << endl;;


                            }
                                    break;

                            case 'u': { // unlock account

                                acc.getCheckAcc(intIdSub).unlock(); //unlocks
                                cout << "\nThe sub-account CHK: " << intIdSub << " is unlocked now!" << endl;


                            }
                                    break;

                            case 'x': { // exit
                                cout << "\nEnd of service for sub-account CHK: " << intIdSub << endl;
                                again3 = false;



                            }
                                    break;

                            } //endif

                        }
                        else {  //saving account 
                            char choice3 = subAccMenu(intIdSub);
                            switch (choice3) {
                            case 'd': { // deposit
                                string dep;
                                cin.ignore();
                                cout << "\nEnter the amount to deposit: ";
                                getline(cin, dep);
                                acc.getSaveAcc(intIdSub).deposit(stoi(dep));
                                break;
                            }
                            case 'w': { //withdraw
                                string wit;
                                cin.ignore();
                                cout << "\nEnter the amount to withdraw: ";
                                getline(cin, wit);
                                acc.getCheckAcc(intIdSub).withdraw(stoi(wit));
                                break;

                            }

                            case 'x': { // exit
                                cout << "\nEnd of service for sub-account SAV: " << intIdSub << endl;
                                again3 = false; //ends service

                                break;

                            }
                            }
                        }

                    } while (again3);

                }
                        break;
                case 'r': { // close sub account
                    string idSub;              
                    cout << "\nEnter th sub-account number to be closed:";
                    cin.ignore(); //buffer
                    getline(cin, idSub); //reads user input
                    int intIdSub = stoi(idSub.substr(3, 6)); //gets ID num
                    if (intIdSub > 2000) { // close checking account
                        acc.closeChecking(intIdSub); 
                        cout << "Sub-Account CHK" << intIdSub << "successfully closed!" << endl;
                    }
                    else { // close saving account
                        acc.closeSaving(intIdSub);
                        cout << "Sub-Account SAV" << intIdSub << "successfully closed!" << endl;
                    }

                }
                        break;
                case 'd': { // detailed display of sub accounts
                    acc.sortAscending();

                }
                        break;
                case 'b': { // brief display of sub accounts
                    cout << "\n   Aggregated Balance of the bank account BNK" << intId << " with " << acc.numberChecking() + acc.numberSaving() << " Sub-Accounts is " << acc.getBriefInfo() << endl;

                }
                        break;
                case 'x': { // exit
                    cout << "\nExiting Bank-Account BNK" << intId << endl;
                    again2 = false; //ends service

                }
                        break;
                }


            } while (again2);

        }
                break;
        case 'd': // display detailed bank stats
        {
            cout << endl;
            bank.detailedBankAccount();
        }
        break;
        case 'b': { // display brief bank stats
            cout << endl;
            bank.briefBankAccount();
        }
        break;
        case 'x': { // exit
            AGAIN = false; //ends service
            cout << endl;
            cout << "Exiting Bank...";

        }
                break;
        }

    } while (AGAIN);


    return 0;
}

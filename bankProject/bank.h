#ifndef BANK_H
#define BANK_H
#include <string>
#include <vector>
#include "bankaccount.h"
using namespace std;


class Bank {

private: 
	string name;
	string address;
	string workingHours;
	vector<BankAccount> bankAcc;

public:
	Bank(string n, string add, string wh) { //constructor
		name = n;
		address = add;
		workingHours = wh;
	}

	int numberOfBankAccounts(){ //returns number of bank accs
		return bankAcc.size();
	}

	int numberOfSavingAccounts() { //returns number of saving accs
		int sum = 0;
		for (int i = 0; i < bankAcc.size(); i++) { //finds number of savings for each account and adds to sum
			sum = sum + bankAcc[i].numberSaving();
		}
		return sum;
	}

	int numberOfCheckingAccounts() { //returns number of checking accs
		int sum = 0;
		for (int i = 0; i < bankAcc.size(); i++) { //finds number of savings for each account and adds to sum
			sum = sum + bankAcc[i].numberChecking();
		}
		return sum;
	}

	BankAccount openBankAccount(string fn, string ln, string ssn) { //opens account
		BankAccount acc = BankAccount(fn, ln, ssn); //new account initialized with constructor
		bankAcc.push_back(acc); //adds account to vector
		return acc;
	}

	void closeBankAccount(int id) { //closes account
		for (int i = 0; i < bankAcc.size(); i++) { //searches vector
			if (bankAcc.at(i).getId() == id) { //stops when ID matches
				bankAcc.erase(bankAcc.begin() + i); //erases account
				
			}
		}
		
	}

	BankAccount& getBankAccount(int id) { //get bank account by account number
		for (int i = 0; i < bankAcc.size(); i++) { //searches vector
			if (bankAcc.at(i).getId() == id) { //stops when ID matches
				return bankAcc[i];
			}
		}
		

	}

	int aggregatedBalance() { //aggregated balance of all bank account accounts
		int sum = 0;
		for (int i = 0; i < bankAcc.size(); i++) { //finds balance for each account and adds to sum
			sum = sum + bankAcc[i].getBriefInfo();
		}
		return sum;
	
	}


	void detailedBankAccount() { //prints info
	
		cout << "| Bank Name: " << name << endl;
		cout << "| Bank Address: " << address << endl;
		cout << "| Bank Working Hours: " << workingHours << endl;
		cout << "| Aggregated Balance " << aggregatedBalance() << endl;
		cout << "| Consists of " << numberOfBankAccounts() << " Banks-Accounts" << endl;

		cout << endl;

		for (int i = 0; i < bankAcc.size(); i++) { 
			cout << "| Bank Account Number: BNK" << bankAcc[i].getId() << endl;
			cout << "| Account Holder Full Name: " << bankAcc[i].getFN() << " " << bankAcc[i].getLN() << endl;
			cout << "| Account Holder SSN: " << bankAcc[i].getSSN() << endl;
			cout << "| Consists of " << bankAcc[i].numberChecking() + bankAcc[i].numberSaving() << " Sub-Accounts" << endl;
			bankAcc[i].sortAscending(); 
		}
	
	}


	void briefBankAccount() {
		cout << "| Bank Name: " << name << endl;
		cout << "| Bank Address: " << address << endl;
		cout << "| Bank Working Hours: " << workingHours << endl;
		cout << "| Aggregated Balance " << aggregatedBalance() << endl;
		cout << "| Consists of " << numberOfBankAccounts() << endl;

		for (int i = 0; i < bankAcc.size(); i++) {
			cout << "|Aggregated Balance of the bank account: BNK" << bankAcc[i].getId() << " with " << bankAcc[i].numberChecking() + bankAcc[i].numberSaving() << " Sub-Accounts is " << bankAcc[i].getBriefInfo() << endl;
		}

	}

};


#endif

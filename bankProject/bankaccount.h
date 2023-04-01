#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "subaccount.h"
#include "savingsubaccount.h"
#include "checkingsubaccount.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class BankAccount {

protected:
	static int nextBankAccount;


private:
	int id;
	string firstName;
	string lastName;
	vector<SavingSubAccount> saveVec;
	vector<CheckingSubAccount> checkVec;
	string SSN;

public:

	BankAccount(string fn, string ln, string sn) : firstName(fn), lastName(ln), SSN(sn) { //constructor
		id = ++nextBankAccount;
	}



	void sortAscending() { //sort sub accounts descending by balance
		sort(checkVec.begin(), checkVec.end());
		sort(saveVec.begin(), saveVec.end());
		
		cout << endl;
		
		int i = 0, j = 0;
		while (i < saveVec.size() && j < checkVec.size()) { //checks each saving and checking acc
			if (saveVec[i].getBalance() > checkVec[j].getBalance()) { //prints saving if balance is lower
				cout << "| Sub-Account number: SAV" << saveVec[i].getId() << endl;
				cout << "| Balance: " << saveVec[i].getBalance() << endl;
				cout << endl;
				i++;
			}

			else if (checkVec[j].getBalance() > saveVec[i].getBalance()) { //prints checking if balance is lower
				
				cout << "| Sub-Account number: CHK" << checkVec[j].getId() << endl;
				cout << "| Balance: " << checkVec[j].getBalance() << endl;
				cout << endl;
				cout << "| The maximum capacity is:" << checkVec[j].getMaxCap() << endl;
				if (checkVec[j].getLocked()) { //if locked
					cout << "| The sub-account is locked." << endl;
				}
				else {
					cout << "| The sub-account is unlocked." << endl;
				}

				cout << endl;
				j++;
			}
				

			else { 
							
				cout << "| Sub-Account number: CHK" << checkVec[j].getId() << endl;
				cout << "| Balance: " << checkVec[j].getBalance() << endl;
				cout << endl;
				cout << "| The maximum capacity is:" << checkVec[j].getMaxCap() << endl;
				if (checkVec[j].getLocked()) { //if locked
					cout << "| The sub-account is locked." << endl;
				}
				else {
					cout << "| The sub-account is unlocked." << endl;
				}

				cout << endl;
				j++;
				i++;
			}
		}

		/* Print remaining elements of the larger array */
		while (i < saveVec.size()) {
			cout << "| Sub-Account number: SAV" << saveVec[i].getId() << endl;
			cout << "| Balance: " << saveVec[i].getBalance() << endl;
			cout << endl;
			i++;
		}
		

		while (j < checkVec.size()) {
			
			cout << "| Sub-Account number: CHK" << checkVec[j].getId() << endl;
			cout << "| Balance: " << checkVec[j].getBalance() << endl;
			cout << endl;
			cout << "| The maximum capacity is:" << checkVec[j].getMaxCap() << endl;
			if (checkVec[j].getLocked()) {
				cout << "| The sub-account is locked." << endl;
			}
			else {
				cout << "| The sub-account is unlocked." << endl;
			}

			cout << endl;
			j++;
			
		}
			
	}



	SavingSubAccount& openSaving(int bal) { //open saving account
		saveVec.push_back(SavingSubAccount(bal)); //adds saving acc to vector
		if (saveVec.size() == 1) {
			saveVec.front().deposit(100); //100 bonus for first acc
		}
		return saveVec.back();
	}

	CheckingSubAccount& openChecking(int cap, bool lock,int bal) { //open checking account
		checkVec.push_back(CheckingSubAccount(cap,lock,bal)); //adds checking acc to vector
		return checkVec.back();

	}

	void closeChecking(int id) { //close checking account
		for (int i = 0; i < checkVec.size(); i++) {
			if (checkVec.at(i).getId() == id)
				checkVec.erase(checkVec.begin() + i);
		}
	}

	void closeSaving(int id) { //close saving account
		for (int i = 0; i < saveVec.size(); i++) {
			if (saveVec.at(i).getId() == id)
				saveVec.erase(saveVec.begin() + i);

		}
	}


	CheckingSubAccount& getCheckAcc(int id) { //get checking account by account number
		for (int i = 0; i < checkVec.size(); i++) {
			if (checkVec.at(i).getId() == id)
				return checkVec[i];
		}

	}


	SavingSubAccount& getSaveAcc(int id) { //get saving account by account number
		for (int i = 0; i < saveVec.size(); i++) {
			if (saveVec.at(i).getId() == id)
				return saveVec[i];
		}
	}

	int numberSaving() { //number of saving accounts
		return saveVec.size();
	}

	int numberChecking() { //number of checking accounts
		return checkVec.size();
	}

	int getId() { 
		return id;
	}

	int getBriefInfo() { 
		int sum = 0;
		for (int i = 0; i < saveVec.size(); i++) { //checks each saving acc
			sum = sum + saveVec[i].getBalance(); //adds balance to sum
		}
		for (int i = 0; i < checkVec.size(); i++) { //checks each checking acc
			sum = sum + checkVec[i].getBalance(); //adds balance to sum
		}

		return sum;
	
	}

	string getFN() {
		return firstName;
	}
	string getLN() {
		return lastName;
	}

	string getSSN() {
		return SSN;
	}


};


int BankAccount::nextBankAccount = 9999;


#endif

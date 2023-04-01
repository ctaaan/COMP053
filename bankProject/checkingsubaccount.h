#ifndef CHECKINGSUBACCOUNT_H
#define CHECKINGSUBACCOUNT_H
#include "subaccount.h"
#include <iostream>


class CheckingSubAccount : public SubAccount {

private:

	int maxCapacity;
	bool locked;


public:

	CheckingSubAccount(int cap, bool lock, int bal) : SubAccount(1,bal) { //constructor
		maxCapacity = cap;
		locked = lock;
	
	} // 1 for checking


	void withdraw(int amount) {
		if (!locked) { // if unlocked
			int left = this->getBalance() - amount; //calculates new balance
			if (left > 0) {
				this->setBalance(left); //withdraws and sets new balance
				cout << "Withdrew " << amount << endl;
			}
			else { //if not enough
				cout << "Not enough funds to withdraw!" << endl;
			}
		}
		else { //if locked
			cout << "	The account is currently locked!" << endl;
			cout << "	The withdraw was unsuccessfull." << endl;
		}

	}
	bool operator<(const  CheckingSubAccount& other) //(1)
	{
		return balance > other.balance;
	}


	void deposit(int amount) {
		if (!locked) { // if unlocked
			int cur = this->getBalance(); //calculates new balance
			if (cur + amount > maxCapacity) { // if more than max
				cout << "Cannot deposit more than a capacity!" << endl;
			}
			else {
				this->setBalance(this->getBalance() + amount); //deposits and sets new balance
				cout << "Deposited " << amount << endl;
			}
			
		}
		else { //if locked
			cout << "	The account is currently locked!" << endl;
			cout << "	The deposit was unsuccessfull." << endl;
		}
	}
	int getMaxCap() {
		return maxCapacity;
	}

	void lock() {
		locked = true;
	}

	void unlock() {
		locked = false;
	}

	bool getLocked() {
		return locked;
	}

	void setMaxCapacity(int cap) {
		maxCapacity = cap;
	}





};

#endif

#ifndef SAVINGSUBACCOUNT_H
#define SAVINGSUBACCOUNT_H
#include "subaccount.h"
#include <iostream>


class SavingSubAccount : public SubAccount {

public:

	SavingSubAccount(int bal) : SubAccount(0,bal) {} // 0 for saving

	void withdraw(int amount) {
		int left = this->getBalance() - amount; //calculates new balance
		if (left > 0) {
			this->setBalance(left); //withdraws and sets new balance
		}

	}
	bool operator<(const  SavingSubAccount& other) //(1)
	{
		return balance > other.balance;
	}


	void deposit(int amount) {
		this->setBalance(this->getBalance() + amount); //deposits and sets new balance
	}


	


};

#endif

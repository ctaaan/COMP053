#ifndef SUBACCOUNT_H
#define SUBACCOUNT_H
#include <string>
using namespace std;


class SubAccount {

protected:
	static int nextChecking;
	static int nextSaving;
	int balance;


private:
	int id;  // str prefix will be used for manipulation only
	int accType; // 0 saving, 1 chcking


public:

	SubAccount(int type,int bal) {
		if (type) { // if checking account
			id = ++nextChecking;

		}
		else { // saving account
			id = ++nextSaving;
		}
		accType = type;
		balance = bal;
	}

	 void deposit(int amount);
	 void withdraw(int amount);


	 int getId() {
		 return id;
	 }

	int getBalance() {
		return balance;
	}

	void setBalance(int newBalance) {
		this->balance = newBalance;
	}





};



int SubAccount::nextChecking = 5999;
int SubAccount::nextSaving = 999;



#endif

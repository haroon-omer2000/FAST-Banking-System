/*
 * UserAccount.cpp
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */

#include "UserAccount.h"
#include<cstdlib>
#include<ctime>
namespace std {

UserAccount::UserAccount() {
	accType = "\0";
	balance = 0;
}

UserAccount::UserAccount(string fn, string mn, string ln, string cnic,
		string add, string tele, string dob, int accNo, string acctype,
		string cardtype, long b) :
		User(fn, mn, ln, cnic, add, tele, dob, accNo, acctype, cardtype) {
	if (b > 0) {
		this->balance = b;
	} else {
		cout << "Balance Cannot Be Zero!" << endl;
		exit(EXIT_FAILURE);
	}
}

bool UserAccount::getCheck(){
	return check;
}

void UserAccount::setCheck(bool c){
	this->check=c;
}

void UserAccount::setWithdrawAmount(long amount){
	this->withdrawAmount=amount;
}

long UserAccount::getWithdrawAmount(){
	return withdrawAmount;
}

long UserAccount::getBalance() const {
	return balance;
}

void UserAccount::setBalance(long balance) {
	this->balance = balance;
}

bool UserAccount::WithDraw(long amount) {

	UserAccount::setWithdrawAmount(amount);
	int x;
	cout << "How do you want to withdraw cash?" << endl;
	cout << "Press 1 to withdraw through checkbook" << endl;
	cout << "Press 2 to withdraw through debit card" << endl;
	cin >> x;

	// 			THROUGH CHECKBOOK
	if (x == 1) {
		int accNo;
		cout << "Enter Account Number: " << endl;
		cin >> accNo;

		if (accNo == accNumber) {
			time_t now = time(0);
			char* dt = ctime(&now);
			cout << "The local date and time is: " << dt << endl;
			if (amount > 50000) {
				balance -= amount;
				balance -= amount * (2.5 / 100.0);
				balance -= amount * (0.2 / 100.0);
				if (accType == "Checking") {
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
					return true;
				} else if (accType == "Saving") {
					UserAccount::Print();
					long interest = amount / 100.0;
					balance += interest;
					balance -= interest * (0.5 / 100.0);
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
					return true;
				}
				return false;
			} else if (amount > 5000 && amount < 50000) {
				balance -= amount;
				balance -= balance * (0.2 / 100.0);
				if (accType == "Checking") {
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
					return true;
				} else if (accType == "Saving") {
					int interest = amount / 100.0;
					balance += interest;
					balance -= interest * (0.5 / 100.0);
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
					return true;
				}
				return false;
			} else if (amount < 5000 && amount > 0) {
				balance -= amount;
				if (accType == "Checking") {
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
					return true;
				} else if (accType == "Saving") {
					cout << amount << endl;
					long interest = amount / 100.0;
					balance += interest;
					balance -= interest * (0.5 / 100.0);
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
					return true;
				}
				return false;
			}
			return false;
		}

		else {
			cout << "Wrong Cnic or Account Number entered!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	// 			THROUGH DEBIT CARD
	else if (x == 2) {
		int Cno;
		cout << "Enter Account Number: " << endl;
		cin >> Cno;

		if (accNumber == Cno) {
			time_t now = time(0);
			char* dt = ctime(&now);
			cout << "The local date and time is: " << dt << endl;
			if (CC.getCardType() == "Master") {
				if (amount < 50000) {
					time_t currentTime;
					currentTime = time(NULL);
					tm *tm_local = localtime(&currentTime);
					balance -= amount;
					balance -= amount * (18.0 / 100.0);
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
				} else {
					cout << "Withdraw amount too high!" << endl;
					exit(EXIT_FAILURE);
				}
			}

			else if (CC.getCardType() == "Visa") {
				if (amount < 100000) {
					balance -= amount;
					balance -= amount * (10.0 / 100.0);
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
				} else {
					cout << "Withdraw amount too high!" << endl;
					exit(EXIT_FAILURE);
				}
			}

			else if (CC.getCardType() == "Local") {
				if (amount < 10000) {
					balance -= amount;
					balance -= amount * (25.0 / 100.0);
					UserAccount::Print();
					cout << "Amount of " << amount
							<< "Rs Successfully withdrawn at time: " << dt
							<< endl;
					cout << "Your New Balance is : " << balance << endl;
				} else {
					cout << "Withdraw amount too high!" << endl;
					exit(EXIT_FAILURE);
				}
			}
		}

		else {
			cout << "Wrong Account Number Entered!" << endl;
			exit(EXIT_FAILURE);
		}
	}
}

bool UserAccount::Deposit(long amount) {

	UserAccount::setWithdrawAmount(amount);
	cout << "Enter Account Number: " << endl;
	int accNo;
	cin >> accNo;

	if (accNo == accNumber) {
		time_t now = time(0);
		char* dt = ctime(&now);
		cout << "The local date and time is: " << dt << endl;
		if (balance > 0) {
			balance += amount;
			UserAccount::Print();
			cout << "Amount of " << amount
					<< "Rs Successfully Deposited at time: " << dt << endl;
			cout << "Your New Balance is : " << balance << endl;
			return true;
		} else {
			exit(EXIT_FAILURE);
		}
	} else {
		cout << "Wrong Account Number!" << endl;
		exit(EXIT_FAILURE);
	}
}

void UserAccount::Print() {
	cout << endl;
	User::Print();
	cout << endl;
}

UserAccount::~UserAccount() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */



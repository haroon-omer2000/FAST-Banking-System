/*
 * UserAccount.h
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */
#include<iostream>
#include "User.h"
#ifndef USERACCOUNT_H_
#define USERACCOUNT_H_

namespace std {

class UserAccount: public User {
protected:
	long balance; 
	long withdrawAmount;
	bool check;
public:
	UserAccount();
	UserAccount(string fn, string mn, string ln, string cnic, string add,
			string tele, string dob, int, string acctype, string cardtype,
			long b);
	bool WithDraw(long amount);
	bool Deposit(long amount);
	long getBalance() const;
	void setBalance(long balance);
	void Print();
	void setCheck(bool);
	void setWithdrawAmount(long amount);
	long getWithdrawAmount();
	bool getCheck();
	virtual ~UserAccount();
};

} /* namespace std */

#endif /* USERACCOUNT_H_ */


/*
 * User.h
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */
#include<iostream>
#include "Person.h"
#include "CardCategory.h"
#ifndef USER_H_
#define USER_H_

namespace std {

class User: public Person {
protected:
	int accNumber;
	string accType;
	CardCategory CC;
public:
	User();
	User(string fn, string mn, string ln, string cnic, string add, string tele,
			string dob, int accNo, string acctype, string card_type);
	void updateData() {
	}
	bool WithDraw(long amount) {
	}
	bool Deposit(long amount) {
	}
	int getAccNo();
	string getCardType();
	const string& getAccType() const;
	void setAccType(const string& accType);
	void Print();
	virtual ~User();
};

} /* namespace std */

#endif /* USER_H_ */


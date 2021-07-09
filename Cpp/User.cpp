/*
 * User.cpp
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */

#include "User.h"

namespace std {

//int User::accNumber = 0;

User::User() :
		Person("\0", "\0", "\0", "\0", "\0", "\0", "\0") {
	accNumber++;
}

User::User(string fn, string mn, string ln, string cnic, string add,
		string tele, string dob, int accNo, string acctype, string cardtype) :
		Person(fn, mn, ln, cnic, add, tele, dob) {
	CC.setCardType(cardtype);
	this->accType = acctype;
	accNumber = accNo;
}

int User::getAccNo() {
	return accNumber;
}

const string& User::getAccType() const {
	return accType;
}

string User::getCardType(){
	return CC.getCardType();
}

void User::setAccType(const string& accType) {
	this->accType = accType;
}

void User::Print() {
	cout << "User info is: " << endl;
	cout << "Full name: " << first_Name << " " << middle_Name << " "
			<< last_Name << endl;
	cout << "Address: " << Address << endl;
	cout << "Cnic: " << Cnic << endl;
	cout << "Telephone Number: " << Telephone << endl;
	cout << "Date of birth: " << dateofBirth << endl;
}

User::~User() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */


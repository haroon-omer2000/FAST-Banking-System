/*
 * Employee.h
 *
 *  Created on: Jul 30, 2019
 *      Author: haroon
 */
#include<iostream>
#include<fstream>
#include "Person.h"
#include "UserAccount.h"
#include <vector>
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

namespace std {

class Employee: public Person {
	int empID;
public:
	Employee();
	Employee(int id);
	bool WithDraw(long amount) {
	}
	bool Deposit(long amount) {
	}
	void Print() {
	}
	void Display(vector<UserAccount>& V1,string cnic,int accNo);
	void updateData() {
	}
	void Update(vector<UserAccount>&V1, string cnic, int accNo);
	void Transaction(vector<UserAccount> &V1, string cnic,int accNo);
	bool Delete(vector<UserAccount> &V1, string, int);
	void sameCardDisplay(vector<UserAccount>& V1,string type);
	void balanceInquiry(vector<UserAccount>& V1,string cnic,int accNo);
	void transactionHistory(vector<UserAccount>& V1,string cnic,int accNo);
	bool checkUniqueAccount(vector<UserAccount>& V1,int accNo);
	bool checkUniqueCnic(vector<UserAccount>& V1,string cnic);
	virtual ~Employee();
};

} /* namespace std */

#endif /* EMPLOYEE_H_ */


/*
 * Person.h
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */
#include<iostream>
#include<vector>
#ifndef PERSON_H_
#define PERSON_H_

namespace std {

class Person {
protected:
	string first_Name;
	string middle_Name;
	string last_Name;
	string Cnic;
	string Address;
	string Telephone;
	string dateofBirth;
public:
	Person();
	Person(string fn, string mn, string ln, string cnic, string add,
			string tele, string dob);
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCnic() const;
	void setCnic(const string& cnic);
	const string& getDateofBirth() const;
	void setDateofBirth(const string& dateofBirth);
	const string& getFirstName() const;
	void setFirstName(const string& firstName);
	const string& getLastName() const;
	void setLastName(const string& lastName);
	const string& getMiddleName() const;
	void setMiddleName(const string& middleName);
	const string& getTelephone() const;
	void setTelephone(const string& telephone);
	virtual void updateData()=0;
	virtual bool WithDraw(long amount)=0;
	virtual bool Deposit(long amount)=0;
	virtual void Print()=0;
	virtual ~Person();
};

} /* namespace std */

#endif /* PERSON_H_ */


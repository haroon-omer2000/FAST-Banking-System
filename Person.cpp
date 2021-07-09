/*
 * Person.cpp
 *
 *  Created on: Jul 29, 2019
 *      Author: haroon
 */

#include "Person.h"

namespace std {

Person::Person() {
	this->first_Name = "\0";
	this->middle_Name = "\0";
	this->last_Name = "\0";
	this->Cnic = "\0";
	this->Address = "\0";
	this->dateofBirth = "\0";
	this->Telephone = "\0";
}

Person::Person(string fn, string mn, string ln, string cnic, string add,
		string tele, string dob) {
	this->first_Name = fn;
	this->middle_Name = mn;
	this->last_Name = ln;
	this->Cnic = cnic;
	this->Address = add;
	this->dateofBirth = dob;
	this->Telephone = tele;
}

const string& Person::getAddress() const {
	return Address;
}

void Person::setAddress(const string& address) {
	Address = address;
}

const string& Person::getCnic() const {
	return Cnic;
}

void Person::setCnic(const string& cnic) {
	Cnic = cnic;
}

const string& Person::getDateofBirth() const {
	return dateofBirth;
}

void Person::setDateofBirth(const string& dateofBirth) {
	this->dateofBirth = dateofBirth;
}

const string& Person::getFirstName() const {
	return first_Name;
}

void Person::setFirstName(const string& firstName) {
	first_Name = firstName;
}

const string& Person::getLastName() const {
	return last_Name;
}

void Person::setLastName(const string& lastName) {
	last_Name = lastName;
}

const string& Person::getMiddleName() const {
	return middle_Name;
}

void Person::setMiddleName(const string& middleName) {
	middle_Name = middleName;
}

const string& Person::getTelephone() const {
	return Telephone;
}

void Person::setTelephone(const string& telephone) {
	Telephone = telephone;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */


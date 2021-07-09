/*
 * Employee.cpp
 *
 *  Created on: Jul 30, 2019
 *      Author: haroon
 */

#include "Employee.h"
#include<sstream>
#include<cstdlib>

namespace std {

Employee::Employee() {

}

Employee::Employee(int id){
	this->empID=id;
}

void Employee::Transaction(vector<UserAccount>& V1, string cnic,int accNo) {
	for (int i = 0; i < V1.size(); i++) {
		if (V1[i].getCnic() == cnic && V1[i].getAccNo()==accNo) {
			int choice;
			cout << "What do you want to do?" << endl;
			cout << "1. Withdraw Cash" << endl;
			cout << "2. Deposit Cash" << endl;
			cout << "3. Balance Inquiry"<< endl;
			cin >> choice;
			if (choice == 1) {
				long amount;
				cout << "Enter amount you want to withdraw: " << endl;
				cin >> amount;
				while(amount>V1[i].getBalance()){
					cout<<"Amount Cannot Be Greater than Current Balance,Enter Again"<<endl;
					cin>>amount;		
				}
					V1[i].WithDraw(amount);
					V1[i].setCheck(false);

			} else if (choice == 2) {
				long amount;
				cout << "Enter amount you want to Deposit: " << endl;
				cin >> amount;
				while(amount>V1[i].getBalance()){
					cout<<"Amount Cannot Be Greater than Current Balance,Enter Again"<<endl;
					cin>>amount;		
				}
					V1[i].Deposit(amount);
					V1[i].setCheck(false);
			}
		}
	}
}

void Employee::Display(vector<UserAccount>& V1,string cnic,int accNo) {
	for (int i = 0; i < V1.size(); i++) {
		if(V1[i].getCnic()==cnic && V1[i].getAccNo()==accNo){
			cout << "//////////////////********CUSTOMER INFORMATION********//////////////////" << endl << endl;
			cout << "Name: " << V1[i].getFirstName() << " " << V1[i].getMiddleName()
					<< " " << V1[i].getLastName() << endl;
			cout << "Cnic: " << V1[i].getCnic() << endl;
			cout << "Account Balance: " << V1[i].getBalance() << endl << endl;
		}
	}
}

void Employee::sameCardDisplay(vector<UserAccount>& V1,string type) {
	for (int i = 0; i < V1.size(); i++) {
		if(V1[i].getCardType()==type){
			cout << "//////////////////********CUSTOMER INFORMATION********//////////////////" << endl << endl;
			cout << "Name: " << V1[i].getFirstName() << " " << V1[i].getMiddleName()
					<< " " << V1[i].getLastName() << endl;
			cout << "Cnic: " << V1[i].getCnic() << endl;
			cout << "Account Balance: " << V1[i].getBalance() << endl << endl;
		}
	}
}

bool Employee::checkUniqueAccount(vector<UserAccount>& V1,int accNo){
	for(int i=0;i<V1.size();i++){
		if(V1[i].getAccNo()==accNo){
			return false;
		}
	}

	return true;
}

bool Employee::checkUniqueCnic(vector<UserAccount>& V1,string cnic){
	for(int i=0;i<V1.size();i++){
		if(V1[i].getCnic()==cnic){
			return false;
		}
	}
	return true;	
}

bool Employee::Delete(vector<UserAccount> &V1, string cnic, int accNo) {
	for (int i = 0; i < V1.size(); i++) {
		if (V1[i].getCnic() == cnic && V1[i].getAccNo() == accNo) {
			V1.erase(V1.begin() + i);
			cout << "Account Successfully removed!" << endl;
			return true;
		}
	}
	return false;
}

void Employee::balanceInquiry(vector<UserAccount>& V1,string cnic,int accNo){
	for(int i=0;i<V1.size();i++){
		if(V1[i].getCnic()==cnic && V1[i].getAccNo()==accNo){
			cout<<"Your Current Balance Is: "<<V1[i].getBalance()<<endl;
		}
	}
}

void Employee::transactionHistory(vector<UserAccount>& V1,string cnic,int accNo){
	for(int i=0;i<V1.size();i++){
		if(V1[i].getCnic() == cnic && V1[i].getAccNo() == accNo){
			
			if(V1[i].getCheck()==true){
				string filename=V1[i].getCnic()+".bin";
				string comment="Your Last Withdrawl Was Of Amount Rs ";
				stringstream ss;
				ss<<V1[i].getWithdrawAmount();

				string amount=ss.str();
				comment=comment+amount;
				fstream fs(filename.c_str(),ios::binary|ios::in|ios::out|ios::app);
					if(fs){
						for(int i=0;comment[i]!='\0';i++){
							fs.put(comment[i]);
						}
						fs<<endl;
					}
					fs.seekg(0);
					char c;
						while(!fs.eof()){
							fs.get(c);
							cout<<c;
						}
					fs.close();
			}
		
			else if(V1[i].getCheck()==false){		
				string filename=V1[i].getCnic()+".bin";
				string comment="Your Last Deposit Was Of Amount Rs ";
				stringstream ss;
				ss<<V1[i].getWithdrawAmount();

				string amount=ss.str();
				comment=comment+amount;
				fstream fs(filename.c_str(),ios::binary|ios::in|ios::out|ios::app);
					if(fs){
						for(int i=0;comment[i]!='\0';i++){
							fs.put(comment[i]);
						}
						fs<<endl;
					}
					fs.seekg(0);
					char c;
						while(!fs.eof()){
							fs.get(c);
							cout<<c;
						}
					fs.close();
			}
		}
	}
}

void Employee::Update(vector<UserAccount>& V1, string cnic, int accNo) {
	for (int i = 0; i < V1.size(); i++) {

		if (V1[i].getCnic() == cnic && V1[i].getAccNo() == accNo) {
			cout << "What info do you want to update?(Press -1 to exit)"
					<< endl;
			int choice;
			cout << "1. Phone Number" << endl;
			cout << "2. Address" << endl;
			cin >> choice;

			while (choice == 1 || choice == 2) {
				if (choice == 1) {
					string n;
					cout << "Enter new number: " << endl;
					cin >> n;
					V1[i].setTelephone(n);
					cout << "Number Successfully updated!" << endl;
				}
				if (choice == 2) {
					string add;
					cout << "Enter new address: " << endl;
					cin >> add;
					V1[i].setAddress(add);
					cout << "Address Successfully updated!" << endl;
				}
				cout
						<< "What else info do you want to update?(Press -1 to exit)"
						<< endl;
				cout << "1. Balance" << endl;
				cout << "2. Address" << endl;
				cin >> choice;
			}
		}

		else {
			cout << "Wrong cnic or acc number entered" << endl;
			exit(EXIT_FAILURE);
		}
	}
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */


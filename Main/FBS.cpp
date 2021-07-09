//============================================================================
// Name        : FastBankingSystem.cpp
// Author      : M.Haroon Omer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include<cstdlib>
#include "Person.cpp"
#include "User.cpp"
#include "UserAccount.cpp"
#include "CardCategory.cpp"
#include "Employee.cpp"
using namespace std;

int main() {

	vector<UserAccount> V1;

	int login;
	cout << "Who do You Want to Login as?(Press -1 to exit)" << endl;
	cout << "1. Customer" << endl;
	cout << "2. Employee" << endl;
	cin >> login;

	if (login == -1){
		cout<<endl<<"-----------------GOODBYE---------------------"<<endl<<endl;
		exit(EXIT_FAILURE);
	}
	while (login == 1 || login == 2) {
		if (login == 1) {
			if (V1.size() == 0) {
				cout << "Currently No Customer Accounts are present" << endl;
				exit(EXIT_FAILURE);
			} else {
				string cnic;
				cout << "Enter your cnic to login" << endl;
				cin >> cnic;
				int uChoice;
				int accNo;
				cout<<"Enter Account Number"<<endl;
				cin>>accNo;
				cout<<" What Do You Want To Do?"<<endl;
				cout<<"1. Make Transaction"<<endl;
				cout<<"2. Balance Inquiry "<<endl;
				cin>>uChoice;
				if(uChoice==1){
					Employee E1;
					E1.Transaction(V1, cnic,accNo);
				}
				else if(uChoice==2){
					Employee E1;
					E1.balanceInquiry(V1,cnic,accNo);
				}
			}
		} else if (login == 2) {

			if(V1.size()==0){
				int id,pw;
				cout<<"Enter Your ID: "<<endl;	
				cin>>id;
				cout<<"Enter Password: "<<endl;	
				cin>>pw;
			}

			int login1;
			cout << endl << "What do you want to perform?(Press -1 to exit)"
					<< endl;
			cout << "1. Create a customer account" << endl;
			cout << "2. Delete a customer account" << endl;
			cout << "3. Display Customers Information" << endl;
			cout << "4. Update a customers account" << endl;
			cout << "5. Display Same Card Users"<<endl;
			cout << "6. Make transaction from a user's account"<<endl;
			cout << "7. Balance Inquiry "<<endl;
			cout << "8. View Transaction History"<<endl;

			cin >> login1;
			while (login1 == 1) {
				UserAccount*P;
				string fn, mn, ln, add, cnic, tele, dob, acctype, cardtype;
				int accNo;
				long b;
				cout << endl <<"Enter first name: " << endl;
				cin >> fn;
				cout << endl << "Enter middle name: " << endl;
				cin >> mn;
				cout << endl << "Enter last name: " << endl;
				cin >> ln;
				cout << endl << "Enter address: " << endl;
				cin >> add;
				cout << endl << "Enter cnic: " << endl;
				cin >> cnic;

				if(V1.size()>0){
					Employee E1;
					while(E1.checkUniqueCnic(V1,cnic)==false){
						cout<<"Cnic Already Present! Please Enter A Different Cnic: "<<endl;
						cin>>cnic;
					}
				}

				cout << endl << "Enter telephone number: " << endl;
				cin >> tele;
				cout << endl << "Enter date of birth: " << endl;
				cin >> dob;
				cout << endl << "Enter account type:(Saving/Checking) " << endl;
				cin >> acctype;
				cout << endl << "Enter card type:(Master/Local/Visa) " << endl;
				cin >> cardtype;
				cout << endl << "Enter balance in your account: " << endl;
				cin >> b;
				cout << endl << "Enter Account Number: " << endl;
				cin >> accNo;
				
				if(V1.size()>0){
					Employee E1;
					while(E1.checkUniqueAccount(V1,accNo)==false){
						cout<<"Account Name Already Present! Please Enter A Different Account Number: "<<endl;
						cin>>accNo;
					}
				}

				P = new UserAccount(fn, mn, ln, cnic, add, tele, dob, accNo,
						acctype, cardtype, b);
				V1.push_back(*P);
				cout << endl << "Customer Succesfully added with own Values"
						<< endl;

				cout << "Press 1 to add another customer(Press -1 to exit)"
						<< endl;
				cin >> login1;
			}

			if (login1 == 2) {
				if(V1.size()!=0){
					int accNo;
					string cnic;
					cout << "Enter Cnic Number of the Account you want to delete: "
							<< endl;
					cin >> cnic;
					cout << "Enter Account Number: " << endl;
					cin >> accNo;
					Employee E1;
					E1.Delete(V1, cnic, accNo);
				}
				else
					cout<<"No accounts Currently Present!"<<endl<<endl;
			}

			if (login1 == 3) {
				if(V1.size()!=0){
					string cnic;
					cout << "Enter Cnic Number of the Account you want to be displayed: "
							<< endl;
					cin>>cnic;
					int accNo;
					cout<<"Enter Account Number: "<<endl;
					cin>>accNo;								
					Employee E1;
					E1.Display(V1,cnic,accNo);
				}
				else{
					cout<<"No accounts Currently Present!"<<endl<<endl;
				}
			}

			if (login1 == 4) {
				if(V1.size()!=0){
					int accNo;
					string cnic;
					cout << "Enter Cnic Number of the Account you want to delete: "
							<< endl;
					cin >> cnic;
					cout << "Enter Account Number: " << endl;
					cin >> accNo;
					Employee E1;
					E1.Update(V1, cnic, accNo);
				}
				else
					cout<<"No accounts Currently Present!"<<endl<<endl;
			}

			if(login1==5){
				if(V1.size()!=0){
					string type;
					cout<<"What type of credit card do you want to display?(Saving or Checking)"<<endl<<endl;
					cin>>type;
					Employee E1;
					E1.sameCardDisplay(V1,type);
				}
				else
					cout<<"No accounts Currently Present!"<<endl<<endl;
			}

			if(login1==6){
				if(V1.size()!=0){
					string cnic;
					cout << "Enter your cnic to login" << endl;
					cin >> cnic;
					int accNo;
					cout<<"Enter Account Number: "<<endl;
					cin>>accNo;	
					Employee E1;
					E1.Transaction(V1, cnic,accNo);
				}
				else
					cout<<"No accounts Currently Present!"<<endl<<endl;
			}

			if(login1==7){
				if(V1.size()!=0){
					string cnic;
					cout << "Enter your cnic to login" << endl;
					cin>>cnic;
					int accNo;
					cout << "Enter account number to login" << endl;
					cin>>accNo;
					Employee E1;
					E1.balanceInquiry(V1,cnic,accNo);			
				}
				
				else
					cout<<"No accounts Currently Present!"<<endl<<endl;
			}

			if(login1==8){	
				if(V1.size()!=0){
					string cnic;
					cout << "Enter your cnic to login" << endl;
					cin>>cnic;
					int accNo;
					cout << "Enter account number to login" << endl;
					cin>>accNo;
					Employee E1;
					E1.transactionHistory(V1,cnic,accNo);
				}

				else
					cout<<"No accounts Currently Present!"<<endl<<endl;
			}
		}
		cout << endl << "Who do You Want to Login as?(Press -1 to exit)"
				<< endl;
		cout << "1. Customer" << endl;
		cout << "2. Employee" << endl;
		cin >> login;
		if (login == -1){
			cout<<endl<<"-----------------GOODBYE---------------------"<<endl<<endl;
			exit(EXIT_FAILURE);
		}
	}
}


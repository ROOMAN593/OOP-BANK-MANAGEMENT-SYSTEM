#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <conio.h>
#include "person.h"
#include "accountRecord.h"
#include <fstream>
using namespace std;

class customerRecord : public person
{
	char address[100];
	char phone[100];
	char citizenShip[100];
	char occupation[100];
	accountRecord account_Record;
	char pin[50];
	
	
	public:     // SETTERS
	    customerRecord(); // DFAULT CONSTRUCTOR
	    ~customerRecord(){} //DESTRUCTOR
		customerRecord(char name[100],short int age,char dateOfBirth[100],char address[100],char citizenShip[100],char occupation[100],char accountType[100],double currentBalance); // CONSTRUCTOR      
		void setName(char name[100]);
		void setAge(short int age);
		void setGender(char gender[30]);
		void setDateOfBirth(char dateOfBirth[100]);                
		void setAddress(char address[100]);
		void setPhone(char phone[100]);
		void setCitizenShip(char citizenShip[100]);
		void setOccupation(char occupation[100]);
		void setCurrentBalance(double currentBalance); 
		void setAccountRecord(void); 
		void updateAccountRecord(int accountNumber); // This Function Is Just To Not To Change Account No
		void withdraw(double amount);
		void deposit(double amount);
		void setPin(char pin[50]);

		
		//GETTERS
		string getName(void) const;
		int getAge(void) const;
		string getGender(void) const;
		string getDateOfBirth(void) const;
		string getAddress(void) const;
		string getPhone(void) const;
		string getCitizenShip(void) const;
		string getOccupation(void) const;
		int getAccountNumber(void) const;
		string getAccountType(void) const;
		double getCurrentBalance(void) const;
		customerRecord getCustomerRecord(void) const;
		string getPin(void) const;

		//DATA CHECKER
		void showCustomerData(void);
		
		//FILE HANDLING
		void WRITE();// for writing in a file
		bool READ();//FOR LOADING RECORD IN MAP WHEN PROGRAM STARTS
};
#endif

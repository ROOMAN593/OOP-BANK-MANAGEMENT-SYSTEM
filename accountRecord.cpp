#include <ctime>
#include <cstdlib>
#include "accountRecord.h"
	     //MUTATORS

void accountRecord :: setAccountNumber()
{
	srand(time(0));
	accountNumber = rand();
}

void accountRecord :: setAccountNumber(int accountNumber)
{
	this -> accountNumber = accountNumber;
}
void accountRecord :: setAccountType(char accountType[50])
{
	strcpy(this -> accountType , accountType);
}

void accountRecord :: setAccountType() 
{
	
	string choice;
	cout << "1.Saving Account\n2.Retirement Account\n3.Checking Account\n";
	a:
	cout << "\nEnter Choice:";
	cin >> choice;
	cin.clear();
	cin.sync();
	if (choice == "1")
	{
       strcpy(this -> accountType ,"Saving Account");
    }
   else if (choice == "2")
   {
   	   strcpy(this -> accountType ,"Retirement Account");

    }
	//this -> accountType = "Retirement Account";
	
	else if (choice == "3")
	{
       strcpy(this -> accountType ,"Checking Account");
    }
	 //this -> accountType = "Checking Account";
	
	else
    {cout << "Invalid Input";
	goto a;
    }
}

void accountRecord :: setCurrentBalance(double currentBalance)
{
    	if (currentBalance < 500)
    	cout << "Cannot Deposit Less Than 500!";
    	
    	else
    	{
	       this -> currentBalance = currentBalance;
	    }
}
	    
         //ACCESSORS
int accountRecord :: getAccountNumber(void) const
{
	return accountNumber;
}
string accountRecord :: getAccountType(void) const
{
	string accountType;
	accountType = this -> accountType;
	return accountType;
}

double accountRecord :: getCurrentBalance(void) const
{
	return currentBalance;
}
		
	     //DATA CHECKER
void accountRecord :: showAccountData(void)
{
	
	cout << "Account Number:" << accountNumber << endl;
	cout << "Account Type:"; //<< accountType << endl;
	puts(accountType);
	cout << "Current Balance:Rs." << currentBalance << endl;
}


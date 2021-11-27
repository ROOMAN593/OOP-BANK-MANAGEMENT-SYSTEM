#ifndef ACCOUNTRECORD_H
#define ACCOUNTRECORD_H
#include <iostream>
#include <cstring>
using namespace std;

class accountRecord 
{
	private:
	    int accountNumber;
		char accountType[50];
	    double currentBalance;
		
	public:
		accountRecord(){} // DEFAULT CONSTRUCTORS 
		~accountRecord(){} //DESTRUCTOR
		     
			 //MUTATORS
	    void setAccountNumber(void);
   	    void setAccountNumber(int accountNumber); //function overloading (polymorphism)

	    void setAccountType(char accountType[30]);//for constructor of customerRecord
		void setAccountType(void);//for initializing without constructor
	    void setCurrentBalance(double currentData);
	    
	         //ACCESSORS
	    int getAccountNumber(void) const;
		string getAccountType(void) const;
		double getCurrentBalance(void) const;
		

		     //DATA CHECKER     
		void showAccountData(void);		     
};
#endif

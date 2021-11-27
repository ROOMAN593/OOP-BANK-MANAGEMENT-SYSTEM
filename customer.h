#include "customerRecord.h"
#include <map>
using namespace std;

class customer
{
	private:
	map<int,customerRecord> customerMap; //a dynamic array
	
	
	public:
        customer();//FOR LOADING RECORD IN MAP WHEN PROGRAM STARTS
		~customer(){}; //DESTRUCTOR
		void insert(customerRecord customer_Record); //for adding new record of customer in array
		void insert(customerRecord *customer_Record);
		void Insert(customerRecord *customer_Record); // only for filing usage
		void fetch(int accountNumber);//for reading any particular record of array in array
		void update(int accountNumber);//for editing any record of customer in  array
		void Delete(int accountNumber);//for removing any record of customer in array
		void load(void); // for reading/loading all data  of file
		void showCustomerRecords(void); //for checking all records of customer 
		void withdraw(int accountNumber);
		void deposit(int accountNumber);
		void transfer(int accountNumber1,int accountNumber2);
		void changeCustomerPin(int accountNumber,char pin[50]);
		
		
		//FOR FILING
		void writeNewRecords();// for update and Delete
		void deleteOldFile(); // for deleting old file
 
        customerRecord getCustomer(int accountNumber); //Returns Specific Customer Object
    public:
     //  void setFileName(string fileName);
	  // void WRITE(customerRecord customer_Record); // for writing static object in a file
       //void WRITE(customerRecord *customer_Record); // for writing dynamic object in a file
      // void READ(); // for reading file for map
       //void ADD(); //for inserting new record in a file
	   //void UPDATE();//for updating any existing record in a file
       //void DELETE();//for deletting any record in a file*/
        // friend void WRITE(customer &c);
        // friend void READ(customer &c);
};


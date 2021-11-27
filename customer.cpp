#include <iostream>
#include "customer.h"
#include <iterator>
#include <fstream>
#include <conio.h>
#include <cstdio>
using namespace std;
customer :: customer()
{
	load();
}

void customer :: load() //THIS FUNCTION INITIALIZES MAP WHEN PROGRAM RUNS
{
	customerRecord customer_Record;
    //FOR LOADING RECORD IN MAP WHEN PROGRAM STARTS
	string fileName("customer.dat");
	ifstream fin;
	fin.open(fileName,ios :: in | ios :: binary);
	if (!fin)
	{
		cout << "\nFile not Found For Customer Record!";
	}
	
	else
	{
		while (!fin.eof())
		{
	           fin.read((char*)&customer_Record,sizeof(customerRecord));
	           if (customer_Record.getAge() != 0) // if file is empty so customerRecord contains default values so it should not be stored
	           {   
	               this -> customerMap.insert(pair<int,customerRecord>(customer_Record.getAccountNumber(),customer_Record));
	           }
        }
	  fin.close();
	  cout << "\nCustomer Record Loaded!";
	  
    }
   
    getch();
}


void customer :: insert(customerRecord customer_Record) //FOR STORING STATIC OBJECT
{
	this -> customerMap.insert(pair<int,customerRecord>(customer_Record.getAccountNumber(),customer_Record));
	customer_Record.WRITE();
}


void customer :: insert(customerRecord *customer_Record) //FOR STORING DYNAMIC OBJECT
{
    
	this -> customerMap.insert(pair<int,customerRecord>(customer_Record -> getAccountNumber(),customer_Record -> getCustomerRecord()));
    
    customer_Record -> WRITE();
    
    delete customer_Record;
}

void customer :: fetch(int accountNumber) // FOR SHOWING SPECIFIC RECORD
{
	int count = 0;
	
	map<int,customerRecord> :: iterator p = customerMap.begin();
	
	while(true)
	{
        if(p -> first == accountNumber)
		{
			customerRecord customer_Record;// = new customerRecord;
        	customer_Record = customerMap.at(accountNumber);
        	customer_Record.showCustomerData(); 
	
        	//delete customer_Record;
        	break;
		}
		else if (count == customerMap.size() && p -> first != accountNumber)
		{
			cout << "\n\t\t*****Record Not Found!*****\n\n";
			break;
		}
		
		count++;
		p++;
		
    }
}

void customer :: update(int accountNumber)
{
	int count = 0;
	map<int,customerRecord> :: iterator p = customerMap.begin();
	while(true)
	{
		if (p -> first == accountNumber)
		{
			customerRecord *customer_Record;
        	customer_Record = new customerRecord;
			
        	char name[100];
            short int age;
        	char dateOfBirth[100];
        	char address[100];
	        char phone[100];
	        char citizenShip[100];
	        char occupation[100];	
	
	        cout << "Enter Name:";
	        cin.getline(name,29);
	    	cin.ignore('\n');
	        customer_Record -> setName(name);
	        
	        cin.clear();
	        cin.sync();
	
	        cout << "Enter Age:";
	        a:
			cin >> age;
	    	
			if (cin.fail()) // THIS FUNCTION CHECKS WEATHER OR NOT INPUT DATATYPE IS CORRECT
	        { 
	        	cin.clear();
		        cin.sync();
		        cin.ignore(256,'\n');
		    
		        cout << "Invalid Input! Enter Valid Age:";
		        goto a;
	        }

		    customer_Record -> setAge(age);
	        cin.sync();
	        cin.clear();
	
	        cout << "Enter DOB(dd/mm/yyyy):";
            cin.getline(dateOfBirth,29);
	        customer_Record -> setDateOfBirth(dateOfBirth);
	
	        cin.sync();
	        cin.clear();
	
	      cout << "Enter Address:";
	      cin.getline(address,29);
  	      customer_Record -> setAddress(address);
	      
		  cin.clear();
	      cin.sync();
	
 	      cout << "Enter Phone:";
	      cin.getline(phone,29);

 	      customer_Record -> setPhone(phone);
	
	      cin.clear();
	      cin.sync();
	
	      cout << "Enter Citizenship:";
	      cin.getline(citizenShip,29);
		  customer_Record -> setCitizenShip(citizenShip);

	      cin.clear();
	      cin.sync();
	
	      cout << "Occupation:";
	      cin.getline(occupation,29);
	      customer_Record -> setOccupation(occupation);
	
	      cin.clear();
	      cin.sync();
	      customer_Record -> updateAccountRecord(accountNumber);
	      
	      this -> deleteOldFile();
	      
          customerMap[accountNumber] = customer_Record -> getCustomerRecord(); //overwriting or updating record in map
       	  this -> writeNewRecords();
		  cout << "\t*****Record Updated Successfully*****!\n";
	
       	  delete customer_Record;
	      break; // as record gets found
	}   
	   else if (count == customerMap.size() && p -> first != accountNumber)
	   {
			cout << "\t\t*****Record Not Found!*****";
			break;
	   } 
		p++;
		count++;
	}
}

void customer :: Delete(int accountNumber)
{
	int count = 0;
	map<int,customerRecord> :: iterator p = customerMap.begin();
	
	while(true)
	{
        if(p -> first == accountNumber)
		{
            customerMap.erase(accountNumber); //old record is removed from map
            this -> deleteOldFile();
            this -> writeNewRecords();
            cout << "\n\t\t*****Record Successfully Removed*****\n\n";
        	break;
		}
		else if (count == customerMap.size() && p -> first != accountNumber)
		{
			cout << "\n\t\t*****Record Not Found!*****\n\n";
			break;
		}
		
		count++;
		p++;
		
    }
}

void customer :: showCustomerRecords(void)
{
	customerRecord customer_Record;// = new customerRecord;
	map<int,customerRecord> :: iterator p = customerMap.begin();
    
	if (customerMap.empty() == 1) //empty() returns 1 if map is null and 0 if map contains elementS
    {
    	cout << "\t\t*****No Record Found!*****\n\n";
	}
	
	else if (customerMap.empty() == 0)//empty() returns 1 if map is null and 0 if map contains elementS
	{
		cout << "\t\t*****ALL RECORDS*****\n\n";
	   for(int i = 1 ; p != customerMap.end() ; i++)
	   {
	   	    cout << "\n\tCUSTOMER # " << i << "\n\n";
	    	customer_Record = p -> second;
		    customer_Record.showCustomerData();
	    	p++;
	   }
     }
 //delete customer_Record;
}

void customer :: changeCustomerPin(int accountNumber,char pin[50])
{
	customerRecord customer_Record;
	
	customer_Record = customerMap.at(accountNumber);
	customer_Record.setPin(pin);
	customerMap[accountNumber] = customer_Record.getCustomerRecord(); //overwriting or updating record in map
      	    
    this -> deleteOldFile();
    this -> writeNewRecords();

}

void customer :: deposit(int accountNumber)
{
	customerRecord customer_Record;
	int count = 0;
	map<int,customerRecord> :: iterator p = customerMap.begin();
	
	while(true)
	{
        if(p -> first == accountNumber)
		{
			customer_Record = p -> second;
			double amount;
			cout << "Enter Amount To Deposit:";
			cin >> amount;
			
			    customer_Record.deposit(amount);
			    customerMap[accountNumber] = customer_Record.getCustomerRecord(); //overwriting or updating record in map
       	    
       	        this -> deleteOldFile();
       	        this -> writeNewRecords();
			    cout << "\n\t\tYou Have Successfully Deposited " << amount << endl;
			break;
		}
		else if (count == customerMap.size() && p -> first != accountNumber)
		{
			cout << "\n\t\t*****Record Not Found!*****\n\n";
 			break;
		}
		
		count++;
		p++;
		
    }
}

void customer :: withdraw(int accountNumber)
{
	customerRecord customer_Record;
	int count = 0;
	map<int,customerRecord> :: iterator p = customerMap.begin();
	
	while(true)
	{
        if(p -> first == accountNumber)
		{
			customer_Record = p -> second;
			double amount;
			cout << "Enter Amount To Withdraw:";
			cin >> amount;
			
			if (amount <= customer_Record.getCurrentBalance()-500 && customer_Record.getCurrentBalance() > 500)
			{
			    customer_Record.withdraw(amount);
			    customerMap[accountNumber] = customer_Record.getCustomerRecord(); //overwriting or updating record in map
       	       
				this -> deleteOldFile();
       	        this -> writeNewRecords();
			    cout << "\n\t\tYou Have Successfully Withdrawn " << amount << endl;
        	}
        	
        	else
        	{
        		cout << "\n\t\tCannot Withdraw Due To Insufficient Balance!" << endl;
			}
			break;
		}
		else if (count == customerMap.size() && p -> first != accountNumber)
		{
			cout << "\n\t\t*****Record Not Found!*****\n\n";
 			break;
		}
		
		count++;
		p++;
		
    }
}

void customer :: transfer(int accountNumber1,int accountNumber2)
{
	bool status1,status2;
	customerRecord customer_Record1,customer_Record2;
	int count = 0;
	map<int,customerRecord> :: iterator p = customerMap.begin();
	
	//For Sender
	while(true)
	{
	    if(p -> first == accountNumber1)
		{
			customer_Record1 = p -> second;
        	status1 = 1;
			break;
		}
		else if (count == customerMap.size() && p -> first != accountNumber1)
		{
			cout << "\n\t\t*****No Record Of Account Number " << accountNumber1 <<  " Found!*****\n\n";
			status1 = 0;
			break;
		}
		
		count++;
		p++;
    }
		 p = customerMap.begin(); // for starting from begining for second record
	
	count = 0;
	
	//For Reciever
	while(true)
	{
		
        if(p -> first == accountNumber2)
		{
			customer_Record2 = p -> second;
        	status2 = 1;
			break;
		}
		else if (count == customerMap.size() && p -> first != accountNumber2)
		{
			cout << "\n\t\t*****No Record Of Account Number " << accountNumber2 <<  " Found!*****\n\n";
			status2 = 1;
			break;
		}
		
		count++;
		p++;		
    }
    
    
    if (status1 == 1 && status2 == 1)
    {
    	double amount;
		cout << "Enter Amount To Transfer:";
		cin >> amount;
				
    		if (amount <= customer_Record1.getCurrentBalance()-500 && customer_Record1.getCurrentBalance() > 500)
			{
			    customer_Record2.setCurrentBalance(customer_Record2.getCurrentBalance() + amount); //for adding amount transfered by other account
                customer_Record1.withdraw(amount); //For Minus amount That is transferd in another account

			    customerMap[accountNumber1] = customer_Record1.getCustomerRecord(); //overwriting or updating record in map
				customerMap[accountNumber2] = customer_Record2.getCustomerRecord(); //overwriting or updating record in map
				this -> deleteOldFile();
       	        this -> writeNewRecords();
			    cout << "\n\t\tYou Have Successfully Transfered " << amount << " Into Account " << accountNumber2 << endl;
        	}
        	else
        	{
        		cout << "\n\t\tCannot Withdraw Due To Insufficient Balance!" << endl;
			}
    	
	}
}

void customer :: writeNewRecords()// for update and Delete
{
	customerRecord customer_Record;// = new customerRecord;
	map<int,customerRecord> :: iterator p = customerMap.begin();
	string fileName("customer.dat");
	ofstream fout;
	fout.open(fileName,ios :: out | ios :: binary);
	 while(p != customerMap.end())
	 {
	    customer_Record = p -> second;
	    fout.write((char*)&customer_Record,sizeof(customerRecord));
		p++;
	 }
	fout.close();
	//delete customer_Record;
}

void customer :: deleteOldFile() /*for updating and deleting reocords this function
                                  deletes old file so we can create new file to save updated records*/
{ 
	remove("customer.dat");
}

 //GETTER
 
customerRecord customer :: getCustomer(int accountNumber)
{
    customerRecord customer_Record;// = new customerRecord;
    map<int,customerRecord> :: iterator p = customerMap.begin();
    
    while (p != customerMap.end())
    {
	
	   if (p -> first == accountNumber)
	   {
	   	    customer_Record = customerMap.at(accountNumber);
		    return customer_Record;
		    break;
       }
       else if (p == customerMap.end())
       cout << "\t\t*****No Record Found!*****\n\n";
       
       p++;
    }
}

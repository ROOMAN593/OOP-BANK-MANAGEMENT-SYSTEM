#include "customerRecord.h"
#include <fstream>             
using namespace std;

customerRecord :: customerRecord()
{
	age = 0;
}
customerRecord :: customerRecord(char name[100],short int age,char dateOfBirth[100],char address[100],char citizenShip[100],char occupation[100],char accountType[100],double currentBalance)
{
	strcpy(this -> name , name);
		if (age < 0) // FOR ACCIDENTAL INPUT
	{
		age = -age;
	}
	this -> age = age;
	strcpy(this -> dateOfBirth , dateOfBirth);
	strcpy(this -> address , address);
	strcpy(this -> phone , phone);
	strcpy(this -> citizenShip , citizenShip);
	strcpy(this -> occupation , occupation);
	     // For Account Record
	account_Record.setAccountNumber();
	account_Record.setAccountType(accountType);
	account_Record.setCurrentBalance(currentBalance);
}
     
	       //MUTATORS
void customerRecord :: setName(char name[100])
{
	strcpy(this -> name , name);
}

void customerRecord :: setAge(short int age)
{
	if (age < 0) // FOR ACCIDENTAL INPUT
	{
		age = -age;
	}
	this -> age = age;
}

void customerRecord :: setGender(char gender[30])
{
	strcpy(this -> gender , gender);

}
void customerRecord :: setDateOfBirth(char dateOfBirth[100])
{
	strcpy(this -> dateOfBirth , dateOfBirth);
}

void customerRecord :: setAddress(char address[100])
{
	strcpy(this -> address , address);
}

void customerRecord :: setPhone(char phone[100])
{
	strcpy(this -> phone , phone);
}

void customerRecord :: setCitizenShip(char citizenShip[100])
{
    strcpy(this -> citizenShip , citizenShip);	
}

void customerRecord :: setOccupation(char occupation[100])
{
	strcpy(this -> occupation , occupation);
}

void customerRecord :: setCurrentBalance(double currentBalance)
{
	account_Record.setCurrentBalance(currentBalance);
}
void customerRecord :: updateAccountRecord(int accountNumber) // This Function Is Just To Not To Change Account No which was set Before
{
	double balance;
	account_Record.setAccountNumber(accountNumber);
	account_Record.setAccountType();
	
	cout << "Current Balance:";
	a:
	cin >> balance;
	cin.sync();
	cin.clear();
	if (balance < 500)  
   {
	 cout << "Cannot Deposit Less Than 500!\nEnter More Than 500:";
	 goto a;
   }

	
	account_Record.setCurrentBalance(balance);
}

void customerRecord :: setAccountRecord(void)
{
	double balance;
	
	account_Record.setAccountNumber();
	
	account_Record.setAccountType();
	
	cout << "Current Balance:";
	a:
	cin >> balance;
	cin.sync();
	cin.clear();
	if (balance < 500)  
   {
	 cout << "Cannot Deposit Less Than 500!\nEnter More Than 500:";
	 goto a;
   }

	
	account_Record.setCurrentBalance(balance);
}

void customerRecord :: deposit(double amount)
{
	amount = amount + this -> getCurrentBalance();
	this -> setCurrentBalance(amount);
}

void customerRecord :: withdraw(double amount)
{
	amount = this -> getCurrentBalance() - amount;
	this -> setCurrentBalance(amount);
}

void customerRecord :: setPin(char pin[50])	
{
    strcpy(this -> pin , pin);
}	
		//GETTERS
string customerRecord :: getName(void) const
{
    string name;
	name = this -> name;
	return name;
}


int customerRecord :: getAge(void) const
{
	return age;
}

string customerRecord :: getGender() const
{
	string gender;
	gender = this -> gender;
    return gender;
}

string customerRecord :: getDateOfBirth(void) const
{
	string dateOfBirth;
	dateOfBirth = this -> dateOfBirth;
	return dateOfBirth;
}

string customerRecord :: getAddress(void) const
{
	string address;
	address = this -> address;
	return address;
}

string customerRecord :: getPhone(void) const
{
	string phone;
	phone = this -> phone;
	return phone;
}

string customerRecord :: getCitizenShip(void) const
{
	string citizenShip;
	citizenShip = this -> citizenShip;
	return citizenShip;
}

string customerRecord :: getOccupation(void) const
{
	string occupation;
	occupation = this -> occupation;
	return occupation;
}

int customerRecord :: getAccountNumber(void) const
{
	return account_Record.getAccountNumber();
}

string customerRecord :: getAccountType(void) const
{
	string accountType;
	accountType = this -> account_Record.getAccountType();
	return accountType;
}

double customerRecord :: getCurrentBalance(void) const
{
	return account_Record.getCurrentBalance();
}

customerRecord customerRecord :: getCustomerRecord(void) const
{
	return (*this);
}
		
		//DATA CHECKER
		
void customerRecord :: showCustomerData(void)
{
    cout << "Name:"; //<< this -> name << endl;
    puts(this -> name);
    cout << "Age:" << this -> age << endl;
	cout << "Date Of Birth:";// << this -> dateOfBirth << endl;
	puts(this -> dateOfBirth);
	cout << "Gender:";
	puts(this -> gender);
	cout << "Address:"; //<< this -> address << endl;
	puts(this -> address);
	cout << "Phone:"; //<< this -> phone << endl;
    puts(this -> phone);
	cout << "Citizenship:"; //<< this -> citizenShip << endl;
	puts(this -> citizenShip);
	cout << "Occupation:"; //<< this -> occupation << endl;
    puts(this -> occupation);
	account_Record.showAccountData();

}

string customerRecord :: getPin(void) const
{
	string pin;
	pin = this -> pin;
	return pin;
}
         //FOR FILING

void customerRecord :: WRITE()// for writing in a file
{
	string fileName("customer.dat");
	ofstream fout;
	fout.open(fileName,ios :: app | ios :: binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}

bool customerRecord :: READ() //FOR LOADING RECORD IN MAP WHEN PROGRAM STARTS
{
	string fileName("customer.dat");
	ifstream fin;
	fin.open(fileName,ios :: in | ios :: binary);
	if (!fin)
	{
		cout << "File not Found";
		return 0;
	}
	
	else
	{
	    fin.read((char*)this,sizeof(*this));
	    fin.close();
	    cout << "record loaded";
	    return 1;
    }
    getch();
}  

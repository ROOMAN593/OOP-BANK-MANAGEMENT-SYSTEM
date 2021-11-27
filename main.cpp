#include <iostream>
#include "customer.h"
#include "admin.h"
using namespace std;

admin ad; //Globally Declared
customer c;

void createAdminAccount(void); //4th
void createCustomerAccount(void); //5th
void login(void); // 1st

void checkRecord(void); // for checking single record using account number
void showData(void); // for checking all customer records
void updateRecord(void);
void deleteRecord(void);
void adminTransaction(void); // for admin 
void adminWithdraw(void); // for admin
void adminDeposit(void); //for admin
void adminTransfer(void);//for admin
void customerTransaction(int accountNumber);
void customerWithdraw(int accountNumber);
void customerDeposit(int accountNumber);
void customerTransfer(int accountNumber);
void changeCustomerPin(customerRecord &customer_Record);
void admin(customerRecord &customer_Record);//2nd // Controls All Activity such as creating ccounts,transactions etc
void customer(customerRecord &customer_Record); //3rd // Controls Only Specific Customer Account


int main()
{
	ad.READ(); //For Loading Record Of Admin
	cout << endl;
	system("pause");
	login();
}

void admin(void)
{
	
	string choice;
	a:
	system("cls");

	cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM";
	cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	cout << "\n\n\t\t1.Create Account\n\t\t2.check customer record\n\t\t3.Update Customer Record\n\t\t4.Delete Customer Record\n\t\t5.View Records List\n\t\t6.Transaction\n\t\t7.Change Pin\n\t\t8.Logout\n\t\t9.Exit\n\n\n\n\n\t\tEnter Choice:";
	cin >> choice;
	
	cin.clear();
	cin.sync();
	
	if (choice == "1")
	{ 
	    system("cls");
	    createCustomerAccount();
	}
	else if (choice == "2")
	{
		system("cls");
		checkRecord();
	}
	else if(choice == "3")
	{
		system("cls");
		updateRecord();
	}
	else if (choice == "4")
	{
		system("cls");
		deleteRecord();
	}
	else if(choice == "5")
	{
		system("cls");
		showData();
	}
	else if(choice == "6")
	{
		system("cls");
		adminTransaction();
	}
	
	/*else if(choice == "7")
	{
		changeAdminPin();
	}*/
	else if (choice == "8")
	{
		system("cls");
		cout << "\t\t*****Thanks For Using Our Service!*****" << endl;
		system("pause");
		login();		
	}
	
	else if (choice == "9")
	{
		system("cls");
		cout << "\t\t*****Thanks For Using Our Service!*****" << endl;
		cout << "\n\t\tThis Program Is Made By Muhammad Owais Danish , Muhammad Rooman And Shubair Raza";
		exit(0);	
	}
	else
	{
		cout << "invalid Choice!";
		cout << " Try Again:";
		getch();
	}
	goto a; 
}

void login(void)
{
	//login:
	system("cls");
	string choice;
	cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM";
    cout << "\n\n\n\t\t\t\t\tLogin As,\n\n\n\t\t\t\t\t1.ADMIN\n\t\t\t\t\t2.CUSTOMER\n\t\t\t\t\t3.CREATE ACCOUNT\n\t\t\t\t\t4.EXIT\n\n\n\t\t\t\t\tEnter Choice:";
    a:
	cin >> choice;
    
    cin.clear();
    cin.sync();
    
    if (choice == "1")
    {
    	char name[100];
    	char pin[50];
    	signIn:
    	system("cls");
    	cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM";
        cout << "\n\n\n\t\t\tName:";
        cin >> name;
        
        cout << "\n\n\t\t\tPin:";
        cin >> pin;
                
        cin.clear();
        cin.sync();
        
        if (pin == ad.getPin() && name == ad.getName())
        {
        	cout << "\n\n\t\tWelcome "<< name << "!";
        	getch();
        	admin();
		}
		
		else
		{
			string choice;
			
			cout << "\n\n\t\tWrong Pin Or Username!\n\n\t\tPress 0 To Go Back Or 1 To continue:";
			C:
			cin >> choice;
			
			cin.clear();
			cin.sync();
			
			if (choice == "0")
			{
			   login();
			}
			else if (choice == "1")
			{
			    goto signIn;	
			}
			else
			{
				cout << "invalid Choice!";
		        cout << " Enter Valid Choice:";
		        goto C;
			}
		}
    	
	}
    
    else if (choice == "2")
    {
    	customerRecord customer_Record; 
    	int accountNumber;
    	char pin[50];
    	sign:
    	system("cls");
    	cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM";
        cout << "\n\n\n\t\t\tAccount Number:";
        
        m:
		cin >> accountNumber;
   	if (cin.fail()) // THIS FUNCTION CHECKS WEATHER OR NOT INPUT DATATYPE IS CORRECT
	{
		cin.clear();
		cin.sync();
		
		cout << "Invalid Input! Enter Valid Account Number:";
		goto m;
	}
        
        cout << "\n\n\t\t\tPin:";
        cin >> pin;
                
        cin.clear();
        cin.sync();
        
        customer_Record = c.getCustomer(accountNumber); //Lodaing specific record from map
        if (customer_Record.getPin() == pin && accountNumber == customer_Record.getAccountNumber())
        {
        	cout << "\n\n\t\tWelcome "<< customer_Record.getName() << "!";
        	getch();
        	customer(customer_Record);
		}
		
		else
		{
			string choice;
			
			cout << "\n\n\t\tWrong Pin Or Account Number!\n\n\t\tPress 0 To Go Back Or 1 To continue:";
			B:
			cin >> choice;
			
			cin.clear();
			cin.sync();
			
			if (choice == "0")
			{
			   login();
			}
			else if (choice == "1")
			{
			    goto sign;	
			}
			else
			{
				cout << "invalid Choice!";
		        cout << " Enter Valid Choice:";
		        goto B;
			}
		}
    	
	}
	else if (choice == "3")
	{
		createAdminAccount();
		cout << "\n\tPress Any Key To Continue:";
		getch();
		login();
	}
	
	else if (choice == "4")
	{
		
		system("cls");
		cout << "\t\t*****Thanks For Using Our Service!*****" << endl;
		cout << "\n\t\tThis Program Is Made By Muhammad Owais Danish, Muhammad Rooman And Shubair Raza";
		exit(0);		
	}
	
	else
	{
		cout << "invalid Choice!";
		cout << " Try Again:";
		getch();
		goto a;
	}
	
}

void createCustomerAccount(void)

{
	customerRecord customer_Record;
			
	char name[100];
	short int age;
	char gender[30];
	char dateOfBirth[100];
	char address[100];
	char phone[100];
	char citizenShip[100];
	char occupation[100];	
	char newPin[50];
	char confirmPin[50];
	
	cout << "Enter Name:";
	cin.getline(name,99);	
	customer_Record.setName(name);
	
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
	customer_Record.setAge(age);
	cin.sync();
	cin.clear();
	
	cout << "Enter DOB(dd/mm/yyyy):";
	cin.getline(dateOfBirth,99);
	customer_Record.setDateOfBirth(dateOfBirth);
	
	cin.sync();
	cin.clear();
	
	cout << "Enter Gender:";
	cin.getline(gender,29);

	customer_Record.setGender(gender);
	
	cin.sync();
	cin.clear();
	
	cout << "Enter Address:";
	cin.getline(address,99);

	customer_Record.setAddress(address);

	cin.clear();
	cin.sync();
	
	cout << "Enter Phone:";
	cin.getline(phone,99);

	customer_Record.setPhone(phone);
	
	cin.clear();
	cin.sync();
	
	cout << "Enter Citizenship:";
	cin.getline(citizenShip,99);

	customer_Record.setCitizenShip(citizenShip);

	cin.clear();
	cin.sync();
	
	cout << "Enter Occupation:";
	cin.getline(occupation,99);

    customer_Record.setOccupation(occupation);
	
	cin.clear();
	cin.sync();
	
	customer_Record.setAccountRecord();
	
	system("cls");
	b:
	cout << "Enter Pin:";
	cin >> newPin;
	
	cin.clear();
	cin.sync();
	
	cout << "Confirm pin:";
	cin >> confirmPin;
	
	cin.clear();
	cin.sync();
	
	if (strcmp(newPin , confirmPin) == 0)
	{
		cout << "\nPin Matched!\n";
		customer_Record.setPin(newPin);
		system("pause");
	}
	
	else 
	{
		cout << "\nPin Did Not Matched!";
		cout << "\nEnter Again!";
		system("pause");
		system("cls");
		goto b;
	}
	
	c.insert(customer_Record); // Saving in map
	system("cls");
	
	cout << "\t\tRecord Saved!\n\n";
	customer_Record.showCustomerData();
	cout << "press any key to continue:";
    getch();
}

void checkRecord(void)
{
	int accountNumber;
	cout << "Enter Account Number:";
	cin >> accountNumber;
    cin.sync();
    cin.clear();
    
	c.fetch(accountNumber);
    cout << "press any key to continue:";
    getch();
}

void createAdminAccount(void)
{
	a:
	system("cls");
	string temp;
	string productKey = "owais546";
	
	cout << "Enter Product Key:"; // This Required to prevent Making More Than One Admin Account
	cin >> temp;
	
	cin.clear();
	cin.sync();
	
  if (temp == productKey)
  {
	cout << "\n\t\tProduct Key Matched!\n";
	system("pause");
	system("cls");
	cout << "\n\n\t\t*****Create Account*****\n";
	char name[100];
	short int age;
	char gender[30];
	char dateOfBirth[100];
	char pin[50];
	
	cout << "Enter Name:";
	cin.getline(name,99);	
	ad.setName(name);
	
	cin.clear();
	cin.sync();
	
	cout << "Enter Age:";
	c:
	cin >> age;
	if (cin.fail()) // THIS FUNCTION CHECKS WEATHER OR NOT INPUT DATATYPE IS CORRECT
	{
		cin.clear();
		cin.sync();
		cin.ignore(256,'\n');
		
		cout << "Invalid Input! Enter Valid Age:";
		goto c;
	}
	ad.setAge(age);
	cin.sync();
	cin.clear();
	
	cout << "Enter DOB(dd/mm/yyyy):";
	cin.getline(dateOfBirth,99);
	ad.setDateOfBirth(dateOfBirth);
	
	cin.sync();
	cin.clear();
	
	cout << "Enter Gender:";
	cin.getline(gender,29);

	ad.setGender(gender);
	
	cin.sync();
	cin.clear();
	
	cout << "Enter pin:";
	cin.getline(pin,50);

	ad.setPin(pin);
	
	cin.sync();
	cin.clear();
	
	ad.WRITE();
	
	system("cls");
	cout << "\n\t\tAccount Created!";
  }
  else
  {
  	string choice;
  	cout << "Wrong Key!";
  	cout << "Press 0 To Go Back Or 1 To retry:";
  	b:
	  cin >> choice;
  	
  	cin.clear();
  	cin.sync();
  	
  	if (choice == "0")
  	{
  	   login();	
    }
    
    else if (choice == "1")
    {
    	goto a;
	}
	
	else
	{
		cout << "Invalid Choice!";
		cout << "Enter Again:";
		goto b;
	}
  	
  }
  
}

void customer(customerRecord &customer_Record)
{
	os:
	system("cls");
	string choice;
	cout << "\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM";
	cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	cout << "\n\n\t\t1.Transaction\n\t\t2.Check Balance\n\t\t3.Change Pin\n\t\t4.Info\n\t\t5.Logout\n\t\t6.Exit\n\n\n\n\n\t\tEnter Choice:";
    cin >> choice;
    
    cin.clear();
    cin.sync();
    
    if (choice == "1")
	{ 
	    system("cls");
	    customerTransaction(customer_Record.getAccountNumber());
	    customer_Record = c.getCustomer(customer_Record.getAccountNumber()); // For overwritting that record which is updated after Transaction
	}
	else if (choice == "2")
	{
		system("cls");
		cout << "Your Current Balance " << customer_Record.getCurrentBalance();
		cout << "\n";
		system("pause");
	}
	else if(choice == "3")
	{
		system("cls");
		changeCustomerPin(customer_Record);
	}
	else if (choice == "4")
	{
		system("cls");
		c.fetch(customer_Record.getAccountNumber());
		cout << "\n";
		system("pause");			    
	}
	
	else if(choice == "5")
	{
		system("cls");
		cout << "\t\t*****Thanks For Using Our Service!*****" << endl;
		system("pause");
		login(); // going back to main menu
	}
	
	else if (choice == "6")
	{
		system("cls");
		cout << "\t\t*****Thanks For Using Our Service!*****" << endl;
		cout << "\n\t\tThis Program Is Made By Muhammad Owais Danish";
		exit(0);	
	}
	goto os;
    
}

void showData(void)
{
	c.showCustomerRecords();
	cout << "press any key to continue:";
    getch();
}

void updateRecord(void)
{
	int accountNumber;
	  cout << "Enter Account Number:";
	  cin >> accountNumber;
      cin.sync();
      
	string choice;
	cout << "Are You Sure?\n  1-YES 2-NO\n";
	cout << "Enter Choice:";
	b:
	cin >> choice;
	cin.clear();
	cin.sync();
	
	if (choice == "1")
	{
	  system("cls");
	  c.update(accountNumber);
    }
    else if(choice == "2")
    {
       goto a;
	}
	
	else
	{
		cout << "Invalid Choice!";
		goto b;
	}
	a:
	cout << "\n\npress any key to continue:";
    getch();
}

void deleteRecord(void)
{
	int accountNumber;
	cout << "Enter Account Number:";
	cin >> accountNumber;
    cin.sync();
      
	string choice;
	cout << "Are You Sure?\n  1-YES 2-NO\n";
	cout << "Enter Choice:";
	b:
	cin >> choice;
	cin.clear();
	cin.sync();
	
	if (choice == "1")
	{
	  system("cls");
	  c.Delete(accountNumber);
    }
    else if(choice == "2")
    {
       goto a;
	}
	
	else
	{
		cout << "Invalid Choice!";
		goto b;
	}
	a:
    cout << "press any key to continue:";
    getch();    
}

void adminTransaction(void)
{
	string choice;
	
	cout << "1.Withdraw\n2.Deposit\n3.Transfer:\n\n";
	cout << "Enter Choice:";
	a:
	cin.clear();
	cin.sync();
	
	cin >> choice;
	
	if (choice == "1")
	{
		adminWithdraw();
	}
	
	else if (choice == "2")
	{
		adminDeposit();
	}
	
	else if (choice == "3")
	{
		adminTransfer();
	}
	else
	{
		cout << "Invalid Choice! Enter Valid Choice:";
		goto a;
	}
	
	cout << "press any key to continue:";
    getch();
}

void adminWithdraw(void)
{
	int accountNumber;
	cout << "Enter Account Number:";
	cin >> accountNumber;
	cin.clear();
	cin.sync();
	
	c.withdraw(accountNumber);
}

void adminDeposit(void)
{
	int accountNumber;
	cout << "Enter Account Number:";
	cin >> accountNumber;
	cin.clear();
	cin.sync();
	
	c.deposit(accountNumber);
}

void adminTransfer(void)
{
	int accountNumber1,accountNumber2;
	cout << "Enter Account Number Of Sender:";
	cin >> accountNumber1;
	cin.clear();
	cin.sync();
	
	
	cout << "Enter Account Number Of Reciver:";
	cin >> accountNumber2;
	cin.clear();
	cin.sync();
	c.transfer(accountNumber1,accountNumber2);
}

void customerTransaction(int accountNumber)
{
	string choice;
	
	cout << "1.Withdraw\n2.Deposit\n3.Transfer:\n\n";
	cout << "Enter Choice:";
	a:
	cin.clear();
	cin.sync();
	
	cin >> choice;
	
	if (choice == "1")
	{
		customerWithdraw(accountNumber);
	}
	
	else if (choice == "2")
	{
		customerDeposit(accountNumber);
	}
	
	else if (choice == "3")
	{
		customerTransfer(accountNumber);
	}
	else
	{
		cout << "Invalid Choice! Enter Valid Choice:";
		goto a;
	}
	
	cout << "press any key to continue:";
    getch();
}

void customerWithdraw(int accountNumber)
{
	c.withdraw(accountNumber);
}

void customerDeposit(int accountNumber)
{	
	c.deposit(accountNumber);
}

void customerTransfer(int accountNumber1)
{
	int accountNumber2;
	cout << "Enter Account Number Of Reciver:";
	cin >> accountNumber2;
	cin.clear();
	cin.sync();
	c.transfer(accountNumber1,accountNumber2);
}

void changeCustomerPin(customerRecord &customer_Record)
{
	char oldPin[50];
	char newPin[50];
	char confirmPin[50];
	
	system("cls");
	
	c:
	cout << "Enter Old Pin:";
	cin >> oldPin;
	
	if (customer_Record.getPin() == oldPin)
	{
		b:
	    cout << "Enter New Pin:";
	    cin >> newPin;
	
    	cin.clear();
	    cin.sync();
	
	    cout << "Confirm pin:";
	    cin >> confirmPin;
	
	    cin.clear();
	    cin.sync();
	
	    if (strcmp(newPin , confirmPin) == 0)
	    {
		    cout << "\nPin Matched!\n";
		    c.changeCustomerPin(customer_Record.getAccountNumber(),newPin);
		    cout << "\nPin Successfully Changed!\n";
		    system("pause");
	    }
	
	    else 
	    {
		    cout << "\nPin Did Not Matched!";
		    cout << "\nEnter Again!";
		    system("pause");
		    system("cls");
		    goto b;
	    }
	
	}
	
	else 
	{
		string choice;
		
		cout << "\nWrong Pin!\n";
	    cout << "Press 0 To Go Back Or 1 To Retry:";
	    d:
		cin >> choice;
	    
	    cin.clear();
	    cin.sync();
	    
	    if (choice == "0")
	    {
	    	customer(customer_Record);
		}
		
		else if (choice == "1")
		{
			goto c;
		}
		
		else
		{
			cout << "Invalid choice! Enter Again:";
			goto d;
		}
	}
}

#include "admin.h"

void admin :: setPin(char pin[50])
{
	strcpy(this -> pin , pin);
}

string admin :: getPin(void) const
{
	string pin;
	pin = this -> pin;
	return pin;
}

void admin :: setName(char name[100])
{
	strcpy(this -> name , name);
}

void admin :: setAge(short int age)
{
	if (age < 0) // FOR ACCIDENTAL INPUT
	{
		age = -age;
	}
	this -> age = age;
}

void admin :: setGender(char gender[30])
{
	strcpy(this -> gender , gender);

}
void admin :: setDateOfBirth(char dateOfBirth[100])
{
	strcpy(this -> dateOfBirth , dateOfBirth);
}

string admin :: getName(void) const
{
    string name;
	name = this -> name;
	//strcpy(name , this -> name);
	return name;
}

int admin :: getAge(void) const
{
	
	return age;
}

string admin :: getGender() const
{
	string gender;
	gender = this -> gender;
    return gender;
}

string admin :: getDateOfBirth(void) const
{
	string dateOfBirth;
	dateOfBirth = this -> dateOfBirth;
	return dateOfBirth;
}

void admin :: WRITE(void)
{
	ofstream fout;
	fout.open("admin.dat");
	fout.write((char*)this,sizeof(admin));
	fout.close();
}
void admin :: READ(void)
{
	ifstream fin;
	fin.open("admin.dat");
	if(!fin)
	{
		cout << "\nFile Not Found For Admin!";
	}
	else
	{
		fin.read((char*)this,sizeof(admin));
		cout << "\nAdmin Record Loaded!";
	}
	fin.close();
}

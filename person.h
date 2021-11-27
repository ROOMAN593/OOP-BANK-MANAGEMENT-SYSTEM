#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;
class person
{
	protected:
	char name[100];
	short int age;
	char gender[30];
	char dateOfBirth[100];

    public:
    	   //MUTATORS
    virtual	void setName(char name[100]) = 0;
	virtual	void setAge(short int age) = 0;
	virtual void setGender(char gender[30]) = 0;
	virtual	void setDateOfBirth(char dateOfBirth[100]) = 0;
	
	       //ACCESSORS
	virtual string getName(void) const = 0;
	virtual	int getAge(void) const = 0;
	virtual string getGender() const = 0;
	virtual	string getDateOfBirth(void) const = 0;       
	       
};
#endif

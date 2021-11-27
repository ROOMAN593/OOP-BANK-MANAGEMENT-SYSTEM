#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include <fstream>
#include <cstring>

class admin : person
{
    char pin[50];
	
	public:
		admin(){};
		void setPin(char pin[50]);
		void setName(char name[100]);
		void setAge(short int age);
		void setGender(char gender[30]);
		void setDateOfBirth(char dateOfBirth[100]);      
		void READ(void);
		void WRITE(void);
		
		string getPin(void) const;
		string getName(void) const;
		int getAge(void) const;
		string getGender(void) const;
		string getDateOfBirth(void) const;
};
#endif

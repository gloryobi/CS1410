//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

class Person
{
	public:
		Person();
		string getID();
		void setID(string ID);
		string getName();
		void setName(string name);
		string getDOB();                  //get date of birth
		void setDOB(string DOB);
		string getGender();
		void setGender(string gender);
		string getAddress();
		void setAddress(string address);
		virtual void read();            //virtual functions
		virtual void write();

	private:
		string m_ID;
		string m_name;
		string m_DOB;               //date of birth
		string m_gender;
		string m_address;

};

#endif
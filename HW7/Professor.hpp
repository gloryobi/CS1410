//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef PROFESSOR_HPP_INCLUDED
#define PROFESSOR_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include "Person.hpp"

using namespace std;

class Professor : public Person             // derived class
{
	public:
		Professor();
		string getJobTitle();
		void setJobTitle(string jobTitle);
		string getOffice();
		void setOffice(string office);
		double getSalary();
		void setSalary(double salary);
		void read();
		void write();

	private:
		string m_jobTitle;
		string m_office;
		double m_salary;

};

#endif
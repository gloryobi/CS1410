//Glory obielodan
//cs 1410 - 002
//a02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "person.hpp"
#include "professor.hpp"

using namespace std;

Professor::Professor() : Person()            //empty values
{
	m_jobTitle = "";
	m_office = "";
	m_salary = 0;
}

string Professor::getJobTitle()
{
	return m_jobTitle;
}

void Professor::setJobTitle(string jobTitle)
{
	m_jobTitle = jobTitle;
}

string Professor::getOffice()
{
	return m_office;
}

void Professor::setOffice(string office)
{
	m_office = office;
}

double Professor::getSalary()
{
	return m_salary;
}

void Professor::setSalary(double salary)
{
	m_salary = salary;
}

void Professor::read()            //get information
{
	string jobTitle;
	string office;
	double salary;
	string id;
	string name;
	string DOB;
	string gender;
	string address;

	cout << "What is the Professor's ID: ";
	cin.ignore();
	getline(cin, id);
	setID(id);
	cout << "What is his/her name: ";
	getline(cin, name);
	setName(name);
	cout << "What is his/her gender: ";
	getline(cin, gender);
	setGender(gender);
	cout << "What is the Date of Birth: ";
	getline(cin, DOB);
	setDOB(DOB);
	cout << "What is the Address: ";
	getline(cin, address);
	setAddress(address);
	cout << "What is the Job Title: ";
	getline(cin, jobTitle);
	setJobTitle(jobTitle);
	cout << "What is the Office: ";
	getline(cin, office);
	setOffice(office);
	cout << "What is the salary: ";
	cin >> salary;
	setSalary(salary);
}

void Professor::write()          //print
{
	cout << "***********Professor Information***********\n\n";
	cout << "ID: " << getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Date of Birth: " << getDOB() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Job Title: " << m_jobTitle << endl;
	cout << "Office: " << m_office << endl;
	cout << "Salary: $" << fixed << setprecision(2) << m_salary << endl;
}
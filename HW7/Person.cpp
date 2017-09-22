//Glory Obielodan
//CS 1410 - 002
//A02042652

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

Person::Person()          //empty values
{
	m_ID = "";
	m_name = "";
	m_DOB = "";
	m_gender = "";
	m_address;
}

string Person::getID()
{
	return m_ID;
}

void Person::setID(string ID)
{
	m_ID = ID;
}

string Person::getName()
{
	return m_name;
}

void Person::setName(string name)
{
	m_name = name;
}

string Person::getDOB()
{
	return m_DOB;
}

void Person::setDOB(string DOB)
{
	m_DOB = DOB;
}

string Person::getGender()
{
	return m_gender;
}

void Person::setGender(string gender)
{
	m_gender = gender;
}

string Person::getAddress()
{
	return m_address;
}

void Person::setAddress(string address)
{
	m_address = address;
}

void Person::read()         // virtual
{
	
}

void Person::write()         //virtual
{

}
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
#include "Course.hpp"

using namespace std;

Course::Course()               //assign empty values
{
	m_courseID = "";
	m_courseName = "";
	m_credit = 0;
	m_grade = "";
	m_semester = "";
	m_year = "";
}

string Course::getCourseID()
{
	return m_courseID;
}

void Course::setCourseID(string ID)
{
	m_courseID = ID;
}

string Course::getCourseName()
{
	return m_courseName;
}

void Course::setCourseName(string name)
{
	m_courseName = name;
}

int Course::getCredit()
{
	return m_credit;
}

void Course::setCredit(int credit)
{
	m_credit = credit;
}

string Course::getGrade()
{
	return m_grade;
}

void Course::setGrade(string grade)
{
	m_grade = grade;
}

string Course::getSemester()
{
	return m_semester;
}

void Course::setSemester(string semester)
{
	m_semester = semester;
}

string Course::getYear()
{
	return m_year;
}

void Course::setYear(string year)
{
	m_year = year;
}

void Course::read()                         // get information and set it
{
	string ID;
	string courseName;
	int credit;
	string grade;
	string semester;
	string year;

	cout << "What is the Course ID: ";
	getline(cin, ID);
	setCourseID(ID);
	cout << "What is the Course Name: ";
	getline(cin, courseName);
	setCourseName(courseName);
	cout << "How many credits does it have: ";
	cin >> credit;
	setCredit(credit);
	cout << "What is the final grade: ";
	cin.ignore();
	getline(cin, grade);
	setGrade(grade);
	cout << "What is the Semester: ";
	getline(cin, semester);
	setSemester(semester);
	cout << "What is the Year: ";
	getline(cin, year);
	setYear(year);
}

void Course::write()                   // write out information
{
	cout << "Course ID: " << m_courseID << endl;
	cout << "Course Name: " << m_courseName << endl;
	cout << "Time Taken: " << m_semester << " " << m_year << endl;
	cout << "Number of Credits: " << m_credit << endl;
	cout << "Final Grade: " << m_grade << endl;
}
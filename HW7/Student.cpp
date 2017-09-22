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
#include "Student.hpp"

using namespace std;

Student::Student() : Person()
{
	m_major = "";
}

string Student::getMajor()
{
	return m_major;
}

void Student::setMajor(string major)
{
	m_major = major;
}

double Student::calculateGPA()               // calculate gpa - average total gpa and divide by number of gpas
{
	string grade;
	double totalGPA = 0;
	double size = m_listOfCourses.size();

	for (int i = 0; i < m_listOfCourses.size(); i++)
	{
		grade = m_listOfCourses[i]->getGrade();                // get the grade
		grade[0] = toupper(grade[0]);                  // change first value of "grade" to upper case
		if (grade == "A" || grade == "A+")
		{
			totalGPA += 4.0;
		}
		else if (grade == "A-")
		{
			totalGPA += 3.67;
		}
		else if (grade == "B+")
		{
			totalGPA += 3.33;
		}
		else if (grade == "B")
		{
			totalGPA += 3.0;
		}
		else if (grade == "B-")
		{
			totalGPA += 2.67;
		}
		else if (grade == "C+")
		{
			totalGPA += 2.33;
		}
		else if (grade == "C")
		{
			totalGPA += 2.0;
		}
		else if (grade == "C-")
		{
			totalGPA += 1.67;
		}
		else if (grade == "D+")
		{
			totalGPA += 1.33;
		}
		else if (grade == "D")
		{
			totalGPA += 1.0;
		}
		else if (grade == "D-" || grade == "F")
		{
			totalGPA += 0.0;
		}
		else
		{
			size--;
		}
	}
	m_gpa = totalGPA / size;
	return m_gpa;
}

void Student::printTranscript()                         // print info
{
	int totalCredits = 0;
	for (int i = 0; i < m_listOfCourses.size(); i++)
	{
		totalCredits += m_listOfCourses[i]->getCredit();
	}

	cout << "***********STUDENT TRANSCRIPT***********\n\n";
	cout << "Student ID: " << getID() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Date of Birth: " << getDOB() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Major: " << m_major << endl << endl;

	cout << "List of Courses:\n\n";

	for (int i = 0; i < m_listOfCourses.size(); i++)
	{
		m_listOfCourses[i]->write();
		cout << endl;
	}

	double gpa = calculateGPA();            // call calculate gpa function
	cout << "Cummulative hours: " << totalCredits << endl;
	cout << "Cummulative GPA: " << fixed << setprecision(2) << gpa << endl;
}

void Student::addCourse(Course *course)
{
	m_listOfCourses.push_back(course);
}

void Student::read()
{
	string id;
	string name;
	string DOB;
	string gender;
	string address;
	string major;

	cout << "What is the Student's ID: ";
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
	cout << "What is the Major: ";
	getline(cin, major);
	setMajor(major);
}

void Student::write()
{
	printTranscript();            // call transcript
}
//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include "Person.hpp"
#include "Course.hpp"

using namespace std;

class Student : public Person            // derived class
{
	public:
		Student();
		string getMajor();
		void setMajor(string major);
		void read();
		void write();
		double calculateGPA();
		void printTranscript();
		void addCourse(Course *course);

	private:
		string m_major;
		vector<Course*> m_listOfCourses;           // vector of courses
		double m_gpa;
};

#endif
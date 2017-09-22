//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef COURSE_HPP_INCLUDED
#define COURSE_HPP_INCLUDED

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

class Course
{
	public:
		Course();
		string getCourseID();
		void setCourseID(string ID);
		string getCourseName();
		void setCourseName(string name);
		int getCredit();
		void setCredit(int credit);
		string getGrade();
		void setGrade(string grade);
		string getSemester();
		void setSemester(string semester);
		string getYear();
		void setYear(string year);
		void read();
		void write();

	private:
		string m_courseID;
		string m_courseName;
		int m_credit;
		string m_grade;
		string m_semester;
		string m_year;

};

#endif
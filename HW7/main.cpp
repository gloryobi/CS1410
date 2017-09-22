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
#include <vector>
#include <Windows.h>
#include "Person.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include "Student.hpp"

using namespace std;

Person* findPerson(string ID, vector<Person*> persons)
{
	for (int i = 0; i < persons.size(); i++)
	{
		if (persons[i]->getID() == ID)
		{
			return persons[i];
		}
	}
	return NULL;             // if no one is found
}

void newPerson(string type, vector<Person*> &persons)            // create new person
{
	if (type == "p")
	{
		Person* prof;
		prof = new Professor;
		prof->read();
		persons.push_back(prof);                  //add to vector
	}
	else if (type == "s")
	{
		Person* stu;
		stu = new Student;
		stu->read();
		persons.push_back(stu);                //add to vector
	}
}

int main()
{
	vector <Person*> listOfPersons;
	char ans;

	cout << "Please choose one of the following options:\n\n";             //menu
	cout << "A - Add a professor\n";
	cout << "B - Add a student\n";
	cout << "C - Add a course for a student\n";
	cout << "D - Print the transcript of a student\n";
	cout << "E - Print information of a professor\n";
	cout << "F - Quit\n\n";
	cout << "Choise: ";
	cin >> ans;
	ans = toupper(ans);

	while (true)                                 // implement choices
	{
		cout << endl;
		if (ans == 'A')                   // new professor
		{
			newPerson("p", listOfPersons);
			cout << endl;
		}
		else if (ans == 'B')                //new student
		{
			newPerson("s", listOfPersons);
			cout << endl;
		}
		else if (ans == 'C')          // add course
		{
			string id;
			Person* person;
			Student* stu;
			Course* course;

			cout << "What is the Student's ID: ";
			cin.ignore();
			getline(cin, id);
			person = findPerson(id, listOfPersons);            // find person
			while (true)                     //verify
			{
				if (person == NULL)
				{
					cout << "\nError - That Student's ID was not found please enter another ID: ";
					getline(cin, id);
					person = findPerson(id, listOfPersons);
				}
				else
				{
					break;
				}
			}
			stu = static_cast <Student*> (person);         // cast
			course = new Course; 
			course->read();
			stu->addCourse(course);              // call addCourse function
			cout << endl;
		}
		else if (ans == 'D')                 //print transcript
		{
			string id;
			Person* person;
			Student* stu;

			cout << "What is the Student's ID: ";
			cin.ignore();
			getline(cin, id);
			person = findPerson(id, listOfPersons);                 // find person
			while (true)              //verify
			{
				if (person == NULL)
				{
					cout << "\nError - That Student's ID was not found please enter another ID: ";
					getline(cin, id);
					person = findPerson(id, listOfPersons);
				}
				else
				{
					break;
				}
			}
			stu = static_cast <Student*> (person);       //cast
			cout << endl;
			stu->write();              //print
			cout << endl;
		}
		else if (ans == 'E')                    //print professor's information
		{
			string id;
			Person* person;
			Professor* prof;

			cout << "What is the Professor's ID: ";
			cin.ignore();
			getline(cin, id);
			person = findPerson(id, listOfPersons);            //find
			while (true)                //verify
			{
				if (person == NULL)
				{
					cout << "\nError - That Professor's ID was not found please enter another ID: ";
					getline(cin, id);
					person = findPerson(id, listOfPersons);
				}
				else
				{
					break;
				}
			}
			prof = static_cast <Professor*> (person);
			cout << endl;
			prof->write();          //print
			cout << endl;
		}
		else if (ans == 'F')           //quit
		{
			break;
		}
		else                        // verify choice
		{
			cout << "Try again. Input a letter between (A-F): ";
			cin >> ans;
			ans = toupper(ans);
			continue;
		}

		cout << "Next Choise: ";
		cin >> ans;
		ans = toupper(ans);
	}
	return 0;
}
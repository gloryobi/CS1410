//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "calculator.hpp"

using namespace std;

int main()
{
	char ans;                             
	double value = 0;                     
	Calculator cal;                       // object "cal" of the Calculator class

	cout << "Hello, Thank You for using our calculator. Please choose an option from the menu\n"          // Greeting the user
	     << "*** Calculator ***\n"                                                                        // menu
		 << "A: Add a value\n"
		 << "S: Subtract a value\n"
		 << "M: Multiply by a value\n"
		 << "D: Divide by a value\n"
		 << "T: Get the current total\n"
		 << "Q: Quit\n\n"
		 << "Current Total: " << cal.m_getTotal() << endl << endl;

	while (true)                           // infinite while loop
	{
		cout << "Selection: ";

		cin >> ans;                        // user interface (user enters a character to signify which option he/she chooses

		if (ans == 'A' || ans == 'a')      // input verification
		{
			cout << "\n************************* Add Selected ************************\n";
			cout << "\nPlease enter a value to add to the total: ";
			cin >> value;
			cout << endl << cal.m_getTotal() << " + " << value << " = ";
			cal.m_add(value);                               // calculate new total
			cout << cal.m_getTotal() << endl;               // output new total
			cout << "\n***************************************************************\n";
		}
		else if (ans == 'S' || ans == 's')
		{
			cout << "\n********************** Subtract Selected **********************\n";
			cout << "\nPlease enter a value to subtract from the total: ";
			cin >> value;
			cout << endl << cal.m_getTotal() << " - " << value << " = ";
			cal.m_subtract(value);                         // calculate new total
			cout << cal.m_getTotal() << endl;              // output new total
			cout << "\n***************************************************************\n";
		}
		else if (ans == 'M' || ans == 'm')
		{
			cout << "\n********************** Multiply Selected **********************\n";
			cout << "\nPlease enter a value to multiply the total by: ";
			cin >> value;
			cout << endl << cal.m_getTotal() << " * " << value << " = ";
			cal.m_multiply(value);                        // calculate new total
			cout << cal.m_getTotal() << endl;             // output new total
			cout << "\n***************************************************************\n";
		}
		else if (ans == 'D' || ans == 'd')
		{
			cout << "\n*********************** Divide Selected ***********************\n";
			cout << "\nPlease enter a value to divide the total by: ";
			cin >> value;
			cout << endl << cal.m_getTotal() << " / " << value << " = ";
			cal.m_divide(value);                         // calculate new total
			cout << cal.m_getTotal() << endl;            // output new total
			cout << "\n***************************************************************\n";
		}
		else if (ans == 'T' || ans == 't')
		{
			cout << "\n*********************** Total Selected ************************\n";
			cout << "\nThe current total is: " << cal.m_getTotal() << endl;          // output total
			cout << "\n***************************************************************\n";
		}
		else if (ans == 'Q' || ans == 'q')
		{
			cout << endl;
			break;                        // break out of the while loop
		}

		cout << "\nPlease choose another option: "                  // menu
		     << "\n\n*** Calculator ***\n"
			 << "A: Add a value\n"
			 << "S: Subtract a value\n"
			 << "M: Multiply by a value\n"
			 << "D: Divide by a value\n"
			 << "T: Get the current total\n"
			 << "Q: Quit\n\n"
			 << "Current Total: " << cal.m_getTotal() << endl << endl;
	}
	return 0;
}
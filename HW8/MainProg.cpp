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
#include "TUStack.h"

using namespace std;

template < class T >
TUStack<T>::TUStack(int nSize)
{
	if (nSize >= 0)                         // validate proper size
	{
		size = nSize;
		aStackArray = new T[size];
		count = 0;
	}
	else
	{
		throw wrongSizeExcep <T> (nSize);            // throw exception
	}
}

template < class T >
void TUStack<T>::Push(T item)
{
	for (int i = 0; i < count; i++)
	{
		if (aStackArray[i] == item)                        // check for duplicate
		{
			throw pushDupExcep <T> (item, size, count);           // throw exception
		}
	}
	if (count < size)                              // check if stack is filled
	{
		aStackArray[count] = item;
		cout << "Push (" << item << ") in position " << count << endl;
		count++;
	}
	else
	{
		throw pushFullExcep <T> (item, size);               // throw exception
	}
}

template < class T >
T TUStack<T>::Pop()
{
	if (count > 0)
	{
		count--;                    // change the current top item
		cout << "Pop (" << aStackArray[count] << ") from position " << count << endl;
		return aStackArray[count];           // return previous top item
	}
	else
	{
		throw emptyPopExcep <T> (size, count);                  // throw exception
	}
}

template < class T >
int TUStack<T>::Size()
{
	cout << "The size of the stack is " << size << endl;
	return size;                 // return size of stack
}

template < class T >
int TUStack<T>::Position()
{
	cout << "The the next available position in the stack is " << count << endl;
	return count;                   // return nex available index position
}

template < class T >
T TUStack<T>::operator[](int position)
{
	if (position < size && position >= 0)
	{
		if (position >= count)                        // if index has not been entered
		{
			cout << "There is nothing in position " << position << " yet\n";
		}
		else
		{
			cout << "The item in position " << position << " is (" << aStackArray[position] << ")" << endl;
			return aStackArray[position];                       // reuturn specified index
		}
	}
	else
	{
		throw wrongIndexExcep <T> (position, size, count);              // throw exception
	}
}

int main()
{
	try                        // error handling
	{
		cout << "Please Select Which Test Case You Will like to see:\n\n";              // print menu of test cases
		cout << "Test Case A:  Integers (Illegal Maximum Size Error Handling)\n";
		cout << "Test Case B:  Integers (Duplicate Item Error Handling)\n";
		cout << "Test Case C:  Integers (Full Stack Error Handling)\n";
		cout << "Test Case D:  Integers (Copy Illegal Index Error Handling)\n";
		cout << "Test Case E:  Integers (Pop Empty Stack Error Handling)\n";
		cout << "Test Case F:  Strings (Illegal Maximum Size Error Handling)\n";
		cout << "Test Case G:  Strings (Duplicate Item Error Handling)\n";
		cout << "Test Case H:  Strings (Full Stack Error Handling)\n";
		cout << "Test Case I:  Strings (Copy Illegal Index Error Handling)\n";
		cout << "Test Case J: Strings (Pop Empty Stack Error Handling)\n\n";

		char ans;
		cout << "User Input (A-J): ";                         // get user input
		cin >> ans;
		cout << endl;
		ans = toupper(ans);

		TUStack <int> s(6);         // create integer stack of size 6
		TUStack <string> s1(6);         // create string stack of size 6
		while (true)
		{
			if (ans == 'A')
			{
				cout << "Test Case A:  Integers (Illegal Maximum Size Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a integer stack of size -1\n";
				TUStack <int> e(-1);                            // size is negative
				break;
			}
			else if (ans == 'B')
			{
				cout << "Test Case B: Integers (Duplicate Item Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a integer stack of size 6\n\n";
				s.Size();              // display size
				s.Push(10);            // fill zeroth position
				s.Push(3);             // fill first position
				s.Push(5);             // fill second position
				s.Push(8);			   // fill third postion
				s.Pop();               // return the top item
				s.Position();          // return available position
				s.operator[](2);       // return copy of item in position 2
				s.Push(15);            // fill third position
				cout << "Push (3) in position 4\n";
				s.Push(3);             // duplicate error handling
				break;
			}
			else if (ans == 'C')
			{
				cout << "Test Case C:  Integers (Full Stack Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a integer stack of size 6\n\n";
				s.Size();              // display size
				s.Push(10);            // fill zeroth position
				s.Push(3);             // fill first position
				s.Push(5);             // fill second position
				s.Push(8);			   // fill third postion
				s.Pop();               // return the top item
				s.Position();          // return available position
				s.operator[](2);       // return copy of item in position 2
				s.Push(15);            // fill third position
				s.Push(6);             // fill fourth position
				s.Push(90);            // fill fifth position
				cout << "Push (23)\n";   // full stack error handling
				s.Push(23);
				break;
			}
			else if (ans == 'D')
			{
				cout << "Test Case D:  Integers (Copy Illegal Index Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a integer stack of size 6\n\n";
				s.Size();              // display size
				s.Push(10);            // fill zeroth position
				s.Push(3);             // fill first position
				s.Push(5);             // fill second position
				s.Push(8);			   // fill third postion
				s.Pop();               // return the top item
				s.Position();          // return available position
				cout << "Return a copy of the item in position 7\n";
				s.operator[](7);       // return from illegal index error handling
				break;
			}
			else if (ans == 'E')
			{
				cout << "Test Case E:  Integers (Pop Empty Stack Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a integer stack of size 6\n\n";
				s.Size();              // display size
				s.Position();          // return available position
				cout << "Pop the stack\n";   //empty stack error handling 
				s.Pop();
				break;
			}
			else if (ans == 'F')
			{
				cout << "Test Case F:  Strings (Illegal Maximum Size Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a string stack of size -1\n";
				TUStack <string> e(-1);                         // size is negative
				break;
			}
			else if (ans == 'G')
			{
				cout << "Test Case G:  Strings (Duplicate Item Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a string stack of size 6\n\n";
				s1.Size();              // display size
				s1.Push("Hello ");            // fill zeroth position
				s1.Push("My ");             // fill first position
				s1.Push("Name ");             // fill second position
				s1.Push("Food");			   // fill third postion
				s1.Pop();               // return the top item
				s1.Position();          // return available position
				s1.operator[](2);       // return copy of item in position 2
				s1.Push("Is ");            // fill third position
				cout << "Push (Is ) in position 4\n";
				s1.Push("Is ");             // duplicate error handling
				break;
			}
			else if (ans == 'H')
			{
				cout << "Test Case H:  Strings (Full Stack Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a string stack of size 6\n\n";
				s1.Size();              // display size
				s1.Push("Hello ");            // fill zeroth position
				s1.Push("My ");             // fill first position
				s1.Push("Name ");             // fill second position
				s1.Push("Food ");			   // fill third postion
				s1.Pop();               // return the top item
				s1.Position();          // return available position
				s1.operator[](2);       // return copy of item in position 2
				s1.Push("Is ");            // fill third position
				s1.Push("Glory ");             // fill fourth position
				s1.Push("Obielodan");            // fill fifth position
				cout << "Push (.)\n";   // full stack error handling
				s1.Push(".");
				break;
			}
			else if (ans == 'I')
			{
				cout << "Test Case I:  Strings (Copy Illegal Index Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a string stack of size 6\n\n";
				s1.Size();              // display size
				s1.Push("Hello ");            // fill zeroth position
				s1.Push("My ");             // fill first position
				s1.Push("Name ");             // fill second position
				s1.Push("Food ");			   // fill third postion
				s1.Pop();               // return the top item
				s1.Position();          // return available position
				cout << "Return a copy of the item in position 7\n";
				s1.operator[](7);       // return from illegal index error handling
				break;
			}
			else if (ans == 'J')
			{
				cout << "Test Case J: Strings (Pop Empty Stack Error Handling)\n";
				cout << "****************************************************************\n\n";
				cout << "Create a string stack of size 6\n\n";
				s1.Size();              // display size
				s1.Position();          // return available position
				cout << "Pop the stack\n";   //empty stack error handling 
				s1.Pop();
				break;
			}
			else
			{
				cout << "Invalid Input: Enter an input (A-J): ";               // user input validation
				cin >> ans;
				ans = toupper(ans);
				continue;
			}
		}
	}
	catch (wrongIndexExcep <int> e)                 // catch exceptions
	{
		e.printError();
	}
	catch (wrongSizeExcep <int> e)
	{
		e.printError();
	}
	catch (emptyPopExcep <int> e)
	{
		e.printError();
	}
	catch (pushFullExcep <int> e)
	{
		e.printError();
	}
	catch (pushDupExcep <int> e)
	{
		e.printError();
	}
	catch (wrongIndexExcep <string> e)
	{
		e.printError();
	}
	catch (wrongSizeExcep <string> e)
	{
		e.printError();
	}
	catch (emptyPopExcep <string> e)
	{
		e.printError();
	}
	catch (pushFullExcep <string> e)
	{
		e.printError();
	}
	catch (pushDupExcep <string> e)
	{
		e.printError();
	}

	return 0;
}
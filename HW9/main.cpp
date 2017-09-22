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
#include "OrderedQueue.h"
#include "Queue.h"
#include "Stack.h"
#include "LinkedListNode.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	char ans;                         // menu
	cout << "Choose a Test Case:\n";
	cout << "Test Case A: Queue Class\n";
	cout << "Test Case B: Ordered Queue Class\n";
	cout << "Test Case C: Stack Class\n";
	cout << "Input D to Quit\n\n";
	cout << "User Input (A-D): ";
	cin >> ans;
	cout << endl;
	ans = toupper(ans);

	while (true)
	{
		if (ans == 'A')                            // Test case A
		{
			cout << "TEST CASE A: QUEUE\n";
			cout << "****************************************************************\n\n";

			Queue <int> q;
			cout << "Push [1], [2], [6], [0]\n";
			q.push(new int(1));                       //Pos 0: = 1
			q.push(new int(2));                       //Pos 1: = 2
			q.push(new int(6));                       //Pos 2: = 6
			q.push(new int(0));                       //Pos 3: = 0
			cout << "QUEUE: ";
			q.display();
			cout << "Pop [1]\n";
			q.pop();                                  //Pos 0: = 2, Pos 1: = 6, Pos 2: = 0
			cout << "Push [-2]\n";
			q.push(new int(-2));                      //Pos 4: = -2
			cout << "The Queue Has a Size of " << q.getSize() << endl;
			cout << "Display Queue: ";
			q.display();
			cout << "Clear Queue\n";
			q.clear();
			cout << "The Queue Now Has a Size of " << q.getSize() << endl;

			cout << "\nTEST CASE ENDED\n";
			cout << "****************************************************************\n";
		}
		else if (ans == 'B')                        // Test Case B
		{
			cout << "TEST CASE B: ORDERED QUEUE\n";
			cout << "****************************************************************\n\n";

			OrderedQueue <int> q;
			cout << "Push [3], [4], [50], [8], [7]\n";
			q.push(new int(3));                      
			q.push(new int(4));                       
			q.push(new int(50));                       
			q.push(new int(8));                       
			q.push(new int(7));    
			cout << "QUEUE: ";
			q.display();
			cout << "Pop [3]\n";
			q.pop();         
			cout << "QUEUE: ";
			q.display();
			cout << "Push [6]\n";
			q.push(new int(6));                    
			cout << "The Queue Has a Size of " << q.getSize() << endl;
			cout << "Display Queue: ";
			q.display();
			cout << "Clear Queue\n";
			q.clear();
			cout << "The Queue Now Has a Size of " << q.getSize() << endl;

			cout << "\nTEST CASE ENDED\n";
			cout << "****************************************************************\n";
		}
		else if (ans == 'C')                      // Test Case C
		{
			cout << "TEST CASE C: STACK\n";
			cout << "****************************************************************\n\n";

			Stack <int> s;
			cout << "Push [3], [4], [50], [8], [7]\n";
			s.push(new int(3));
			s.push(new int(4));
			s.push(new int(50));
			s.push(new int(8));
			s.push(new int(7));
			cout << "STACK: ";
			s.display();
			cout << "Pop [7]\n";
			s.pop();
			cout << "The top stack value is now [" << *(s.top()) << "]\n";
			cout << "STACK: ";
			s.display();
			cout << "The Stack Has a Size of " << s.getSize() << endl;
			cout << "Clear Stack\n";
			s.clear();
			cout << "The Stack Now Has a Size of " << s.getSize() << endl;

			cout << "\nTEST CASE ENDED\n";
			cout << "****************************************************************\n";
		}
		else if (ans == 'D')               // Quit
		{
			cout << "Quit Test Cases\n";
			break;
		}
		else
		{
			cout << "Invalid Input: Enter an input (A-D): ";               // user input validation
			cin >> ans;
			ans = toupper(ans);
			continue;
		}
		cout << "\nNext Input: ";
		cin >> ans;
		cout << endl;
		ans = toupper(ans);
	}

	return 0;
}
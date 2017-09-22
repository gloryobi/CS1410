//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <Windows.h>
#include "Account.hpp"
#include "Checking.hpp"
#include "Savings.hpp"
#include "Bank.hpp"

using namespace std;

int Account::numAccounts = 0;
int Savings::SavingAcctNum = 0;
int Checking::CheckingAcctNum = 0;

int main()
{
	char bankMode;
	Bank b;
	cout << "How do you wish to use the bank. File loading or User interface (F/U): ";
	cin >> bankMode;
	while (true)
	{
		if (bankMode == 'F' || bankMode == 'f')                // file inputs
		{
			cout << "\n********************BANK OUTPUTS********************\n\n";
			b.handleInputs();
			break;
		}
		else if (bankMode == 'U' || bankMode == 'u')        // user inputs
		{
			int numOfAccts;
			cout << "\nEnter the total number of Accounts: ";
			cin >> numOfAccts;
			Bank b1(numOfAccts);
			cout << "\n********************BANK OUTPUTS********************\n\n";
			cout << "MENU\n";
			cout << "s - New Savings Account\n";
			cout << "c - New Checking Account\n";
			cout << "t - transaction\n";
			cout << "u - update account\n";
			cout << "r - transfering account\n";
			cout << "d - list all accounts\n\n";
			b.handleUserInputs();
			break;
		}
		else                     // validation
		{
			cout << "Please input either F or U: ";
			cin >> bankMode;
		}
	}

	return 0;
}
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
#include "Bank.hpp"

using namespace std;

Bank::Bank()               // default constructor
{
	ifstream fin;

	fin.open("Bank.txt");

	while (!fin.eof())
	{
		string store;
		getline(fin, store);
		if (store[0] == 's' || store[0] == 'c' || store[0] == 'r')
		{
			numOfAccts++;
		}
	}

	fin.close();
	paListOfAccts = new Account*[numOfAccts];              //allocation 
}

Bank::Bank(int numberOfAccts)                  // user interface constructor
{
	numOfAccts = numberOfAccts;
	paListOfAccts = new Account*[numOfAccts];             //allocation
}

Bank::~Bank()              // destructor
{
	delete[] paListOfAccts;            // deallocation
	paListOfAccts = NULL;
}

int Bank::findAcct(int acctNum, int size)          // find account in array
{
	for (int i = 0; i < size; i++)
	{
		if (paListOfAccts[i]->getAcctNum() == acctNum)
		{
			return i;
		}
	}
	return -1;
}

void Bank::newSavings(int acctNum, char* pAcctName, double iBalance, double interest)       // new savings
{
	paListOfAccts[index] = new Savings(acctNum, pAcctName, iBalance, interest);
}

void Bank::newChecking(int acctNum, char* pAcctName, double iBalance, double fee)        // new checking
{
	paListOfAccts[index] = new Checking(acctNum, pAcctName, iBalance, fee);
}

void Bank::handleInputs()                             // file inputs
{
	char command;
	ifstream fin;
	
	fin.open("Bank.txt");

	while (fin >> command)
	{
		if (command == 's')              // new savings
		{
			int acctNum;
			string name;
			
			double balance, interest;
			fin >> acctNum;
			fin >> name;
			fin >> balance;
			fin >> interest;
			char *pAcctName = new char[name.length()];
			strcpy_s(pAcctName ,name.length()+1, name.c_str());
			index++;
			newSavings(acctNum, pAcctName, balance, interest);
			cout << "new account...\n";
			cout << pAcctName << " (savings): balance is $" << fixed << setprecision(2) << balance << endl << endl;
		}
		else if (command == 'c')             //new checkings
		{
			int acctNum;
			string name;
			char *pAcctName;
			double balance, fee;
			fin >> acctNum;
			fin >> name;
			fin >> balance >> fee;
			pAcctName = new char[name.length()];
			strcpy_s(pAcctName, name.length() + 1, name.c_str());
			index++;
			newChecking(acctNum, pAcctName, balance, fee);
			cout << "new account...\n";
			cout << pAcctName << " (checking): balance is $" << fixed << setprecision(2) << balance << endl << endl;
		}
		else if (command == 't')                        //transactions
		{
			cout << "transaction...\n";
			int acctNum;
			double value;
			fin >> acctNum >> value;
			int index1 = findAcct(acctNum, numOfAccts);
			if (index1 < 0)                                //validation
			{
				cout << "Error: Can't find Account\n\n";
			}
			else
			{
				if ((paListOfAccts[index1]->getBalance() + value) < 0)
				{
					cout << paListOfAccts[index1]->getName() << " (";
					if ((paListOfAccts[index1]->getType()) == 's')
					{
						cout << "savings): $";
					}
					else if ((paListOfAccts[index1]->getType()) == 'c')
					{
						cout << "checking): $";
					}
					cout << fixed << setprecision(2) << value << " rejected (insufficient funds)\n";
					applyTransaction(acctNum, -25);
				}
				else
				{
					applyTransaction(acctNum, value);
				}
			}
		}
		else if (command == 'u')                   //update
		{
			cout << "update...\n";
			int acctNum;
			fin >> acctNum;
			applyUpdate(acctNum);
		}
		else if (command == 'r')                            //transferring
		{
			cout << "transferring...\n";
			int acctNum, acctNum1;
			fin >> acctNum >> acctNum1;
			transfer(acctNum, acctNum1);
		}
		else if (command == 'd')                          //list accounts
		{
			cout << "listing all accounts...\n";
			listAccounts();
		}
	}
}

void Bank::handleUserInputs()                         // user interface
{
	char command;
	while (true)
	{
		cout << "Enter a command: ";
		cin >> command;
		if (command == 's' || command == 'S')
		{
			int acctNum;
			string name;

			double balance, interest;
			cout << "Enter the Account Number: ";
			cin >> acctNum;
			while (true)
			{
				if (acctNum < 0)
				{
					cout << "Enter a positive number: ";
					cin >> acctNum;
				}
				else
				{
					break;
				}
			}
			cout << "Enter the Account Name: ";
			cin >> name;
			cout << "Enter the initial Balance: ";
			cin >> balance;
			cout << "Enter the interest: ";
			cin >> interest;
			while (true)
			{
				if (interest < 0)
				{
					cout << "Enter a positive ammount: ";
					cin >> interest;
				}
				else
				{
					break;
				}
			}
			char *pAcctName = new char[name.length()];
			strcpy_s(pAcctName, name.length() + 1, name.c_str());
			index++;
			newSavings(acctNum, pAcctName, balance, interest);
			cout << "\nnew account...\n";
			cout << pAcctName << " (savings): balance is $" << fixed << setprecision(2) << balance << endl << endl;
		}
		else if (command == 'c' || command == 'C')
		{
			int acctNum;
			string name;
			char *pAcctName;
			double balance, fee;
			cout << "Enter the Account Number: ";
			cin >> acctNum;
			while (true)
			{
				if (acctNum < 0)
				{
					cout << "Enter a positive number: ";
					cin >> acctNum;
				}
				else
				{
					break;
				}
			}
			cout << "Enter the Account Name: ";
			cin >> name;
			cout << "Enter the initial Balance: ";
			cin >> balance;
			cout << "Enter the fee: ";
			cin >> fee;
			while (true)
			{
				if (fee < 0)
				{
					cout << "Enter a positive number: ";
					cin >> fee;
				}
				else
				{
					break;
				}
			}
			pAcctName = new char[name.length()];
			strcpy_s(pAcctName, name.length() + 1, name.c_str());
			index++;
			newChecking(acctNum, pAcctName, balance, fee);
			cout << "\nnew account...\n";
			cout << pAcctName << " (checking): balance is $" << fixed << setprecision(2) << balance << endl << endl;
		}
		else if (command == 't' || command == 'T')
		{
			cout << "\ntransaction...\n";
			int acctNum;
			double value;
			cout << "Enter an Account Number: ";
			cin >> acctNum;
			while (true)
			{
				if (acctNum < 0)
				{
					cout << "Enter a positive number: ";
					cin >> acctNum;
				}
				else
				{
					break;
				}
			}
			cout << "Enter the ammount of the transaction: ";
			cin >> value;
			int index1 = findAcct(acctNum, numOfAccts);
			if (index1 < 0)
			{
				cout << "Error: Can't find Account\n\n";
			}
			else
			{
				if ((paListOfAccts[index1]->getBalance() + value) < 0)
				{
					cout << endl;
					cout << paListOfAccts[index1]->getName() << " (";
					if ((paListOfAccts[index1]->getType()) == 's')
					{
						cout << "savings): $";
					}
					else if ((paListOfAccts[index1]->getType()) == 'c')
					{
						cout << "checking): $";
					}
					cout << fixed << setprecision(2) << value << " rejected (insufficient funds)\n";
					applyTransaction(acctNum, -25);
				}
				else
				{
					cout << endl;
					applyTransaction(acctNum, value);
				}
			}
		}
		else if (command == 'u')
		{
			cout << "\nupdate...\n";
			int acctNum;
			cout << "Enter an Accout Number: ";
			cin >> acctNum;
			while (true)
			{
				if (acctNum < 0)
				{
					cout << "Enter a positive number: ";
					cin >> acctNum;
				}
				else
				{
					break;
				}
			}
			cout << endl;
			applyUpdate(acctNum);
		}
		else if (command == 'r' || command == 'R')
		{
			cout << "\ntransferring...\n";
			int acctNum, acctNum1;
			cout << "Enter an Account Number: ";
			cin >> acctNum;
			while (true)
			{
				if (acctNum < 0)
				{
					cout << "Enter a positive number: ";
					cin >> acctNum;
				}
				else
				{
					break;
				}
			}
			cout << "Enter another Account Number: ";
			cin >> acctNum1;
			while (true)
			{
				if (acctNum1 < 0)
				{
					cout << "Enter a positive number: ";
					cin >> acctNum1;
				}
				else
				{
					break;
				}
			}
			cout << endl;
			transfer(acctNum, acctNum1);
		}
		else if (command == 'd' || command == 'D')
		{
			cout << "\nlisting all accounts...\n";
			listAccounts();
		}
	}
}

void Bank::applyTransaction(int acctNum, double value)                   // conducting transaction
{
	int index1 = findAcct(acctNum, numOfAccts);
	paListOfAccts[index1]->handleTransaction(acctNum, value);
	cout << paListOfAccts[index1]->getName() << " (";
	if ((paListOfAccts[index1]->getType()) == 's')
	{
		cout << "savings): $";
	}
	else if ((paListOfAccts[index1]->getType()) == 'c')
	{
		cout << "checking): $";
	}
	cout << fixed << setprecision(2) << value << " applied to account\n";
	cout << paListOfAccts[index1]->getName() << " (";
	if ((paListOfAccts[index1]->getType()) == 's')
	{
		cout << "savings): ";
	}
	else if ((paListOfAccts[index1]->getType()) == 'c')
	{
		cout << "checking): ";
	}
	cout << "balance is $" << fixed << setprecision(2) << paListOfAccts[index1]->getBalance() << endl << endl;
}

void Bank::applyUpdate(int acctNum)             // conducting update
{
	int index1 = findAcct(acctNum, numOfAccts);
	cout << paListOfAccts[index1]->getName() << " (";
	if ((paListOfAccts[index1]->getType()) == 's')
	{
		cout << "savings): $";
	}
	else if ((paListOfAccts[index1]->getType()) == 'c')
	{
		cout << "checking): $";
	}
	cout << fixed << setprecision(2) << paListOfAccts[index1]->getUpdate() << " applied to account\n";
	paListOfAccts[index1]->handleUpdate(acctNum);
	cout << paListOfAccts[index1]->getName() << " (";
	if ((paListOfAccts[index1]->getType()) == 's')
	{
		cout << "savings): ";
	}
	else if ((paListOfAccts[index1]->getType()) == 'c')
	{
		cout << "checking): ";
	}
	cout << "balance is $" << fixed << setprecision(2) << paListOfAccts[index1]->getBalance() << endl << endl;
}

void Bank::transfer(int acctNum, int acctNum1)               // conducting transfer
{
	int index1 = findAcct(acctNum, numOfAccts);
	if ((paListOfAccts[index1]->getType()) == 's')
	{
		index++;
		newSavings(acctNum1, paListOfAccts[index1]->getName(), paListOfAccts[index1]->getBalance(), paListOfAccts[index1]->getUpdateValue());
		//create a set new balance function
		cout << paListOfAccts[index1]->getName() << " (savings): $" << fixed << setprecision(2) << paListOfAccts[index1]->getBalance() << " transferred to savings account " << acctNum1 << endl;
		int index2 = findAcct(acctNum1, numOfAccts);
		cout << paListOfAccts[index2]->getName() << " (savings): balance is $" << fixed << setprecision(2) << paListOfAccts[index2]->getBalance() << endl << endl;
	}
	else if ((paListOfAccts[index1]->getType()) == 'c')
	{
		index++;
		newChecking(acctNum1, paListOfAccts[index1]->getName(), paListOfAccts[index1]->getBalance(), paListOfAccts[index1]->getUpdateValue());
		//create a set new balance function
		cout << paListOfAccts[index1]->getName() << " (checking): $" << fixed << setprecision(2) << paListOfAccts[index1]->getBalance() << " transferred to checking account " << acctNum1 << endl;
		int index2 = findAcct(acctNum1, numOfAccts);
		cout << paListOfAccts[index2]->getName() << " (checking): balance is $" << fixed << setprecision(2) << paListOfAccts[index2]->getBalance() << endl << endl;
	}
}

void Bank::listAccounts()          // conducting list
{
	cout << "There are a total of " << Account::getNumberofAccounts() << " accounts\n";
	cout << "There are " << Savings::getNumberOfSavingsAccounts() << " savings accounts\n";
	cout << "There are " << Checking::getNumberOfCheckingAccounts() << " checking accounts\n\n";
}
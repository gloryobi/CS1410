#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

struct BNKHeader                                             //  header struct
{
	char signature[4]; // {'B','A','N','K'};
	int numberOfAccounts;
	char reserved[24];
};

struct BNKAccount                     // accounts struct
{
	int number;
	char name[20];
	double balance;
	char reserved[96];
};

struct BNKIndex                   // index struct
{
	int accountNumber;
	long filePosition;
};


int acctSearch(int acct, BNKIndex* pIndex, BNKHeader m_header)            // binary search function
{
	int x;
	int y;
	x = m_header.numberOfAccounts - 1;
	y = 0;
	while (true)
	{
		int mid = (x + y) / 2;
		if (pIndex[mid].accountNumber == acct)
		{
			//cout << acct << " = " << pIndex[mid].accountNumber << endl;
			return mid;
		}
		else if (x - y <= 0)
		{
			x = m_header.numberOfAccounts - 1;
			y = 0;
			cout << "\nThat Account is not Listed\n";
			cout << "Please enter another number: ";
			cin >> acct;
		}
		else if (pIndex[mid].accountNumber < acct)
		{
			y = mid + 1;
		}
		else if (pIndex[mid].accountNumber > acct)
		{
			x = mid - 1;
		}
	}
}

int main()
{
	fstream file;
	char ans;

	file.open("converted.BNK", ios::in | ios::out | ios::binary);          // open file as binary
	
	BNKHeader m_header;

	file.read((char*)&m_header, sizeof(BNKHeader));                 // read out header

	//confirm signature
	if (m_header.signature[0] != 'B' || m_header.signature[1] != 'A' || m_header.signature[2] != 'N' || m_header.signature[3] != 'K')
	{
		cout << "The signature is wrong\n";
	}

	BNKIndex*  pIndex;                                            // dynamically allocate array
	pIndex = new BNKIndex[m_header.numberOfAccounts];

	file.seekg(sizeof(BNKHeader) + m_header.numberOfAccounts * sizeof(BNKAccount), ios::beg);        // seekg
	file.read((char*)pIndex, m_header.numberOfAccounts * sizeof(BNKIndex));

	cout << "Welcome to the Online Banking System!!\n\n";                   // menu
	cout << "Choose an Option:\n";
	cout << "S - Display an Account\n";
	cout << "W - Withdraw from an Account\n";
	cout << "D - Deposit into an Account\n";
	cout << "Q - Quit\n\n";
	cout << "***************************************\n";
	cout << "Input: ";
	cin >> ans;

	while (true)
	{
		int acct;
		int mid;
		int pos;
		BNKAccount line;
		if (ans == 'S' || ans == 's')                            // display account
		{
			cout << "\nEnter the Account Number: ";
			cin >> acct;
			mid = acctSearch(acct, pIndex, m_header);
			pos = pIndex[mid].filePosition;
			file.seekp(pos, ios::beg);
			file.read((char*)&line, sizeof(BNKAccount));
			cout << "\nAccount #: " << line.number << endl;
			cout << "Name: " << line.name << endl;
			cout << "Balance: $" << line.balance << endl << endl;
		}
		else if (ans == 'W' || ans == 'w')                     // withdraw
		{
			double answer;
			cout << "\nEnter the Account Number: ";
			cin >> acct;
			mid = acctSearch(acct, pIndex, m_header);
			pos = pIndex[mid].filePosition;
			file.seekp(pos, ios::beg);
			file.read((char*)&line, sizeof(BNKAccount));
			cout << "\nThe Account Balance is $" << line.balance << endl;
			cout << "How much do you wish to Withdraw: $";
			cin >> answer;
			while (true)
			{
				if (answer < 0)
				{
					cout << "\nPlease enter a Positive Value: $";
					cin >> answer;
				}
				else
				{
					break;
				}
			}
			cout << endl;
			line.balance -= answer;
			file.seekp(pos, ios::beg);
			file.write((char*)&line, sizeof(BNKAccount));
		}
		else if (ans == 'D' || ans == 'd')                  // deposit
		{
			double ans1;
			cout << "\nEnter the Account Number: ";
			cin >> acct;
			mid = acctSearch(acct, pIndex, m_header);
			pos = pIndex[mid].filePosition;
			file.seekp(pos, ios::beg);
			file.read((char*)&line, sizeof(BNKAccount));
			cout << "\nThe Account Balance is $" << line.balance << endl;
			cout << "How much do you wish to Deposit: $";
			cin >> ans1;
			while (true)
			{
				if (ans1 < 0)
				{
					cout << "\nPlease enter a Positive Value: $";
					cin >> ans1;
				}
				else
				{
					break;
				}
			}
			cout << endl;
			line.balance += ans1;
			file.seekp(pos, ios::beg);
			file.write((char*)&line, sizeof(BNKAccount));
		}
		else if (ans == 'Q' || ans == 'q')                // quit
		{
			cout << "\nThanks for Using our Bank. See you next Time.\n\n";
			break;
		}
		else                                          // validate input
		{
			cout << "\nPlease enter a Valid input\n";
			cout << "Input: ";
			cin >> ans;
			continue;
		}
		cout << "***************************************\n";
		cout << "Input: ";
		cin >> ans;
	}

	delete[] pIndex;										//deallocate pointer array
	pIndex = NULL;

	file.clear();                              // clear file

	return 0;
}
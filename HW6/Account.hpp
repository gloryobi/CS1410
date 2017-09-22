//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

class Account
{
	public:
		Account(char type, int acctNum, char* pName, double balance);
		Account();
		static int getNumberofAccounts();
		bool getActiveState();
		bool operator==(Account);
		Account(const Account& other);
		int getAcctNum();
		double getBalance();
		char* getName();
		char getType();
		virtual double handleTransaction(int acctNum, double value);         // virtual functions
		virtual double handleUpdate(int acctNum);
		virtual double getUpdate();
		virtual double getUpdateValue();

	protected:
		char type;
		static int numAccounts;
		bool active;
		char* pName;
		double balance;
		int acctNum;
};

#endif

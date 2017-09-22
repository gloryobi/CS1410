//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef BANK_HPP_INCLUDED
#define BANK_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include "Account.hpp"
#include "Checking.hpp"
#include "Savings.hpp"

using namespace std;

class Bank
{
	public:
		Bank();
		Bank(int numberOfAccts);
		void newSavings(int acctNum, char* pAcctName, double iBalance, double interest);
		void newChecking(int acctNum, char* pAcctName, double iBalance, double fee);
		void handleInputs();
		void handleUserInputs();
		void applyTransaction(int acctNum, double value);
		void applyUpdate(int acctNum);
		void transfer(int acctNum, int acctNum1);
		void listAccounts();
		~Bank();
		
	private:
		Account **paListOfAccts;             // accouunts array
		int numOfAccts = 0;
		int index = -1;
		int findAcct(int acctNum, int size);
};


#endif
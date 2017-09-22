//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef SAVINGS_HPP_INCLUDED
#define SAVINGS_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include "Account.hpp"

using namespace std;

class Savings :public Account
{
public:
	Savings(int acctNum, char* pName, double balance, double interest);
	double handleTransaction(int accountNum, double value);
	double handleUpdate(int accountNum);
	static int getNumberOfSavingsAccounts();
	bool operator==(Savings);
	Savings(const Savings& other);
	friend ostream &operator<<(ostream &out, Savings s);
	double getUpdate();
	double getUpdateValue();
		
private:
	double interest;
	double interestCount;
	static int SavingAcctNum;
};


#endif
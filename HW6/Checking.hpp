//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef CHECKING_HPP_INCLUDED
#define CHECKING_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include "Account.hpp"

using namespace std;

class Checking :public Account
{
public:
	Checking(int acctNum, char* pName, double balance, double fee);
	double handleTransaction(int accountNum, double value);
	double handleUpdate(int accountNum);
	static int getNumberOfCheckingAccounts();
	bool operator==(Checking);
	Checking(const Checking& other);
	friend ostream &operator<<(ostream &out, Checking c);
	double getUpdate();
	double getUpdateValue();

private:
	double fee;
	double feeCount = 0;
	static int CheckingAcctNum;
};

#endif
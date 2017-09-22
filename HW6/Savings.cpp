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
#include "Savings.hpp"


using namespace std;

Savings::Savings(int acctNum, char* pName, double balance, double interest) :Account('s', acctNum, pName, balance)
{
	this->interest = interest;
	numAccounts++;
	SavingAcctNum++;
}

double Savings::handleTransaction(int accountNum, double value)
{
	balance += value;
	return balance;
}

double Savings::handleUpdate(int accountNum)
{
	balance =  interestCount + balance;
	return balance;
}

int Savings::getNumberOfSavingsAccounts()
{
	return SavingAcctNum;
}

bool Savings::operator==(Savings right)
{
	if (!Account::operator==(right))
	{
		return false;
	}
	if (interest == right.interest)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Savings::Savings(const Savings& other)
{
	Account::Account(other);
	interest = other.interest;
}

ostream &operator<<(ostream &out, Savings s)
{
	out << s.pName << " (savings): balance is $" << s.balance << endl;
	return out;
}

double Savings::getUpdate()
{
	interestCount = balance * interest;
	return interestCount;
}

double Savings::getUpdateValue()
{
	return interest;
}
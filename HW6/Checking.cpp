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
#include "Checking.hpp"

using namespace std;

Checking::Checking(int acctNum, char* pName, double balance, double fee) : Account('c', acctNum, pName, balance)
{
	this->fee = fee;
	numAccounts++;
	CheckingAcctNum++;
}

double Checking::handleTransaction(int accountNum, double value)
{
	balance += value;
	if (value < 0)
	{
		feeCount -= fee;
	}
	return balance;
}

double Checking::handleUpdate(int accountNum)
{
	balance += feeCount;
	feeCount = 0;
	return balance;
}

int Checking::getNumberOfCheckingAccounts()
{
	return CheckingAcctNum;
}

bool Checking::operator==(Checking right)
{
	if (!Account::operator==(right))
	{
		return false;
	}
	if (fee == right.fee && feeCount == right.feeCount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Checking::Checking(const Checking& other)
{
	Account::Account(other);
	fee = other.fee;
	//feeCount = other.feeCount;
}

ostream &operator<<(ostream &out, Checking c)
{
	out << c.pName << " (checking): balance is $" << c.balance << endl;
	return out;
}

double Checking::getUpdate()
{
	return feeCount;
}

double Checking::getUpdateValue()
{
	return fee;
}
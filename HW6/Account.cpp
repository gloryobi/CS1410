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

using namespace std;

Account::Account(char type, int acctNum, char* pName, double balance)
{
	this->type = type;
	this->acctNum = acctNum;
	this->pName = pName;
	this->balance = balance;
}

int Account::getNumberofAccounts()
{
	return numAccounts;
}

bool Account::getActiveState()
{
	return active;
}

bool Account::operator==(Account right)
{
	if (type == right.type && active == right.active && acctNum == right.acctNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Account::Account()
{
	type = 's';
	active = true;
	pName = "Bob";
	balance = 0;
	acctNum = 1;
}

Account::Account(const Account& other)
{
	type = other.type;
	active = other.active;
	active = false;
	balance = other.balance;
	pName = other.pName;
	//acctNum = other.acctNum;
}

int Account::getAcctNum()
{
	return acctNum;
}

double Account::handleTransaction(int acctNum, double value)
{
	balance += value;
	return balance;
}

double Account::handleUpdate(int acctNum)
{
	return balance;
}

double Account::getBalance()
{
	return balance;
}

char* Account::getName()
{
	return pName;
}

char Account::getType()
{
	return type;
}

double Account::getUpdate()
{
	return balance;
}

double Account::getUpdateValue()
{
	return balance;
}
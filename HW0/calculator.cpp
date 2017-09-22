//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "calculator.hpp"

using namespace std;

Calculator::Calculator()
{
	m_total = 0;
}

void Calculator::m_add(double value)
{
	m_total += value;
	return;
}

void Calculator::m_subtract(double value)
{
	m_total -= value;
	return;
}

void Calculator::m_multiply(double value)
{
	m_total *= value;
	return;
}

void Calculator::m_divide(double value)
{
	m_total /= value;
	return;
}

double Calculator::m_getTotal()
{
	return m_total;
}

Calculator::~Calculator()
{
	cout << "Thank you for using our calculator! Have a nice Day.\n\n";
}

//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Calculator
{
public:
	Calculator();
	void m_add(double value);
	void m_subtract(double value);
	void m_multiply(double value);
	void m_divide(double value);
	double m_getTotal();
	~Calculator();

private:
	double m_total;
};

#endif

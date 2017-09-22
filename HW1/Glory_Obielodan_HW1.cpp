//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

const int n = 10000;

int mid = n / 2;

int y = 5000;

class TermTable
{
public:
	TermTable()
	{
		m_fieldData = 0;
		for (int i = 0; i < n; i++)
		{
			m_aFrequency[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			m_aTerm[i] = 0;
		}
	}

	void binarySearch()
	{
		while (true)
		{
			if (m_aTerm[mid] == y)
			{
				break;
			}
			else if (m_aTerm[mid] < y)
			{
				mid = mid / 2;
			}
			else if (m_aTerm[mid] > y)
			{
				mid = mid + (mid / 2);
			}
		}
	}

	void insert()
	{
		int term;
		ifstream fin;
		ofstream fout;

		fin.open("input.txt");
		fout.open("output.txt");

		fin >> m_aTerm[0];
		fin >> m_aTerm[1];

		for (int i = 2; i < n; ++i)
		{
			for (int j = i - 1; j = 1; --j)
			{
				if (fin.get() == m_aTerm[j])
				{
					m_aFrequency[j] += 1;
					break;
				}
				else
				{
					fin >> m_aTerm[i];
					m_aFrequency[i] = 1;
					m_fieldData += 1;
				}
			}
		}

	}

	void sort()
	{
		int i = 0;
		double a, b;
		while (i < n)
		{
			if (m_aFrequency[i] < m_aFrequency[i+1])
			{
				a = m_aFrequency[i];
				m_aFrequency[i] = m_aFrequency[i + 1];
				m_aFrequency[i + 1] = a;
				b = m_aTerm[i];
				m_aTerm[i] = m_aTerm[i + 1];
				m_aTerm[i + 1] = b;
			}
			++i;
		}
	}

	void output()
	{
		ifstream fin;
		ofstream fout;

		fin.open("input.txt");
		fout.open("output.txt");

		for (int i = 0; i < n; ++i)
		{
			fout << setw(8) << m_aTerm[i] << " " << m_aFrequency[i] << endl;
		}
	}

private:
	double m_fieldData;
	double m_aTerm[n];
	double m_aFrequency[n];

};

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("input.txt");
	fout.open("output.txt");

	TermTable obj;


	obj.insert();
	obj.sort();
	obj.output();

	fin.close();
	fout.close();

	return 0;
}
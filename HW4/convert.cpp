//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//#include <string>
//#include <fstream>
//#include <istream>
//
//using namespace std;
//
//struct BNKHeader                               //header struct
//{
//	char signature[4]; // {'B','A','N','K'};
//	int numberOfAccounts;
//	char reserved[24];
//};
//
//struct BNKAccount                             //accounts struct
//{
//	int number;
//	char name[20];
//	double balance;
//	char reserved[96];
//};
//
//struct BNKIndex                               // index struct
//{
//	int accountNumber;
//	long filePosition;
//};
//
//void swap(BNKIndex& a, BNKIndex& b)           // swap function
//{
//	BNKIndex temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	ifstream fin;
//	ofstream fout;
//
//	string line;
//	int numLines = -1;
//	int count = 0;
//	
//	BNKHeader obj1;
//	BNKAccount obj2;
//
//	fin.open("convert.CSV");
//	fout.open("converted.BNK", ios::out | ios::binary);            // open file as binary
//
//	while (getline(fin, line))
//	{
//		numLines++;                             // count number of accounts
//	}
//
//	obj1.numberOfAccounts = numLines;
//
//	obj1.signature[0] = 'B';                   // binary file signature
//	obj1.signature[1] = 'A';
//	obj1.signature[2] = 'N';
//	obj1.signature[3] = 'K';
//
//	fout.write((char*)&obj1, sizeof(BNKHeader));          // write the header to binary file
//
//	BNKIndex*  pIndex;                       // dynamic allocation
//	pIndex = new BNKIndex [numLines];
//
//	fin.close();                             // close file
//	fin.open("convert.CSV");                   // reopen file
//
//	getline(fin, line);
//	while (!fin.eof())                  // write the accounts into file
//	{
//		fin >> obj2.number;
//		pIndex[count].accountNumber = obj2.number;
//		pIndex[count].filePosition = fout.tellp();
//		count++;
//		fin.ignore();
//		fin.getline(obj2.name, 20, ',');
//		fin >> obj2.balance;
//		fout.write((char*)&obj2, sizeof(BNKAccount));
//	}
//
//	for (int j = 0; j < numLines - 1; j++)               // sort accounts
//	{
//		for (int i = 1; i < numLines; i++)
//		{
//			if (pIndex[i].accountNumber < pIndex[i - 1].accountNumber)
//			{
//				swap(pIndex[i].accountNumber, pIndex[i - 1].accountNumber);
//				swap(pIndex[i].filePosition, pIndex[i - 1].filePosition);
//			}
//		}
//	}
//
//	for (int i = 0; i < numLines; i++)                 // index
//	{
//		fout.write((char*)&pIndex[i], sizeof(BNKIndex));
//	}
//
//	fin.close();                                 // close files
//	fout.close();
//
//	delete[] pIndex;										//deallocate pointer array
//	pIndex = NULL;
//
//	return 0;
//}
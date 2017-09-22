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

using namespace std;

int fibonacci(int n)                          //fibonacci sequence
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int ComputeSumOfDigits(int number)
{
	if (number == 0)
	{
		return 0;
	}
	int digit = number % 10;                               //seperate digits
	int sum = ComputeSumOfDigits(number / 10);              //break out last digit
	return sum + digit;                                   //return the sum
}

int CountWays(int n)
{
	return fibonacci(n + 1);                 //fibonacci sequence with n+1
}

int CountSubSetSum(int aArraySet[], int size, int target)
{
	if (size == 0 && target == 0)                  //return 1 for acceptable situation
	{
		return 1;
	}
	else if (size == 0 && target != 0)               //return 0 for unacceptable situations
	{
		return 0;
	}
	else
	{
		return CountSubSetSum(aArraySet, size - 1, target) + CountSubSetSum(aArraySet, size - 1, target - aArraySet[size - 1]);
	}
}

bool IsSolvable(int startPos, int aArraySet[], int size)
{
	int* aArrayCpy = new int[size];                //copy of array // allocate
	for (int i = 0; i < size; i++)
	{
		aArrayCpy[i] = aArraySet[i];
	}

	aArrayCpy[startPos] = -1;

	if (aArraySet[startPos] == -1)             //don't go back to already visited spot
	{
		return false;
	}
	else if (aArraySet[startPos] == 0)         //puzzle solved
	{
		return true;
	}
	else                             //make position to stay within endpoints
	{
		if ((startPos - aArraySet[startPos]) < 0 && (startPos + aArraySet[startPos]) >= size)
		{
			return false;
		}
		else if ((startPos - aArraySet[startPos]) < 0)
		{
			startPos += aArraySet[startPos];
			return IsSolvable(startPos, aArrayCpy, size);
		}
		else if ((startPos + aArraySet[startPos]) >= size)
		{
			startPos -= aArraySet[startPos];
			return IsSolvable(startPos, aArrayCpy, size);
		}
		else
		{
			return IsSolvable(startPos - aArraySet[startPos], aArrayCpy, size) || IsSolvable(startPos + aArraySet[startPos], aArrayCpy, size);
		}
	}
	delete[] aArrayCpy;										//deallocate pointer array
	aArrayCpy = NULL;
}

bool mazePath(char** pMap, int rowsPos, int colsPos, int rows, int cols)
{
	if (pMap[rowsPos][colsPos] == 'Y')              //if visited before
	{
		return false;
	}
	if (pMap[rowsPos][colsPos] == 't')             //if found
	{
		return true;
	}
	else
	{
		pMap[rowsPos][colsPos] = 'Y';           //mark as visited
		if (pMap[rowsPos - 1][colsPos] == '.' || pMap[rowsPos - 1][colsPos] == 't')
		{ 
			if (mazePath(pMap, rowsPos - 1, colsPos, rows, cols) == true)             //check to see if there is a path
			{
				cout << "treasure path: " << rowsPos << ", " << colsPos << endl;
				return true;
			}
		}
		if (pMap[rowsPos + 1][colsPos] == '.' || pMap[rowsPos + 1][colsPos] == 't')         
		{
			if (mazePath(pMap, rowsPos + 1, colsPos, rows, cols) == true)                     //check to see if there is a path
			{
				cout << "treasure path: " << rowsPos << ", " << colsPos << endl;
				return true;
			}
		}
		if (pMap[rowsPos][colsPos - 1] == '.' || pMap[rowsPos][colsPos - 1] == 't')
		{
			if (mazePath(pMap, rowsPos, colsPos - 1, rows, cols) == true)                      //check to see if there is a path
			{
				cout << "treasure path: " << rowsPos << ", " << colsPos << endl;
				return true;
			}
		}
		if (pMap[rowsPos][colsPos + 1] == '.' || pMap[rowsPos][colsPos + 1] == 't')
		{
			if (mazePath(pMap, rowsPos, colsPos + 1, rows, cols) == true)               //check to see if there is a path
			{
				cout << "treasure path: " << rowsPos << ", " << colsPos << endl;
				return true;
			}
		}
		pMap[rowsPos][colsPos] = '.';              //unmark as visited
		return false;
	}
}

int main()
{
	cout << "                         RECURSIVE FUNCTIONS\n";                           //tests
	cout << "***************************************************************\n\n";
	cout << "TASK 1: SUM OF DIGITS\n";
	cout << "TEST 1:\n";
	int number;
	number = 1234;
	cout << "The number is " << number << endl;
	cout << "The sum of the digits of " << number << " is " << ComputeSumOfDigits(number) << endl << endl;

	cout << "TEST 2:\n";
	number = 365;
	cout << "The number is " << number << endl;
	cout << "The sum of the digits of " << number << " is " << ComputeSumOfDigits(number) << endl << endl;
	cout << "***************************************************************\n\n";

	cout << "TASK 2: CLIMB WAYS\n";
	cout << "TEST 1:\n";
	number = 6;
	cout << "The number of steps is " << number << endl;
	cout << "There are " << CountWays(number) << " Ways to climb " << number << " steps\n\n";

	cout << "TEST 2:\n";
	number = 10;
	cout << "The number of steps is " << number << endl;
	cout << "There are " << CountWays(number) << " Ways to climb " << number << " steps\n\n";
	cout << "***************************************************************\n\n";

	cout << "TASK 3: SUBSET SUMS\n";
	cout << "TEST 1:\n";

	int aArray[5];

	aArray[0] = 2;
	aArray[1] = 3;
	aArray[2] = -1;
	aArray[3] = 5;
	aArray[4] = 4;

	cout << "The array is ( ";
	for (int i = 0; i < 5; i++)
	{
		cout << aArray[i] << " ";
	}
	cout << ")\n";
	cout << "The target is 4\n";
	cout << "There are " << CountSubSetSum(aArray, 5, 4) << " subsets in this array\n\n";

	cout << "TEST 2:\n";

	int aArray1[7];

	aArray1[0] = 4;
	aArray1[1] = -1;
	aArray1[2] = 2;
	aArray1[3] = -3;
	aArray1[4] = 7;
	aArray1[5] = 5;
	aArray1[6] = 0;

	cout << "The array is ( ";
	for (int i = 0; i < 7; i++)
	{
		cout << aArray1[i] << " ";
	}
	cout << ")\n";
	cout << "The target is 6\n";
	cout << "There are " << CountSubSetSum(aArray1, 7, 6) << " subsets in this array\n\n";
	cout << "***************************************************************\n\n";

	cout << "TASK 4: IN/SOLVABLE PUZZLE\n";
	cout << "TEST 1:\n";
	int aArray2[10];

	aArray2[0] = 3;
	aArray2[1] = 6;
	aArray2[2] = 4;
	aArray2[3] = 1;
	aArray2[4] = 3;
	aArray2[5] = 4;
	aArray2[6] = 2;
	aArray2[7] = 5;
	aArray2[8] = 3;
	aArray2[9] = 0;

	cout << "The array is ( ";
	for (int i = 0; i < 10; i++)
	{
		cout << aArray2[i] << " ";
	}
	cout << ")\n";
	cout << "The Starting Position is 0\n";

	if (IsSolvable(0, aArray2, 10) == true)                   //verify
	{
		cout << "The Puzzle is Solvable\n\n";
	}
	else
	{
		cout << "The Puzzle is Not Solvable\n\n";
	}

	cout << "TEST 2:\n";
	int aArray3[5];

	aArray3[0] = 3;
	aArray3[1] = 1;
	aArray3[2] = 2;
	aArray3[3] = 3;
	aArray3[4] = 0;

	cout << "The array is ( ";
	for (int i = 0; i < 5; i++)
	{
		cout << aArray3[i] << " ";
	}
	cout << ")\n";
	cout << "The Starting Position is 3\n";

	if (IsSolvable(3, aArray3, 5) == true)                 //verify
	{
		cout << "The Puzzle is Solvable\n\n";
	}
	else
	{
		cout << "The Puzzle is Not Solvable\n\n";
	}
	cout << "***************************************************************\n\n";

	cout << "TASK 5: MAZE PATH\n";
	cout << "TEST 1:\n";

	ifstream fin;
	int rows, cols, rowPos, colPos;
	fin.open("maze.txt");

	fin >> rows >> cols >> rowPos >> colPos;

	char** pMap;                        //allocate array
	pMap = new char *[rows];
	for (int count = 0; count < rows; count++)	
	{
		pMap[count] = new char[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fin >> pMap[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (pMap[i][j] == 't')
			{
				cout << "\ntreasure: " << i << ", " << j << endl;
			}
		}
	}
	fin.close();
	if (mazePath(pMap, rowPos, colPos, rows, cols) == true)              //verify
	{
		cout << "FOUND!\n\n";
	}
	else
	{
		cout << "No Path Found\n\n";
	}

	cout << "TEST 2:\n";

	fin.open("maze1.txt");

	fin >> rows >> cols >> rowPos >> colPos;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fin >> pMap[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (pMap[i][j] == 't')
			{
				cout << "\ntreasure: " << i << ", " << j << endl;
			}
		}
	}
	fin.close();
	if (mazePath(pMap, rowPos, colPos, rows, cols) == true)             //verify
	{
		cout << "FOUND!\n\n";
	}
	else
	{
		cout << "No Path Found\n\n";
	}
	cout << "***************************************************************\n";
	delete[] pMap;										//deallocate pointer array
	pMap = NULL;

	return 0;
}
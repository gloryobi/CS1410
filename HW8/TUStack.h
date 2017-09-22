//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef TUSTACK_H_INCLUDED
#define TUSTACK_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

template < class T >
class wrongIndexExcep : public exception                       //illegal specified index exception
{
	public:
		wrongIndexExcep(int specifiedIndex, int size, int currentPosition)
		{
			index = specifiedIndex;
			totalSize = size;
			Position = currentPosition;
		}
		void printError()
		{
			cout << "\nERROR:";
			cout << "\nYou tried to copy from an illegal index\n";
			cout << "Size of Stack: " << totalSize << endl;
			cout << "Current Available Position: " << Position << endl;
			cout << "Your Inputted Index: " << index << endl << endl;
		}

	private:
		int index;
		int totalSize;
		int Position;
};

template < class T >
class wrongSizeExcep : public exception                    // illegal size input exception
{
public:
	wrongSizeExcep(int specifiedSize)
	{
		size = specifiedSize;
	}
	void printError()
	{
		cout << "\nERROR:";
		cout << "\nYou entered a negative input for the size\n";
		cout << "Your Input: " << size << endl << endl;
	}

private:
	int size;
};

template < class T >
class emptyPopExcep : public exception              // popping empty stack exception
{
public:
	emptyPopExcep(int size, int nextPos)
	{
		totalSize = size;
		pos = nextPos;
	}
	void printError()
	{
		cout << "\nERROR:";
		cout << "\nYou tried to pop an empty stack\n";
		cout << "Size of Stack: " << totalSize << endl;
		cout << "Current Available Index: " << pos << endl << endl;
	}

private:
	int totalSize;
	int pos;
};

template < class T >
class pushFullExcep : public exception              // pushing in full stack exception
{
public:
	pushFullExcep(T inputItem, int size)
	{
		item = inputItem;
		totalSize = size;
	}
	void printError()
	{
		cout << "\nERROR:";
		cout << "\nStack is full, you cannot push\n";
		cout << "Size of Stack: " << totalSize << endl;
		cout << "Attempted Item: (" << item << ")" << endl << endl;
	}

private:
	T item;
	int totalSize;
};

template < class T >
class pushDupExcep : public exception                        // pushing duplicate exception
{
public:
	pushDupExcep(T inputItem, int size, int nextPosition)
	{
		item = inputItem;
		totalSize = size;
		pos = nextPosition;
	}
	void printError()
	{
		cout << "\nERROR:";
		cout << "\nYou tried to push a duplicate item\n";
		cout << "Size of Stack: " << totalSize << endl;
		cout << "Current Available Index: " << pos << endl;
		cout << "Attempted Item: (" << item << ")" << endl << endl;
	}

private:
	T item;
	int totalSize;
	int pos;
};

template < class T > class TUStack                     // template class
{
	public:
		TUStack(int nSize);
		void Push(T item);                           // add new item to stack
		T Pop();                                     // return top item in stack
		int Size();                                  // return size of stack
		int Position();                              // return position of next available index
		T operator[](int position);                  // return copy of specified index

	private:
		int size;
		T *aStackArray;
		int count;

};

#endif
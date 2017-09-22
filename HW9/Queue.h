//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include "LinkedList.h"

using namespace std;

template <class T>
class Queue : public LinkedList <T>
{
	public:
		Queue() : LinkedList()
		{
			//empty
		}

		T* pop()
		{
			return removeAt(0);          // call remove function
		}

		virtual void push(T* pItem)
		{
			insert(pItem);    // call insert function at end position
		}

	private:
};

#endif
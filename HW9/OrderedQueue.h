//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef ORDEREDQUEUE_H_INCLUDED
#define ORDEREDQUEUE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include "Queue.h"

using namespace std;

template <class T>
class OrderedQueue : public Queue <T>
{
	public:
		OrderedQueue() : Queue()
		{
			//empty
		}

		void push(T* pItem)
		{
			orderList(pItem);            // call LinkedList function
		}

	private:
};

#endif
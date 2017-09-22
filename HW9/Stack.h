//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

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
class Stack : public LinkedList <T>
{
	public:
		Stack() : LinkedList() 
		{
			//empty
		}

		void push(T* pItem)
		{
			insert(pItem);                // call insert function at end position
		}

		T* pop()
		{
			return popStack();                //call remove function
		}

		T* top()
		{
			return topStack();               //call retrieve function
		}

	private:

};

#endif
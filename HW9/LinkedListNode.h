//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef LINKEDLISTNODE_H_INCLUDED
#define LINKEDLISTNODE_H_INCLUDED

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

template <class T>
class LinkedListNode
{
	public:
		LinkedListNode()            // default constructor
		{
			pNextNode = NULL;
			pPreviousNode = NULL;
		}

		LinkedListNode(T* data, LinkedListNode* next, LinkedListNode* pre)
		{
			pData = data;
			pNextNode = next;
			pPreviousNode = pre;
		}

		LinkedListNode(T* data)              // constructor with data parameter
		{
			pData = data;
			pNextNode = NULL;
			pPreviousNode = NULL;
		}

		T* getData()                 // get pointer to data
		{
			return pData;
		}

		LinkedListNode* getNext()            // get pointer to next node
		{
			return pNextNode;
		}

		void setData(T* Data)               //set data for node
		{
			pData = Data;
		}

		void setNext(LinkedListNode* NextNode)        // set pointer to next node
		{
			pNextNode = NextNode;
		}

		LinkedListNode* getPrevious()       // get pointer to previous node
		{
			return pPreviousNode;
		}

		void setPrevious(LinkedListNode* PreNode)        // set pointer to previous node
		{
			pPreviousNode = PreNode;
		}

	private:
		T* pData;                      // data pointer
		LinkedListNode* pNextNode;             // next node pointer
		LinkedListNode* pPreviousNode;          // previous node pointer
};

#endif
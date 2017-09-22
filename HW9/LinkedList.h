//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include "LinkedListNode.h"

using namespace std;

template <class T>
class LinkedList
{
	public:
		LinkedList()                           // default list
		{
			pHeadPointer = NULL;
			pTailPointer = NULL;
			count = 0;
		}

		int getSize()                   // return size of list
		{
			return count;
		}

		LinkedListNode<T>* begin()            // get to beginning of list
		{
			return pHeadPointer;
		}

		LinkedListNode<T>* end()                 // get to end of list
		{
			return pTailPointer;
		}
		
		void display()                    // display list
		{
			if (count == 0)
			{
				cout << "List is Empty\n";
			}
			else
			{
				int counter = 0;
				while (counter < count)
				{
					cout << "[" << *(at(counter)) << "] ";
					counter++;
				}
				cout << endl;
			}
		}

		T* at(int pos)                          // retrieve node from list
		{
			if (pHeadPointer == NULL)
			{
				return NULL;
			}
			else
			{
				return (at_p(pos)->getData());
			}
		}

		int findPos(T* pItem)                       // find the position of an item from the list
		{
			LinkedListNode<T>* temp = new LinkedListNode<T>(pItem);
			LinkedListNode<T>* temp2 = pHeadPointer;
			int counter = 0;
			while (*(temp->getData()) != *(temp2->getData()))
			{
				temp2 = temp2->getNext();
				counter++;
			}
			return counter+1;
		}

		int orderList(T* pItem)                    // put list in order (for ordered queue class)
		{
			if (pHeadPointer == NULL)
			{
				return insert(pItem, 0);
			}
			if (*(pItem) <= *(at(0)))
			{
				return insert(pItem, 0);
			}
			else
			{
				LinkedListNode<T>* temp = new LinkedListNode<T>(pItem);
				LinkedListNode<T>* temp2 = pHeadPointer;
				LinkedListNode<T>* temp3 = NULL;
				temp3 = temp2;
				temp2 = temp2->getNext();
				while (temp2 != NULL && !(*(temp2->getData()) >= *(temp->getData())))// && !(*(temp3->getData()) <= *(temp->getData())))
				{
					temp3 = temp2;
						temp2 = temp2->getNext();
				}
				return insert(pItem, findPos(temp3->getData()));
			}
		}

		T* popStack()                          // pop the stack class
		{
			return removeAt(count-1);
		}

		T* topStack()                         // return top value (for stack class)
		{
			return at_p(count - 1)->getData();
		}

		int insert(T* pItem, int pos = -1)                // call insert function
		{
			return insert_p(pItem, pos);
		}

		LinkedListNode<T>* At(int pos)                  // call retrieve function
		{
			return at_p(pos);
		}

		T* removeAt(int pos)                        // call remove function
		{
			return removeAt_p(pos);
		}

		LinkedListNode<T>* find(T* pItem)                // call find item function
		{
			return find_p(pItem);
		}

		void clear()                          // call clear function
		{
			clear_p(pHeadPointer);
		}

		~LinkedList()
		{
			clear_p(pHeadPointer);
		}

	protected:
		int insert_p(T* pItem, int pos = -1)                              // insert function
		{
			LinkedListNode<T>* temp = new LinkedListNode<T>(pItem);
			if (pHeadPointer == NULL)                                   // empty list
			{
				pHeadPointer = temp;
				pTailPointer = temp;
				count++;
			}
			else if (pos < 0 || pos > count-1)                     // outside list parameters
			{
				LinkedListNode<T>* temp2 = pHeadPointer;
				while (temp2->getNext() != NULL)
				{
					temp2 = temp2->getNext();
				}
				temp->setNext(temp2->getNext());
				temp2->setNext(temp);
				temp->setPrevious(temp2);
				count++;
			}
			else if (pos == 0)                                 // if insert postion is 0
			{
				LinkedListNode<T>* temp2 = pHeadPointer;
				pHeadPointer = temp;
				temp->setNext(temp2);
				temp2->setPrevious(temp);
				count++;
			}
			else if (pos > 0 && pos <= count - 1)                // within list parameters
			{
				LinkedListNode<T>* temp2 = pHeadPointer;
				LinkedListNode<T>* temp3 = NULL;
				int counter = 0;
				while (counter != pos)
				{
					temp3 = temp2;
					temp2 = temp2->getNext();
					counter++;
				}
				temp3->setNext(temp);
				temp->setPrevious(temp3);
				temp->setNext(temp2);
				temp2->setPrevious(temp);
				count++;
			}
			return pos;
		}

		LinkedListNode <T>* at_p(int pos)                        // return item at postion function
		{
			LinkedListNode<T>* temp = pHeadPointer;
			if (pHeadPointer == NULL)                   // empty list
			{
				cout << "Empty List: ";
			}
			else if (pos >= 0 || pos <= count - 1)               //withing list parameters
			{
				int counter = 0;
				while (counter != pos)
				{
					temp = temp->getNext();
					counter++;
				}
			}
			return temp;
		}

		T* removeAt_p(int pos)                         // remove an item function
		{
			LinkedListNode<T>* temp = pHeadPointer;
			LinkedListNode<T>* temp2 = NULL;
			LinkedListNode<T>* temp3 = NULL;
			T* temp4 = NULL;
			if (pos == 0)                              // if item is at 0
			{
				pHeadPointer = pHeadPointer->getNext();
				pHeadPointer->setPrevious(NULL);
				temp->setNext(NULL);
				count--;
				return temp->getData();
			}
			else
			{
				int counter = 0;
				while (counter != pos)
				{
					temp2 = temp;
					temp = temp->getNext();
					counter++;
				}
				temp3 = temp->getNext();
				temp2->setNext(temp3);
				if (temp3 != NULL)
				{
					temp3->setPrevious(temp2);
				}
				temp4 = temp->getData();
				delete temp;
				count--;
				return temp4;
			}
		}

		LinkedListNode<T>* find_p(T* pItem)                        //find item function
		{
			LinkedListNode<T>* temp = new LinkedListNode<T>(pItem);
			LinkedListNode<T>* temp2 = pHeadPointer;
			while (*(temp->getData()) != *(temp2->getData()))
			{
				temp2 = temp2->getNext();
			}
			return temp2;
		}

		void clear_p(LinkedListNode<T>* n)                  // clear list
		{
			if (n == NULL)                  // if list is empty
			{
				pHeadPointer = NULL;
				return;
			}
			else
			{
				clear_p(n->getNext());
				n->setNext(NULL);
				count--;
				delete n;
			}
		}

	private:
		LinkedListNode<T>* pHeadPointer;             // head pointer
		LinkedListNode<T>* pTailPointer;            // tail pointer
		int count;                       // list size count
};

#endif
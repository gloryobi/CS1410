//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "ConnectNGame.h"

using namespace std;

Position place;

ConnectNGame::ConnectNGame(int n)
{
	m_N = n;                                          //number of pieces needed to win
	place.m_rows = n + 2;                             //number of rows on gameboard
	place.m_cols = n + 3;                             //number of rows on gameboard
	aGameBoard = new char *[place.m_rows]; 
	for (int count = 0; count < place.m_rows; count++)    //initialize gameboard
	{
		aGameBoard[count] = new char[place.m_cols];
	}
	for (int i = 0; i < place.m_rows; i++)
	{
		for (int j = 0; j < place.m_cols; j++)
		{
			aGameBoard[i][j] = '.';                 // "." signifies empty space
		}
	}
}

void ConnectNGame::Play()
{
	while (true)
	{
		DisplayGameBoard();
		PlayerMove();
		DisplayGameBoard();
		if (CheckTie(place) == true || CheckRowWin(place) == true || CheckColumnWin(place) == true || CheckRightDiagonalWin(place) == true || CheckLeftDiagonalWin(place) == true)             //check to see if player has won
		{
			cout << endl;
			break;
		}
		ComputerMove();
		Sleep(1000);               //pause for one second
		if (CheckTie(place) == true || CheckRowWin(place) == true || CheckColumnWin(place) == true || CheckRightDiagonalWin(place) == true || CheckLeftDiagonalWin(place) == true)             //check to see if player has won
		{
			cout << endl;
			DisplayGameBoard();
			break;
		}
	}
}

ConnectNGame::~ConnectNGame()
{
	cout << "\nThanks for Playing. Have a nice Day!\n\n";
	delete[] aGameBoard;                   //deallocate pointer array
	aGameBoard = NULL;
}

void ConnectNGame::DisplayGameBoard()
{
	for (int i = 0; i < place.m_rows; i++)
	{
		cout << i + 1 << "|";
		for (int j = 0; j < place.m_cols; j++)
		{
			cout << aGameBoard[i][j];
		}
		cout << endl;
	}

	cout << "  ";

	for (int i = 0; i < place.m_cols; i++)
	{
		cout << "_";
	}
	
	cout << endl;

	cout << "  ";

	for (int i = 0; i < place.m_cols; i++)
	{
		cout << i + 1;
	}

	cout << endl;
}

Position ConnectNGame::PlayerMove()
{
	cout << "\n***************YOUR TURN***************\n";
	int ans;
	cout << "\nWhich Column do you wish to place your Piece.\n";
	cout << "Column: ";
	cin >> ans;
	if (ans < 1 || ans > place.m_cols)                      //column verification
	{
		while (true)
		{
			cout << "\nYou can only choose between 1 and " << place.m_cols << endl << endl;
			cout << "Please Choose again.\nColumn: ";
			cin >> ans;
			if (ans >= 1 && ans <= place.m_cols)
			{
				break;
			}
			else
			{
				continue;
			}
		}
	}
	while (true)
	{
		int k = 0;
		for (int i = (place.m_rows - 1); i > -1; i--)                //placing player's piece at the lowest possible part of the column
		{
			if (aGameBoard[i][ans - 1] == '.')
			{
				aGameBoard[i][ans - 1] = 'p';
				break;
			}
			else if (aGameBoard[0][ans - 1] == 'p')
			{
				cout << "\nYou cannot Place a piece there. Pick another Column.\n\n";
				cout << "Coulumn: ";
				cin >> ans;
				k++;
				break;
			}
		}
		if (k == 1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	cout << endl;
	return place;
}

Position ConnectNGame::ComputerMove()
{
	cout << "\n************COMPUTER'S TURN************\n";
	while (true)
	{
		int i = rand() % place.m_rows + 0;                  //place the computer's piece in a random column
		int j = rand() % place.m_cols + 0;
		if (aGameBoard[i][j] == '.')
		{
			for (int i = (place.m_rows - 1); i > -1; i--)
			{
				while (true)
				{
					if (aGameBoard[i][j] == '.')
					{
						aGameBoard[i][j] = 'c';
						break;
					}
					else if (aGameBoard[0][j] != '.')
					{
						j = rand() % place.m_cols + 0;            //change random column
					}
					else
					{
						i--;
					}
				}
				break;
			}
			break;
		}
	}
	cout << endl;
	return place;
}

bool ConnectNGame::CheckRowWin(Position p)
{
	int k = 0;                                                       //counter
	for (int i = (p.m_rows - 1); i > -1; i--)                        //start checking from the bottom
	{
		for (int j = (p.m_cols - 1); j > -1; j--)
		{
			if (j + m_N-1 <= p.m_cols - 1)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i][j + x] == 'p')            //verify that the next pieces are the player's pieces
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;                                                  //reinitialize counter
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i][j + x] == 'c')                           //verify that the next pieces are the computer's
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
			else if (j - m_N-1 >= 0)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i][j - x] == 'p')                             //verify that the next pieces are the player's
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i][j - x] == 'c')                                         //verify that the next pieces are the computer's
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
		}
	}
}

bool ConnectNGame::CheckColumnWin(Position p)                         //the rest of the checks are similar to the first one
{
	int k = 0;
	for (int i = (p.m_rows - 1); i > -1; i--)
	{
		for (int j = (p.m_cols - 1); j > -1; j--)
		{
			if (i + m_N - 1 <= p.m_rows - 1)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i + x][j] == 'p')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i + x][j] == 'c')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
			else if (i - m_N - 1 >= 0)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i - x][j] == 'p')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i - x][j] == 'c')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
		}
	}
}

bool ConnectNGame::CheckRightDiagonalWin(Position p)
{
	int k = 0;
	for (int i = (p.m_rows - 1); i > -1; i--)
	{
		for (int j = (p.m_cols - 1); j > -1; j--)
		{
			if (i + m_N - 1 <= p.m_rows - 1 && j + m_N - 1 <= p.m_cols - 1)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i + x][j + x] == 'p')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i + x][j + x] == 'c')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
			else if (i - m_N - 1 >= 0 && j - m_N - 1 >= 0)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i - x][j - x] == 'p')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i - x][j - x] == 'c')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
		}
	}
}

bool ConnectNGame::CheckLeftDiagonalWin(Position p)
{
	int k = 0;
	for (int i = (p.m_rows - 1); i > -1; i--)
	{
		for (int j = (p.m_cols - 1); j > -1; j--)
		{
			if (i + m_N - 1 <= p.m_rows - 1 && j - m_N - 1 >= 0)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i + x][j - x] == 'p')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i + x][j - x] == 'c')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
			else if (i - m_N - 1 >= 0 && j + m_N - 1 <= p.m_cols)
			{
				if (aGameBoard[i][j] == 'p')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i - x][j + x] == 'p')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU WIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
				else if (aGameBoard[i][j] == 'c')
				{
					for (int x = 0; x < m_N; x++)
					{
						if (aGameBoard[i - x][j + x] == 'c')
						{
							k++;
						}
					}
					if (k == m_N)
					{
						cout << "\nYOU LOSE :(\n";
						return true;
					}
					else
					{
						k = 0;
					}
				}
			}
		}
	}
}

bool ConnectNGame::CheckTie(Position p)
{
	int i = 0;                                             //counter
	for (int j = 0; j < p.m_cols; j++)
	{
		if (aGameBoard[0][j] != '.')
		{
			i++;
		}
	}
	if (i == p.m_cols)
	{
		cout << "\nITS A TIE GAME!!!!\n\n";
		return true;
	}
	else
	{
		return false;
	}
}
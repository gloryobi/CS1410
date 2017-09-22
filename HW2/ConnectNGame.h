//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef CONNECTNGAME_H_INCLUDED
#define CONNECTNGAME_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Position
{
	int m_rows;        //number of rows
	int m_cols;        //number of columns
};

class ConnectNGame
{
public:
	char** aGameBoard;
	ConnectNGame(int);
	void Play();
	~ConnectNGame();

private:
	int m_N;             //numeber of Connected pieces need to win
	void DisplayGameBoard();
	Position PlayerMove();
	Position ComputerMove();
	bool CheckRowWin(Position);
	bool CheckColumnWin(Position);
	bool CheckRightDiagonalWin(Position);
	bool CheckLeftDiagonalWin(Position);
	bool CheckTie(Position);

};

#endif
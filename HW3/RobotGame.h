//Glory Obielodan
//CS 1410 - 002
//A02042652

#ifndef ROBOTGAME_H_INCLUDED
#define ROBOTGAME_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class RobotGame
{
public:
	RobotGame(int rows, int cols);
	void Play(ifstream&);
	void intPlay();
	void loadRow(int row, char* pRowString);
	~RobotGame();

private:
	int m_rows;
	int m_cols;
	int m_gCount = 0;            // gold and diamond count
	int m_dCount = 0;
	int m_gPicked = 0;
	int m_dPicked = 0;
	int m_aRobotPos[2];             // robot position
	string m_dir;                  // direction
	float m_dirDeg;                // degrees
	char**  m_pBoard;
	void DisplayGameBoard();
	int moveRobot(int spaces);
	void rotateRobot(float degrees);
	void pickup(); 
};

#endif
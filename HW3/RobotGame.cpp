//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>
#include <fstream>
#include "RobotGame.h"

using namespace std;

RobotGame::RobotGame(int rows, int cols)
{
	m_rows = rows;
	m_cols = cols;
	m_pBoard = new char *[rows];
	for (int count = 0; count < rows; count++)    //initialize board
	{
		m_pBoard[count] = new char[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m_pBoard[i][j] = '_';                 // "_" signifies empty space
		}
	}
}

void RobotGame::Play(ifstream& file)             // scripted game mode
{
	for (int i = 0; i < m_rows; i++)             // count the number of gold and diamonds
	{
		for (int j = 0; j < m_cols; j++)
		{
			if (m_pBoard[i][j] == 'G' || m_pBoard[i][j] == 'g')
			{
				m_gCount++;
			}
			else if (m_pBoard[i][j] == 'D' || m_pBoard[i][j] == 'd')
			{
				m_dCount++;
			}
		}
	}
	while (true)
	{
		int spaces;
		float degrees;
		string command;
		file >> command;
		for (unsigned int i = 0; i < command.size(); i++)        // make commands case insensitive
		{
			command[i] = toupper(command[i]);
		}

		if (command == "ROBOT")                                  // initialize robot position
		{
			for (int i = 0; i < 2; i++)
			{
				file >> m_aRobotPos[i];
			}
			file >> m_dir;
			for (unsigned int i = 0; i < m_dir.size(); i++)
			{
				m_dir[i] = toupper(m_dir[i]);
			}
			if (m_dir == "EAST")
			{
				m_dirDeg = 90.0;
			}
			else if (m_dir == "SOUTH")
			{
				m_dirDeg = 180.0;
			}
			else if (m_dir == "WEST")
			{
				m_dirDeg = 270.0;
			}
			else if (m_dir == "NORTH")
			{
				m_dirDeg = 0.0;
			}
			else if (m_dir == "NORTH-EAST")
			{
				m_dirDeg = 45.0;
			}
			else if (m_dir == "SOUTH-EAST")
			{
				m_dirDeg = 135.0;
			}
			else if (m_dir == "SOUTH-WEST")
			{
				m_dirDeg = 225.0;
			}
			else if (m_dir == "NORTH-WEST")
			{
				m_dirDeg = 315.0;
			}
			DisplayGameBoard();
			cin.get();
		}
		else if (command == "MOVE" || command == "JUMP")                   //move command
		{
			file >> spaces;
			cout << "Command: " << command << " " << spaces << endl << endl;
			moveRobot(spaces);
			cin.get();
		}
		else if (command == "PICKUP")                               // pickup
		{
			cout << "Command: " << command << endl << endl;
			pickup();
			cin.get();
		}
		else if (command == "ROTATE")                         // rotate
		{
			while (true)
			{
				file >> degrees;
				if (fmod(degrees, 45.0) == 0)           // verify degrees
				{
					cout << "Command: " << command << " " << degrees << endl << endl;
					rotateRobot(degrees);
					break;
				}
				else
				{
					cout << "You can only enter a value that is a multiple of 45.0\n\n";
				}
			}
			cin.get();
		}
		else if (command == "QUIT")                   // end game
		{
			cout << "Command: " << command << endl << endl;
			cout << "Numner of Gold Picked: " << m_gPicked << endl;
			cout << "Number of Gold Left: " << m_gCount << endl;
			cout << "Number of Diamond Picked: " << m_dPicked << endl;
			cout << "Number of Diamond Left: " << m_dCount << endl << endl;
			break;
		}
	}
}

void RobotGame::intPlay()                      // interactive game mode
{
	for (int i = 0; i < m_rows; i++)           // count the number of gold and diamonds
	{
		for (int j = 0; j < m_cols; j++)
		{
			if (m_pBoard[i][j] == 'G' || m_pBoard[i][j] == 'g')
			{
				m_gCount++;
			}
			else if (m_pBoard[i][j] == 'D' || m_pBoard[i][j] == 'd')
			{
				m_dCount++;
			}
		}
	}

	string command;

	cout << "Input the Robot Position and Direction: ";                  // initialize robot position

	cin >> command >> m_aRobotPos[0] >> m_aRobotPos[1] >> m_dir;

	cout << endl;

	for (unsigned int i = 0; i < command.size(); i++)
	{
		command[i] = toupper(command[i]);
	}

	for (unsigned int i = 0; i < m_dir.size(); i++)
	{
		m_dir[i] = toupper(m_dir[i]);
	}

	if (command == "ROBOT")
	{
		if (m_dir == "EAST")
		{
			m_dirDeg = 90.0;
		}
		else if (m_dir == "SOUTH")
		{
			m_dirDeg = 180.0;
		}
		else if (m_dir == "WEST")
		{
			m_dirDeg = 270.0;
		}
		else if (m_dir == "NORTH")
		{
			m_dirDeg = 0.0;
		}
		else if (m_dir == "NORTH-EAST")
		{
			m_dirDeg = 45.0;
		}
		else if (m_dir == "SOUTH-EAST")
		{
			m_dirDeg = 135.0;
		}
		else if (m_dir == "SOUTH-WEST")
		{
			m_dirDeg = 225.0;
		}
		else if (m_dir == "NORTH-WEST")
		{
			m_dirDeg = 315.0;
		}
		DisplayGameBoard();
	}

	while (true)
	{
		int spaces;
		float degrees;

		cout << "Next Command (MOVE, ROTATE, PICKUP, or QUIT): ";

		cin >> command;

		for (unsigned int i = 0; i < command.size(); i++)
		{
			command[i] = toupper(command[i]);
		}
		
		if (command == "MOVE" || command == "JUMP")                    // move function
		{
			cout << "Enter the number of spaces: ";
			cin >> spaces;
			cout << "\nCommand: " << command << " " << spaces << endl << endl;
			moveRobot(spaces);
		}
		else if (command == "PICKUP")                              // pickup
		{
			cout << "\nCommand: " << command << endl << endl;
			pickup();
			cin.get();
		}
		else if (command == "ROTATE")                             // rotate function
		{
			while (true)
			{
				cout << "Enter the degree: ";
				cin >> degrees;
				if (fmod(degrees, 45.0) == 0)                   // verify degrees
				{
					cout << "\nCommand: " << command << " " << degrees << endl << endl;
					rotateRobot(degrees);
					break;
				}
				else
				{
					cout << "\nYou can only enter a value that is a multiple of 45.0\n\n";
				}
			}
			cin.get();
		}
		else if (command == "QUIT")            // end
		{
			cout << "\nCommand: " << command << endl << endl;
			cout << "Numner of Gold Picked: " << m_gPicked << endl;
			cout << "Number of Gold Left: " << m_gCount << endl;
			cout << "Number of Diamonds Picked: " << m_dPicked << endl;
			cout << "Number of Diamonds Left: " << m_dCount << endl << endl;
			break;
		}
	}
}

void RobotGame::loadRow(int row, char* pRowString)              //load each row
{
	m_pBoard[row] = pRowString;
}

RobotGame::~RobotGame()
{
	cout << "Thanks for Playing. Have a nice Day!\n\n";
	delete[] m_pBoard;										//deallocate pointer array
	m_pBoard = NULL;
}

void RobotGame::DisplayGameBoard()
{
	cout << "**************************************************************************\n\n";
	cout << "Robot is facing " << m_dir << " at (" << m_aRobotPos[0] << ", " << m_aRobotPos[1] << ")" << endl << endl;
	cout << "  ";

	for (int i = 0; i < m_cols; i++)
	{
		cout << i + 1 << " ";
	}

	cout << endl;

	cout << "  ";

	for (int i = 0; i < m_cols - 1; i++)
	{
		cout << "__";
	}

	cout << "_";
	cout << endl;

	for (int i = 0; i < m_rows; i++)
	{
		cout << i + 1 << "|";
		for (int j = 0; j < m_cols; j++)
		{
			if (i == (m_aRobotPos[0] - 1) && j == (m_aRobotPos[1] - 1))      // place R without changing board value
			{
				cout << "R ";
			}
			else
			{
				cout << m_pBoard[i][j] << " ";
			}
		}
		cout << endl;
	}

	cout << endl;

	cout << "Gold Left: " << m_gCount << ", Gold Picked: " << m_gPicked
		<< ", Diamonds Left: " << m_dCount << ", Diamonds Picked: " << m_dPicked << endl << endl;
	cout << "**************************************************************************\n\n";
}

int RobotGame::moveRobot(int spaces)
{
	if (m_dir == "EAST")                         // move based on direction in the East
	{
		if ((m_aRobotPos[1] + spaces) >= 1 && (m_aRobotPos[1] + spaces) <= m_cols)
		{
			m_aRobotPos[1] += spaces;
		}
		else
		{
			if (spaces < 0)
			{
				m_aRobotPos[1] = 1;
			}
			else if (spaces > 0)
			{
				m_aRobotPos[1] = m_cols;
			}
		}
	}
	else if (m_dir == "WEST")                       //West
	{
		if ((m_aRobotPos[1] + spaces) >= 1 && (m_aRobotPos[1] + spaces) <= m_cols)
		{
			m_aRobotPos[1] -= spaces;
		}
		else
		{
			if (spaces < 0)
			{
				m_aRobotPos[1] = m_cols;
			}
			else if (spaces > 0)
			{
				m_aRobotPos[1] = 1;
			}
		}
	}
	else if (m_dir == "SOUTH")                     //South
	{
		if ((m_aRobotPos[0] + spaces) >= 1 && (m_aRobotPos[0] + spaces) <= m_rows)
		{
			m_aRobotPos[0] += spaces;
		}
		else
		{
			if (spaces < 0)
			{
				m_aRobotPos[0] = 1;
			}
			else if (spaces > 0)
			{
				m_aRobotPos[0] = m_rows;
			}
		}
	}
	else if (m_dir == "NORTH")                 //North
	{
		if ((m_aRobotPos[0] + spaces) >= 1 && (m_aRobotPos[0] + spaces) <= m_rows)
		{
			m_aRobotPos[0] -= spaces;
		}
		else
		{
			if (spaces < 0)
			{
				m_aRobotPos[0] = m_rows;
			}
			else if (spaces > 0)
			{
				m_aRobotPos[0] = 1;
			}
		}
	}
	else if (m_dir == "NORTH-EAST")               // North-east
	{
		if (((m_aRobotPos[0] - spaces) >= 1 && (m_aRobotPos[0] - spaces) <= m_rows) && ((m_aRobotPos[1] + spaces) >= 1 && (m_aRobotPos[1] + spaces) <= m_cols))
		{
			m_aRobotPos[0] -= spaces;
			m_aRobotPos[1] += spaces;
		}
		else
		{
			if (spaces < 0)
			{
				while (m_aRobotPos[0] < m_rows  && m_aRobotPos[1] > 1)
				{
					++m_aRobotPos[0];
					--m_aRobotPos[1];
				}
			}
			else if (spaces > 0)
			{
				while (m_aRobotPos[0] > 1  && m_aRobotPos[1] < m_cols)
				{
					--m_aRobotPos[0];
					++m_aRobotPos[1];
				}
			}
		}
	}
	else if (m_dir == "SOUTH-WEST")                    // south-west
	{
		if (((m_aRobotPos[0] + spaces) >= 1 && (m_aRobotPos[0] + spaces) <= m_rows) && ((m_aRobotPos[1] - spaces) >= 1 && (m_aRobotPos[1] - spaces) <= m_cols))
		{
			m_aRobotPos[0] += spaces;
			m_aRobotPos[1] -= spaces;
		}
		else
		{
			if (spaces < 0)
			{
				while (m_aRobotPos[0] > 1  && m_aRobotPos[1] < m_cols)
				{
					--m_aRobotPos[0];
					++m_aRobotPos[1];
				}
			}
			else if (spaces > 0)
			{
				while (m_aRobotPos[0] < m_rows && m_aRobotPos[1] > 1)
				{
					++m_aRobotPos[0];
					--m_aRobotPos[1];
				}
			}
		}
	}
	else if (m_dir == "SOUTH-EAST")                 // south east
	{
		if (((m_aRobotPos[0] + spaces) >= 1 && (m_aRobotPos[0] + spaces) <= m_rows) && ((m_aRobotPos[1] + spaces) >= 1 && (m_aRobotPos[1] + spaces) <= m_cols))
		{
			m_aRobotPos[0] += spaces;
			m_aRobotPos[1] += spaces;
		}
		else
		{
			if (spaces < 0)
			{
				while (m_aRobotPos[0] > 1 && m_aRobotPos[1] > 1)
				{
					--m_aRobotPos[0];
					--m_aRobotPos[1];
				}
			}
			else if (spaces > 0)
			{
				while (m_aRobotPos[0] < m_rows && m_aRobotPos[1] < m_cols)
				{
					++m_aRobotPos[0];
					++m_aRobotPos[1];
				}
			}
		}
	}
	else if (m_dir == "NORTH-WEST")                         //north west
	{
		if (((m_aRobotPos[0] + spaces) >= 1 && (m_aRobotPos[0] + spaces) <= m_rows) && ((m_aRobotPos[1] + spaces) >= 1 && (m_aRobotPos[1] + spaces) <= m_cols))
		{
			m_aRobotPos[0] += spaces;
			m_aRobotPos[1] += spaces;
		}
		else
		{
			if (spaces < 0)
			{
				while (m_aRobotPos[0] < m_rows && m_aRobotPos[1] < m_cols)
				{
					++m_aRobotPos[0];
					++m_aRobotPos[1];
				}
			}
			else if (spaces > 0)
			{
				while (m_aRobotPos[0] > 1 && m_aRobotPos[1] > 1)
				{
					--m_aRobotPos[0];
					--m_aRobotPos[1];
				}
			}
		}
	}
	DisplayGameBoard();
	return 0;
}

void RobotGame::rotateRobot(float degrees)
{
	m_dirDeg += degrees;

	if (m_dirDeg >= 360.0)                     // make sure degrees never go beyond 360 and never goes negative
	{
		m_dirDeg -= 360.0;
	}
	else if (m_dirDeg <= 0.0)
	{
		m_dirDeg += 360.0;
	}

	if (m_dirDeg == 90.0)                       // initialize direction
	{
		m_dir = "EAST";
	}
	else if (m_dirDeg == 180.0)
	{
		m_dir = "SOUTH";
	}
	else if (m_dirDeg == 270.0)
	{
		m_dir = "WEST";
	}
	else if (m_dirDeg == 0.0 || m_dirDeg == 360.0)
	{
		m_dir = "NORTH";
	}
	else if (m_dirDeg == 45.0)
	{
		m_dir = "NORTH-EAST";
	}
	else if (m_dirDeg == 135.0)
	{
		m_dir = "SOUTH-EAST";
	}
	else if (m_dirDeg == 225.0)
	{
		m_dir = "SOUTH-WEST";
	}
	else if (m_dirDeg == 315.0)
	{
		m_dir = "NORTH-WEST";
	}

	DisplayGameBoard();
}

void RobotGame::pickup()
{
	if (m_pBoard[m_aRobotPos[0] - 1][m_aRobotPos[1] - 1] == 'G' || m_pBoard[m_aRobotPos[0] - 1][m_aRobotPos[1] - 1] == 'g')
	{
		m_gCount--;
		m_gPicked++;
		m_pBoard[m_aRobotPos[0] - 1][m_aRobotPos[1] - 1] = '_';         //pickup and change value
	}
	else if (m_pBoard[m_aRobotPos[0] - 1][m_aRobotPos[1] - 1] == 'D' || m_pBoard[m_aRobotPos[0] - 1][m_aRobotPos[1] - 1] == 'd')
	{
		m_dCount--;
		m_dPicked++;
		m_pBoard[m_aRobotPos[0] - 1][m_aRobotPos[1] - 1] = '_';
	}
	DisplayGameBoard();
}
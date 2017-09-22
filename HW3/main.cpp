//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "RobotGame.h"
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	ifstream fin;
	ofstream fout;
	string gameMode;
	string mapHolder;
	int rows, cols;

	while (argv[1] == NULL)                                //if there is no file already specified
	{
		char *pfilename = new char[1000];
		cout << "Please enter an input filename: ";
		cin >> pfilename;
		argv[1] = pfilename;
	}

	fin.open(argv[1]);

	fin >> gameMode;               // decide gamemode

	for (unsigned int i = 0; i < gameMode.size(); i++)
	{
		gameMode[i] = toupper(gameMode[i]);
	}

	if (gameMode == "MAP")
	{
		mapHolder = gameMode;
	}
	else
	{
		fin >> mapHolder;
	}

	fin >> rows >> cols;                  // take the board dimensions
	fin.ignore();

	RobotGame player(rows, cols);

	char* pmap;

	for (int i = 0; i < rows; i++)
	{
		pmap = new char[cols];
		fin.getline(pmap, cols + 1);               // load the rows
		player.loadRow(i, pmap);
	}

	cout << "Welcome to the Robot Game!!!!\n\n";
	cout << "Have fun playing!!\n\n";
	
	if (gameMode == "INTERACTIVE")                       // decide which game mode to use
	{
		cout << "Game Mode: " << gameMode << endl << endl;
		cout << "COMMANDS:\n\n";
		cout << "ROBOT X Y DIRECTION - (X IS ROW POSITION, Y IS COLUMN)\n";
		cout << "MOVE - MOVE THE ROBOT\n";
		cout << "ROTATE - ROTATE ROBOT\n";
		cout << "PICKUP - PICKUP ITEM\n";
		cout << "QUIT - END GAME\n\n";

		player.intPlay();
	}
	else
	{
		cout << "Game Mode: SCRIPTED\n\n";
		cout << "PRESS ENTER TO MOVE ON\n\n";
		player.Play(fin);
	}

	fin.close();                // close file
	fout.close();

	return 0;
}
//Glory Obielodan
//CS 1410 - 002
//A02042652

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ConnectNGame.h"

using namespace std;

int main()
{
	int n;

	cout << "Welcome to the Connect N Game.\n\n";
	cout << "Please State the Number of Connected Pieces needed to Win (3, 4 or 5): ";
	while (true)
	{
		cin >> n;
		if (n == 3 || n == 4 || n == 5)                   //verification
		{
			break;
		}
		else
		{
			cout << "\nYou can only choose 3, 4 or 5 pieces.\n\n";
			cout << "Pick again: ";
			continue;
		}
	}
	cout << "\nYou would need " << n << " Connected Pieces to win.\n\n";
	cout << "Have fun playing!!\n\n";

	ConnectNGame player(n);
	player.Play();
	return 0;
}
// Ashley Allan

//Program 6: Chutes and Ladders, File:AllanA_Pgm6

/*
Purpose: Plays a random game of chutes and ladders 
Input: Player names
Processing: Player names are collected, positions are set to 1, move number is set to 1, header is printed using a function. While loop begins the game 
and iterates until someone wins. Starting with player 1, the current position is set and the dice is rolled using a function. The player is moved using
a function, and that move is printed using another function. The current position is reset and the program checks to see if the player won using a 
function. If the player didn't win, the same process is used for player 2's turn. At the end of the loop, the program checks to see if player 2 won
using the same functions used for player 1. Once there is a winner, the name of the winner is output and the game ends. 
Output: Player names, move number, current position, number on dice, new position, and winner 

Reflection: During the creation of this program, I began to appreciate functions so much more. I realized how much simpler it made my program, and
I tried to imagine how difficult and time consuming this game would be to create without the use of functions. It was a fairly simple project, and
I really enjoyed creating it. 
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

void PrintHeader() { //Function used to print the game header
	cout << " PLAYER      " << "MOVE NUMBER      " << "CURR POSITION      " << "DIE      " << "NEW POSITION" << endl;
	cout << "**********************************************************************" << endl;
}

bool CheckWin(int playerPosition) { //Function used to check if a player has won 
	bool won;
	if (playerPosition < 100) {
		won = false;
	}
	else if (playerPosition >= 100) {
		won = true;
	}

	return won;
}

int RollDice() { //Function used to roll the dice 
	int result;
	result = rand() % 6 + 1; //Generates a random number between 1 and 6
	return result;
}

int CheckChutes(int& position) { //Function that checks if a player has landed on chutes and switches player position if they have 
	if (position == 8) {
		position = 1;
	}
	else if (position == 13) {
		position = 3;
	}
	else if (position == 24) {
		position = 18;
	}
	else if (position == 36) {
		position = 29;
	}
	else if (position == 51) {
		position = 37;
	}
	else if (position == 64) {
		position = 54;
	}
	else if (position == 86) {
		position = 44;
	}
	return position;
}

int CheckLadders(int& position) { //Function that checks if a player has landed on ladders and changes player position if they have 
	if (position == 7) {
		position = 19;
	}
	else if (position == 12) {
		position = 27;
	}
	else if (position == 28) {
		position = 41;
	}
	else if (position == 39) {
		position = 50;
	}
	else if (position == 53) {
		position = 62;
	}
	else if (position == 66) {
		position = 78;
	}
	else if (position == 75) {
		position = 91;
	}
	return position;
}

int MovePlayer(int position, int numberOnDice) { //Function that moves player 
	int moves;
	moves = position + numberOnDice;
	CheckChutes(position);
	CheckLadders(position);
	return moves;
}

void PrintOneMove(string playerName, int move, int position, int numberOnDice, int newPosition) { //Function that outputs the player's move 
	cout << " " << playerName << "             "
	<< move << "                  " 
	<< position << "             " 
	<< numberOnDice << "            " 
	<< newPosition << endl;
}

int main()
{
	srand(time(NULL)); //Seeds rand() function

	string player1; //Holds player names
	string player2;
	int playerPosition1 = 1; //Holds positions
	int playerPosition2 = 1;
	int currPosition1; //Holds current positions
	int currPosition2;
	int moveNumber = 0; //Holds move number
	int dice = 0; //Holds number rolled on dice 

	cin >> player1; //Gets player names from input
	cin >> player2;

	PrintHeader(); //Prints game header 

	while ((!CheckWin(playerPosition1)) && (!CheckWin(playerPosition2))) { //Plays game until someone wins
		++moveNumber; //Increments move Number
		currPosition1 = playerPosition1; //Sets current position
		dice = RollDice(); //Rolls dice 
		
		playerPosition1 = MovePlayer(playerPosition1, dice); //Moves Player
		PrintOneMove(player1, moveNumber, currPosition1, dice, playerPosition1); //Outputs move
		currPosition1 = playerPosition1; //Resets current position
		CheckWin(playerPosition1); //Checks if player 1 has won yet 

			if (!CheckWin(playerPosition1)) { //Plays player 2's turn if player 1 didn't win 
				currPosition2 = playerPosition2;
				dice = RollDice();
				playerPosition2 = MovePlayer(playerPosition2, dice);
				PrintOneMove(player2, moveNumber, currPosition2, dice, playerPosition2);
				currPosition2 = playerPosition2;
			}
			
			cout << "----------------------------------------------------------------------" << endl; //Outputs line at end of move for both players
			CheckWin(playerPosition2); //Checks if player 2 has won yet 

	}
	cout << endl;

	if (CheckWin(playerPosition1)) { //Outputs winner 
		cout << "The winner is " << player1 << endl;
	}
	else if (CheckWin(playerPosition2)) {
		cout << "The winner is " << player2 << endl;
	}


	return 0;
}

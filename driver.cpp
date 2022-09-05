// This program is a recreation of the classic dice game Pig. You can read more here: https://en.wikipedia.org/wiki/Pig_(dice_game)
#include <iomanip>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

int performTurn(string pname, int pscore, int winScore);

void printGameState(string p1name, string p2name, int p1score, int p2score, int turnCount);

int main()
{
	string p1name, p2name;
	string winner;
	int p1score = 0, p2score = 0, turnCount = 0;
	int winCondition;

	// Provide the rand function with a seed using the current time.
	srand(time(NULL));

	cout << "Welcome to Ryan's Pig simulator. The rules of the game can be viewed here: https://en.wikipedia.org/wiki/Pig_(dice_game)" << endl;
	cout << "Player 1, please enter you name: ";
	cin >> p1name;

	cout << "Player 2, please enter you name: ";
	cin >> p2name;

	cout << "Play to how many points? ";
	cin >> winCondition;

	cout << "The game will now begin.\n\n";

	while(true)
	{
		p1score += performTurn(p1name, p1score, winCondition);
		printGameState(p1name, p2name, p1score, p2score, ++turnCount);
		if(p1score >= winCondition)
		{
			winner = p1name;
			break; 
		}

		p2score += performTurn(p2name, p2score, winCondition);
		printGameState(p1name, p2name, p1score, p2score, ++turnCount);
		if(p2score >= winCondition)
		{
			winner = p2name;
			break;
		}
	}

	cout << winner << " wins! Congratulations!" << endl;

	return 0;
}

int performTurn(string pname, int pscore, int winScore)
{
	int roll;
	int turnTot = 0;

	cout << pname << "\'s turn.";
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	while(true)
	{
		roll = 1 + rand() % 6;
		cout << "Rolled a " << roll << "." << endl;		
		if(roll == 1)
		{
			cout << pname << "\'s turn total is set to 0 and their turn is now over." << endl;
			turnTot = 0;
			break;
		}
		else
		{
			turnTot += roll;
			cout << pname << "\'s current turn total: " << turnTot << endl;	
		}

		if(turnTot + pscore >= winScore)
		{
			break;
		}
		else
		{
			char resp;
			cout << "Roll again? (y/n)" << endl;
			cin >> resp;
		
			if(resp == 'n')
			{
				break;
			}
		}

	}

	return turnTot;
}

void printGameState(string p1name, string p2name, int p1score, int p2score, int turnCount)
{
	cout << "Turn # " << turnCount << " (" << p1name << ": " << p1score << "; " << p2name << ": " << p2score << ")\n\n";
}

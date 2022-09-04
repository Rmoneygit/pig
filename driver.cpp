// This program is a recreation of the classic dice game Pig. You can read more here: https://en.wikipedia.org/wiki/Pig_(dice_game)
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

int performTurn(string pname);

void printGameState(string p1name, string p2name, int p1score, int p2score, int turnCount);

int main()
{
	string p1name, p2name;
	string winner;
	int p1score, p2score, turnCount = 0;

	// Provide the rand function with a seed using the current time.
	srand(time(NULL));

	cout << "Welcome to Ryan's Pig simulator. The rules of the game can be viewed here: https://en.wikipedia.org/wiki/Pig_(dice_game)" << endl;
	cout << "Player 1, please enter you name: ";
	cin >> p1name;

	cout << "Player 2, please enter you name: ";
	cin >> p2name;

	cout << "The game will now begin." << endl;

	while(true)
	{
		p1score += performTurn(p1name);
		printGameState(p1name, p2name, p1score, p2score, ++turnCount);
		if(p1score >= 100)
		{
			winner = p1name;
			break; 
		}

		p2score += performTurn(p2name);
		printGameState(p1name, p2name, p1score, p2score, ++turnCount);
		if(p2score >= 100)
		{
			winner = p2name;
			break;
		}
	}

	cout << winner << " wins! Congratulations!" << endl;

	return 0;
}

int performTurn(string pname)
{
	int roll;
	int turnTot = 0;

	while(true)
	{
		cout << pname << "\'s turn." << endl;
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

		char resp;
		cout << "Roll again? (y/n)" << endl;
		cin >> resp;
		
		if(resp == 'n')
		{
			break;
		}

	}

	return turnTot;
}

void printGameState(string p1name, string p2name, int p1score, int p2score, int turnCount)
{
	int p1nameWidth = (int) p1name.length();
	int p2nameWidth = (int) p2name.length();
	
	cout << setfill('*') << setw(9 + p1nameWidth) << "Turn # " << turnCount << setw(4 + p2nameWidth) << endl;
	cout << setfill('*') << setw(6) << p1name << setw(14) << p2name << endl;
	cout << "Score: " << setfill('*') << setw(9) << p1score << setw(14) << p2score << endl;
}

#include <iostream>
#include <string>
#include <stdlib.h>	// rand, srand
#include <time.h>
#include <Windows.h>
using namespace std;

int player1_score;
int bot_score;
int tie;
int bot;
int input;

int main()
{
	do
	{
		cout << "\n\n Rock-Papper-Scissors Game \n\n";
		cout << " Press 1 For Rock...\n";
		cout << " Press 2 For Paper...\n";
		cout << " Press 3 For Scissors...\n\n";

		srand(time(NULL));
		bot = rand() % 3 + 1;	// From 0, 1, 2  ->  1, 2, 3
		int input;
		cin >> input;

		// First
		if (input == 1 && bot == 1)
		{
			cout << "\n Player 1 : Rock \t VS \t CPU : Rock \n\n";
			cout << " Draw.";
			tie++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else if (input == 1 && bot == 2)
		{
			cout << "\n Player 1 : Rock \t VS \t CPU : Paper \n\n";
			cout << " Bot Wins.";
			bot_score++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else if (input == 1 && bot == 3)
		{
			cout << "\n Player 1 : Rock \t VS \t CPU : Scissors \n\n";
			cout << " Player 1 Wins.";
			player1_score++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}

		// Second
		else if (input == 2 && bot == 1)
		{
			cout << "\n Player 1 : Paper \t VS \t CPU : Rock \n\n";
			cout << " Player 1 Wins.";
			player1_score++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else if (input == 2 && bot == 2)
		{
			cout << "\n Player 1 : Paper \t VS \t CPU : Paper \n\n";
			cout << " Draw.";
			tie++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else if (input == 2 && bot == 3)
		{
			cout << "\n Player 1 : Paper \t VS \t CPU : Scissors \n\n";
			cout << " Bot Wins.";
			bot_score++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}

		// Third
		else if (input == 3 && bot == 1)
		{
			cout << "\n Player 1 : Scissors \t VS \t CPU : Rock \n\n";
			cout << " Bot Wins.";
			bot_score++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else if (input == 3 && bot == 2)
		{
			cout << "\n Player 1 : Scissors \t VS \t CPU : Paper \n\n";
			cout << " Player 1 Wins.";
			player1_score++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else if (input == 3 && bot == 3)
		{
			cout << "\n Player 1 : Scissors \t VS \t CPU : Scissors \n\n";
			cout << " Draw.";
			tie++;
			cout << "\n\n Player 1 Scores = " << player1_score;
			cout << "\n Bot Scores : " << bot_score;
			cout << "\n Tied : " << tie;
		}
		else
			cout << "Please Type In Numbers.";

		cout << "\n\n______________________________________________________";
		Sleep(3000);
		system("cls");
	} while (1);

	return 0;
}
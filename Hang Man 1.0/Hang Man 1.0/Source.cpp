#include <iostream>
#include <Windows.h>
#include <cctype>	// Lowercase / Uppercase.
using namespace std;

char alphabets[3][9]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char word[50];
char hidden[50]{ '_', '_', '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' , '_' };
char player_input;
int lives = 9;
bool win, lose;
bool guess;
int match = 0;

void draw()	// Prints the alphabets
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (player_input == alphabets[i][j] && guess == true)
			{
				alphabets[i][j] = ' ';	// If input match, it will dissapear from the alphabets.
			}
			cout << alphabets[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < strlen(word); i++)
	{
		cout << " " << hidden[i] << " ";
	}
	cout << "\n\nLives: " << lives;
	cout << "\n";
}

void input()
{
	cout << "\nInput a character: ";
	cin >> player_input;

	for (int i = 0; i < strlen(word); i++)
	{
		// Does the character has been inputed?
		if (player_input == hidden[i])
		{
			cout << "\nYou Have Inputed the Same Character. Please Try Another.";
			guess = true;
			Sleep(1000);
		}
		// Does the input match the word?
		else if (player_input == word[i])
		{
			hidden[i] = player_input;	// Changes the '_' into the correct word.
			++match;
			guess = true;	// If it's true, then guess is true. When it's gonna loop again, guess is set 
							// to false again. If guess is true even once, then the lives remain.
		}		
		// Does the input is a capital letter?
		else if (!isupper(player_input))	
		{
			cout << "\nPlease use capital letters.\n";
			input();
		}
	}
	cout << "\n";

	// Does the input match the word? 
	if (guess == false)
	{
		--lives;
		cout << player_input << " is wrong.";
		Sleep(1000);
	}
}

void logic()
{
	guess = false;	// Set the guess to false.

	// If all the input matches the word, win is true.
	if (match == strlen(word))
	{
		win = true;
		system("cls");
		cout << "YOU WIN!";
		exit(0);
	}
	else if (lives == 0)
	{
		lose = true;
		system("cls");
		cout << "YOU LOSE!";
		exit(0);
	}
}

int main()
{
	cout << "Enter a word: ";
	cin >> word;

	for (int i = 0; i < strlen(word); i++)
	{
		if (!isupper(word[i]))
		{
			cout << "Please use capital letters.\n\n";
			main();
		}
	}

	while (win == false || lose == false)
	{	
		draw();logic();
		input();
	}

	system("PAUSE");
	return 0;
}
/*
Bugs:

*/
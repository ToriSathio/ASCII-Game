#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int fruit_x, fruit_y;
const int height = 10;
const int width = 30;
int player_xpos;
int player_ypos;
bool game_over;
enum direction {LEFT, RIGHT, UP, DOWN};
direction dir;
int choice;
int score;
int number_of_tail, tail_x[100], tail_y[100];

void setup()
{
	game_over = false;
	player_xpos = width / 2;
	player_ypos = height / 2;
	number_of_tail = 0;
}

void food_placement()
{
	fruit_x = rand() % width;	// Random number from 0 to width - 1
	if (fruit_x == 0)
		++fruit_x;
	else if (fruit_x == width - 1)
		--fruit_x;
	fruit_y = rand() % height;	// Random number from 0 to height - 1
	if (fruit_y == 0)
		++fruit_y;
	else if (fruit_y == height - 1)
		--fruit_y;
}

void player_char_selection()	// Masalahnya disini. Ga mau ke print pilihannya
{
	switch (choice)
	{
	case 1:
		cout << "0";
		break;
	case 2:
		cout << "O";
		break;
	case 3:
		cout << "[]";
		break;
	case 4:
		cout << "{}";
		break;
	case 5:
		cout << "<";
		break;
	case 6:
		cout << "+";
		break;
	}
}

void snake_body()
{
	switch (choice)
	{
	case 1:
		cout << "o";
		break;
	case 2:
		cout << "o";
		break;
	case 3:
		cout << "~";
		break;
	case 4:
		cout << "~";
		break;
	case 5:
		cout << "-";
		break;
	case 6:
		cout << "-";
		break;
	}
}

void clear_screen()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			cout << " ";
		}
	}
}

void map()
{
	clear_screen();

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == player_ypos && j == player_xpos)		
				player_char_selection();	// Prints the snake's head
			else if (i == fruit_y && j == fruit_x)
				cout << "X";	// Prints the food
			else if (j == 0)
				cout << "*";	// Prints the left side of the map
			else if (j == width - 1)
				cout << "*";	// Prints the right side of the map
			else if (i == 0)
				cout << "*";	// Prints the upper side of the map
			else if (i == height - 1)
				cout << "*";	// Prints the lower side of the map
			else if (fruit_y == player_ypos && fruit_x == player_xpos)
			{
				snake_body();	// Prints the snake's body
				food_placement();
				score += 10;
			}
			else
				cout << " ";	// Prints the empty area inside the map

			/*
			if (i == player_xpos && j == player_ypos)	
				cout << "0";
			else
				cout << "*";	// Hasilnya g bisa ngenain X-nya kalo secara vertikal karena dilompat istilahnya.
			
			if (i == fruit_x && j == fruit_y)
				cout << "X";	
			else
				cout << "*";	// Ganti pake "" jadinya kelebihan 1. Diganti pake " " jadinya aneh, terasa hampa.
				*/
		}
		cout << endl;
	}
	if (player_xpos > width - 2 || player_xpos < 1 || player_ypos > height - 2 || player_ypos < 1)	// If the player touches the wall --> game over
		game_over = true;

	cout << "Score : " << score;
}

void logic()
{
	switch (dir)	// To make the snake move constantly in a specific direction
	{
	case UP:	
		--player_ypos;	
		break;
	case DOWN:
		++player_ypos;
		break;
	case LEFT:
		--player_xpos;
		break;
	case RIGHT:
		++player_xpos;
		break;
	default:
		break;
	}


}

void movement()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':	// Ini masuk akal, harus pake kertas. Kurfa f(x) = x^2 = u, kurfa f(x) = -x^2 = n
			dir = UP;	// Positif ke bawah, negatif ke atas dalam kurfa f(x)
			break;
		case 's':
			dir = DOWN;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		}
	}

	/*
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++) { i = player_xpos && j = player_ypos }
		
		0 1 2  3  4 5 6     anggap x = 3, y = 3. Di baris paling belakang deret ke 4 (itung dari 0), pencet A --x
		0 1 2  3  4 5 6     x = 2, y = 3. Di baris ke 3, deret ke 4. Pencet W ++y
		0 1 2  3  4 5 6     x = 2, y = 4. Di baris ke 3, deret ke 5.
		0 1 2 (3) 4 5 6
		*/

		/*
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) { i = player_xpos && j = player_ypos }
			
		0 1 2  3  4 5 6     anggap x = 3, y = 3. Di baris paling belakang deret ke 4 (itung dari 0), pencet A --x
		0 1 2  3  4 5 6     x = 2, y = 3. Di baris ke 4, deret ke 3. Pencet W ++y
		0 1 2  3  4 5 6     x = 2, y = 4. Di baris ke 5, deret ke 3.
		0 1 2 (3) 4 5 6
		0 1 2  3  4 5 6
		*/
}

int main()
{
	/* int choice; */	// Di atas udh di declare, ini di declare ulang jadinya ga bakal ke print karena, player_char_selection() punya choice dengan int main() itu beda
	cout << "\n\t 1. 0ooo\t 2. Oooo\t 3. []~~~\t 4. {}~~~\t 5. <---\t 6. +---";
	cout << "\n\n\tChoose Your Character: ";
	cin >> choice;

	setup();
	food_placement();
	while (!game_over)
	{
		map();
		movement();
		logic();
		Sleep(75);
	}
	return 0;
}
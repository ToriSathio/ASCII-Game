#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <conio.h>
#include <chrono>
using namespace std;

bool game_over;
int score;

class bird
{
private:
	int width, height;
	int bird_posx, bird_posy;
	int obstacles_posx, obstacles_posy;
	int obstacles_holes;
	enum direction { UP, GRAVITY };
	direction dir;
public:
	int set_width(int width) { return this->width = width; }
	int set_height(int height) { return this->height = height; }

	int set_obstacles_holes() // Generate random number to determine where the holes will be placed at.
	{
		// The number is always positive.
		// Each times this function is called, it will generate a random number.		
		srand((unsigned int)time(NULL));

		/*
		unsigned srand(time(NULL));	// Converting time_t to unsigned int. Possible loss of data.
		*/

		return this->obstacles_holes = rand() % height;
	}

	int set_bird_posx(int x) { return this->bird_posx = x; }
	int set_bird_posy() { return this->bird_posy = height / 2; }
	int set_obstacles_posx(int x) { return this->obstacles_posx = x; }
	int set_obstacles_posy() { return this->obstacles_posy = height; }

	void draw_character()
	{
		string character = "@";
		cout << character;
	}

	void draw_obstacles()
	{
		string obstacles = "x";
		cout << obstacles;
	}

	void print()	// Prints the map.
	{
		system("cls");

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == bird_posx && i == bird_posy)	// Prints the bird.
				{
					draw_character();
				}
				else if (obstacles_posx == j && i != obstacles_holes && i != obstacles_holes + 1 && i != obstacles_holes - 1)	// Prints the obstacles.
				{		// If the height == obstacles_holes (randomized), it will print an empty area.
						// If obstacles_holes + 1 and - 1 are both 'i' then it will print an empty area.
					draw_obstacles();	// Kenapa space yang kosong bisa direplace ketiga tiganya padahal j == 45.
									// Kan harusnya yang pas 45 doang ke printnya. Kelebihan 2. 
									// Kenapa bisa di replace lagi 2 spacenya.

									// Total space yang kosong jadinya kelebihan 2. Total width + 2.
									// Tapi karena ini ditengah-tengah jadinya keliatannya di replace.
									// Padahal aslinya kelebihan.
				}
				else if (obstacles_holes == 0 || obstacles_holes == height - 1 || obstacles_holes == 1 || obstacles_holes == height - 2)
				{	// If the randomized holes is == 0, 1, height - 1, or height - 2. It will be randomized again
					set_obstacles_holes();
				}
				else if (obstacles_posx == 0)
				{
					set_obstacles_posx(30);
					set_obstacles_holes();
					
				}
				else
				{
					cout << " ";	// Prints the empty area.
				}
			}
			cout << "\n";
		}
		cout << "\nScore : " << score;
	}

	void input()	// Player's input.
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case VK_SPACE:	// If space is pressed, it will jump 3 times and the bird will be pulled by the gravity by 1.
				dir = GRAVITY;
				bird_posy -= 3;
				break;
			}
		}
	}

	void update()	// Updates the game.
	{
		switch (dir)
		{
		case GRAVITY:	// If space is pressed once, the gravity will run continuously and the pipes will move.
			++bird_posy;
			--obstacles_posx;
			Sleep(50);
			break;
		default:
			break;
		}

		if (bird_posy == obstacles_holes || bird_posy == obstacles_holes + 1 || bird_posy == obstacles_holes - 1 && bird_posx == obstacles_posx)
		{	// If it passess the holes then, the game will keep running.
			game_over = false;
		}
		else if (bird_posy == obstacles_posy - 1 || bird_posx == obstacles_posx)	// If the bird touches the ground or obstacles then, game over.
		{
			game_over = true;
		}
		else   // For the continue, so when 'c' is pressed, the game will continue as usual.
		{
			game_over = false;
		}
	
		if (bird_posx == obstacles_posx + 1)	// Passess the holes, +1 score.
		{
			++score;
		}
	}
};

int main()
{
	game_over = false;
	score = 0;
	string choice;

	bird bird;
	bird.set_width(40);
	bird.set_height(20);
	bird.set_bird_posx(5);	// It prints from left to right. From 0 to 50(the width).
	bird.set_bird_posy();
	bird.set_obstacles_posx(35);
	bird.set_obstacles_posy();
	bird.set_obstacles_holes();

	while (game_over == false || choice == "c" || choice == "C")	// C to continue
	{
		// Rule 
		// 1st. Input.
		// 2nd. Update.
		// 3rd. Print. 

		bird.input();
		bird.update();
		bird.print();

		if (game_over == true)
		{
			system("cls");
			cout << "Score: " << score;
			cout << "\nHighest Score: " << max(score,score);	// Compare previous score with current score
			cout << "\nPress c to continue, y to retry, or n to exit.";
			cin >> choice;
		}
		
		if (choice == "n" || choice == "N")
		{
			exit(0);
		}
		else if (choice == "y" || choice == "Y")
		{
			main();
		}	
	}

	cin.ignore();
	return 0;
}

// How to implemented the gravity?
// How to reprint the obstacles?
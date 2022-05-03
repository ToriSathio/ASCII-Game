#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

class game
{
private:
	int level_difficulty = 1;
	int user_input;
	int choice;
	int wrong = 0;
	bool busted;
	unsigned int code_a, code_b, code_c, code_d;
	unsigned int guess_a, guess_b, guess_c, guess_d;

	int code_sum1;
	int code_sum2;
	int code_multiplication1;
	int code_multiplication2;

	int guess_sum1;
	int guess_sum2;
	int guess_multiplication1;
	int guess_multiplication2;

	void logic()
	{
		code_sum1 = code_a + code_b + code_c;
		code_sum2 = code_a + code_b + code_c + code_d;
		code_multiplication1 = code_a * code_b * code_c;
		code_multiplication2 = code_a * code_b * code_c * code_d;

		guess_sum1 = guess_a + guess_b + guess_c;
		guess_sum2 = guess_a + guess_b + guess_c + code_d;
		guess_multiplication1 = guess_a * guess_b * guess_c;
		guess_multiplication2 = guess_a * guess_b * guess_c * guess_d;
	}

	bool check_if_pass()
	{
		code_sum1 = code_a + code_b + code_c;
		code_sum2 = code_a + code_b + code_c + code_d;
		code_multiplication1 = code_a * code_b * code_c;
		code_multiplication2 = code_a * code_b * code_c * code_d;

		guess_sum1 = guess_a + guess_b + guess_c;
		guess_sum2 = guess_a + guess_b + guess_c + code_d;
		guess_multiplication1 = guess_a * guess_b * guess_c;
		guess_multiplication2 = guess_a * guess_b * guess_c * guess_d;

		if (guess_sum1 == code_sum1 && guess_multiplication1 == code_multiplication1
			|| guess_sum2 == code_sum2 && guess_multiplication2 == code_multiplication2)
		{
			return true;
		}
		else
		{
			++wrong;
			return false;
		}
	}

	void random_number()
	{
		srand((unsigned int)time(NULL));

		code_a = rand() % 5 + level_difficulty;
		code_b = rand() % 5 + level_difficulty;
		code_c = rand() % 5 + level_difficulty;
	}

	void introduction()
	{
		cout << "You are a student that is trying to take back your phone that has been confiscated by your teacher.\n";
		cout << "\nIt's placed in the teacher's office and it's patrolled by the guards!\n";
		cout << "\nRemember you MUST NOT get caught! As it may results in your expulsion.\n";
		cout << "\nProceed with caution...\n\n\n";

		system("pause");
	}

	void story_arc1()
	{
		system("cls");
		random_number();
		logic();

		cout << "You are in front of your school in the middle of the night.";
		cout << "\nYou tried to climb the wall but to no avail, it's way too risky as you might get seen by the guards.";
		cout << "\nYou tried to open the gate and found out that it's locked by a 3 digit combination lock.";
		cout << "\nYou need to hurry before the guards stumbled upon you!.";

		cout << "\n\nThe sum of the 3 digits of the combination lock is " << code_sum1;
		cout << "\nThe multiplication of the 3 digits of the combination lock is " << code_multiplication1;
		cout << "\n" << code_a << " " << code_b << " " << code_c << " ";
		cout << "\n\n\nEnter the 3 digit numbers: ";
		cin >> guess_a >> guess_b >> guess_c;

		check_if_pass();

		if (wrong == 1)
		{
			cout << "Oh no! A Guard has heard some noises and he's coming to your direction. HURRY, BREAK IN! NOW!!";
			cout << "\n\nEnter the 3 digit numbers: ";
			cin >> guess_a >> guess_b >> guess_c;
			check_if_pass();
		}

		if (wrong == 2)
		{
			cout << "You've been caught by the guard and expelled from school.\n\n\n";
			busted = true;
		}

		if (check_if_pass() == true)
		{
			cout << "\n\nNice, you're in now!";
			Sleep(2000);
			story_arc2();
		}
	}

	void story_arc2()
	{
		system("cls");

		cout << "You sneak in akin to a shadow, leaving no trail whatsoever.";
		cout << "\nHiding your breath, you saw 2 guards sitting next to each other near the teacher's office.";
		cout << "\nYou decided to make a distraction.";
		cout << "\n1. Throw a rock into a door.";
		cout << "\n2. Imitate a cat's sound.";
		cout << "\n3. Turn on the school's broadcast.";

		cout << "\n\nChoice: ";
		cin >> user_input;

		switch (user_input)
		{
		case 1:
			system("cls");
			random_number();
			code_d = rand() % 5 + level_difficulty;
			logic();
			

			cout << "You decided to throw a rock.";
			cout << "\nThe guard grows suspicious and decided to check on it.";
			cout << "\nYou sneak pass him and saw a 4 digits combination lock.";
			cout << "\n\nThe sum of the 4 digits of the combination lock is " << code_sum2;
			cout << "\nThe multiplication of the 4 digits of the combination lock is " << code_multiplication2;
			cout << "\n" << code_a << " " << code_b << " "<< code_c << " " << code_d;
			cout << "\n\n\nEnter the 4 digit numbers: ";

			cin >> guess_a >> guess_b >> guess_c >> guess_d;

			check_if_pass();

			if (wrong == 1)
			{
				cout << "Oh no! A Guard has heard some noises and he's coming to your direction. HURRY, BREAK IN! NOW!!";
				cout << "\n\nEnter the 4 digit numbers: ";
				cin >> guess_a >> guess_b >> guess_c;
				check_if_pass();
			}

			if (wrong == 2)
			{
				cout << "You've been caught by the guard and expelled from school.\n\n\n";
				busted = true;
			}

			if (check_if_pass() == true)
			{
				cout << "\n\nNice, you're in now!";
				cout << "\nYou got your phone! Now it's time to get out of here before the guard notice something amiss!!\n\n";
				exit(0);
			}
			break;

		case 2:
			system("cls");

			cout << "You decided to imitate a cat's sound.";
			cout << "\nThe guard grows suspicious and knows that it's not a cat sound but a human one.";
			cout << "\nYou've been caught by the guard and will be expelled tomorrow.\n\n";
			exit(0);
			break;

		case 3:
			system("cls");
			random_number();
			logic();

			cout << "You decided to turn on the school's brodcast. So you go into the broadcasting room.";
			cout << "\nYou saw a 3 digits combination lock.";
			cout << "\n\nThe sum of the 3 digits of the combination lock is " << code_sum1;
			cout << "\nThe multiplication of the 3 digits of the combination lock is " << code_multiplication1;
			cout << "\n" << code_a << " " << code_b << " " << code_c;
			cout << "\n\n\nEnter the 3 digit numbers: ";
			cin >> guess_a >> guess_b >> guess_c;

			check_if_pass();

			if (check_if_pass() == true)
			{
				cout << "\n\nNice, you're in now!";
				Sleep(2000);
				system("cls");

				random_number();
				code_d = rand() % 5 + level_difficulty;

				cout << "You turned on the school's music broadcast.";
				cout << "\nThe guards are hurrying to into the music room.";
				cout << "\nYou move pass them and rush into the the teacher's office and saw a 4 digits combination lock.";
				cout << "\n\nThe sum of the 4 digits of the combination lock is " << code_sum2;
				cout << "\nThe multiplication of the 4 digits of the combination lock is " << code_multiplication2;
				cout << "\n" << code_a << " " << code_b << " " << code_c << " " << code_d;
				cout << "\n\n\nEnter the 4 digit numbers: ";

				cin >> guess_a >> guess_b >> guess_c >> guess_d;

				check_if_pass();

				if (check_if_pass() == true)
				{
					cout << "\n\nNice, you're in now!";
					cout << "\nYou got your phone! Now it's time to get out of here before the guard notice something amiss!!\n\n";
					exit(0);
				}
				break;
			}
		}
	}

public:

	void run()
	{
		introduction();
		while (busted != true)
		{
			story_arc1();
		}
	}
};

int main()
{
	game game;
	game.run();

	return 0;
}
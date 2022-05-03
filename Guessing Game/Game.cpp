#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>	// srand, rand
using namespace std;

int random_number;
int guess;
int chances = 5;
bool game_over;
bool shut_down;

int main()
{
	cout << "\n Let's Play A Game, Little Boy...";
	cout << "\n\n I Will Pick A Random Number Between 1 To 100.... And You Must GUESS!!";
	cout << "\n\n Dont Be Scared, I Wont Bite. *slurp*";
	cout << "\n\n You Only Have 5 Chances, You Know What Would Happen If You Lose Right...?";
	cout << "\n\n You Just Need To Say 1 Word, 1 Word Only And You Can Play With Mr.Clown! Just Say 'yes'. SAY IT!!!  ";
	

	do
	{
		string input;
		cin >> input;
		if (input == "yes")
		{
			system("cls");
			cout << "\n Oooo Mr.Clown Likes Your Answer, Mr.Clown Cant Wait To Taste Your Mea... I Mean Having Fun !";
			cout << "\n\n Now Dont Mind Getting It Wrong, Just Believe In Yourself And LET ME EAT YOU !!!\n\n";
			srand(time(NULL));
			random_number = rand() % 100;	

			while (game_over == false)
			{
				int guess;
				cin >> guess;
				
				if (guess <= random_number && guess != random_number)
				{
					system("cls");
					cout << "\n Dont Be Like This, You Gotta Eat More Or You Wont Get Fat, AHAHAHAHAHA";
					chances--;
					cout << "\n\n Ooohh What A Poor Little Fella, Now You Only Have " << chances << " Left. Better Treasure It Well...\n\n";
				}
				else if (guess >= random_number && guess != random_number)
				{
					system("cls");
					cout << "\n Ehihihihi, Thats A Little Too Many My Sweet Little Meat";
					chances--;
					cout << "\n\n Ooohh What A Poor Little Fella, Now You Only Have " << chances << " Chances Left. Better Treasure It Well...\n\n";
				}
				else if (guess == random_number)
				{
					system("cls");
					cout << "\n My Little Boy, Who Would've Thought You Won. But The Door Is Closed. You Need To Accompany Mr.Clown Now AHAHAHAHAHA!";
					Sleep(5000);
					shut_down = true;
				}
				else
					cout << "\n You Are So Naughty Arent Ya ? Remember To Put Only Numbers My Little Boy";
				if (chances == 0 || chances < 1)
				{
					system("cls");
					cout << "\n Y O U  L O S E  L I T T L E  B O Y !!!! AHAHAHAHHAHAHAHHAHA";
					shut_down = true;
				}
			}
		}
	} while (shut_down == false);

	return 0;
}
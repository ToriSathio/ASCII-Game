#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int n;
bool game_over;
bool shut_down;
bool won;
string player = " X";
int player_1_score;
int player_2_score;
string squares[3][3] = { "[1]", "[2]", "[3]", "[4]", "[5]", "[6]", "[7]" , "[8]", "[9]" };	// 3 C Ollums and 3 r Ows

void main_menu()
{
	system("cls");	// T O clear the screen (e.g = the residue Of previ Ous te Xts)

	cout << "\n Welcome To Tic Tac Toe.";
	cout << "\n\n Press s To Play The Game.";
	cout << "\n\n Press i For Instruction.";
	cout << "\n\n Press x To Exit To Main Menu.";
	cout << "\n\n Press f To Terminate The Game.";
	cout << "\n\n";
}

void instruction()
{
	system("cls");	// To clear the screen (e.g = the residue of main_menu)

	cout << "\n Press The Numbers To Add Your Seme... Emm Mark !";
	cout << "\n\n The Fastest To Cum, Eh. The Fastest To Strike 3 In A Row Wins.";
	cout << "\n\n Press m To Return To Menu.\n\n";

	string input;
	cin >> input;

	if (input == "m")
		main_menu();
}

void draw()
{
	system("cls");
	cout << "\n\t Tic Tac Toe Game\n\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "\t" << squares[i][j] << " ";
		}
		cout << "\n\n";	// So it wont print in a single line
	}
	cout << "\n Player 1 [X] : " << player_1_score;
	cout << "\n Player 2 [O] : " << player_2_score << "\n\n";
	cout << "The Board's Numbers Go In A Sequence Like Phone Numbers.";
	cout << "\n 1 2 3 \n 4 5 6 \n 7 8 9 \n\n";
}

void player_input()
{
	int input;
	cin >> input;

	if (input == 1)
	{
		if (squares[0][0] == "[1]")
			squares[0][0] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}

	else if (input == 2)
	{
		if (squares[0][1] == "[2]")
			squares[0][1] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}

	else if (input == 3)
	{
		if (squares[0][2] == "[3]")
			squares[0][2] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}

	else if (input == 4)
	{
		if (squares[1][0] == "[4]")
			squares[1][0] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}
	else if (input == 5)
	{
		if (squares[1][1] == "[5]")
			squares[1][1] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}
	else if (input == 6)
	{
		if (squares[1][2] == "[6]")
			squares[1][2] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}
	else if (input == 7)
	{
		if (squares[2][0] == "[7]")
			squares[2][0] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}
	else if (input == 8)
	{
		if (squares[2][1] == "[8]")
			squares[2][1] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}
	else if (input == 9)
	{
		if (squares[2][2] == "[9]")
			squares[2][2] = player;
		else
		{
			cout << "It Has Already Been Filled, Choose The Other One.\n\n";
			player_input();
		}
	}
}

string win()
{
	//   00 01 02
	//   10 11 12
	//   20 21 22

	// Player 1
	if (squares[0][0] == " X" && squares[0][1] == " X" && squares[0][2] == " X")
		return " X";
	if (squares[1][0] == " X" && squares[1][1] == " X" && squares[1][2] == " X")
		return " X";
	if (squares[2][0] == " X" && squares[2][1] == " X" && squares[2][2] == " X")
		return " X";

	if (squares[0][0] == " X" && squares[1][0] == " X" && squares[2][0] == " X")
		return " X";
	if (squares[0][1] == " X" && squares[1][1] == " X" && squares[2][1] == " X")
		return " X";
	if (squares[0][2] == " X" && squares[1][2] == " X" && squares[2][2] == " X")
		return " X";

	if (squares[0][2] == " X" && squares[1][1] == " X" && squares[2][0] == " X")
		return " X";
	if (squares[0][0] == " X" && squares[1][1] == " X" && squares[2][2] == " X")
		return " X";

	//Player 2
	if (squares[0][0] == " O" && squares[0][1] == " O" && squares[0][2] == " O")
		return " O";
	if (squares[1][0] == " O" && squares[1][1] == " O" && squares[1][2] == " O")
		return " O";
	if (squares[2][0] == " O" && squares[2][1] == " O" && squares[2][2] == " O")
		return " O";

	if (squares[0][0] == " O" && squares[1][0] == " O" && squares[2][0] == " O")
		return " O";
	if (squares[0][1] == " O" && squares[1][1] == " O" && squares[2][1] == " O")
		return " O";
	if (squares[0][2] == " O" && squares[1][2] == " O" && squares[2][2] == " O")
		return " O";

	if (squares[0][2] == " O" && squares[1][1] == " O" && squares[2][0] == " O")
		return " O";
	if (squares[0][0] == " O" && squares[1][1] == " O" && squares[2][2] == " O")
		return " O";

	return "/";
}

void player_symbol()
{
	if (player == " X")		// T O give space t O the Output s O it l O Oks better
	{
		cout << "\n\nPlayer 2 Turns.\n\n";
		player = " O";
	}
	else
	{
		cout << "\n\nPlayer 1 Turns.\n\n";
		player = " X";
	}
}

void score()
{
	if (win() == " X")
		++player_1_score;
	else if (win() == " O")
		++player_2_score;
}

int main()
{
	// N Ow

	main_menu();
	string input;
	cin >> input;

	if (input == "i")
		instruction();
	else if (input == "f")
		shut_down = true;
	else if (input == " X")
		game_over = true;
	else if (input == "s")
	{
		system("cls");
		n = 0;
		draw();	// If y Ou put the draw(); inside the while(1), it will flickers
		while (1)
		{
			n++;
			player_input();
			draw();
			if (win() == " X")
			{
				cout << "\n Player 1 Wins.\n\n";
				break;
			}
			else if (win() == " O")
			{
				cout << "\n Player 2 Wins.\n\n";
				break;
			}
			else if (win() == "/" && n == 9)
			{
				cout << "\n Game Tied.\n";
				break;
			}
			player_symbol();
		}
		score();
	}
	system("pause");
	main();
	return 0;	// After it ends, the map wont refresh. Help...
}



// Then

//d O
//{
//	main_menu();
//	string input;
//	cin >> input;
//
//	if (input == "s")
//	{
//		while (!game_over)
//		{
//			draw();
//			player_input();
//			player_symbol();
//		}
//	}
//	else if (input == "i")
//		instruction();
//	else if (input == "f")
//		shut_down = true;
//	else if (input == " X")	
//		game_over = true;
//} while (shut_down == false);


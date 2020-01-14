#include<iostream>
#include<algorithm>
using namespace std;

bool Moves_Left(char board[3][3]);
bool Space_Left(char board[3][3], int , int );
void print_board(char board[3][3]);
int check(char board[3][3],bool &,char &);
int checking(char board[3][3], int r, int c);
int Min_Max(char board[3][3], bool isMax, int depth);

char player = 'x', opponent = 'o';
struct Movement
{
	int row;
	int col;
};
Movement Best_Move(char board[3][3]);

int main()
{
	char Game_board[3][3] = {{ '_', '_', '_' },{ '_', '_', '_' },{ '_', '_', '_' }};
	cout << "------------------------------------------" << endl;
	cout << "-----WELCOME TO Game ------" << endl;
	cout << "-----TIC TAC TOE Game ------" << endl;
	bool flag_Main,flag;
	print_board(Game_board);
	int row, col;
	do
	{
		cout << endl << "Opponent Turn (o) : " << endl;
		do
		{
			cout << "Enter Row # : ";
			do
			{
				cin >> row;
			} while (row < 0 || row > 2);
			cout << "Enter Column # : ";
			do
			{
				cin >> col;
			} while (col < 0 || col > 2);
			flag = Space_Left(Game_board, row, col);
		} while (flag == false);
		
		
		Game_board[row][col] = opponent;

		cout << endl;
		print_board(Game_board);

		flag_Main = Moves_Left(Game_board);

		bool winning = false;
		char ch = 'a';
		check(Game_board, winning, ch);

		if (winning == true && ch == 'o')
		{
			flag_Main = false;
			cout << endl <<"   "<< "Wow.....!!! Opponent won.......:)" << endl;
		}
		if (!Moves_Left)
		{
			cout << endl << "   " << "OoOops.....!!! Game Tie.......:)" << endl;
		}
		if (flag_Main == true)
		{
			cout << endl << "Player Turn (x) : " << endl;
			Movement move = Best_Move(Game_board);
			winning = false;
			
			Game_board[move.row][move.col] = player;

			flag_Main = Moves_Left(Game_board);
			print_board(Game_board);

			check(Game_board, winning, ch);
			if (winning == true && ch == 'x')
			{
				flag_Main = false;
				cout << endl << "   " << "Wow.....!!! Player won.......:)" << endl;
			}
		}
	} while (flag_Main != false);

	system("pause>NULL");
	return 0;
}

bool Moves_Left(char board[3][3])
{
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				flag = true;
			}
		}
	}
	return flag;
}
bool Space_Left(char board[3][3], int r, int c)
{
	bool flag = false;
	if (board[r][c] == '_')
	{
		flag = true;
	}
	return flag;
}
void print_board(char board[3][3])
{
	cout << endl << " --:  Game Board is  :-- " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "   ";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int check(char board[3][3], bool &flag, char &c)
{
	for (int i = 0; i < 3; i++)				//for rows checks
	{   
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			flag = true;
			c = board[i][0];
			return checking(board, i, 0);
		}
	}
	for (int i = 0; i < 3; i++)				//for  cols check
	{  
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			flag = true;
			c = board[0][i];
			return checking(board, 0, i);
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])    //for left diagnol
	{
		flag = true;
		c = board[0][0];
		return checking(board, 0, 0);
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])    //for right diagnol
	{
		flag = true;
		c = board[0][2];
		return checking(board, 0, 2);
	}
	return 0;
}
int checking(char board[3][3],int r, int c)
{
	if (board[r][c] == player)
	{
		return +10;
	}
	else if (board[r][c] == opponent)
	{
		return -10;
	}
}

int Min_Max(char board[3][3], bool flag, int depth)
{
	if (Moves_Left(board) == false)
	{
		return 0;
	}
	char c = 'a';
	int point;
	bool flagg;
	int score = check(board, flagg, c);
	
	if (score == -10)
	{
		return score;
	}
	else if (score == 10)
	{
		return score;
	}
	
	if (flag)
	{
		point = -500;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = player;
					point = max(point, Min_Max(board, !flag, depth + 1));
					board[i][j] = '_';
				}
			}
		}
	}
	else
	{
		point = 1000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = opponent;
					point = min(point, Min_Max(board, !flag, depth + 1));
					board[i][j] = '_';
				}
			}
		}
	}
	return point;
}
Movement Best_Move(char board[3][3])
{
	Movement movement;
	movement.row = movement.col = -1;
	int value = -500;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				board[i][j] = player;
				int value1 = Min_Max(board, false, 0);
				board[i][j] = '_';
				if (value1 > value)
				{
					movement.row = i;
					movement.col = j;
					value = value1;
				}
			}
		}
	}
	return movement;
}

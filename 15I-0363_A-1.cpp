//------------------------
//Name: Hamid Iqbal
//Roll NO: i15-0363
//Section: A (DS-Summer)
//------------------------

#include<iostream>
#include<ctime>
#include<random>
using namespace std;
bool check(int **Array, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Array[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Random(int row, int col, int &s_row, int &s_col)
{
	bool flag = false;
	int c;
	//srand(time(NULL));
	c = rand() % 4;
	if (c == 0)
	{
		if (s_row > 0)
		{
			s_row = s_row - 1;
			flag = true;
		}
	}
	else if (c == 1)
	{
		if (s_col > 0)
		{
			s_col = s_col - 1;
			flag = true;
		}
	}
	else if (c == 2)
	{
		if (s_row < (row - 1))
		{
			s_row = s_row + 1;
			flag = true;
		}
	}
	else if (c == 3)
	{
		if (s_col < (col - 1))
		{
			s_col = s_col + 1;
			flag = true;
		}
	}
	return flag;
}
int Cockroach_move(int **Array, int row, int col,int &s_row,int &s_col,int &count)
{
	if (check(Array, row, col) == true)
	{
		return 0;
	}
	else
	{
		bool flag = Random(row, col, s_row, s_col);
		if (flag)
		{
			Array[s_row][s_col] = Array[s_row][s_col] + 1;
			count += 1;
		}
		Cockroach_move(Array, row, col, s_row, s_col,count);
	}
	return 0;
}
int main()
{
	int loop = 0;
	while (loop == 0)
	{
		cout << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "1) For Cockroach Movement : " << endl;
		cout << "2) Exit...:)" << endl;
		cout << "----------------------------------------------------------------" << endl;
		int n;
		do
		{
			cout << "Enter : ";
			cin >> n;
		} while (n != 1 && n != 2);

		if (n == 1)
		{
			int row, col;
			cout << "Enter number of Rows : ";
			cin >> row;
			cout << "Enter number of Cols : ";
			cin >> col;
			int **Array;
			Array = new int*[row];
			for (int i = 0; i < row; i++)
			{
				Array[i] = new int[col];
				for (int j = 0; j < col; j++)
				{
					Array[i][j] = 0;
				}
			}
			int s_row, s_col;
			cout << "Enter starting row : ";
			do
			{
				cin >> s_row;
			} while (s_row < 0 || s_row >= row);

			cout << "Enter starting col : ";
			do
			{
				cin >> s_col;
			} while (s_col < 0 || s_col >= col);


			int count = 0;
			Cockroach_move(Array, row, col, s_row, s_col, count);

			cout << endl;
			cout << "Total Number of Moves is : " << count << endl;
			cout << "The number of Times Each Tile visited is as Follows : " << endl;;
			int sum = 0, min = Array[0][0];
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << Array[i][j] << '\t';
					sum = sum + Array[i][j];
					if (Array[i][j] < min)
					{
						min = Array[i][j];
					}
				}
				cout << endl;
			}
			cout << endl;
			cout << "The Sum of Element in the Array is : " << sum << endl;
			cout << "The Minimum of Element in the Array is : " << min << endl;
			for (int i = 0; i < row; i++)
			{
				delete[] Array[i];
			}
			delete[] Array;
		}
		else if (n == 2)
		{
			loop = 1;
		}
		//system("ClS");
	}

	system("pause>NULL");
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef char(*array2)[];
int turnLeft(unsigned &H_column, char * column)
{
	if (column[H_column - 1] == 'F')
	{
		return 5;
	}
	if (column[H_column - 1] == '.')
	{
		--H_column;
		return 3;
	}
	return 0;
}
int turnRight(unsigned &H_column, char * column)
{
	
	if (column[H_column + 1] == 'F')
	{
		return 5;
	}
	if (column[H_column + 1] == '.')
	{
		++H_column;
		return 4;
	}
	return 0;
}
int forward(unsigned &H_row,unsigned &H_column, char (*row)[20] )
{
	if (row[H_row - 1][H_column] == 'F')
	{
		return 5;
	}
	if (row[H_row - 1][H_column] == '.')
	{
		--H_row;
		return 1;
	}
	return 0;
}
int backward(unsigned &H_row, unsigned &H_column, char(*row)[20])
{
	if (row[H_row + 1][H_column] == 'F')
	{
		return 5;
	}
	if (row[H_row + 1][H_column] == '.')
	{
		++H_row;
		return 2;
	}
	return 0;
}
int findF(unsigned state, unsigned & n)
{

	if (state == 5)
		return n;
	if (state == 0)
	{
		return 0;
	}
	if (state == 1)
	{
		
	}
}
int main()
{

	char c;
	unsigned N, M, H_row, H_column, F_row, F_column, n;
	while (cin >> N >> M)
	{
		n = 0;
		char maze[5][20] ;
		auto a = maze;
		for (int i = 0; i != N; ++i)
		{
			for (int t = 0; t != M; ++t)
			{
				cin >> c;
				maze[i][t] = c;
				if (c == 'H')
				{
					H_row = i;
					H_column = t;
				}
				if (c == 'F')
				{
					F_row = i;
					F_column = t;
				}
			}
		}

	}
}
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < n; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool n_queen(vector<vector<int>> &board, int col, int n)
{
	/* base case: If all queens are placed 
	then return true */
	if (col >= n)
		return true;

	/* Consider this column and try placing 
	this queen in all rows one by one */
	for (int i = 0; i < n; i++)
	{
		/* Check if the queen can be placed on 
		board[i][col] */
		if (isSafe(board, i, col, n))
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (n_queen(board, col + 1, n))
				return true;

			/* If placing queen in board[i][col] 
			doesn't lead to a solution, then 
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any row in 
		this colum col then return false */
	return false;
}

int32_t main()
{
	/*int n;
    cin >> n;*/
	int n = 4;
	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			board[i][j] = 0;
		}
	}

	if (n_queen(board, 0, n) == false)
	{
		cout << "Sol does't Exist." << endl;
	}

	//printing the matix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
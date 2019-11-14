// 37. Sudoku Solver
#include <vector>
using namespace std;

class Solution {
private:
	bool isValid(vector<vector<char>>& board, int row, int col, char num)
	{
		for (int k = 0; k < 9; k++)
		{
			if (board[row][k] != '.' && board[row][k] == num)
				return false;
			if (board[k][col] != '.' && board[k][col] == num)
				return false;
			if (board[(row / 3) * 3 + k / 3][(col / 3) * 3 + k % 3] != '.' && board[(row / 3) * 3 + k / 3][(col / 3 * 3) + k % 3] == num)
				return false;
		}

		return true;
	}

	bool solve(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					for (int k = 0; k < 9; k++)
					{
						char num = k + '1';
						if (isValid(board, i, j, num))
						{
							board[i][j] = num;
							if (solve(board))
								return true;
							else
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}

		return true;
	}

public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
};
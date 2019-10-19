// 51. N-Queens
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	bool check(vector<string>& board, int row, int col)
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'Q')
				{
					if (i == row || i + j == row + col || i - j == row - col)
						return false;
				}
			}
		}

		return true;
	}

	void putQueens(vector<string>& board, vector<vector<string>>& res, int col)
	{
		if (col == board[0].size())
		{
			res.push_back(board);
			return;
		}

		for (int i = 0; i < board.size(); i++)
		{
			if (check(board, i, col))
			{
				board[i][col] = 'Q';
				putQueens(board, res, col + 1);
				board[i][col] = '.';
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> board(n, string(n, '.'));
		putQueens(board, res, 0);
		return res;
	}
};
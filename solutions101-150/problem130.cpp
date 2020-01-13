// 130. Surrounded Regions
#include <vector>
using namespace std;

class Solution
{
private:
	void check(vector<vector<char>>& board, int i, int j)
	{
		if (board[i][j] != 'O')
			return;

		board[i][j] = 'Y';
		if (i > 0)
			check(board, i - 1, j);
		if (i < board.size() - 1)
			check(board, i + 1, j);
		if (j > 0)
			check(board, i, j - 1);
		if (j < board[i].size() - 1)
			check(board, i, j + 1);
	}

public:
	void solve(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty())
			return;

		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i < m; i++)
		{
			check(board, i, 0);
			check(board, i, n - 1);
		}
		for (int j = 0; j < n; j++)
		{
			check(board, 0, j);
			check(board, m - 1, j);
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'Y')
					board[i][j] = 'O';
			}
		}
	}
};

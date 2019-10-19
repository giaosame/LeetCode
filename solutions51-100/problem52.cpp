// 52. N-Queens II
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

	void putQueens(vector<string>& board, int& cnt, int col)
	{
		if (col == board[0].size())
		{
			cnt++;
			return;
		}

		for (int i = 0; i < board.size(); i++)
		{
			if (check(board, i, col))
			{
				board[i][col] = 'Q';
				putQueens(board, cnt, col + 1);
				board[i][col] = '.';
			}
		}
	}

public:
	int totalNQueens(int n) {
		int cnt = 0;
		vector<string> board(n, string(n, '.'));
		putQueens(board, cnt, 0);
		return cnt;
	}
};
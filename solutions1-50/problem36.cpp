// 36. Valid Sudoku
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9 || board[0].size() != 9)
			return false;

		for (int i = 0; i < board.size(); i++)
		{
			set<int> row;
			set<int> col;
			set<int> square;

			for (int j = 0; j < board[0].size(); j++)
			{
				int row_idx = (i / 3) * 3;
				int col_idx = (i % 3) * 3;

				if (board[i][j] != '.')
				{
					if (row.find(board[i][j]) != row.end())
						return false;
					row.insert(board[i][j]);
				}

				if (board[j][i] != '.')
				{
					if (col.find(board[j][i]) != col.end())
						return false;
					col.insert(board[j][i]);
				}

				if (board[row_idx + j / 3][col_idx + j % 3] != '.')
				{
					if (square.find(board[row_idx + j / 3][col_idx + j % 3]) != square.end())
						return false;
					square.insert(board[row_idx + j / 3][col_idx + j % 3]);
				}
			}
		}

		return true;
	}
};
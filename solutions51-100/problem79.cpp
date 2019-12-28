// 79. Word Search
#include <vector>
using namespace std;

class Solution {
private:
	bool search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited)
	{
		if (idx == word.size())
			return true;
		if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || word[idx] != board[i][j] || visited[i][j])
			return false;

		visited[i][j] = true;
		if (search(board, word, idx + 1, i - 1, j, visited) ||
			search(board, word, idx + 1, i + 1, j, visited) ||
			search(board, word, idx + 1, i, j - 1, visited) ||
			search(board, word, idx + 1, i, j + 1, visited))
			return true;

		visited[i][j] = false;
		return false;
	}

public:
	bool exist(vector<vector<char>>& board, string word)
	{
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0] && search(board, word, 0, i, j, visited))
					return true;
			}
		}

		return false;
	}
};
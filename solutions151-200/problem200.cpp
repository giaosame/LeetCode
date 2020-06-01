// 200. Number of Islands
#include <vector>
using namespace std;

class Solution 
{
	void search(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j)
	{
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0' || visited[i][j])
			return;

		visited[i][j] = true;
		search(grid, visited, i + 1, j);
		search(grid, visited, i - 1, j);
		search(grid, visited, i, j + 1);
		search(grid, visited, i, j - 1);
	}

public:
	int numIslands(vector<vector<char>>& grid) 
	{
		if (grid.empty() || grid[0].empty())
			return 0;

		int m = grid.size();
		int n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));

		int num = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '1' && !visited[i][j])
				{
					search(grid, visited, i, j);
					num++;
				}
			}
		}

		return num;
	}
};

// 59. Spiral Matrix II
#include <vector>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> generateMatrix(int n) 
	{
		vector<vector<int>> matrix(n, vector<int>(n));
		if (n <= 0)
			return matrix;

		int row_begin = 0;
		int row_end = n - 1;
		int col_begin = 0;
		int col_end = n - 1;

		int cnt = 1;
		while (row_begin <= row_end && col_begin <= col_end)
		{
			for (int j = col_begin; j <= col_end; j++)
			{
				matrix[row_begin][j] = cnt++;
			}
			row_begin++;
			if (row_begin > row_end)
				break;

			for (int i = row_begin; i <= row_end; i++)
			{
				matrix[i][col_end] = cnt++;
			}
			col_end--;
			if (col_begin > col_end)
				break;

			for (int j = col_end; j >= col_begin; j--)
			{
				matrix[row_end][j] = cnt++;
			}
			row_end--;
			if (row_begin > row_end)
				break;

			for (int i = row_end; i >= row_begin; i--)
			{
				matrix[i][col_begin] = cnt++;
			}
			col_begin++;
		}

		return matrix;
	}
};
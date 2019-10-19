// 54. Spiral Matrix
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> spiral;
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return spiral;

		int row_begin = 0;
		int row_end = matrix.size() - 1;
		int col_begin = 0;
		int col_end = matrix[0].size() - 1;

		while (row_begin <= row_end && col_begin <= col_end)
		{
			for (int j = col_begin; j <= col_end; j++)
				spiral.push_back(matrix[row_begin][j]);
			row_begin++;
			if (row_begin > row_end)
				break;

			for (int i = row_begin; i <= row_end; i++)
				spiral.push_back(matrix[i][col_end]);
			col_end--;
			if (col_begin > col_end)
				break;

			for (int j = col_end; j >= col_begin; j--)
				spiral.push_back(matrix[row_end][j]);
			row_end--;
			if (row_begin > row_end)
				break;

			for (int i = row_end; i >= row_begin; i--)
				spiral.push_back(matrix[i][col_begin]);
			col_begin++;
		}

		return spiral;
	}
};
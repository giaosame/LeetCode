// 48. Rotate Image
#include <vector>
using namespace std;

class Solution {
private:
	void swap(vector<vector<int>>& matrix, int i, int j)
	{
		int temp = matrix[i][j];
		matrix[i][j] = matrix[j][i];
		matrix[j][i] = temp;
	}

public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				swap(matrix, i, j);
			}
		}
	}
};
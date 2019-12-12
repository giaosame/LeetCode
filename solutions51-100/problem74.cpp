// 74. Search a 2D Matrix
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;

		int m = matrix.size();
		int n = matrix[0].size();

		int start = 0;
		int end = m * n - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			int r = mid / n;
			int c = mid % n;

			if (matrix[r][c] == target)
				return true;
			else if (matrix[r][c] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}

		return false;
	}
};
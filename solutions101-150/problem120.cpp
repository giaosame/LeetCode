// 120. Triangle
#include <algorithm>
#include <vector>
using namespace std;

// DP with 2D array
class Solution1 
{
public:
	int minimumTotal(vector<vector<int>>& triangle) 
	{
		int m = triangle.size();
		int n = triangle.back().size();
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		dp[0][0] = triangle[0][0];

		for (int i = 1; i < m; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j - 1 >= 0)
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
				else
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
		}

		int min_path_sum = dp.back()[0];
		for (int j = 0; j < n; j++)
		{
			min_path_sum = min(min_path_sum, dp.back()[j]);
		}

		return min_path_sum;
	}
};


// DP with 1D array
class Solution2
{
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		vector<int> dp = triangle.back();

		for (int i = triangle.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
			}
		}

		return dp[0];
	}
};

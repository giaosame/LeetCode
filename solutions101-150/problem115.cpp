// 115. Distinct Subsequences
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	int numDistinct(string s, string t) 
	{
		int m = s.size();
		int n = t.size();
		vector<vector<long>> dp(m + 1, vector<long>(n + 1));
		for (int i = 0; i <= m; i++)
			dp[i][0] = 1;

		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= m; i++)
			{
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		return dp[m][n];
	}
};

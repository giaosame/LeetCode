// 10. Regular Expression Matching
// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//     '.' Matches any single character.
//     '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
		dp[0][0] = true;
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] == '*')
			{
				if (dp[0][j - 1] || (j > 1 && dp[0][j - 2]))
					dp[0][j] = true;
			}
		}

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (p[j - 1] == s[i - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '.')
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '*')
				{
					if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
						dp[i][j] = dp[i][j - 2];
					else
						dp[i][j] = (dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j]);
				}
			}
		}

		return dp[m][n];
	}
};

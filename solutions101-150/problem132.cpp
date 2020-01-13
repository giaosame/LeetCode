// 132. Palindrome Partitioning II
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	int minCut(string s) 
	{
		int n = s.size();
		vector<int> cuts(n);
		vector<vector<bool>> dp(n, vector<bool>(n));

		for (int i = 0; i < n; i++)
		{
			cuts[i] = i;
			for (int j = 0; j <= i; j++)
			{
				if (s[j] == s[i] && (j + 1 >= i - 1 || dp[j + 1][i - 1]))
				{
					dp[j][i] = true;
					cuts[i] = j > 0 ? min(cuts[i], cuts[j - 1] + 1) : 0;
				}
			}
		}

		return cuts[n - 1];
	}
};

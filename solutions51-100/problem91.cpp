// 91. Decode Ways
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	int numDecodings(string s) 
	{
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;
		if (s[0] != '0')
			dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			int one = s[i - 1] - '0';
			int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

			if (one > 0 && one <= 9)
				dp[i] += dp[i - 1];
			if (two > 9 && two <= 26)
				dp[i] += dp[i - 2];
		}

		return dp[n];
	}
};

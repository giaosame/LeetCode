// 188. Best Time to Buy and Sell Stock IV
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(int k, vector<int>& prices)
	{
		int n = prices.size();
		if (k <= 0)
			return 0;

		if (k > n / 2)
		{
			int profit = 0;
			for (int i = 1; i < n; i++)
			{
				if (prices[i] > prices[i - 1])
					profit += prices[i] - prices[i - 1];
			}

			return profit;
		}

		vector<vector<int>> dp(k + 1, vector<int>(n));
		for (int i = 1; i <= k; i++)
		{
			int temp_max = -prices[0];
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = max(dp[i][j - 1], temp_max + prices[j]);
				temp_max = max(temp_max, dp[i - 1][j - 1] - prices[j]);
			}
		}

		return dp[k][n - 1];
	}
};

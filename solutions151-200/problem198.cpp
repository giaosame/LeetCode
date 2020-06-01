// 198. House Robber
#include <algorithm>
#include <vector>
using namespace std;

// Recursion: 
// The maximum money we can get is the maximum between these 2 ways:
//   1. Rob the current house and then jump to the house before the previous one: nums[i] + recurRob(i - 2);
//   2. Ignore the current house and rob the previous one: recurRob(i - 1);
//   max_money = max(nums[i] + recurRob(i - 2), recurRob(i - 1));
// This algorithm will process the same i multiple times.
class Solution1
{
	int recurRob(vector<int>& nums, int i)
	{
		if (i < 0)
			return 0;

		return max(recurRob(nums, i - 2) + nums[i], recurRob(nums, i - 1));
	}

public:
	int rob(vector<int>& nums) 
	{
		return recurRob(nums, nums.size() - 1);
	}
};

// Recursion + memo
// To avoid the repetitive computation.
class Solution2
{
	int recurRob(vector<int>& nums, vector<int>& money, int i)
	{
		if (i < 0)
			return 0;
		if (money[i] != -1)
			return money[i];

		money[i] = max(recurRob(nums, money, i - 2) + nums[i], recurRob(nums, money, i - 1));
		return money[i];
	}

public:
	int rob(vector<int>& nums) 
	{
		int n = nums.size();
		vector<int> money(n, -1);
		return recurRob(nums, money, n - 1);
	}
};

// DP1: iterative + memo array
class Solution3 
{
public:
	int rob(vector<int>& nums) 
	{
		if (nums.empty())
			return 0;

		int n = nums.size();
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = nums[0];

		for (int i = 2; i <= n; i++)
		{
			dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
		}

		return dp[n];
	}
};

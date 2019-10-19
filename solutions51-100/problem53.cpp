// 53. Maximum Subarray
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int max_sum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];
			max_sum = max(max_sum, dp[i]);
		}

		return max_sum;
	}
};
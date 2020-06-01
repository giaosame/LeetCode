// 152. Maximum Product Subarray
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
	int maxProduct(vector<int>& nums)
	{
		int max_product, pre_max, pre_min, cur_max, cur_min;
		max_product = pre_max = pre_min = cur_max = cur_min = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			cur_max = max(nums[i], max(pre_max * nums[i], pre_min * nums[i]));
			cur_min = min(nums[i], min(pre_max * nums[i], pre_min * nums[i]));
			max_product = max(max_product, cur_max);
			pre_max = cur_max;
			pre_min = cur_min;
		}

		return max_product;
	}
};

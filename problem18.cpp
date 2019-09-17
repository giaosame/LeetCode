// 18. 4Sum
// Given an array nums of n integers and an integer target, 
// are there elements a, b, c, and d in nums such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	void twoSum(vector<vector<int>>& res, vector<int>& nums, int target, int start, int e1, int e2)
	{
		if (start + 1 >= nums.size())
			return;
		if (2 * nums[start] > target || 2 * nums.back() < target)
			return;

		int left = start;
		int right = nums.size() - 1;
		while (left < right)
		{
			int temp_sum = nums[left] + nums[right];
			if (temp_sum == target)
			{
				vector<int> sum = { e1, e2, nums[left], nums[right] };
				res.push_back(sum);
				while (left < right && nums[left] == nums[left + 1])
					left++;
				while (left < right && nums[right] == nums[right - 1])
					right--;
				left++;
				right--;
			}
			else if (temp_sum < target)
				left++;
			else
				right--;
		}
	}

	void threeSum(vector<vector<int>>& res, vector<int>& nums, int target, int start, int e1)
	{
		if (start + 2 >= nums.size())
			return;
		if (3 * nums[start] > target || 3 * nums.back() < target)
			return;

		for (int i = start; i < nums.size(); i++)
		{
			int e = nums[i];
			if (i > start && e == nums[i - 1])
				continue;
			if (e + 2 * nums.back() < target)
				continue;
			if (3 * e > target)
				break;
			if (3 * e == target)
			{
				if (i + 2 < nums.size() && e == nums[i + 2])
				{
					vector<int> sum = { e1, e, e, e };
					res.push_back(sum);
					break;
				}
			}

			twoSum(res, nums, target - e, i + 1, e1, e);
		}
	}

public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		if (nums.size() < 4)
			return res;

		sort(nums.begin(), nums.end());
		if (4 * nums.front() > target || 4 * nums.back() < target)
			return res;

		for (int i = 0; i < nums.size(); i++)
		{
			int e = nums[i];
			if (i > 0 && e == nums[i - 1])
				continue;
			if (e + 3 * nums.back() < target)
				continue;
			if (4 * e > target)
				break;
			if (4 * e == target)
			{
				if (i + 3 < nums.size() && e == nums[i + 3])
				{
					vector<int> sum = { e, e, e, e };
					res.push_back(sum);
					break;
				}
			}

			threeSum(res, nums, target - e, i + 1, e);
		}

		return res;
	}
};

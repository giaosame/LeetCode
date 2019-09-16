// 16. 3Sum Closest
// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers. You may assume that each input would have exactly one solution.
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
			return 0;

		sort(nums.begin(), nums.end());
		int closest = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int left = i + 1;
			int right = nums.size() - 1;

			while (left < right)
			{
				int temp_sum = nums[i] + nums[left] + nums[right];
				if (temp_sum == target)
					return target;
				else if (temp_sum < target)
					left++;
				else
					right--;

				if (abs(temp_sum - target) < abs(closest - target))
					closest = temp_sum;
			}
		}

		return closest;
	}
};
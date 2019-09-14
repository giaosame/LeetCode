// 15. 3Sum
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> sums;
		if (nums.size() < 3)
			return sums;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int target = -nums[i];
			int left = i + 1;
			int right = nums.size() - 1;

			while (left < right)
			{
				if (nums[left] + nums[right] < target)
					left++;
				else if (nums[left] + nums[right] > target)
					right--;
				else
				{
					vector<int> three_sum = { nums[i], nums[left], nums[right] };
					sums.push_back(three_sum);

					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
			}
		}

		return sums;
	}
};

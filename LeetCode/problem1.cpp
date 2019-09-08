// 1. Two Sum
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;

		vector<int> idxs;
		for (int i = 0; i < nums.size(); i++)
		{
			if (map.find(nums[i]) != map.end())
			{
				idxs.push_back(map[nums[i]]);
				idxs.push_back(i);
				return idxs;
			}
			map[target - nums[i]] = i;
		}
	}
};

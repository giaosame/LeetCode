// 1. Two Sum
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

// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in ascending order, 
// find the starting and ending position of a given target value.
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> idxs = { -1, -1 };
		if (nums.size() == 0)
			return idxs;

		int left = 0;
		int right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (target > nums[mid])
				left = mid + 1;
			else
				right = mid;
		}

		if (nums[left] != target)
			return idxs;

		idxs[0] = left;
		right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right + 1) / 2;
			if (target < nums[mid])
				right = mid - 1;
			else
				left = mid;
		}
		idxs[1] = right;

		return idxs;
	}
};